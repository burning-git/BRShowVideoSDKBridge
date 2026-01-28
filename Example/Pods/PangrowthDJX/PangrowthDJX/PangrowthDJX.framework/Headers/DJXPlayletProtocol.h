//
//  DJXPlayletProtocol.h
//  PangrowthMedia
//
//  Created by ByteDance on 2023/1/18.
//

#import <Foundation/Foundation.h>
#import "DJXPlayletInfoModel.h"
#import "DJXAdTrackEvent.h"
#import "DJXPlayletConfig.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DJXPlayletInterfaceProtocol <NSObject>
@required
/// 解锁流程开始，开发者可以做一些弹框交互，比如让用户选择是否看广告等
/// - Parameters:
///   - infoModel: 短剧详情信息
///   - unlockInfoHandler: 解锁信息回传
///   - extraInfo: 附加信息
- (void)playletDetailUnlockFlowStart:(DJXPlayletInfoModel *)infoModel
                   unlockInfoHandler:(void (^)(DJXPlayletUnlockModel *unlockInfo))unlockInfoHandler
                           extraInfo:(NSDictionary * _Nullable)extraInfo;

/// 显示自定义广告流程
/// - Parameters:
///   - infoModel: 短剧详情信息
///   - onADWillShow: 开始显示广告，调用通知SDK
///   - onADRewardDidVerified: 激励完成，调用通知SDK
- (void)playletDetailUnlockFlowShowCustomAD:(DJXPlayletInfoModel *)infoModel
                               onADWillShow:(void (^)(NSString * cpm))onADWillShow
                      onADRewardDidVerified:(void (^)(DJXRewardAdResult *rewardResult))onADRewardDidVerified;

/// 解锁流程结束，回调解锁结果
/// - Parameters:
///   - infoModel: 短剧详情信息
///   - success: 是否解锁成功
///   - error: 解锁失败错误信息
///   - extraInfo: 附加信息
- (void)playletDetailUnlockFlowEnd:(DJXPlayletInfoModel *)infoModel
                           success:(BOOL)success
                             error:(NSError * _Nullable)error
                         extraInfo:(NSDictionary * _Nullable)extraInfo;

@optional
/// 点击混排中进入跳转播放页的按钮
- (void)clickEnterView:(DJXPlayletInfoModel *)infoModel;
/// 本剧集观看完毕，切到下一部短剧回调
- (void)nextPlayletWillPlay:(DJXPlayletInfoModel *)infoModel;

- (UIView *)playletDetailBottomBanner;

@end

@protocol DJXPlayletPlayerProtocol <NSObject>

//@optional
/*! @abstract 视频开始播放的回调 */
- (void)drawVideoStartPlay:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
/*! @abstract 视频播放结束的回调（视频结束播放（退出或者中断）） */
- (void)drawVideoOverPlay:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
/*! @abstract 视频暂停播放 */
- (void)drawVideoPause:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
/*! @abstract 视频继续播放 */
- (void)drawVideoContinue:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
/*! @abstract 视频完整播放结束一遍的回调 */
- (void)drawVideoPlayCompletion:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
/*! @abstract 进度条拖动感到某个点 */
- (void)onVideSeekToTime:(NSTimeInterval)endTime inPosition:(NSInteger)position;
/*! @abstract 播放进度 */
- (void)drawVideo:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config progress:(CGFloat)progress;
/// 播放器内部错误
- (void)drawVideoError:(UIViewController *)viewController config:(DJXPlayletInfoModel *)config;
@end


/// 短剧自定义View协议
@protocol DJXPlayletDetailCellDelegate <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)djx_playletDetailCellCustomView:(UITableViewCell *)cell;

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)djx_playletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(DJXPlayletInfoModel *)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)djx_playletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)djx_playletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end

@protocol DJXShortplayDetailDrawAdDelegate <NSObject>

@required

- (UIView *)djx_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)djx_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)djx_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)djx_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)djx_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@end


@protocol DJXPlayletAdvertProtocol <NSObject>

//@optional
/*! @abstract 发起广告请求 */
- (void)djxSendAdRequest:(DJXAdTrackEvent *)event;
/*! @abstract 加载成功 */
- (void)djxAdLoadSuccess:(DJXAdTrackEvent *)event;
/*! @abstract 加载失败 */
- (void)djxAdLoadFail:(DJXAdTrackEvent *)event error:(NSError *)error;
/*! @abstract 填充失败 */
- (void)djxAdFillFail:(DJXAdTrackEvent *)event;
/*! @abstract 广告曝光 */
- (void)djxAdWillShow:(DJXAdTrackEvent *)event;
/*! @abstract 视频广告开始播放 */
- (void)djxVideoAdStartPlay:(DJXAdTrackEvent *)event;
/*! @abstract 视频广告暂停播放 */
- (void)djxVideoAdPause:(DJXAdTrackEvent *)event;
/*! @abstract 视频广告继续播放 */
- (void)djxVideoAdContinue:(DJXAdTrackEvent *)event;
/*! @abstract 视频广告停止播放 */
- (void)djxVideoAdOverPlay:(DJXAdTrackEvent *)event;
/*! @abstract 点击广告 */
- (void)djxClickAdViewEvent:(DJXAdTrackEvent *)event;
/*! @abstract 广告缓冲 */
- (void)djxVideoBufferEvent:(DJXAdTrackEvent *)event;
/*! @abstract 激励视频广告结束，event中包含激励结果 */
- (void)djxVideoRewardFinishEvent:(DJXAdTrackEvent *)event;
/*! @abstract 激励视频广告跳过 */
- (void)djxVideoRewardSkipEvent:(DJXAdTrackEvent *)event;

@end

NS_ASSUME_NONNULL_END
