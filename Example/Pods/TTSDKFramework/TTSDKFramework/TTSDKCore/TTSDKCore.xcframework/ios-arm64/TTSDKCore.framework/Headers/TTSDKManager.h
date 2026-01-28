//
//  TTSDKManager.h
//  TTSDK
//
//  Created by 陈昭杰 on 2020/2/4.
//  Copyright © 2020 ByteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseDidAdd;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationIdKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseResultKey;

NS_ASSUME_NONNULL_BEGIN

typedef void(^TTSDKLogger)(NSString * _Nullable log);

typedef NS_ENUM(NSInteger, TTSDKServiceVendor) {
    TTSDKServiceVendorCN = 0x010,
    TTSDKServiceVendorSG,
    TTSDKServiceVendorVA,
    TTSDKServiceVendorMYA,        
};

typedef NS_ENUM (NSInteger, TTSDKServiceBizType) {
    TTSDKServiceBizType_Vod     = 1 << 0,
    TTSDKServiceBizType_Live    = 1 << 1,
    TTSDKServiceBizType_Upload  = 1 << 2,
    TTSDKServiceBizType_Image   = 1 << 3,
    
    TTSDKServiceBizType_All = (TTSDKServiceBizType_Vod |
                              TTSDKServiceBizType_Live |
                              TTSDKServiceBizType_Upload |
                              TTSDKServiceBizType_Image),

    /// @private
    /// - 仅火山引擎内部使用，App 请勿设置。
    /// - 仅在二方库与TTSDK联合交付场景中使用
    TTSDKServiceBizType_SecondParty = 1 << 4,
};

typedef NS_ENUM(NSUInteger, TTSDKLogLevel) {
    /** {zh}
     * @brief 输出 VERBOSE、DEBUG、INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelVerbose,
    /** {zh}
     * @brief 输出 DEBUG、INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelDebug,
    /** {zh}
     * @brief 输出 INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelInfo,
    /** {zh}
     * @brief 输出 WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelWarn,
    /** {zh}
     * @brief 输出 ERROR 级别的日志
     */
    TTSDKLogLevelError,
    /** {zh}
     * @brief 关闭日志打印
     */
    TTSDKLogLevelNone,
};

@interface TTSDKVodConfiguration : NSObject

/// cache path, default "NSCachesDirectory/com.video.cache"
@property (nonatomic, copy, nullable) NSString *cachePath;

/// cache max size, default 100M ( 100 * 1024 * 1024 )
@property (nonatomic, assign) NSInteger cacheMaxSize;

@end

@interface TTSDKLogConfiguration : NSObject

/**
 * 是否开启日志功能，默认为NO。
 */

@property (nonatomic, assign) BOOL enable;
/**
 * 设备ID，没有自定义的需求时，设置为nil即可。
 */
@property (nonatomic, copy) NSString *deviceID;
/**
 * @brief logPath, 日志写入路径. 如果为空，会使用默认的路径
 *  默认路径为/Library/Volclog目录
 */
@property (nonatomic, copy) NSString *logPath;

/**
 * @brief maxLogSizeM, 日志文件最大值，单位M
 *  默认值为100M
 */
@property (nonatomic, assign) NSUInteger maxLogSizeM;

/**
 * @brief singleLogSizeM, 单个日志文件大小（单位M）
 *  默认值为2M
 */
@property (nonatomic, assign) NSUInteger singleLogSizeM;

/**
 * @brief logExpireTime, 日志文件的过期时间（过期后下次创建文件时会删除之前的文件)，单位 s
 *  默认值为7天
 */
@property (nonatomic, assign) NSUInteger logExpireTimeS;

/**
 * @brief enableConsole, 是否开启日志输出到console
 *  默认值为YES
 */
@property (nonatomic, assign) BOOL enableConsole;

/**
 * @brief enableLogFile, 是否开启日志保存到文件
 * 默认值为YES
 */
@property (nonatomic, assign) BOOL enableLogFile;

/**
 * @brief 允许写入的日志等级，默认为 TTSDKLogLevelDebug
 */
@property (nonatomic, assign) TTSDKLogLevel logLevel;
@end

@interface TTSDKImagexConfiguration : NSObject

/// 是否需要在 TTSDK 中进行 httpdns 功能的初始化，默认是YES
/// > 须先接入 `TTNet`
@property (nonatomic, assign) BOOL shouldInitHttpDns;

/// 是否需要在 TTSDK 中进行 quic 功能的初始化，默认是NO
/// > 须先接入 `TTNet`
@property (nonatomic, assign) BOOL shouldInitQuic;

/// 唯一token
@property (nonatomic, copy) NSString *token;

/// 本地授权码
@property (nonatomic, copy) NSArray<NSString *> *authCodes;

/// 默认图片配置
+ (instancetype)defaultImagexConfig;

@end

@interface TTSDKConfiguration : NSObject

/// AppID，非空，必须设置
@property (nonatomic, copy, nonnull, readonly) NSString *appID;

/// app name
@property (nonatomic, copy) NSString *appName;

/// app channel, default "App Store"
@property (nonatomic, copy) NSString *channel;

/// 新版本已弃用，业务如果使用了该字段建议尽早处理下，直接删除赋值即可
@property (nonatomic, assign) TTSDKServiceVendor serviceVendor DEPRECATED_MSG_ATTRIBUTE("deprecated");

/// 请勿擅自选择，需要与申请服务地区一致或者联系客服确认,  默认 TTSDKServiceVendorCN
@property (nonatomic, assign) TTSDKServiceVendor appRegion;

/// 默认 TTSDKServiceBizType_All 支持所有模块，业务可以指定使用单独模块
@property (nonatomic, assign) TTSDKServiceBizType bizType;

/// license文件路径
@property (nonatomic, copy) NSString *licenseFilePath;

/// app version
@property (nonatomic, copy) NSString *appVersion;

/// bundle identifier
@property (nonatomic, copy) NSString *bundleID;

/// 是否需要初始化 `Rangers App Log` SDK，默认是YES
/// > 须先接入 `RangersAppLog`
@property (nonatomic, assign) BOOL shouldInitAppLog;

/// 是否需要初始化 `TTNet` SDK，默认是YES
/// > 须先接入 `TTNet`
@property (nonatomic, assign) BOOL shouldInitTTNet;

/// 用于视频点播初始化配置
@property (nonatomic, strong) TTSDKVodConfiguration *vodConfiguration;

/// 用于Imagex初始化配置
@property (nonatomic, strong) TTSDKImagexConfiguration *imagexConfiguration;

/// 初始化日志配置，不设置会使用默认值
@property (nonatomic, strong) TTSDKLogConfiguration *logConfiguration;

/// 用指定appID获取默认配置
/// @param appID appID
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID;

/// 用指定appID&licensePath获取默认配置
/// @param appID appID
/// @param licensePath license file path
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID licensePath:(NSString *)licensePath;

/// 用指定appID&licenseName获取默认配置
/// @param appID appID
/// @param licenseName license name from volc ( E.g demo.lic )
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID licenseName:(NSString *)licenseName;

@end

@interface TTSDKManager : NSObject

/// TTSDK版本号
@property (class, nonatomic, copy, nonnull, readonly) NSString *SDKVersionString;

/// 使用给定的配置启动TTSDK相关任务，启动app时调用
/// @param configuration TTSDK相关配置信息
+ (void)startWithConfiguration:(TTSDKConfiguration *)configuration;

/// 设置当前UserUniqueID，UserUniqueID发生变化时使用
/// @param uniqueID 用户id，如无特殊需求，请勿传 空字符串 或者 全是空格的字符串
+ (void)setCurrentUserUniqueID:(nullable NSString *)uniqueID;

+ (nullable NSString *)getCurrentUserUniqueID;

/// 清除当前UserUniqueID
+ (void)clearUserUniqueID;

/// 获取ID对应的证书信息
/// @param licenseId 证书id
/// @return 证书信息
+ (NSDictionary *)getCurrentLicenseInfo:(NSString *)licenseId;

/// 默认业务只有一个License调用 startWithConfiguration 会自动更新License，不需要调用该方法
/// 当业务集成多个License，通过该方法更新License
/// @param configuration TTSDK相关配置信息
+ (void)updateLicenseWithConfiguration:(TTSDKConfiguration *)configuration;

/// TTSDK日志是否上报到RangersAppLog
+ (void)setShouldReportToAppLog:(BOOL)shouldReport DEPRECATED_MSG_ATTRIBUTE("use [VeLiveCommon enableReportApplog:]");

+ (void)setAppLogCustomData:(nullable NSDictionary *)data DEPRECATED_MSG_ATTRIBUTE("use [VeLiveCommon setAppLogCustomData:]");

///获取deviceid，需要集成RangersApplog
+ (NSString *)getRangersDeivceID;
@end

NS_ASSUME_NONNULL_END
