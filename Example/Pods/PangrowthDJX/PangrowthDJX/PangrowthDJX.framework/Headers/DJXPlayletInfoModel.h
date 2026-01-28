//
//  DJXPlayletInfoModel.h
//  PangrowthMedia
//
//  Created by ByteDance on 2023/1/18.
//

#import <Foundation/Foundation.h>
#import "DJXPublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DJXPlayletUnlockResult) {
    DJXPlayletUnlockResult_Success,
    DJXPlayletUnlockResult_AD_Not_Show,     // 广告没有展示
    DJXPlayletUnlockResult_Request_Error,   // 解锁接口请求失败
    DJXPlayletUnlockResult_User_Cancel,     //用户取消解锁
};

typedef NS_ENUM(NSUInteger, DJXPlayletUnlockModeType) {
    DJXPlayletUnlockModeType_Default = 0,  // 单次解锁模式
    DJXPlayletUnlockModeType_Continuous = 1,   // 连续解锁模式
};

@interface DJXPlayletUnlockModel : NSObject
/// 不看广告，取消解锁
@property (nonatomic) BOOL cancelUnlock;
/// 短剧id
@property (nonatomic) NSInteger playletId;
/// 每个激励广告解锁多少集
@property (nonatomic) NSInteger unlockEpisodeCount;

/// 解锁模式,默认单次解锁 连续解锁封装模式不支持
@property (nonatomic) DJXPlayletUnlockModeType unlockModeType;

@end

/// 解锁流程最终结束时的结果
@interface DJXRewardAdResult : NSObject
/// 激励广告是否成功
@property (nonatomic) BOOL success;
/// 激励cpm
@property (nonatomic, copy) NSString *cpm;
/// 其他信息
@property (nonatomic, copy) NSDictionary<NSString *, id> *extraData;

@end

@interface DJXShortplayCover : NSObject

@property (nonatomic, copy) NSString *main_url;

@property (nonatomic, copy) NSString *backup_url;

@property (nonatomic, copy) NSString *definition;

@end

//短剧信息
@interface DJXPlayletInfoModel : NSObject

@property (nonatomic, assign) NSInteger shortplay_id;            // 短剧ID
@property (nonatomic, copy) NSString *title;                     // 短剧名
@property (nonatomic, copy) NSString *cover_image;               // 短剧的封面
@property (nonatomic, assign) NSInteger status;                  // 短剧状态 1表示未完结
@property (nonatomic, assign) NSInteger total;                   // 共多少集
@property (nonatomic, copy) NSString *desc;                      // 简介
@property (nonatomic, assign) NSInteger category_id;             // 分类id
@property (nonatomic, copy) NSString *category_name;             // 分类名称
@property (nonatomic, copy) NSString *source_novel_name;         // 短剧对应的小说名
@property (nonatomic, copy) NSString *source_novel_author;       // 小说作者
@property (nonatomic, assign) CGFloat video_duration;            // 时长
@property (nonatomic, assign) NSInteger current_episode;         // 播放到第几集
@property (nonatomic, assign) NSInteger group_id;                // 播放到的剧集gid
@property (nonatomic, assign) NSInteger channel_id;              // 推荐模块id
@property (nonatomic, assign) NSInteger next_skit_id;            // 下一步短剧的id
@property (nonatomic, assign) NSInteger create_time;             // 上线时间
@property (nonatomic, assign) NSInteger action_time;             // 观看时间
@property (nonatomic, assign) NSInteger unlock_index;            // 解锁集数
@property (nonatomic, copy) NSArray<NSNumber *> *lockStatusArray; // 解锁状态列表
@property (nonatomic) NSString *icp_number;                       // 备案号
@property (nonatomic, copy) NSArray<DJXShortplayCover *> *cover_image_v2s; // 短剧封面海报
@property (nonatomic, copy) NSArray<DJXShortplayCover *> *poster_image_v2s; // 剧集首帧

@property (nonatomic) NSInteger favorite_state;
@property (nonatomic) NSInteger favorite_time;
@property (nonatomic) NSInteger favorite_count;
@property (nonatomic) NSInteger like_state;
@property (nonatomic) NSInteger like_time;
@property (nonatomic) NSInteger like_count;
@property (nonatomic) NSInteger level_label;                    //等级标签 "1:S|2:A|3:B"
@property (nonatomic) BOOL is_potential;                        //是否潜力剧
@end

NS_ASSUME_NONNULL_END
