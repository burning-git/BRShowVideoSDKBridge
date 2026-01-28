//
//  DJXDrawVideoViewController.h
//  DJXSDK
//
//  Created by cuiyanan on 2020/3/15.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DJXPublicDefine.h"
#import "DJXCallBackProtocol.h"
#import "DJXPlayletConfig.h"

@class DJXDrawVideoViewController;
@class DJXEvent;

NS_ASSUME_NONNULL_BEGIN

@protocol DJXReportContentViewController <NSObject>

@property (nonatomic, copy) void(^reportContentCompletionHandler)(BOOL isSuccess, DJXEvent *event);

@end

typedef NS_ENUM(NSUInteger, DJXDrawVideoWatcherRole) {
    DJXDrawVideoWatcherRole_Default,      //正常Draw流
    DJXDrawVideoWatcherRole_Host,      //正常Draw流 控制端模式
    DJXDrawVideoWatcherRole_User,  //正常Draw流 被控制端模式
};

typedef NS_ENUM(NSUInteger, DJXDrawQuizOptions) {
    DJXDrawSmallVideo = 0,              //传统小视频
    DJXDrawQuizVideo = 1                //猜歌名答题
};

typedef NS_ENUM(NSUInteger, DJXSurveyUserGender) {
    DJXSurveyUserGender_Unknown = 0,            ///< 未知
    DJXSurveyUserGender_Male = 1,               ///< 男性
    DJXSurveyUserGender_Female = 2             ///< 女性
};

typedef NS_ENUM(NSUInteger, DJXSurveyUserAge) {
    DJXSurveyUserAge_Unknown = 0,  ///< 未知
    DJXSurveyUserAge_1960s = 1,    ///< 60年代
    DJXSurveyUserAge_1970s = 2,    ///< 70年代
    DJXSurveyUserAge_1980s = 3,    ///< 80年代
    DJXSurveyUserAge_1990s = 4,    ///< 90年代
    DJXSurveyUserAge_2000s = 5,    ///< 21世纪-00年代
    DJXSurveyUserAge_2010s = 6,    ///< 21世纪-10年代
    DJXSurveyUserAge_2020s = 7     ///< 21世纪-20年代
};

@interface DJXDrawVideoNavigationBarInset : NSObject
/// 默认为is_iphoneX?44:20，navigationBar距顶部距离
@property (nonatomic) CGFloat top;
/// 默认为16，若showCloseButton为YES，则为左侧按钮距关闭按钮右侧距离；若为NO，则为距VC.view左侧的距离
@property (nonatomic) CGFloat buttonLeft;
/// 默认为16，右侧按钮距VC.view右侧的距离
@property (nonatomic) CGFloat buttonRight;
@end

@interface DJXDrawVideoVCConfig : NSObject

/*! @abstract 顶部导航栏的inset*/
@property (nonatomic, strong) DJXDrawVideoNavigationBarInset *navBarInset;
/*! @abstract 接收回调的代理 */
@property (nonatomic, weak) id<DJXDrawVideoViewControllerDelegate> delegate;
/*! @abstract 接收广告回调的代理 */
@property (nonatomic, weak) id<DJXAdvertCallBackProtocol> adDelegate;
/// 自定义Draw流的subview
@property (nonatomic, weak) id<DJXDrawVideoCellAddSubviewDelegate> drawVideoCellAddSubviewDelegate;
/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id<DJXDrawVideoViewControllerBannerDelegate> bannerDelegate;
/*! @abstract 是否需要展示左上角的关闭按钮。 默认不展示 */
@property (nonatomic, assign) BOOL showCloseButton;
/*! @abstract 是否需要隐藏首次安装出现的引导手势图。 默认展示 */
@property (nonatomic, assign) BOOL hiddenGuideGeste;
/*! @abstract 展示VC的大小。 默认屏幕大小 */
@property (nonatomic, assign) CGSize viewSize;
/*! @abstract 外流进度条距离最低部的距离 */
@property (nonatomic, assign) CGFloat out_bottomOffset;
/*! @abstract 短剧内流进度条距离最低部的距离 */
@property (nonatomic, assign) CGFloat inner_playPlet_bottomOffset;
/*! @abstract 进度条的样式。 默认浅色系 */
@property (nonatomic, assign) DJXDrawVideoProgressBarStyle progressBarStyle;
/*! @abstract 支持的返回内容的类型，默认小视频 */
@property (nonatomic, copy) NSArray<DJXDrawFeatureString> *featureValuesArr;
/*! 直播预览流模版渲染广告位id，继承直播+小视频SDK时候创建沉浸式小视频的时候此参数必填  */
@property (nonatomic, copy) NSString *livePreViewFeedAdExpressId;
 /*! 直播预览流子渲染广告位id ，继承直播+小视频SDK时候创建沉浸式小视频的时候此参数必填*/
@property (nonatomic, copy) NSString *livePreViewFeedAdNativeId;
/*! @abstract 将分享获取到的group_id设置给小视频组件/初始化新的小视频组件时使用
 跟DJXUserInteractionCallBackProtocol.djxClickShareShareEvent 分享回调配合使用
 */
@property (nonatomic, assign) long long initShareAwakeDataGroupID;

@property (nonatomic, assign) long long initPushAwakeDataGroupID;
/// 以下方法仅限以添加view的形式使用DJXDrawVideoViewController的开发者使用，直接使用Controller的开发者可忽略
/// 例如：DJXDrawVideoViewController *vc = [[DJXDrawVideoViewController alloc] initWithConfigBuilder:^(DJXDrawVideoVCConfig * _Nonnull config) {
/// 使用示例：
///           config.customAppear = YES;
///      }];
///      [parentView addSubView: _vc.view]
///      [self addChildViewController:_vc];
/// 使用示例：
///      //在合适的时机主动调用展示和消失方法
///      [_vc drawVideoViewControllerDidAppear];
///      [_vc drawVideoViewControllerDidDisappear];
/*! @abstract 开发者是否主动调用view即将展示和隐藏，默认NO
              想要下面的展示和消失方法生效，此属性必须设置为YES
 */
@property (nonatomic, assign) BOOL customAppear;
/*! 配置scrollView，可以通过configScrollViewsBlock添加下拉刷新viekw */
@property (nonatomic, copy) void(^configScrollViewsBlock)(DJXDrawVideoViewController *vc, UIScrollView *dataView, NSUInteger atIndex);
/*! 个性化推荐关闭以后，推荐频道名称，默认为“首页” */
@property (nonatomic, copy) NSString *recommandTabName;
/*! 自定义刷新行为和手势 */
@property (nonatomic, assign) BOOL customRefresh;
/*! 需要展示的tab，默认全部展示*/
@property (nonatomic, assign) DJXDrawVideoVCTabOptions drawVCTabOptions;

/*! 是否屏蔽关注功能，当drawVCTabOptions为DJXDrawVideoVCTabOptions_recommand时有效
 默认为NO，若disableFollowingFunc为YES，则不展示关注相关功能(“我的”个人主页、关注按钮、关注指引等)
 */
@property (nonatomic, assign) BOOL shouldDisableFollowingFunc;

/// 是否隐藏频道tab，仅有一个tab时这个开关才生效
@property (nonatomic, assign) BOOL shouldHideTabBarView;

/*! 一起看视频当前页面的模式 */
@property (nonatomic, assign) DJXDrawVideoWatcherRole currentMode;
@property (nonatomic, assign) long long watchVideoTogetherGroupID;

/** --------------------for 内容定制-------------------- */
/*! @abstract optional，标记接入场景，例如首页、顶tab等。必须与后台申请的scene保持一致，否则会出问题。 */
@property (nonatomic, copy) NSString *scene;

/** --------------------for 短剧-------------------- */
/// 短剧参数
@property (nonatomic, strong) DJXPlayletConfig *playletConfig;
/// 隐藏底部跳转区域
@property (nonatomic, assign) BOOL hiddenPlayletEnterView;
/// 隐藏点赞
@property (nonatomic) BOOL hideLikeIcon;
/// 隐藏收藏
@property (nonatomic) BOOL hideCollectIcon;
/// 短剧混排流中的免费短剧集数，默认为1集混排
@property (nonatomic, assign) NSInteger playletFreeCount;
/// 短剧混排流中要第一部展现的短剧id
@property (nonatomic, assign) NSInteger topSkitId;
/// 禁用双击点赞
@property (nonatomic) BOOL disableDoubleClickLike;
/// 禁用长按倍速
@property (nonatomic) BOOL disableLongPressSpeed;

/// 埋点，入口页面；区分从哪个页面进入
@property (nonatomic, copy) NSString *from_page;

@end

@interface DJXDrawVideoViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*! @abstract 将api获取到的awake_data字段数据设置给小视频组件/在已经存在的小视频组件上添加
 跟+[DJXFeedNativeLoadManager getApiParams]配合使用
 */
@property (nonatomic, copy) NSString *awakeData;

/*! @abstract 将分享获取到的group_id设置给小视频组件/在已经存在的小视频组件上添加
 跟DJXUserInteractionCallBackProtocol.djxClickShareShareEvent 分享回调配合使用
 */
@property (nonatomic, assign) long long shareAwakeDataGroupID;

- (instancetype)initWithConfigBuilder:(void(^)(DJXDrawVideoVCConfig *config))configBuilder;

/*! @abstract 刷新数据及数据刷新完成回调 */
- (void)refreshDataWithCompletion:(void (^ _Nullable)(NSError * _Nullable))completion;
/*! @abstract 用来做挽留的刷新数据及数据刷新完成回调 */
- (void)refreshDataToStayUserWithCompletion:(void (^ _Nullable)(NSError * _Nullable))completion;

/*! @abstract 文案提示“再按一次返回键退出” */
- (void)showToastToStayUser;

/*! @abstract 创建内容举报页，该方法只负责创建ViewController，展示逻辑 需要开发者自行处理
              若当前展示广告，则返回值为nil
 */
- (UIViewController<DJXReportContentViewController> * _Nullable)createReportContentViewController;

/*! @abstract 视图已经展示 */
- (void)drawVideoViewControllerDidAppear;
/*! @abstract 视图已经消失 */
- (void)drawVideoViewControllerDidDisappear;

/*! @abstract 控制播放进度  单位 毫秒*/
- (void)seekVideoToMSeconds:(float)mSeconds;
/*! @abstract 被控端用来同步数据*/
- (void)syncDataToPlay:(NSString *)syncData refreshType:(int)type withCompletion:(void (^)(bool isSuccess, NSString *msg))completion;

/*! @abstract 上传用户的年龄和性别信息 */
- (void)setUserInformationsWithAge:(DJXSurveyUserAge)age Gender:(DJXSurveyUserGender)gender;

/*! @abstract 短剧切换集数 */
- (void)setCurrentPlayletEpisode:(NSInteger)episode;
/*! @abstract 短剧右上角更多按钮点击*/
- (void)playletMoreButtonClick;

// 获取当前播放的倍速档位（各个范围计算后的档位）
- (CGFloat)playSpeed;
// 设置当前播放的倍速档位（取值0<speed<=3），并指定倍速范围
- (void)setPlaySpeed:(CGFloat)speed scope:(DJXDrawVideoSpeedScope)scope;
@end

NS_ASSUME_NONNULL_END
