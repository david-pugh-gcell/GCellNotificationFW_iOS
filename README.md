# GCellNotificationFWv1 for iOS
This project is an example XCode project that uses the GCell iBeacon Notification FW to easily set up and detect proximity to nearby iBeacons. It is written in Swift (XCode 7.3).

For more information about iBeacons, potential applications, the Framework and other software support such as platforms please contact us at [GCell ibeacon.solar](www.ibeacon.solar).

<h3>Description</h3>

This is an example XCode iOS app written in Swift that uses the GCellNotificationFWv_1 Cocoa Touch Framework. This framework allows the developer to quickly and easily integrate iBeacon proximity awareness into their app with the minimal of code. It can be used to return any nearby ranged iBeacons in foreground and background modes, or can be configured to call custom actions within the app when the beacon signal strength is greater than a certain figure and a defined ammount of time has passed. The Framework automatically mannages permissions, deetcting Bluetooth state and manages Beacon Regions. 

<h3>Using the Framework</h3>

Importing the Framework into your XCode Project
1. Drag the GCellNotificationFWv_1 framework into your XCode Project
2. Click on your project target ->General and also add the framework to the Embedded Binaries
3. Clean and rebuild the project - the classes in the framework should now be avilable to use

<h4>Setting up your Project to work with iBeacons</h4>
We need to add a few settings to your project to enable it to successfully see iBeacons. 

1. Open the info.plist file and add an entry for <i>NSLocationAlwaysUsageDescription</i>. This is shown when the app asks the user to have permissions to use location services to scan for nearby beacons. Add a sensible string that informs the user what we need the permissions for, e.g., "This app needs access to your location to send you relevant notifications and offers."
2. Click on the Project -> Targets - Project Target and select the Capablities option. Scroll down and enable <i>Background Modes</i>. Click on to select the <i> Uses Bluetooth LE accessory</i> checkbox. These allow the app to search for iBeacons using Bluetooth Low Energy when the app is in the background. 

**Your app is now ready to scan for iBeacons!** 

<h4>Telling the app what to Search for</h4>
There are two ways in which the framework can be used - either configured to operate like the standard iOS iBeacon framework in CoreLocation, or using a 'AutoNotify' option. This auto notify options allows the user to easily supply a list of beacons in JSON format, and associate actions that get called when the beacon is ranged. The user can also adjust the signal strength and timings of when these actions are triggered.

<h4>Using Auto-notify</h4>
Firstly, create a list of which beacons you want to scan for, along with any actions and store them in the following JSON file. The file should be called **beacons.json** and included in your project. 

* The **actionName** is the string that is called when the action is triggered
* The **minActionRssi** determines the min Signal Strength (RSSI) that the phone should see before triggering the action (the higher the number the closer you will be to the beacon, e.g., -90dB would be approx 20m and -40dB would be 5m). 
* The **reccurance** value is teh time in seconds between subsequent triggers. E.g., a value of 500 would mean the time between multiple actionName triggers would be 5 minutes (600 seconds). This means we can control the ammount of times a user would be presented with information or notifications, improving user experience. 

```json
{
    "beacons":[
               {
               "comment":"Example 1",
               "UUID":"A36AD2B5-0736-43FB-8572-63DB53886FF3",
               "major":200,
               "minor":108,
               "actions":   [
                             {
                             "actionName":"custom1",
                             "minActionRssi": -55,
                             "recurrance": 5
                             },
                             {
                             "actionName":"custom3",
                             "minActionRssi": -55,
                             "recurrance": 10
                             }
                             
                             ]
               },
               {
               "comment":"Example 2",
               "UUID":"96530d4d-09af-4159-b99e-951a5e826584",
               "major":100,
               "minor":1,
               "actions":   [
                             {
                             "actionName":"custom2",
                             "minActionRssi": -55,
                             "recurrance": 20
                             }
                             ]
               }
               
               ]
}
```

<h4>Starting the Scan</h4>
Firstly declare a GCBeaconManager as an instance variable.

```Swift
var beaconManager = GCBeaconManager()
```

Ensure that the class adopts the GCBeaconManagerDelegate protocol in its definition. Then set the delegate, switch on/off debugging, set autonotify to true and start scanning. 

```Swift
beaconManager.debug = true
beaconManager.delegate = self
beaconManager.autoNotify = true
beaconManager.useDefaultBeaconRegion = false
beaconManager.startScanningForBeacons()
```

The app will chack permissions and settings, load up the beacos data, autoconfigure beacon regions and start scanning. It will return triggered actions and any error feedback messages through the GCBeaconManagerDelegate protocol.

```Swift
 //You can either react to the list of beacons that are in the notification list and in range, or just the list of actions associated with those beacons
    
    //These are the beacons that were ranged as part of the notification system
    func notificationBeaconsRanged(beacons: [GCBeacon]){
        print("Ranged the following listed beacons:")
        for b in beacons{
            print("\(b.major)/\(b.minor) with \(b.lastKnownRssi)dB at \(b.lastSeen)")
        }
        
    }
    
    //These are the custom action calls as part of the notification system
    func notificationActionsReceived(actions: Set<GCBeaconAction>){
        print("Actions Received:")
        for a in actions{
            print("\(a.actionName)")
        }
    }
    
    //Handle any feedback received from framework
    func errorMessage(error: Int, errorDesc: String) {
        print("Error! \(error) - \(errorDesc)")
    }

```

<h4>Using Standard Scan</h4>
This sets the app to run like a normal iOS project using CoreLocation, except permissions and Bluetooth status is handled automatically. You can also use the default GCell UUID without having to enter any UUID details. Set up the instance variable and protocol adoption as above, and also remeber to set the delegate. Set autoNotify to false and then set up the Beacon Regions you wish to monitor and add them to the beaconManager. 

```Swift
 //set the auto notify function OFF
                beaconManager.autoNotify = false
                beaconManager.debug = true
                beaconManager.delegate = self
                
                //Set up beacon regions
                let uuidString = "A36AD2B5-0736-43FB-8572-63DB53886FF3"
                let beaconIdentifier = "iBeaconModules.us"
                let beaconUUID:NSUUID = NSUUID(UUIDString: uuidString)!
                let beaconRegion:CLBeaconRegion = CLBeaconRegion(proximityUUID: beaconUUID, identifier: beaconIdentifier)
 
                //Add the regions
                beaconManager.addBeaconRegion(beaconRegion) //Leave this out to use the default GCell UUID as the beacon region
                
                //Start Scanning
                beaconManager.startScanningForBeacons()
```

Respond to the beacons ranged delegate call back. 

```Swift
    //Handle any feedback received from framework
    func errorMessage(error: Int, errorDesc: String) {
        print("Error! \(error) - \(errorDesc)")
    }
    
    
    //Handel didRanging calls
    func beaconsRanged(manager: GCBeaconManager, beacons: [CLBeacon], region: CLBeaconRegion){
        if option == 2{
            print("Ranged the following beacons in region \(region):")
            for b in beacons{
                print("\(b.major)/\(b.minor) with \(b.rssi)dB")
            }
        }

    }

```

<h3>Backgrond Mode</h3>
The framework will follow Apple guidelines for working in background mode. The ranging function of the app is extended to improve accuracy once a beacon region is detected, but this is only for a short time to minimise battery use. It should be enough for many applications. This Framework is not intended to be used for a navigation based app requiring continal ranging whilst in background mode - if you require this please contact us to discuss this.  The app doesnt automatically deliver local notifications, just the callback to say the beacon has been ranged/action has been trigger. It is left to the developer to implement any notifications to the user. Again - any queries or requests please do not hesitate to contact us to see how we can help.



