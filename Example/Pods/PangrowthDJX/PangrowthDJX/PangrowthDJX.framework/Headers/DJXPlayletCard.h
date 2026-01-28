//
//  DJXPlayletCard.h
//  PangrowthMedia
//
//  Created by admin on 2023/5/30.
//

#import <UIKit/UIKit.h>
#import "DJXPublicDefine.h"
#import "DJXPlayletInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DJXPlayletCardPlaybackState) {
    DJXPlayletCardPlaybackStateStopped,
    DJXPlayletCardPlaybackStatePlaying,
    DJXPlayletCardPlaybackStatePaused,
    DJXPlayletCardPlaybackStateError,
};

@class DJXPlayletCard;

@protocol DJXPlayletCardDelegate <NSObject>
@optional
/// 短剧卡片加载数据，成功playletData有值，失败error有值
/// - Parameters:
///   - playletCard: 短剧卡片
///   - playletData: 短剧卡片数据
///   - error: 失败原因
- (void)playletCard:(DJXPlayletCard *)playletCard didLoadData:(DJXPlayletInfoModel *)playletData error:(nullable NSError *)error;

/// 播放器回调
/// 第一帧回调
- (void)playletCardReadyToDisplay:(DJXPlayletCard *)playletCard;
/// 即将开始播放
- (void)playletCardReadyToPlay:(DJXPlayletCard *)playletCard;
/// 播放状态切换
- (void)playletCard:(DJXPlayletCard *)playletCard playbackStateDidChanged:(DJXPlayletCardPlaybackState)playbackState;
/// 手动stop
- (void)playletCardUserStopped:(DJXPlayletCard *)playletCard;
/// finish，正常结束，异常结束error或者statusCode会有值
- (void)playletCardDidFinish:(DJXPlayletCard *)playletCard error:(nullable NSError *)error videoStatusException:(NSInteger)statusCode;

@end

@interface DJXPlayletCardConfig : NSObject
/// 短剧卡片的frame，内部会保持`高:宽`为`16:9`
@property (nonatomic) CGRect frame;
/// 短剧id
@property (nonatomic) NSInteger skit_id;
/// 是否自动播放，默认YES
@property (nonatomic) BOOL autoPlay;
/// 是否循环播放，默认YES
@property (nonatomic) BOOL loop;
/// 是否静音，默认YES
@property (nonatomic) BOOL mute;
/// 隐藏所有上层交互UI，媒体可以自己添加任意UI，默认NO
@property (nonatomic) BOOL hideActionUI;
/// 默认 NO
@property (nonatomic) BOOL hidePlayButton;
/// 默认 NO
@property (nonatomic) BOOL hideMuteButton;

@end

/// 短剧卡片
@interface DJXPlayletCard : UIView
/// 暴露给开发者的短剧信息
@property (nonatomic, readonly) DJXPlayletInfoModel *playletInfo;

@property (nonatomic, weak) id<DJXPlayletCardDelegate> delegate;

@property (nonatomic) BOOL muted;

@property (nonatomic, readonly) DJXPlayletCardPlaybackState playbackState;

@property (nonatomic, copy) NSString *from_page;

/// 初始化一张短剧卡片，传入必要设置
- (instancetype)initWithConfig:(void (^)(DJXPlayletCardConfig *cardConfig))configBuilder;

- (void)play;
- (void)pause;
- (void)stop;

/// 数据拉取失败，重新加载
- (void)retryLoadData;

/// 曝光埋点
- (void)trackShowWithDuration:(CGFloat)duration;

@end

NS_ASSUME_NONNULL_END
