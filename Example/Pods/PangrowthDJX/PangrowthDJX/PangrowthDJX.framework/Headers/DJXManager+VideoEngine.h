//
//  DJXManager+VideoEngine.h
//  PangrowthDJX
//
//  Created by admin on 2023/12/12.
//

#import <PangrowthDJX/DJXManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface DJXManager (VideoEngine)

/*! @abstract 此方法用于激活渲染  【重要】⚠️⚠️⚠️必须调用
 你应该在appDelegate的applicationDidBecomeActive:方法中调用这个方法，否则可能会产生黑屏的bug
 */
+ (void)startOpenGLESActivity;

/*! @abstract 这个方法用于使渲染不活跃 【重要】⚠️⚠️⚠️必须调用
你应该在appDelegate的applicationWillResignActive:方法中调用这个方法，否则它可能导致崩溃
*/
+ (void)stopOpenGLESActivity;

@end

NS_ASSUME_NONNULL_END
