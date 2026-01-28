//
//  TTVideoEngineMediaSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/18.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineModelDef.h"
#import "TTVideoEnginePlayerDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TTVideoEngineSourceType) {
    TTVideoEngineSourceTypeVideoId   = 0,
    TTVideoEngineSourceTypeDirectUrl = 1,
    TTVideoEngineSourceTypeVideoModel = 2,
};

@protocol TTVideoEngineMediaSource <NSObject>

@property (nonatomic, readonly, strong, getter=getUniqueId) NSString *uniqueId;

@property (nonatomic, assign) TTVideoEngineSourceType sourceType;

@property (nonatomic, assign) TTVideoEngineCodecStrategy codecStrategy;

/// Enable 403 error self-refresh. The usage steps are as follows:
/// 1. enableFallbackRefresh = YES
/// 2. Implement TTVideoURLRefreshFetcher instance and set TTVideoEngine  `[TTVideoEngine urlRefreshFetcher]`
@property (nonatomic, assign) BOOL enableFallbackRefresh;

@end

NS_ASSUME_NONNULL_END
