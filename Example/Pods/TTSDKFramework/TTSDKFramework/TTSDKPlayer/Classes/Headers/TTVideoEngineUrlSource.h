//
//  TTVideoEngineUrlSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/9/10.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineMultiEncodingUrlSource;

@interface TTVideoEngineUrlSource : NSObject <TTVideoEngineMediaSource>

/// play urls, support backup url
@property (nonatomic, strong) NSArray *urls;

/// URL expire timestamp string array for urls. (utc timestamp in second)
@property (nonatomic, copy, nullable) NSArray<NSString *> *urlExpiredTimes;

/// media data loader cache video unique identification key, recommended  you can use unique url md5 string
@property (nonatomic, copy) NSString *cacheKey;

/// encode type of this resource
@property (nonatomic, assign) TTVideoEngineEncodeType encodeType;

/// video id
@property (nonatomic, copy, nullable) NSString *vid;

/// is hdr, default no
@property (nonatomic, assign) BOOL isHDRSource;

/// Enable 403 error self-refresh. The usage steps are as follows: 
/// 1. enableFallbackRefresh = YES
/// 2. Implement TTVideoURLRefreshFetcher instance and set TTVideoEngine  `[TTVideoEngine urlRefreshFetcher]`
@property (nonatomic, assign) BOOL enableFallbackRefresh;

/// custom decryption key
@property (nonatomic, strong, nullable) NSString *decryptionKey;

/// custom defined cache file path.
@property (nonatomic, copy, nullable) NSString *filePath;

@property (nonatomic, assign) TTVideoEngineCodecStrategy codecStrategy;

/// Note: Maybe nil
@property (nullable, nonatomic, strong, readonly) TTVideoEngineMultiEncodingUrlSource *multiEncodingUrlSource;

@property (nullable, nonatomic, copy, readonly) NSString *hlsproxyQuery;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


/// Designated initializer.
/// @param url The encode type of current asset, make sure it is correct.
/// @param cacheKey MDL cache key. Alternative with filePath
- (instancetype)initWithUrl:(NSString *)url
                   cacheKey:(NSString *)cacheKey;

/// Designated initializer.
/// @param url The encode type of current asset, make sure it is correct.
/// @param cacheKey MDL cache key. Alternative with filePath
/// @param vid video unique id
- (instancetype)initWithUrl:(NSString *)url
                   cacheKey:(NSString *)cacheKey
                    videoId:(NSString * _Nullable)vid;

/// Designated initializer.
/// @param urls support backup url
/// @param cacheKey MDL cache key. Alternative with filePath
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey;

/// Designated initializer.
/// @param urls support backup url
/// @param cacheKey MDL cache key. Alternative with filePath
/// @param vid video unique id
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey
                     videoId:(NSString * _Nullable)vid;

/// Designated initializer.
/// @param urls support backup url
/// @param cacheKey MDL cache key. Alternative with filePath
/// @param encodeType The encode type of current asset, make sure it is correct.
/// @param decryptionKey auth key for encrypted video.
/// @param filePath Cache file path. Alternative with cacheKey
/// @param isHDRSource is hdr source
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey
                     videoId:(NSString * _Nullable)vid
                  encodeType:(TTVideoEngineEncodeType)encodeType
               decryptionKey:(NSString * _Nullable)decryptionKey
                    filePath:(NSString * _Nullable)filePath
                 isHDRSource:(BOOL)isHDRSource;

/// Add direct url source for multi ecodetype.
/// @param urls support backup url
/// @param encodeType The source's encode type.
/// @param cacheKey Local file cache key.
/// @param decryptionKey Decrypt key for encrypted video.
/// @param filePath Cache file path. Alternative with cacheKey
/// @param isHDRSource is hdr source
- (void)addUrls:(NSArray *)urls
       cacheKey:(NSString *)cacheKey
     encodeType:(TTVideoEngineEncodeType)encodeType
  decryptionKey:(NSString * _Nullable)decryptionKey
       filePath:(NSString * _Nullable)filePath
    isHDRSource:(BOOL)isHDRSource;

@end


@class TTVideoEngineHLSProxyParam;
@interface TTVideoEngineUrlSource (Private)

- (void)setHlsProxyParam:(TTVideoEngineHLSProxyParam *)hlsProxyParam;

@end

NS_ASSUME_NONNULL_END
