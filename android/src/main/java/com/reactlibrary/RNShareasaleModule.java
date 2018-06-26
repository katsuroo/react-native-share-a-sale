
package com.reactlibrary;

import java.util.*;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

public class RNShareasaleModule extends ReactContextBaseJavaModule {
  private com.shareasale.android.tracking.trackingUtility shareASaleTracking;

  public RNShareasaleModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.shareASaleTracking = shareASaleInstance;
    shareASaleTracking.trackInstall(getReactApplicationContext());

  }

  @Override
  public String getName() {
    return "RNShareasale";
  }

  @ReactMethod
  public void trackPurchase(String orderNumber,
                            String transactionType,
                            Double amountInCents) {
      Map<String, String> additionalParameters = new HashMap<String, String>();
      Double amountInDollars = amountInCents / 100.0;
      shareASaleTracking.trackSale(getReactApplicationContext(), orderNumber, transactionType, amountInDollars, additionalParameters);
  }

}