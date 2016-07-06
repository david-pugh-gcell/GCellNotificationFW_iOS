// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import CoreBluetooth;
@import CoreLocation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSUUID;
@class NSNumber;
@class NSDate;

\Author 
/// David Pugh, G24 Power Ltd
///
/// The GCBeacon class represents a beacon that was encountered during region monitoring. You do not create instances of this class directly. The beacon manager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
///
/// The identity of a beacon is defined by its proximityUUID, major, and minor properties.
SWIFT_CLASS("_TtC24GCBeaconNotificationFWv18GCBeacon")
@interface GCBeacon : NSObject <NSCopying>

/// label for the beacon
@property (nonatomic, readonly, copy) NSString * _Nonnull label;

/// Returns the beacon UUID in string format
@property (nonatomic, readonly, copy) NSString * _Nonnull uuidString;

/// Returns the beacon UUID in NSUUID format
@property (nonatomic, readonly, strong) NSUUID * _Nonnull uuid;

/// Major number of the beacon (read only)
@property (nonatomic, readonly, strong) NSNumber * _Nonnull major;

/// Minor number of the beacon (read only)
@property (nonatomic, readonly, strong) NSNumber * _Nonnull minor;

/// RSSI value of beacon when last seen
@property (nonatomic) NSInteger lastKnownRssi;

/// Date value of beacon when last seen
@property (nonatomic, strong) NSDate * _Nonnull lastSeen;

/// Copy
- (id _Nonnull)copyWithZone:(struct _NSZone * _Null_unspecified)zone;
@end


\Author 
/// David Pugh, G24 Power Ltd
///
/// The GCBeaconAction class represents an action that can be associated with a beacon that was encountered during region monitoring. You do not create instances of this class directly. The beacon manager object will evaluate if the action sshould be triggered when a beacon is ranged, and reports the beacon and its actions to its associated delegate object. You can use the information in an action object to identify which action should be performed.
///
/// The identity of an action is defined by its ationName, and whether it should be used by its minActionRssi (in dB) and actionReoccurance (in seconds) values
SWIFT_CLASS("_TtC24GCBeaconNotificationFWv114GCBeaconAction")
@interface GCBeaconAction : NSObject

/// The min period between the action being repeated (in seconds) (read only)
@property (nonatomic, readonly) NSInteger actionRecurrance;

/// The min RSSI value a beacon must have before the action is triggered (in dB) (read only)
@property (nonatomic, readonly) NSInteger minActionRssi;

/// The name of the action that will be called - this will be delivered to the delgate object(read only)
@property (nonatomic, readonly, copy) NSString * _Nonnull actionName;

/// The date of the last time the action was used (read only)
@property (nonatomic, strong) NSDate * _Nullable lastUsed;
@end

@class CLBeaconRegion;
@class CLLocationManager;
@class CLBeacon;
@class CLRegion;
@class NSError;
@class CBPeripheralManager;
@protocol GCBeaconManagerDelegate;

\Author 
/// David Pugh, G24 Power Ltd
///
/// The GCBeaconManager class is the central point for configuring the delivery of iBeacon and proximity based events to your app. You use an instance of this class to establish the parameters that determine when iBeacon and proximity notifcation events should be delivered and to start and stop the actual delivery of those events.
/// A GCBeaconManager object provides support for the following iBeacon-related activities:
///
/// <ul><li>Monitoring the status of the Bluetooth on the users devices (on and off).</li><li>Handles all of the CoreLocation set up functionality.</li><li>Checking and managing the Location Services permissions in iOS.</li><li>Auto creation of beacon regions based on a supplied list of beacons (in beacons.json) OR adding user generated regions.</li><li>Monitoring distinct beacon regions of interest and generating location events when the user enters or leaves those regions.</li><li>Reporting the range to nearby beacons.</li><li>If auto-notify is selected, monitoring beacons and deliverying custom action call events when the beacon signal strength and time since last call conditions are met.</li><li>Handling notifiation and ranging updates while the app is in the background.</li></ul>
/// <h2>Usage</h2>
/// To configure and use a GCBeaconManager object to deliver events:
///
/// <ul><li>Always ensure that Framework has been imported into your project, and that an appropriate <NSLocationAlwaysUsageDescription> has been added to the project info.plist
/// The framework will check for - and request as appropriate - authorization to use location services and check to see whether the desired services are available as described in <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/index.html#//apple_ref/doc/uid/TP40007125-CH3-SW72">Requesting Permission to Use Location Services</a>.</li><li>Create an instance of the GCBeaconManager class and store a strong reference to it somewhere in your app.</li><li>Keeping a strong reference to the location manager object is required until all tasks involving that object are complete. Because most beacon manager tasks run asynchronously, storing your beacon manager in a local variable is insufficient.</li><li>Assign a custom object to the delegate property. This object must conform to the <a href="../Protocols/GCBeaconManagerDelegate.html">GCBeaconManagerDelegate Protocol</a>.</li><li>Configure any additional properties relevant to the desired service, e.g., set <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager10autoNotifySb">autoNotify</a> = false</li><li>Call the <a href="GCBeaconManager.html#/s:FC24GCBeaconNotificationFWv115GCBeaconManager23startScanningForBeaconsFT_T_">startScanningForBeacons</a> method to begin the delivery of events.</li><li>All iBeacon and notifcation related updates are delivered to the associated delegate object, which is a custom object that you provide. For information about the delegate methods you use to receive events, see <a href="../Protocols/GCBeaconManagerDelegate.html">GCBeaconManagerDelegate Protocol</a> Reference.</li></ul>\Warning 
/// [Auto-notify] parameter indicates if we should use beacons and notifications stored in beacons.json. If false the user should define and set the beaconRegions array manually. If <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager22useDefaultBeaconRegionSb">useDefaultBeaconRegion</a> is set true, if no regions are set then a region based on the default GCell UUID will be used. If this is false the fraework will not scan for devices.
///
/// <h2>Using Beacon Regions</h2>
/// The framework uses region-monitoring services to be notified when the user crosses a region-based boundary. Region monitoring here applies to beacon regions (represented by the <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/index.html#//apple_ref/occ/cl/CLBeaconRegion">CoreLocation CLBeaconRegion</a>. Region monitoring is used to detect boundary crossings of the specified region and those boundary crossings are used to perform related tasks. For example, upon approaching a stadium the user could be welcomed to the game and be sent a link to the latest team news.
///
/// If <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager10autoNotifySb">autoNotify</a>is enabled, the framework will load a list of beacons from the beacons.json file. It will then automatically generate the apporiate beacon regions to monitor and range. If auto-notify is disabled, you will need to supply a one or more regions for the framework to monitor. These can be generated using the GCBeaconRegion class, which extends the <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/index.html#//apple_ref/occ/cl/CLBeaconRegion">CoreLocation CLBeaconRegion</a>. To generate a beacon region with the default GCell UUID just call the <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager22useDefaultBeaconRegionSb">gcellDefaultRegion</a> method, otherwise create a <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/index.html#//apple_ref/occ/cl/CLBeaconRegion">CoreLocation CLBeaconRegion</a> by specifying a UUID, UUID and Major or UUID, Major and Minor as specified by GCBeaconRegion. Pass these regions to the GCBeaconManager object using addBeaconRegion method. The framework registers these regions and uses them then you start scanning.
/// If no regions are defined - either the reading of the beacons.json file failes OR no region is manually supplied, then the value of the <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager22useDefaultBeaconRegionSb">useDefaultBeaconRegion</a> determines the framework behaviour. If set false, the framework will not scan to save battery power. If set true a beacon region using the default GCell UUID will be used.
///
/// <h3>The beacons.json File</h3>
/// If using <a href="GCBeaconManager.html#/s:vC24GCBeaconNotificationFWv115GCBeaconManager10autoNotifySb">autoNotify</a> then the project should contain a list of the beacons of interest in JSON format. This allows the developer to just add a file of beacons and the framework will automatically set up beacon regions as appropriate. In addition, each beacon can have an associate list of actions that should be called if certain criteria is met. These criteria are:
///
/// <ul><li>Signal Strength (proximity) - by tuning the "minActionRssi" you can tune the approximate distance from the beacon the action to be triggered. A low value (-95) will casuse the action to be triggered as soon as the beacon is observed (approx 20m). BY lowering this value to say -50, you would need to be much closer to the beacon to see the notification.</li><li>Time Interval - the "recurrance" value represents the time interval in seconds between subsequent triggers. A value of say 60 means triggers will not occur more than once a minute. This can be a useful way of minimising the numbe rof callbacks received.</li></ul>
/// When an action is triggered, the framework delivers a Notification action through the <a href="../Protocols/GCBeaconManagerDelegate.html">GCBeaconManagerDelegate Protocol</a>. This will return the "actionName" which can be used to do whatever you want within the app.
///
/// The format of the beacons.json file should be:
///
/// {
/// "beacons":[
/// {
/// "comment":"Example 1",
/// "UUID":"A36AD2B5-0736-43FB-8572-63DB53886FF3",
/// "major":200,
/// "minor":108,
/// "actions":   [
/// {
/// "actionName":"custom1",
/// "minActionRssi": -55,
/// "recurrance": 5
/// },
/// {
/// "actionName":"custom3",
/// "minActionRssi": -55,
/// "recurrance": 10
/// }
///
/// <code>                           ]
///               },
///               {
///                "comment":"Example 2",
///                "UUID":"96530d4d-09af-4159-b99e-951a5e826584",
///                "major":100,
///                "minor":1,
///                "actions":   [
///                            {
///                            "actionName":"custom2",
///                            "minActionRssi": -55,
///                            "recurrance": 20
///                            }
///                            ]
///               }
/// 
///       ]
/// 
/// </code>
/// }
///
/// <h2>Monitoring of iBeacons and Notifications in the Background</h2>
/// Most location services are meant to be used while your app is in the foreground but some can also run in the background. In some cases, location events can even cause your app to be relaunched to process an event. To run most location services in the background, you need to enable the location updates background mode in the Capabilities tab of your Xcode project. For services that launch your app, you need to request (and be granted) “Always” authorization from the user.
///
/// <ul><li>The standard location service delivers events normally while an app is running in the foreground. When your app is in the background, this service delivers events only when the location-updates background mode is enabled for the app. This service does not relaunch iOS apps that have been terminated.</li><li>The region monitoring (entering and exiting a beacon region) service delivers events normally while an app is running in the foreground or background. For a terminated iOS app, this service relaunches the app to deliver events. Use of this service requires “Always” authorization from the user.</li><li>Beacon ranging delivers events normally while an app is running in the foreground. When your app is in the background, this service delivers events only when the location-updates background mode is enabled for the app and the standard location service is running. The framework allows the app to range for beacons for approximately 3 minutes in the background. This service does not relaunch iOS apps that have been terminated.</li><li>Enabling the location-updates background mode ensures that an app continues to receive location events while in the background. When the app moves to the background, the system adds the location-services indicator to the status bar to let the user know that an app is using location services. The system may still terminate the app at any time to reclaim its memory or other resources.</li></ul>
SWIFT_CLASS("_TtC24GCBeaconNotificationFWv115GCBeaconManager")
@interface GCBeaconManager : NSObject <CBPeripheralManagerDelegate, CLLocationManagerDelegate>

/// Indicates if a beacon region with the Default GCell UUID should be used if no beacon regions are defined.
@property (nonatomic) BOOL useDefaultBeaconRegion;

/// The delegate object to receive update events.
@property (nonatomic, weak) id <GCBeaconManagerDelegate> _Nullable delegate;

/// Parameter to indicate if we should use beacons and notifications stored in beacons.json. If false the user should define and set beaconRegions manually.
@property (nonatomic) BOOL autoNotify;

/// Parameter to indicate if debugging feedback is displayed at the command line. Set false for production release
@property (nonatomic) BOOL debug;

/// an array of beaconRegions that the app will scan for
@property (nonatomic, copy) NSArray<CLBeaconRegion *> * _Nonnull beaconRegions;

/// Initializes a new GCellbeaconManager .
///
/// \returns  A GCellBeaconManager, helping you find nearby iBeacons
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;

/// Function to add a new beacon region
///
/// <ul><li>Parameters:</li><li>beaconRegion - a Core Location CLBeaconRegion</li></ul>
- (void)addBeaconRegion:(CLBeaconRegion * _Nonnull)beaconRegion;

/// This function returns a CoreLocation CLBeaconRegion based on the default GCell Proximity UUID
- (CLBeaconRegion * _Nonnull)gcellDefaultRegion;

/// This function starts scanning for nearby iBeacons with the regions defined in beaconRegions
///
/// <h4>Warning</h4>
/// Bluetooth Low Energy needs to be ON to search for iBeacons
///
/// <h4>Usage</h4>
/// Call to start scanning for iBeacons, The Beacon regions to scan can be set in anumber of ways:
///
/// <ul><li>Setting autoNotify to true means the app will use the beacons listed in teh beacons.json file to define appropriate regions automatically</li><li>If autoNatifiy is false, you can create your own beacon regions as you would for CoreLocation and add then to beaconRegions https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/index.html</li><li>If useDefaultBeaconRegion is true, then if beacons.json is missing, there has been an error or no regions are defined, then a beacon region corresponding to the default GCell UUID will be used.</li></ul>
- (void)startScanningForBeacons;

/// This function stops scanning for nearby iBeacons with the regions defined in beaconRegions
- (void)stopScanningForBeacons;

/// CoreLocation locationManager didRangeBeacons callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didRangeBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons inRegion:(CLBeaconRegion * _Nonnull)region;

/// CoreLocation locationManager didDetermineState callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion * _Nonnull)region;

/// CoreLocation locationManager didStartMonitoringForRegion callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didStartMonitoringForRegion:(CLRegion * _Nonnull)region;

/// CoreLocation locationManager didFailWithError callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didFailWithError:(NSError * _Nonnull)error;

/// CoreLocation locationManager monitoringDidFailForRegion callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager monitoringDidFailForRegion:(CLRegion * _Nullable)region withError:(NSError * _Nonnull)error;

/// CoreLocation locationManager rangingDidFailForRegion callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager rangingBeaconsDidFailForRegion:(CLBeaconRegion * _Nonnull)region withError:(NSError * _Nonnull)error;

/// CoreLocation locationManager didEnterRegion callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didEnterRegion:(CLRegion * _Nonnull)region;

/// CoreLocation locationManager didExitRegion callback
- (void)locationManager:(CLLocationManager * _Nonnull)manager didExitRegion:(CLRegion * _Nonnull)region;

/// This function checks the Location Services Authorsation status
///
/// <h4>Warning</h4>
/// If Location Services is not Authorised no iBeacons will be found
/// Always permission needs to be grantedto allow background monitoring
- (void)locationManager:(CLLocationManager * _Nonnull)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

/// This function monitors the state of the Bluetooth on the device. Call back from CoreBluetooth Periphery Manager.
///
/// <h4>Warning</h4>
/// Bluetooth Low Energy needs to be ON to search for iBeacons
- (void)peripheralManagerDidUpdateState:(CBPeripheralManager * _Nonnull)peripheral;
@end



/// The GCBeaconManagerDelegate protocol defines the methods used to receive iBeacon and prximity notification updates from a GCBeaconManager object.
///
/// Upon receiving a successful iBeacon or Notification update, you can use the result to update your user interface or perform other actions. You can use the stopScanningforBeacons method of GCBeaconManager to stop the iBeacon and notification services. The service will also return any errors found during scanning.
/// The methods of your delegate object are called from the thread in which you started the corresponding manager services. That thread must itself have an active run loop, like the one found in your application’s main thread.
///
/// <h2>Error codes corresponding to the GCBeaconManagerProtocol Protocol</h2>
/// If there are any issues the service will return an error with an appropriate code and description. These are summarised below:
///
/// <ul><li>1  - Error with Location manager - Error message fed back in Desc</li><li>10 - SW/HW settings or availability issue, eg, BLE switched off or Location Services OFF</li><li>20 - LocationSevices Permissions issue</li><li>30 - Monioring failed for region</li><li>40 - Ranging Failed for region</li><li>50 - Beacon JSON file import error</li><li>60 - No Beacon Regions Defined</li><li>70 - no Beacon.json file found</li></ul>
SWIFT_PROTOCOL("_TtP24GCBeaconNotificationFWv123GCBeaconManagerDelegate_")
@protocol GCBeaconManagerDelegate
@optional

/// Tells the delegate that the user entered the specified region.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param region An object containing information about the region that was entered.
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didEnterRegion:(CLBeaconRegion * _Nonnull)region;

/// Tells the delegate that the user exited the specified region.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param region An object containing information about the region that was exited.
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didExitRegion:(CLBeaconRegion * _Nonnull)region;

/// Tells the delegate that one or more beacons are in range.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param beacons An array of <a href="../Classes/GCBeacon.html">GCBeacon</a> objects representing the beacons currently in range. If beacons is empty, you can assume that no beacons matching the specified region are in range. When a specific beacon is no longer in beacons, that beacon is no longer received by the device. You can use the information in the GCBeacon objects to determine the range of each beacon and its identifying information.
///
/// \param region An object containing information about the region that was entered.
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didRangeBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons inRegion:(CLBeaconRegion * _Nonnull)region;

/// Tells the delegate that one or more proximity based notification actions were recieved.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param beacons An array of <a href="../Classes/GCBeacon.html">GCBeacon</a> objects representing the beacons currently in range and meeting the notifcation criteria (signal strength and time since last notification). You can use the information in the GCBeacon objects to determine the range of each beacon and its identifying information.
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didRangeNotificationBeacons:(NSArray<GCBeacon *> * _Nonnull)beacons;

/// Tells the delegate that one or more proximity based notification actions were recieved.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param actions An array of <a href="../Classes/GCBeaconAction.html">GCBeaconActions</a> objects representing the notification actions recieved. You can use the information in the GCBeaconAction objects to determine the action the notifcation is calling, e.g., the calling action name can be used to trigger certain events.
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didReceiveNotificationActions:(NSSet<GCBeaconAction *> * _Nonnull)actions;

/// Tells the delegate that the device changed the Bluetooth status.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param errorCode An integer representing the error type recieved
///
/// \param errorString An string description of the error
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager didChangeBluetoothStatus:(BOOL)status;

/// Tells the delegate that an error was recieved.
///
/// \param beaconManager The GCBeaconManager object reporting the event
///
/// \param errorCode An integer representing the error type recieved
///
/// \param errorString An string description of the error
- (void)beaconManager:(GCBeaconManager * _Nonnull)beaconManager errorCode:(NSInteger)errorCode with:(NSString * _Nonnull)errorMessage;
@end


@interface NSDate (SWIFT_EXTENSION(GCBeaconNotificationFWv1))
@end

#pragma clang diagnostic pop
