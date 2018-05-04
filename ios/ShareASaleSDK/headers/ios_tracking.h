//
//  ios_tracking.h
//  ios.tracking
//
//  Created by Michael on 8/15/13.
//  Copyright (c) 2013 ShareASale.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SASIos_tracking : NSObject <UIWebViewDelegate>

@property (readonly) NSString* shareasaleMerchantID;
@property (readonly) NSString* shareasaleAppID;
@property (readonly) NSString* shareasaleAppKey;
@property (nonatomic, strong)UIWebView* conversionView;


- (id)initWithMerchantID:(NSString *)inMID withAppID:(NSString *) inAppID withAppKey:(NSString *) inAppKey;

- (void) trackInstallWithView:(UIView*)mainView;

- (void)webViewDidFinishLoad:(UIWebView *)webView;

- (void)webViewDidStartLoad:(UIWebView *)webView;

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

- (void) resetTrackedFlag;

- (void) trackTransactionWithView:(UIView*)mainView withOrderNumber:(NSString *) inOrderNumber withTranstype:(NSString *) inTransType withAmount:(double) inAmount withAdditionalParams:(NSDictionary *) inParams;

- (void) markAsTracked;

- (void) setFeatureFlagsWithInt:(int)features;

@end
