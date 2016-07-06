//
//  AppDelegate.swift
//  GcellExampleFrameworkUse
//
//  Created by David Pugh on 24/06/2016.
//  Copyright © 2016 G24 Power Ltd David Pugh. All rights reserved.
//


/// TO SUCESSFULLY DETECT IBEACONS PLEASE ENSURE THAT THE INFO.PLIST HAS A ENTRY FOR NSLocationAlwaysUsageDescription
// ALSO ENABLE BACKGROUND MODES AND Uses Bluetooth LE accessory

import UIKit
import GCBeaconNotificationFWv1_1
import CoreLocation




//Remember to adopt the GCBEaconManagerDelegate so we get the relevant call backs

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, GCBeaconManagerDelegate{

    var window: UIWindow?
    
    //Declare your manager as an instance variable, that way it is not destroyed and allows delegates etc
    var beaconManager = GCBeaconManager()
    
    //Change option here to see different ways of work
    var option = 1  //Use beacon.json data and notitifcations
                    // 2 is using code defined regions and getting standard CoreLocation didRange calls
    
    
  


    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
        //Set debug to true to get more console feedback
        beaconManager.debug = true
        //Set the delegate so we receive callbacks
        beaconManager.delegate = self
        
        switch option{
            case 1:
                //Use auto notifications - reads beacons and notifcations from JSON files
                beaconManager.autoNotify = true
                beaconManager.useDefaultBeaconRegion = false
                beaconManager.startScanningForBeacons()
            break
            case 2:
                //Use like standard CoreLocation ranging
                //set the auto notify function OFF
                beaconManager.autoNotify = false
                
                
                //Set up beacon regions
                let uuidString = "A36AD2B5-0736-43FB-8572-63DB53886FF3"
                let beaconIdentifier = "iBeaconModules.us"
                let beaconUUID:NSUUID = NSUUID(UUIDString: uuidString)!
                let beaconRegion:CLBeaconRegion = CLBeaconRegion(proximityUUID: beaconUUID, identifier: beaconIdentifier)
 
                //Add the regions
                beaconManager.addBeaconRegion(beaconRegion)//Leave this out to use the default GCell UUID as the beacon region
                
                //Start Scanning
                beaconManager.startScanningForBeacons()
                
            break
        default:
            break
        }
   
        
        return true
    }

    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

extension AppDelegate{
    
    
    //MARK: beacon manager delegate update calls
    
    /**
     Handle any errors returned from the beacon manager
     */
    func beaconManager(beaconManager: GCBeaconManager, errorCode: Int, with errorMessage: String) {
        print("Error! \(errorCode) - \(errorMessage)")
    }
    
    //You can either react to the list of beacons that are in the notification list and in range, or just the list of actions associated with those beacons

    
    //MARK: Using Auto-notify
    /**
     Recieved list of beacons that are associated with notifications that have been triggered
    */
    func beaconManager(beaconManager: GCBeaconManager, didRangeNotificationBeacons beacons: [GCBeacon]) {
        print("Ranged the following listed beacons:")
        for b in beacons{
            print("\(b.major)/\(b.minor) with \(b.lastKnownRssi)dB at \(b.lastSeen)")
        }

    }
    
    /**
     These are the custom actions that were triggered when seeing the beacon
     */
    func beaconManager(beaconManager: GCBeaconManager, didReceiveNotificationActions actions: Set<GCBeaconAction>) {
        print("Actions Received:")
        for a in actions{
            print("\(a.actionName)")
        }
    }
    

    
    /**
        If using as a standard iBeacon detector, handle any didRange calls as you would from CoreLocation
     */
    func beaconManager(beaconManager: GCBeaconManager, didRangeBeacons beacons: [CLBeacon], inRegion region: CLBeaconRegion) {
        if option == 2{
            print("Ranged the following beacons in region \(region):")
            for b in beacons{
                print("\(b.major)/\(b.minor) with \(b.rssi)dB")
            }
        }

    }
    
  


    
    
}

