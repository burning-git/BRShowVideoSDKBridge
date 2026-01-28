//
//  DJXPublicDefine.h
//  DJXSDK
//
//  Created by iCuiCui on 2020/5/27.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 过期提醒
#define DJX_DEPRECATED_MSG_ATTRIBUTE(DESCRIPTION) __attribute__((deprecated(DESCRIPTION)))

typedef NSNumber * DJXGroupID;

typedef NSString * DJXDrawFeatureString;
typedef NSNumber *  DJX_BU_SlotIDType;

typedef NS_ENUM(NSInteger,DJX_BU_SlotID) {
    DJX_BU_SlotID_feed            =   1,  //【信息流】
    DJX_BU_SlotID_DocPage_1       =   2,  //【信息流】文章标题下的广告
    DJX_BU_SlotID_DocPage_2       =   3,  //【信息流】文章评论页上方的广告
    DJX_BU_SlotID_VideoPage_1     =   4,  //【信息流】视频详情页后贴片广告
    DJX_BU_SlotID_VideoPage_2     =   5,  //【信息流 视频详情页标题下的广告
    DJX_BU_SlotID_DetailRelated   =   6,  //【信息流】图文、视频详情页相关推荐广告
    DJX_BU_SlotID_DrawExpress     =   7,   //【沉浸式小视频】【信息流】小视频模板渲染广告
    DJX_BU_SlotID_DrawNative      =   8,   //【沉浸式小视频】【信息流】小视频自渲染广告
//    DJX_BU_SlotID_DrawBigInterstitial         =   9,   //【沉浸式小视频】小视频大插屏广告
    DJX_BU_SlotID_DrawNoteInterstitial      =   10,   //【沉浸式小视频】小视频便利贴广告
    DJX_BU_SlotID_Feed_interstitial        = 11, // 【信息流】信息流插屏广告
    DJX_BU_SlotID_DrawInterstitial      = 12, //【沉浸式小视频】小视频新插屏半屏广告
    DJX_BU_SlotID_DrawFullscreenInterstitial = 13, //【沉浸式小视频】小视频新插屏全屏广告
    DJX_BU_SlotID_DrawBanner           = 14, //【沉浸式小视频】banner广告
    DJX_BU_SlotID_PlayletReward        = 15, //【短剧】激励视频广告(封装)
    DJX_BU_SlotID_PlayletReward_2      = 16, //【短剧】激励视频广告(接口)
};

typedef NS_ENUM(NSInteger, DJXDrawVideoProgressBarStyle) {//进度条样式
    DJXDrawVideoProgressBarStyleLightContent     = 0,  // 浅色系
    DJXDrawVideoProgressBarStyleDarkContent      = 1   // 深色系
};

typedef NS_ENUM(NSInteger, DJXFeedSecondaryDetailPageType) { //详情页类型
    DJXFeedSecondaryDetailPageType_Doc        = 0,  // 图文详情页
    DJXFeedSecondaryDetailPageType_Video      = 1   // 视频详情页
};

typedef NS_ENUM(NSInteger, DJXFontSize) {
    DJXFontSizeSmall,
    DJXFontSizeMedium, // default
    DJXFontSizeLarge,
    DJXFontSizeExtraLarge
};

typedef NS_ENUM(NSUInteger, DJXPlayletUnlockADModeOptions) {
    DJXPlayletUnlockADMode_Unknown = 0,  // 未知模式
    DJXPlayletUnlockADMode_Common = 1,   // SDK广告
    DJXPlayletUnlockADMode_Specific = 2  // 开发者自定义广告
};

typedef NS_OPTIONS(NSUInteger, DJXDrawVideoVCTabOptions) {
    DJXDrawVideoVCTabOptions_playlet       = 1 << 0,
    DJXDrawVideoVCTabOptions_playlet_feed  = 1 << 1,
    DJXDrawVideoVCTabOptions_theater       = 1 << 2,
};

typedef NS_ENUM(NSInteger, DJXPlayletEntranceType) {
    DJXPlayletEntranceTypeDefault,   // 默认
    DJXPlayletEntranceTypeHome,      // 首页
    DJXPlayletEntranceTypeSkitMixed, // 短剧混排
    DJXPlayletEntranceTypeHistory,   // 历史记录
    DJXPlayletEntranceTypeCard,      // 短剧卡片
    DJXPlayletEntranceTypeSearch     // 搜索页
};

typedef NS_ENUM(NSInteger, DJXPlayletTrackEvent) {
    //自建聚合页
    DJXPlayletTrackEventAppActivate,    // 媒体自建聚合页场景
    DJXPlayletTrackEventClientShow,     // 聚合页每部短剧show埋点
    DJXPlayletTrackEventEnterCategory,  // 进入自建聚合页埋点
    DJXPlayletTrackEventStayCategory,   // 离开自建聚合页埋点
};

typedef NS_ENUM(NSInteger, DJXPlayletOrderType) {
    DJXPlayletOrderTypeDefault = 0,     // 正序
    DJXPlayletOrderTypeReverse = 1      // 倒序
};

typedef NS_ENUM(NSUInteger, DJXDrawVideoSpeedScope) { // 倍速范围
    DJXDrawVideoSpeedScopeEpisode, // 当前单集，切换单集失效
    DJXDrawVideoSpeedScopeShortPlay, // 当前整剧，退出详情失效
};
NS_ASSUME_NONNULL_END
