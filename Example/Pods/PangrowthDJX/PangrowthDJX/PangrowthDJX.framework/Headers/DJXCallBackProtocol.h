//
//  DJXCallBackProtocol.h
//  DJXSDK
//
//  Created by yuxr on 2020/8/24.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJXEvent.h"
#import "DJXAdTrackEvent.h"

NS_ASSUME_NONNULL_BEGIN

@class DJXPlayletInfoModel;

@protocol DJXPlayerCallBackProtocol,DJXRequestCallBackProtocol,DJXUserInteractionCallBackProtocol;

@protocol DJXDrawVideoViewControllerBannerDelegate <NSObject>
@optional
- (UIView *)drawVideoVCBottomBannerView:(UIViewController *)vc;
@end

@protocol DJXDrawVideoViewControllerShortplayDrawADDelegate <NSObject>

@optional

- (__kindof UIView *)shortplayDetailsVC:(UIViewController *)vc tableView:(UITableView *)tableView contentViewForRowAtIndex:(NSInteger)index;

- (void)shortplayDetailsVC:(UIViewController *)vc tableView:(UITableView *)tableView willDisplayContentView:(UIView *)contentView;

- (void)shortplayDetailsVC:(UIViewController *)vc tableView:(UITableView *)tableView didEndDisplayContentView:(UIView *)contentView;

@end

@protocol DJXDrawVideoViewControllerDelegate <DJXPlayerCallBackProtocol, DJXRequestCallBackProtocol, DJXUserInteractionCallBackProtocol>

@optional
/*! @abstract 视频切换时的回调，当前索引值 =  event.params[@"position"]，
   drawVideoCurrentVideoChanged在首次进入页面时也会触发
   若当前页为广告，则不会触发此回调 */
- (void)drawVideoCurrentVideoChanged:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 加载失败按钮点击重试回调 */
- (void)drawVideoDidClickedErrorButtonRetry:(UIViewController *)viewController;
/*! @abstract 默认关闭按钮被点击的回调 */
- (void)drawVideoCloseButtonClicked:(UIViewController *)viewController;
/*! @abstract 数据刷新完成回调 */
- (void)drawVideoDataRefreshCompletion:(NSError *)error;
/*! @abstract 数据源变更获得当前数据回调，供一起看视频场景使用  refresh 1 append 2*/ 
- (void)onDataSourceChange:(NSString *)dataSource withAction:(int)refreshOrAppendIndex;
/*! @abstract tab栏切换控制器的回调*/
- (void)pageViewControllerSwitchToIndex:(NSInteger)index;

@end

@protocol DJXDrawVideoCellAddSubviewDelegate <NSObject>

/// 创建subview直接返回，外部不用持有，cell自己持有复用
/// @param cell 小视频的cell
- (UIView *)djx_drawVideoCellSubview:(UITableViewCell *)cell;

/// 根据数据更新UI
/// @param cell Draw短剧的cell
/// @param subview `djx_drawVideoCellSubview:`返回的subview
/// @param playletInfoModel 答题的数据
- (void)djx_drawVideoCell:(UITableViewCell *)cell updateSubview:(UIView *)subview withData:(DJXPlayletInfoModel *)playletInfoModel;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell Draw短剧的cell
/// @param subview `djx_drawVideoCellSubview:`返回的subview
- (void)djx_drawVideoCell:(UITableViewCell *)cell layoutSubviews:(UIView *)subview;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell Draw短剧的cell
/// @param subview `djx_drawVideoCellSubview:`返回的subview
- (void)djx_drawVideoCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)subview;

@end

@protocol DJXPlayerCallBackProtocol <NSObject>

@optional
/*! @abstract 视频开始播放的回调 */
- (void)drawVideoStartPlay:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 视频播放结束的回调（视频结束播放（退出或者中断）） */
- (void)drawVideoOverPlay:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 视频暂停播放 */
- (void)drawVideoPause:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 视频继续播放 */
- (void)drawVideoContinue:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 视频完整播放结束一遍的回调 */
- (void)drawVideoPlayCompletion:(UIViewController *)viewController event:(DJXEvent *)event;
/*! @abstract 进度条拖动感到某个点 */
- (void)onVideSeekToTime:(NSTimeInterval)endTime inPosition:(NSInteger)position;

@end

@protocol DJXUserInteractionCallBackProtocol <NSObject>

@optional
/*! @abstract 点击作者头像 */
- (void)djxClickAuthorAvatarEvent:(DJXEvent *)event;
/*! @abstract 点击作者昵称 */
- (void)djxClickAuthorNameEvent:(DJXEvent *)event;
/*! @abstract 点击点赞按钮 */
- (void)djxClickLikeButton:(BOOL)isLike event:(DJXEvent *)event;
/*! @abstract 点击评论按钮 */
- (void)djxClickCommentButtonEvent:(DJXEvent *)event;
/*! @abstract 点击分享按钮里分享icon的回调 */
- (void)djxClickShareShareEvent:(DJXEvent *)event;
@end

@protocol DJXAdvertCallBackProtocol <NSObject>

@optional
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

@end

@protocol DJXRequestCallBackProtocol <NSObject>

@optional
- (void)djxContentRequestStart:(DJXEvent * _Nullable)event;
- (void)djxContentRequestSuccess:(NSArray<DJXEvent *> *)events;
- (void)djxContentRequestFail:(DJXEvent *)event;

@end

@protocol DJXScrollViewDelegate <NSObject>

@optional
/// 列表页scroll滑动
- (void)djxScrollViewDidScroll:(UIScrollView *)scrollView;
// called on start of dragging (may require some time and or distance to move)
- (void)djxScrollViewWillBeginDragging:(UIScrollView *)scrollView;
// called on finger up if the user dragged. velocity is in points/millisecond. targetContentOffset may be changed to adjust where the scroll view comes to rest
- (void)djxScrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset API_AVAILABLE(ios(5.0));
// called on finger up if the user dragged. decelerate is true if it will continue moving afterwards
- (void)djxScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

- (void)djxScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;   // called on finger up as we are moving
- (void)djxScrollViewDidEndDecelerating:(UIScrollView *)scrollView;      // called when scroll view grinds to a halt

- (void)djxScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView; // called when setContentOffset/scrollRectVisible:animated: finishes. not called if not animating

/// 详情页滑scroll动
- (void)djxDetailScrollViewDidScroll:(UIScrollView *)scrollView;
// called on start of dragging (may require some time and or distance to move)
- (void)djxDetailScrollViewWillBeginDragging:(UIScrollView *)scrollView;
// called on finger up if the user dragged. velocity is in points/millisecond. targetContentOffset may be changed to adjust where the scroll view comes to rest
- (void)djxDetailScrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset API_AVAILABLE(ios(5.0));
// called on finger up if the user dragged. decelerate is true if it will continue moving afterwards
- (void)djxDetailScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

- (void)djxDetailScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;   // called on finger up as we are moving
- (void)djxDetailScrollViewDidEndDecelerating:(UIScrollView *)scrollView;      // called when scroll view grinds to a halt

- (void)djxDetailScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView; // called when setContentOffset/scrollRectVisible:animated: finishes. not called if not animating
@end

@protocol DJXPageDetailUserInteractionDelegate <NSObject>
/// 信息流图文+视频详情页底部view回调
@optional
/*! @abstract 点击点赞按钮
    @param event 当前点赞的推荐内容数据
 */
- (void)djxPageDetailBottomViewDidClickPraise:(DJXEvent *)event;

/*! @abstract 点击收藏按钮
    @param event 当前收藏的推荐内容数据
 */
- (void)djxPageDetailBottomViewDidClickFavorite:(DJXEvent *)event;

- (BOOL)djxPageDetailBottomViewShouldCustomSharePanel:(DJXEvent *)event;
/// 点击share
- (void)djxPageDetailBottomViewDidClickShare:(DJXEvent *)event;

/*! @abstract 点击相关推荐
    @param event 当前相关推荐内容
 */
- (void)djxPageDetailRelatedItemDidClick:(DJXEvent *)event;

/*! @abstract 图文详情页内容阅读百分比
    @param event 离开图文详情页时触发
 */
- (void)djxDocPageDetailReadPrecent:(DJXEvent *)event;

/*! @abstract 视频详情页视频全屏切换
    @param event 点击进入全屏和退出全屏时触发
 */
- (void)djxVideoPageDetailOrientation:(DJXEvent *)event;

@end

NS_ASSUME_NONNULL_END
