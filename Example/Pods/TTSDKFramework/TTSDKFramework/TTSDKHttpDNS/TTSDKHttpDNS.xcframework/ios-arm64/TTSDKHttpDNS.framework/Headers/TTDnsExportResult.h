//
//  TTDnsExportResult.h
//  BytedanceHTTPDNS
//
//  The BytedanceHTTPDNS is licensed under the MIT License.
//  Copyright (c) 2021 Bytedance Inc.
//

#import <Foundation/Foundation.h>

@class TTDnsRecord;

NS_ASSUME_NONNULL_BEGIN

/*!
    @typedef DnsResultSource
    @brief DNS请求结果来源枚举
    @discussion SDK 支持stale cache,即只要有cache,无论过期与否都会返回，有效性由服务端保证，过期后经过 overStaleCacheTimeIntervalAfterTTL 会自动更新。
    @enum DnsResultSource
 */
typedef NS_ENUM(NSInteger, DnsResultSource) {
    SourceHttpDnsRequest = 0,   /*!< DNS结果来源于HTTPDNS 请求 */
    SourceHttpDnsCache,         /*!< DNS结果来源于HTTPDNS cache */
    SourceHttpDnsExpiredCache,  /*!< DNS结果来源于HTTPDNS 过期cache */
    SourceLocalDns,             /*!< DNS结果来源于local DNS请求 */
    SourceLocalDnsCache,        /*!< DNS结果来源于local DNS cache */
    SourceLocalDnsExpiredCache, /*!< DNS结果来源于local DNS 过期 cache */
    SourceNone                  /*!< DNS结果来源于DNS失败 */
};

/*!
    @interface TTHttpDnsAuthenticationInfo
    @brief HTTPDNS 所需鉴权信息，需要从鉴权回调返回给HTTPDNS SDK
    @discussion 每一项都需要注入，否则可能导致crash
 */
@interface TTHttpDnsAuthenticationInfo : NSObject

/*! @brief HTTPDNS 账号 */
@property(nonatomic, copy) NSString* httpDnsAccount;
/*! @brief HTTPDNS 是否使用临时KEY鉴权方式 */
@property(nonatomic, assign) BOOL useTemporaryKey;
/*! @brief HTTPDNS 密钥 */
@property(nonatomic, copy) NSString* key;
/*! @brief HTTPDNS 密钥过期时间，如果采用临时KEY方式，则需要注入
    @code 一小时后过期example:
   [NSString stringWithFormat:@"%lld", (long long)(([[TTDnsResolver shareInstance] getCurrentLocalTime] + 3600) * 1000)]; */
@property(nonatomic, copy) NSString* keyExpiredTimeStamp;

@end


/*!
    @interface DNS解析结果
    @brief TTDnsExportResult
 */
@interface TTDnsExportResult : NSObject

/*! @brief DNS解析的Host */
@property(nonatomic, copy, readonly) NSString* host;
/*! @brief DNS解析结果来源 */
@property(nonatomic, assign, readonly) DnsResultSource source;
/*! @brief DNS解析结果有效时间 */
@property(nonatomic, assign, readonly) int ttl;
/*! @brief DNS解析结果IPv4列表 */
@property(nonatomic, strong, readonly) NSArray<NSString*>* ipv4List;
/*! @brief DNS解析结果IPv6列表 */
@property(nonatomic, strong, readonly) NSArray<NSString*>* ipv6List;

/*! @brief HTTPDNS解析请求耗时，Source为HTTPDNS相关时有效 */
@property(nonatomic, assign, readonly) int rtt;
/*! @brief HTTPDNS请求返回的客户端IP地址，Source为HTTPDNS相关时有效 */
@property(nonatomic, copy, readonly) NSString* cip;

/*! @brief 通过传入的TTDnsRecord来获取DNS信息并构造Result*/
- (id)initWithDnsRecord:(TTDnsRecord* _Nullable)record andSource:(DnsResultSource)source;
/*! @brief DNS解析结果NSLog打印 */
- (NSString*)convertDnsResultToJsonString;

@end

/*! @brief DNS异步调用方式的回调定义 */
typedef void (^DnsCallback)(TTDnsExportResult* _Nonnull);
/*! @brief HTTPDNS鉴权信息回调定义 */
typedef TTHttpDnsAuthenticationInfo* _Nonnull (^HttpDnsAuthenticationBlock)(void);


NS_ASSUME_NONNULL_END
