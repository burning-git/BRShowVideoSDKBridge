//
//  DJXPlayletAggregatePageViewController.h
//  PangrowthMedia
//
//  Created by haiyang on 2023/1/16.
//

#import <UIKit/UIKit.h>
#import "DJXPlayletProtocol.h"
#import "DJXPublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

/// 聚合页初始化参数
@interface DJXPlayletAggregatePageVCConfig : NSObject

/// 短剧详情页config
@property (nonatomic, strong) DJXPlayletConfig *playletConfig;
/// 是否展示导航栏左上角返回按钮，默认关闭
@property (nonatomic, assign) BOOL isShowNavigationItemBackButton;
/// 是否展示导航栏标题名称，默认关闭
@property (nonatomic, assign) BOOL isShowNavigationItemTitle;
/// 页面上方偏移量
@property (nonatomic, assign) CGFloat marginTop;
/// 支持传入多个置顶热门短剧ID
@property (nonatomic, copy) NSArray<NSString *> *topSkitIds;

@property (nonatomic, copy) NSString *from_page;

@end

@interface DJXPlayletAggregatePageViewController : UIViewController

- (instancetype)initWithConfigBuilder:(void (^)(DJXPlayletAggregatePageVCConfig * _Nonnull config))configBuilder;

@end

NS_ASSUME_NONNULL_END
