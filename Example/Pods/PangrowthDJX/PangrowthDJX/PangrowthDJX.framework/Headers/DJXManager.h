//
//  DJXManager.h
//  DJXSDK
//
//  Created by cuiyanan on 2020/3/15.
//  Copyright © 2020 cuiyanan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^DJXStartCompletionBlock)(BOOL isSuccess, NSDictionary *userInfo);
typedef void(^DJXLoginCompletionBlock)(BOOL isSuccess, NSDictionary *userInfo);

@class DJXConfig;

@interface DJXManager : NSObject

/*! @abstract SDK 版本号 */
@property (nonatomic, copy, readonly, class) NSString *SDKVersion;

/// 配置信息
/// @param configPath json文件路径
/// @param config 初始化配置
+ (void)initializeWithConfigPath:(NSString *)configPath config:(DJXConfig *)config;

/// 主线程注册,不注册会导致SDK功能无法正常使用。
/// @param completionBlock 初始化回调
+ (void)startWithCompleteHandler:(DJXStartCompletionBlock)completionBlock;

/*! @abstract 设置个性化推荐
YES：打开个性化开关
NO：关闭个性化开关
*/
+ (void)setPersonalizationRecommendation:(BOOL)pr;

/*! @abstract 获取个性化推荐开关
*/
+ (BOOL)personalizationRecommendation;

/// 设置外部账户的名字和头像，登录时设置
+ (void)setUserName:(NSString *)userName userAvatar:(UIImage *)userAvatar;
/// 清空设置的账户名和头像
+ (void)clearUserNameAndAvatar;

/*! @abstract 获取SDK请求token，请在[DJXManager startWithCompleteHandler:]初始化成功，
 回调initStatus返回DJXINITStatus_success时使用。SDK未初始化成功时，该方法返回nil
*/
+ (NSString * _Nullable)getToken;

/**
 * @abstract 获取签名参数
 *
 * @param  nonce        16位随机字符串
 * @param  timeStamp    时间戳，单位秒
 * @param  params       其他参数
 * @return 签名参数，     用来调用登录时使用。可能返回null(如参数透传错误)
 */
+ (NSString * _Nullable)getSignWithPaySecretKey:(NSString *)paySecretKey nonce:(NSString *)nonce timeStamp:(NSTimeInterval)timeStamp params:(NSDictionary<NSString *, NSString *> *)params;

/**
 * 登录接口
 *
 * @param paramsString 登录参数，格式为：nonce=xxx&ouid=xxx&timestamp=xxx&sign=xxx
 */
+ (void)loginWithParamsString:(NSString *)paramsString completionBlock:(DJXLoginCompletionBlock)completionBlock;
/**
 * 退出登录
 */
+ (void)logoutWithCompletionBlock:(DJXLoginCompletionBlock)completionBlock;

/**
 * 获取sdk是否登录成功：
 *
 * @return YES已经登录、NO未登录
 */
+ (BOOL)isLogin;

@end

NS_ASSUME_NONNULL_END
