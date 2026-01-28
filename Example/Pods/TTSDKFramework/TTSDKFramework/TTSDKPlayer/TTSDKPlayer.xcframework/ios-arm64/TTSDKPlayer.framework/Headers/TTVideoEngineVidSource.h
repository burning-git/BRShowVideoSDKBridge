//
//  TTVideoEngineVidSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/18.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngineVidSource : NSObject <TTVideoEngineMediaSource>

/// video id
@property (nonatomic, copy) NSString *vid;

/// play auth token
@property (nonatomic, copy) NSString *playAuthToken;

/// resolution type
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;

/// default h264
@property (nonatomic, assign) TTVideoEngineEncodeType encodeType;
/// is volc dash source, default NO
@property (nonatomic, assign) BOOL isDash;
/// is hls Source, default NO
@property (nonatomic, assign) BOOL isHLS;

@property (nonatomic, assign) TTVideoEngineCodecStrategy codecStrategy;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


/// Designated initializer.
/// @param vid video id.
/// @param playAuthToken play auth token
/// @param resolution video resolution
- (instancetype)initWithVid:(NSString *)vid
              playAuthToken:(NSString *)playAuthToken
                 resolution:(TTVideoEngineResolutionType)resolution;

/// Designated initializer.
/// @param vid video id.
/// @param playAuthToken play auth token
/// @param resolution video resolution
/// @param encodeType The encode type of current asset, make sure it is correct.
/// @param isDash is volc dash format video
/// @param isHLS is hls format video
- (instancetype)initWithVid:(NSString *)vid
              playAuthToken:(NSString *)playAuthToken
                 resolution:(TTVideoEngineResolutionType)resolution
                 encodeType:(TTVideoEngineEncodeType)encodeType
                     isDash:(BOOL)isDash
                      isHLS:(BOOL)isHLS;

@end

NS_ASSUME_NONNULL_END
