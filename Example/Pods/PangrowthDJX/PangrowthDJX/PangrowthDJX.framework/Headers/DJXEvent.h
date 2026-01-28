//
//  DJXEvent.h
//  DJXSDK
//
//  Created by iCuiCui on 2020/4/21.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NSString * DJXEventParamsKey;

@interface DJXEvent : NSObject<NSCopying>
/// 文章/小视频唯一标示
@property (nonatomic, assign) long long group_id;
/// 扩展参数
@property (nonatomic, copy) NSDictionary<DJXEventParamsKey,id> *params;

- (NSString *)toJSONString;

@end

NS_ASSUME_NONNULL_END
