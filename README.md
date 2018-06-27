
# react-native-shareasale

React native bridge library for the share a sale SDK.

##### status: alpha

##### done:
- iOS implementation for track purchases

##### todos:
- implement the rest of iOS methods
- android implementation

## Getting started

`$ npm install react-native-shareasale --save`

### Installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-shareasale` and add `RNShareasale.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNShareasale.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<
5. Add the following lines into your AppDelegate.m
```
// import the library at the top of the file

#import <RNShareasale/RNShareasale.h>


// Insert inside the didFinishLaunchingWithOptions method
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
      // The rootView should already be defined in your app delegate file. It is needed to initialize the share a sale library.
      RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:jsCodeLocation
                                                          moduleName:@"moduleName"
                                                   initialProperties:nil
                                                       launchOptions:launchOptions];

      NSString *shareASaleMerchantId = INSERT SHARE A SALE MERCHANT ID;
      NSString *shareASaleAppId = INSERT SHARE A SALE APP ID;
      NSString *shareASaleAppKey = INSERT SHARE A SALE APP KEY;

      [[RNShareasale alloc] init:shareASaleAppKey
                           appId:shareASaleAppId
                      merchantId:shareASaleMerchantId
                        rootView:rootView];
}
```

#### Android

1. Open up `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.reactlibrary.RNShareasalePackage;` to the imports at the top of the file
  - Add the following code
  ```
  public class MainApllication extends Application implements ReactApplication {
    com.shareasale.android.tracking.trackingUtilitiy shareASaleTracking;
    ...
    @Override
    public void onCreate() {
      super.onCreate();
      shareasaleTracking = new com.shareasale.android.tracking.trackingUtility(
        MERCHANT_ID,
        APP_ID,
        APP_KEY,
        HAS_PHONE_PERMISSION,
        HAS_WIFI_PERMISSION
        );
    }
  }
  ```
  - Add `new RNShareasalePackage(shareASaleTracking)` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-shareasale'
  	project(':react-native-shareasale').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-shareasale/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-shareasale')
  	```
4. Add Path to ShareASale SDK in `android/build.gradle`
    ```
       allprojects {
         repositories {
           ...
           flatDir {
             dir "$rootDir/../node_modules/react-native-shareasale/android/lib"
           }
         }
       }
    ```
## Usage
```javascript
import RNShareasale from 'react-native-shareasale';

const orderNumber = 1234;
const transactionType = 'Sales';
const total = 12

RNShareasale.trackPurchase(
  orderNumber,
  transactionType,
  total
);

// TODO: What to do with the module?
RNShareasale;
```
