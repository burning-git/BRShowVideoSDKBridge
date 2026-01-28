//
//  TTVideoEngineStrategyPreloadConfig.h
//  TTSDK
//
//  Created by zyw on 2024/5/14.
//

#import <Foundation/Foundation.h>

/**
 * @locale zh
 * @type keytype
 * @brief 自定义预加载配置对象
 */
@interface TTVideoEngineStrategyPreloadConfig : NSObject

/**
 * @locale zh
 * @brief 设置预加载个数
 * @notes 建议设置 3 - 5 个，SDK内部限制最多10个，设置过多可能会带来成本浪费
 */
@property (nonatomic, assign) NSInteger count;
/**
 * @locale zh
 * @brief 设置预加载大小
 * @notes 建议设置短视频场景建议 500K - 800K，可根据视频时长调整，确保设置 size 可以加载出视频首帧
 */
@property (nonatomic, assign) NSInteger size;
/**
 * @locale zh
 * @brief 设置预加载开始时机，播放器缓冲 buffer 大于设置时长才会开始预加载
 * @notes 建议设置 15 秒以上
 */
@property (nonatomic, assign) NSInteger startBufferLimit;
/**
 * @locale zh
 * @brief 设置预加载任务停止时机，播放器缓冲 buffer 小于设置时长才会停止预加载，并取消当前正在预加载的任务
 * @notes 建议设置 5 秒左右
 */
@property (nonatomic, assign) NSInteger stopBufferLimit;


/**
 * @locale zh
 * @hidden
 * @brief 字符串描述
 * @return 返回字符串描述
 */
- (NSString * _Nullable)toStringDescriptor;

@end
