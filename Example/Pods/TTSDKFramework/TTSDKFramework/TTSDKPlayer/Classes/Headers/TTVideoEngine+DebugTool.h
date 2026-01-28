//
//  TTVideoEngine+DebugTool.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2022/7/1.
//

#import "TTVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngine (DebugTool)

/// debug tool view is showing
+ (BOOL)debugToolIsShowing;

/// show debug tool with container view
/// @param containerView add debug tool on the container view
+ (void)showDebugTool:(UIView *)containerView;

/// show debug tool with container view
/// @param containerView add debug tool on the container view
/// @param rect custom debug tool view show in rect
+ (void)showDebugTool:(UIView *)containerView inRect:(CGRect)rect;

/// refresh current video engine
/// @param videoEngine  video engine
+ (void)refreshCurrentVideoEngine:(TTVideoEngine *)videoEngine;

/// remove debug too view
+ (void)removeDebugTool;

@end

NS_ASSUME_NONNULL_END
