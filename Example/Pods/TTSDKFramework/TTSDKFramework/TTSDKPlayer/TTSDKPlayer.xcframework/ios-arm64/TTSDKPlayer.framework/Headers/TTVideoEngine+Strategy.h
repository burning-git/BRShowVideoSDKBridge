//
//  TTVideoEngine+Strategy.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/15.
//

#import "TTVideoEngine.h"
#import "TTVideoEngineMediaSource.h"
#import "TTVideoEngine+Preload.h"
#import "TTVideoEngineStrategyPreloadConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineVidSource;
@class TTVideoEngineUrlSource;

/// Strategy Type
typedef NS_ENUM(NSInteger, TTVideoEngineStrategyType) {
    TTVideoEngineStrategyTypeNone      = 1 << 0,
    TTVideoEngineStrategyTypeCommon    = 1 << 1,
    TTVideoEngineStrategyTypePreload   = 1 << 2,
    TTVideoEngineStrategyTypePreRender = 1 << 3,
};

/// Strategy scene
FOUNDATION_EXTERN NSString * const TTVEngineStrategySceneSmallVideo;
FOUNDATION_EXTERN NSString * const TTVEngineStrategySceneShortVideo;

// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - Engine Preload - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //

@interface TTVideoEnginePreloaderURLItem (PreloadItem)

/// Construct a TTVideoEnginePreloaderURLItem instance for direct url source.
/// @param source TTVideoEngineUrlSource
/// @param preloadSize preload size, like 800*1024(800KB)
+ (nullable instancetype)urlItemWithVideoSource:(id<TTVideoEngineMediaSource>)source preloadSize:(NSInteger)preloadSize;

@end

@interface TTVideoEnginePreloaderVidItem (PreloadItem)

/// Construct a TTVideoEnginePreloaderVidItem instance for vid source.
/// @param source TTVideoEngineVidSource
/// @param preloadSize preload size, like 800*1024(800KB)
+ (nullable instancetype)vidItemWithVideoSource:(id<TTVideoEngineMediaSource>)source preloadSize:(NSInteger)preloadSize;

@end


@interface TTVideoEnginePreloaderVideoModelItem (PreloadItem)

+ (nullable instancetype)videoModelItemWithVideoSource:(id<TTVideoEngineMediaSource>)source
                                           preloadSize:(NSInteger)preloadSize
                                                params:(nullable NSDictionary *)params;

@end


// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - Engine - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //

@interface TTVideoEngine()

@end

@interface TTVideoEngine (PlaySouce)

/// Set play source, use mdl to load data.
/// @param source vid-TTVideoEngineVidSource, url-TTVideoEngineUrlSource, codecUrl-TTVideoEngineMultiEncodingUrlSource
- (void)setVideoEngineVideoSource:(id<TTVideoEngineMediaSource>)source;

/// Get engine unique id for engine strategy
- (NSString *)getVideoEngineStrategyUniqueId;

@end



// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - -  Engine Strategy - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - //

@interface TTVideoEngine (EngineStrategy)

/// Enable engine strategy, open ViewController settings enable strategy, do not repeat settings
/// @param strategyType  support (TTVideoEngineStrategyTypeCommon | TTVideoEngineStrategyTypePreload | TTVideoEngineStrategyTypePreRender)
/// @param scene use TTVEngineStrategySceneSmallVideo、TTVEngineStrategySceneShortVideo
+ (BOOL)enableEngineStrategy:(TTVideoEngineStrategyType)strategyType scene:(NSString *)scene;

/** {zh}
 * @type api
 * @brief 开启预渲染策略
 * @param scene 指定场景 <br>
 *              -`TTVEngineStrategySceneSmallVideo`: 类似 "抖音" Feed 流场景
 *              -`TTVEngineStrategySceneShortVideo`: 类似 "西瓜" Feed 流场景
 *  @return 预渲染策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
+ (BOOL)enableEnginePreRenderStrategy:(NSString *)scene;

/** {zh}
 * @type api
 * @brief 开启预加载策略
 * @param scene 指定场景 <br>
 *              -`TTVEngineStrategySceneSmallVideo`: 类似 "抖音" Feed 流场景
 *              -`TTVEngineStrategySceneShortVideo`: 类似 "西瓜" Feed 流场景
 *  @return 预加载策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
+ (BOOL)enableEnginePreloadStrategy:(NSString *)scene;
/** {zh}
 * @type api
 * @brief 开启预加载策略，可以自定义预加载策略配置参数
 * @param preloadConfig 预加载策略配置
 * @param scene 指定场景 <br>
 *              -`TTVEngineStrategySceneSmallVideo`: 类似 "抖音" Feed 流场景
 *              -`TTVEngineStrategySceneShortVideo`: 类似 "西瓜" Feed 流场景
 * @return 预加载策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
+ (BOOL)enableEnginePreloadStrategy:(TTVideoEngineStrategyPreloadConfig *)preloadConfig scene:(NSString *)scene;

/// Clearn all engine strategy,
/// Make sure close ViewController clear old engine strategy
+ (void)clearAllEngineStrategy;

@end

// - - - - - - - - - - - Preload|PreRender videoSource - - - - - - - - - - - //

@interface TTVideoEngine (EngineStrategySource)

// When enable (TTVideoEngineStrategyTypePreload|TTVideoEngineStrategyTypePreRender) strategy
// Need to set the current playlist

/// Set up playlist, E.g Refresh data
/// @param videoSources play sources
+ (void)setStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources;
/// Add playlist to current playlist, E.g Load more data
/// @param videoSources play sources
+ (void)addStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources;

/// Set up playlist, E.g Refresh data
/// Support codec strategy,
/// @param videoSources play sources
/// @param codecStrategy TTVideoEngineCodecStrategy
+ (void)setStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources codecStrategy:(TTVideoEngineCodecStrategy)codecStrategy;
/// Add playlist to current playlist, E.g Load more data
/// Support codec strategy,
/// @param videoSources play sources
/// @param codecStrategy TTVideoEngineCodecStrategy
+ (void)addStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources codecStrategy:(TTVideoEngineCodecStrategy)codecStrategy;

@end

// - - - - - - - - - - - - - - Preload Strategy - - - - - - - - - - - - - - //

@interface TTVideoEngine (EngineStrategyPreload)

+ (void)startEnginePreloadStrategyWithIndex:(NSInteger)startIndex;

@end


// - - - - - - - - - - - - - - PreRender Strategy - - - - - - - - - - - - - - //


@protocol TTVideoEnginePreRenderDelegate <NSObject>

/// Implement this method:
///     - Set all options you need by invoking `-[TTVideoEngine setOptions:forKey:]`
///     - note: This will be invoked before -[TTVideoEngine setVideoEngineVideoSource:]
- (void)videoEngine:(TTVideoEngine *)videoEngine willPreRenderSource:(id<TTVideoEngineMediaSource>)source;

/// This will be called before video engine prepare to play
/// @param videoEngine videoengine
- (void)videoEngineWillPrepare:(TTVideoEngine *)videoEngine;

@end

@interface TTVideoEngine (EngineStrategyPreRender)

/// Set pre render VideoEngineDelegate
/// @param delegate video engine delegate
+ (void)setPreRenderVideoEngineDelegate:(id<TTVideoEnginePreRenderDelegate>)delegate;

/// Get pre render videoEngine, use this videoEngine replace current play videoEngine
/// If return nil, use the original logic
/// @param source vid-TTVideoEngineVidSource, url-TTVideoEngineUrlSource, codecUrl-TTVideoEngineMultiEncodingUrlSource
+ (TTVideoEngine * _Nullable)getPreRenderVideoEngineWithVideoSource:(id<TTVideoEngineMediaSource>)source;

/// Get pre render player view, player view can be use backgroud image
/// If return nil, use the original logic
/// @param source vid-TTVideoEngineVidSource, url-TTVideoEngineUrlSource, codecUrl-TTVideoEngineMultiEncodingUrlSource
+ (UIView * _Nullable)getPreRenderFinishedPlayerViewWithVideoSource:(id<TTVideoEngineMediaSource>)source;
/// Get pre render player view, player view can be use backgroud image
+ (TTVideoEngine * _Nullable)getPreRenderFinishedVideoEngineWithVideoSource:(id<TTVideoEngineMediaSource>)source;

@end

NS_ASSUME_NONNULL_END
