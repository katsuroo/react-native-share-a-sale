#import "RNShareasale.h"

@implementation RNShareasale

RCT_EXPORT_MODULE();

UIView *view = nil;
Boolean isInitialized = false;
SASIos_tracking *shrsl;

- (void) init:(NSString*)appKey
        appId:(NSString*)appId
   merchantId:(NSString*)merchantId
     rootView:(UIView*)rootView {

  // Setup ShareASale
  NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
  NSString *isTracked = [prefs stringForKey:@"com.shareasale.ios.isTracked"];

  if (!shrsl) {
    shrsl = [[SASIos_tracking alloc] initWithMerchantID:merchantId withAppID: appId withAppKey: appKey];
  }

  if (!isTracked) {
    [shrsl trackInstallWithView:rootView];
  }

  view = rootView;
  isInitialized = YES;
}

RCT_EXPORT_METHOD(trackPurchase:(NSString *) inOrderNumber
                  withTranstype:(NSString *) inTransType
                  withAmount:(double) inAmount
                  withAdditionalParams:(NSDictionary *) inParams) {
  if (shrsl && view && isInitialized) {
    NSDictionary *additional = [[NSDictionary alloc] init];
    [shrsl trackTransactionWithView:view
                    withOrderNumber:inOrderNumber
                      withTranstype:inTransType ? inTransType : @"INAPP"
                         withAmount:inAmount
               withAdditionalParams:additional];
  }
}

@end
