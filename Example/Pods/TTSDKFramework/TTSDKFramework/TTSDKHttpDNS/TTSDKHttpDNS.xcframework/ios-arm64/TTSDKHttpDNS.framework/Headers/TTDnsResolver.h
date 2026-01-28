//
//  TTDnsResolver.h
//  BytedanceHTTPDNS
//
//  The BytedanceHTTPDNS is licensed under the MIT License.
//  Copyright (c) 2021 Bytedance Inc.
//

#import <Foundation/Foundation.h>
#import "TTDnsExportResult.h"

NS_ASSUME_NONNULL_BEGIN

/*!
    @interface TTDnsResolver为单例，通过shareInstance来调用SDK方法
    @brief BytedanceHTTPDNS 接口类
    @discussion SDK的使用主要包含初始化和DNS解析接口调用
*/
@interface TTDnsResolver : NSObject

/*! @brief 监控回调定义*/
typedef void (^Monitorblock)(NSDictionary*, NSString*);

/*! @brief 是否开启HTTPDNS， 默认YES*/
@property(nonatomic, assign) BOOL enableHttpDns;
/*! @brief 是否允许使用过期缓存， 默认YES*/
@property(nonatomic, assign) BOOL enableUseStaleCache;
/*! @brief 是否允许网络切换自动刷新， 默认YES*/
@property(nonatomic, assign) BOOL enableAutoRefreshWithNetworkChanged;
/*! @brief 是否允许自动刷新过期缓存， 默认YES*/
@property(nonatomic, assign) BOOL enableAutoRefreshWithHosts;
/*! @brief 是否允许攒够一定数量的过期host后自动刷新， 默认YES*/
@property(nonatomic, assign) BOOL enableAutoRefreshStaleCache;
/*! @brief 最大攒包数量， 默认10*/
@property(nonatomic, assign) int maxAutoRefreshHostCount;
/*! @brief 是否选用LocalDns优先，默认NO。*/
@property(nonatomic, assign) BOOL isLocalDnsMode;
/*! @brief 备选DNS模式的等待时间，如果这段时间内主DNS模式没有结果，则使用备选结果，默认5000ms。*/
@property(nonatomic, assign) int firstTaskPreferTimeMs;
/*! @brief 主动更新某一个超时域名的时间，在ttl+overStaleCacheTimeIntervalAfterTTL后主动更新，默认60s.*/
@property(nonatomic, assign) int overStaleCacheTimeIntervalAfterTTL;
/*! @brief DNS预解析域名列表，默认为空，可注入，SDK启动时解析*/
@property(nonatomic, strong) NSArray<NSString*>* preloadDomains;

/*! @brief 获取TTDnsResolver单例对象。*/
+ (instancetype)shareInstance;

/*!
    @brief 设置HTTPDNS鉴权信息回调
    @discussion 必须设置，SDK通过该回调获取HTTPDNS鉴权信息。
    @param block 所注入的回调，必须设置
 */
- (void)setHttpDnsAuthenticationBlock:(HttpDnsAuthenticationBlock)block;

/*!
    @brief 初始化SDK并发送预解析请求
    @discussion 必须在初始化的最后一步调用，主要工作包括判断鉴权回调是否注入和预解析域名。
 */
- (void)dnsResolverColdStart;

/*!
    @brief 设置HTTPDNS解析主机域名，默认httpdns.volcengineapi.com
    @discussion 可选调用，但一般不要修改
    @param host : HTTPDNS解析服务域名
 */
- (void)setHttpDnsHost:(NSString*)host;

/*!
    @brief 设置备用的HTTPDNS主机IP, 主机域名解析失败使用该IP.
    @discussion 可选调用，但一般不要修改
    @param ips : 兜底HTTPDNS解析服务IP
 */
- (void)setHttpDnsHardcodeIps:(NSArray*)ips;

/*!
    @brief 设置HTTPDNS请求超时时间.
    @discussion 可选调用
    @param timeout :请求超时时间，默认15s
 */
- (void)setHttpDnsRequestTimeout:(int)timeout;

/*!
    @brief 设置HTTPDNS监控回调
    @discussion 可选设置，通过该回调可以获取HTTPDNS运行期间的日志信息
    @param block : 所注入的回调
 */
- (void)setHttpDnsMonitorBlock:(Monitorblock)block;

/*!
    @brief 设置Appid, HTTPDNS请求增加一个appid的参数，用于HTTPDNS后台统计.
    @discussion 可选设置，一个账户下可以通过appid进行流量的区分
    @param appId :  一个整数来区分应用。
 */
- (void)setHttpDnsAppId:(NSString*)appId;

/*!
    @brief 设置当前时间
    @discussion 可选设置，计算该时间和本机时间的差别，之后的时间都加上该差值
    @param time :  单位ms。
 */
- (void)setCurrentLocalTime:(NSTimeInterval)time;

/*!
    @brief 获取纠正时间差后的当前时间
    @param time :  单位ms。
 */
- (NSTimeInterval)getCurrentLocalTime;


/*!
    @brief 异步接口获取DNS结果。
    @discussion 异步接口，通过callback的参数来回传DNS结果
    @param host :  要解析的域名
    @param callback : 注入的回调
 */
- (void)getDnsResultForHostAsync:(NSString*)host
                        callback:(DnsCallback)callback;

/*!
    @brief 同步接口获取DNS结果。
    @discussion 同步接口使用信号量包装异步接口，DNS结果通过返回值给出
    @param host :  要解析的域名
    @return DNS解析结果
 */
- (TTDnsExportResult*)getDnsResultForHost:(NSString*)host;

/*!
    @brief 异步接口获取HTTPDNS结果，不使用缓存和LocalDNS.
    @discussion 异步接口，通过callback的参数来回传DNS结果，该接口不使用本地缓存和备用Local DNS，直接发请求解析。
    @param host :  要解析的域名
    @param callback : 注入的回调
 */
- (void)getHttpDnsResultForHostWithoutCacheAsync:(NSString*)host
                                        callback:(DnsCallback)callback;

/*!
    @brief 同步接口获取HTTPDNS结果，不使用缓存和LocalDNS，该接口不使用本地缓存和备用Local DNS，直接发请求解析。
    @discussion 同步接口使用信号量包装异步接口，DNS结果通过返回值给出
    @param host :  要解析的域名
    @return DNS解析结果
 */
- (TTDnsExportResult*)getHttpDnsResultForHostWithoutCache:(NSString*)host;



@end

NS_ASSUME_NONNULL_END
