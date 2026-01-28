//
//  TTVideoEngine+Tracker.h
//  TTVideoEngine
//
//  Created by 黄清 on 2018/12/10.
//

#import "TTVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef __TTVIDEOENGINE_TRACKER__
#define __TTVIDEOENGINE_TRACKER__
#if  __has_include("BDTrackerSDK.h")
#define TTVIDEOENGINE_ENABLE_TRACKER 1
#else
#define TTVIDEOENGINE_ENABLE_TRACKER 0
#endif
#endif


typedef void(^TTVideoEngineDeviceInfo)(NSString *_Nullable deviceID, NSString *_Nullable installID, NSString *_Nullable ssID);

@interface TTVideoEngine()

/// Report log switch. Default: YES
@property (nonatomic, assign) BOOL reportLogEnable;

/**
 Set video tag, recommended to set before calling [engine play]

 @param tag （example: short vdieo, long video）
 */
- (void)setTag:(NSString *)tag;

/**
 Get once play session id

 @return player session id
 */
- (NSString *)getPlayerSessionId;

/**
 Get the device unique id, if the app is not deleted, this id will not change

 @return engine unique id
 */
+ (NSString *)getEngineUniqueId;

@end

NS_ASSUME_NONNULL_END
