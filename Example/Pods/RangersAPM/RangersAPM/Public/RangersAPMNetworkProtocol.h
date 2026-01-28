//
//  RangersAPMNetworkProtocol.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2023/2/21.
//

#import <Foundation/Foundation.h>

@class RangersAPMRequestModel;

NS_ASSUME_NONNULL_BEGIN

/**
 Network request callback.
 */
typedef void (^RangersAPMDataTaskCompletionHandler)(NSData *_Nullable data, NSURLResponse *_Nullable response, NSError *_Nullable error);

@protocol RangersAPMNetworkProtocol <NSObject>

@required
/**
 Build an HTTP request with model, and call the handler when the request is completed.
 
 @param model If the model.HTTPMethod is "POST", set the HTTP body data by model.HTTPBody.
 @param handler The same callback as NSURLSession.
 */
- (void)dataRequestWithModel:(RangersAPMRequestModel *)model completionHandler:(RangersAPMDataTaskCompletionHandler _Nullable)handler;

/**
 Build an HTTP request for uploading task with model, and call the handler when the request is completed.
 
 @param model Set the HTTP upload data by model.HTTPBody.
 @param handler The same callback as NSURLSession.
 */
- (void)uploadRequestWithModel:(RangersAPMRequestModel *)model completionHandler:(RangersAPMDataTaskCompletionHandler _Nullable)handler;

@end

NS_ASSUME_NONNULL_END
