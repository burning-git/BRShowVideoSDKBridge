//
//  DJXPlayletConfig.h
//  PangrowthMedia
//
//  Created by ByteDance on 2023/1/18.
//

#import <Foundation/Foundation.h>
#import "DJXPublicDefine.h"
#import "DJXPlayletInfoModel.h"
@protocol DJXPlayletInterfaceProtocol,DJXPlayletPlayerProtocol,DJXPlayletAdvertProtocol,DJXPlayletDetailCellDelegate, DJXShortplayDetailDrawAdDelegate;

NS_ASSUME_NONNULL_BEGIN

//短剧详情页config
@interface DJXPlayletConfig : NSObject

// *必要参数*
//接入模式
@property (nonatomic, assign) DJXPlayletUnlockADModeOptions playletUnlockADMode;

// *详情页必要参数*
//短剧id
@property (nonatomic, assign) NSInteger skitId;
//短剧index
@property (nonatomic, assign) NSInteger episode;

// *公共可选参数*
/// 短剧来源上边距
@property (nonatomic, assign) CGFloat fromTopMargin;
/// 隐藏左上角返回按钮
@property (nonatomic, assign) BOOL hideBackButton;
/// 隐藏左上角集数
@property (nonatomic) BOOL hideTopInfo;
/// 是否隐藏更多按钮
@property (nonatomic, assign) BOOL hideMoreButton;
/// 隐藏备案号
@property (nonatomic) BOOL hideICPNumber;
/// 隐藏底部信息
@property (nonatomic) BOOL hideBottomInfo;
/// 隐藏SDK的激励弹框
@property (nonatomic) BOOL hideRewardDialog;
/// 隐藏蜂窝数据弹框
@property (nonatomic) BOOL hideCellularToast;
/// 隐藏点赞
@property (nonatomic) BOOL hideLikeIcon;
/// 隐藏收藏
@property (nonatomic) BOOL hideCollectIcon;
/// 禁用双击点赞
@property (nonatomic) BOOL disableDoubleClickLike;
/// 禁用长按倍速
@property (nonatomic) BOOL disableLongPressSpeed;

//关闭无限下滑功能，默认开启，一部剧播完会播下一部剧
@property (nonatomic, assign) BOOL closeInfiniteScroll;
//起播时间点
@property (nonatomic, assign) CGFloat playStartTime;

// *封装模式可选参数*
//免费观看的集数n
@property (nonatomic, assign) NSInteger freeEpisodesCount;
//观看一次激励视频解锁的集数m
@property (nonatomic, assign) NSInteger unlockEpisodesCountUsingAD;

@property (nonatomic, copy) void (^closeVCBlock)(UIViewController *playletDetailVC);

// *设置delegate*
// 播放器回调
@property (nonatomic, weak) id<DJXPlayletPlayerProtocol> playerDelegate;
// 广告回调
@property (nonatomic, weak) id<DJXPlayletAdvertProtocol> adDelegate;
// 业务接口回调
@property (nonatomic, weak) id<DJXPlayletInterfaceProtocol> interfaceDelegate;
// 自定义详情页cell试图
@property (nonatomic, weak) id<DJXPlayletDetailCellDelegate> customViewDelegate;
/// 自定义详情页Draw广告
@property (nonatomic, weak) id<DJXShortplayDetailDrawAdDelegate> customDrawAdViewDelegate;
/// 短剧播放详情页，表示在第几集后面插入自定义Draw广告
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *customAdIndex;

// *埋点参数*
// 入口类型 自定义页面和组件务必传入，否则严重影响推荐效果
@property (nonatomic, assign) DJXPlayletEntranceType entranceType;
// 回调返回的短剧数据
@property (nonatomic, strong) DJXPlayletInfoModel *infoModel;
// 剧集id
@property (nonatomic, assign) NSInteger groupId;


@end

NS_ASSUME_NONNULL_END
