//
//  DJXAdTrackEvent.h
//  DJXSDK
//
//  Created by yuxr on 2020/8/26.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, DJXAdEventType) {
    DJXAdEventTypeRequest, ///< 发起广告请求
    DJXAdEventTypeLoadSuccess, ///< 加载成功
    DJXAdEventTypeLoadFail, ///< 加载失败
    DJXAdEventTypeFillFail, ///< 填充失败
    DJXAdEventTypeAdWillShow, ///< 广告曝光
    DJXAdEventTypeVideoAdStartPlay, ///< 视频广告开始播放
    DJXAdEventTypeVideoAdPause, ///< 视频广告暂停播放
    DJXAdEventTypeVideoAdContinue, ///< 视频广告继续播放
    DJXAdEventTypeVideoAdOverPlay, ///< 视频广告停止播放
    DJXAdEventTypeClickAd, ///< 点击广告
    DJXAdEventTypeBuffering, ///< 广告缓冲
    DJXAdEventTypeRewardFinish, ///< 激励视频完成
    DJXAdEventTypeRewardSkip, ///< 激励视频跳过
};

FOUNDATION_EXPORT NSString *_Nonnull const DJXAdEventAdCountKey;
FOUNDATION_EXPORT NSString *_Nonnull const DJXAdEventErrorCodeKey;
FOUNDATION_EXPORT NSString *_Nonnull const DJXAdEventErrorMsgKey;
FOUNDATION_EXPORT NSString *_Nonnull const DJXAdEventVerifyKey;

/** 视频广告总时长 */
FOUNDATION_EXPORT NSString *_Nonnull const kDJXAdEventVideoAdDurationKey;
/** 视频广告当前播放时长 */
FOUNDATION_EXPORT NSString *_Nonnull const kDJXAdEventVideoAdCurrentPlayedTimeKey;

@interface DJXAdTrackEvent : NSObject

@property (nonatomic) DJXAdEventType eventType;
@property (nonatomic) NSString *adSlotID;
@property (nonatomic) NSString *adID;
@property (nonatomic) NSDictionary<NSString *, id> *params;

+ (instancetype)eventWithBuilder:(void(^)(DJXAdTrackEvent *event))builder;
- (NSString *)toJSONString;

@end

NS_ASSUME_NONNULL_END
