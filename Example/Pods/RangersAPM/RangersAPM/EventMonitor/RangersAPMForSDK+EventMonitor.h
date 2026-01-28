//
//  RangersAPMForSDK+EventMonitor.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/2/8.
//

#import "RangersAPMForSDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPMForSDK (EventMonitor)

/*! @abstract 记录一个事件
 @param eventName 事件名称
 @param metrics 事件相关指标信息，字典只能有一级，value为数值类型
 @param dimension 事件相关维度信息，字典只能有一级，可在平台上用于对指标的分组和筛选
 @param extraValue 额外信息，一些环境、用户信息等，可以在DID追查中的原始日志查看
 */
- (void)trackEvent:(nonnull NSString *)eventName
           metrics:(nullable NSDictionary <NSString *, NSNumber *> *)metrics
         dimension:(nullable NSDictionary <NSString *, NSString *> *)dimension
        extraValue:(nullable NSDictionary *)extraValue;

@end

NS_ASSUME_NONNULL_END
