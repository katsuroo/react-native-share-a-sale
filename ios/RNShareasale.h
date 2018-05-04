#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import "ios_tracking.h"

@interface RNShareasale : NSObject <RCTBridgeModule>;

- (void) init:(NSString*)appKey
        appId:(NSString*)appId
   merchantId:(NSString*)merchantId
     rootView:(UIView*)rootView;

@end
