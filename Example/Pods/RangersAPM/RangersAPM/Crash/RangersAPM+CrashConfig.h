//
//  RangersAPM+CrashConfig.h
//  Pods
//
//  Created by xuminghao.eric on 2024/1/31.
//

#import "RangersAPM.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (CrashConfig)

/**
 声明开启了 '-Wl,-no_compact_unwind'  编译选项
 
 Declare turns on the '-Wl,-no_compact_unwind' compilation option
 */
+ (void)crashMarkNoCompactUnwind;

@end

NS_ASSUME_NONNULL_END
