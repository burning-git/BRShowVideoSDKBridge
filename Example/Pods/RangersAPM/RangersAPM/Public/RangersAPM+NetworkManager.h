//
//  RangersAPM+NetworkManager.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2023/2/21.
//

#import "RangersAPM.h"
#import "RangersAPMNetworkProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPMRequestModel : NSObject

/**
 @abstract The NSString of HTTP request URL.
 */
@property (atomic, copy) NSString *URLString;

/**
 @abstract HTTP request method.
 */
@property (atomic, copy) NSString *HTTPMethod;

/**
 @abstract HTTP header fields.
 */
@property (atomic, strong, nullable) NSDictionary<NSString *, NSString *> *HTTPHeaderField;

/**
 @abstract Request data.
  */
@property (atomic, strong, nullable) NSData *HTTPBody;

/**
 @abstract Request timeout interval.
 */
@property (atomic, assign) NSTimeInterval timeoutInternal;

@end

@interface RangersAPM (NetworkManager)

/**
 Set your custom network manager.
 
 @param manager An instance of your custom network manager which conforms the RangersAPMNetworkProtocol.
 */
+ (void)setCustomNetworkManager:(id<RangersAPMNetworkProtocol>)manager;

@end

NS_ASSUME_NONNULL_END
