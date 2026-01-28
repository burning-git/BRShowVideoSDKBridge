//
//  DJXPlayletManager.h
//  PangrowthMedia
//
//  Created by ByteDance on 2023/1/18.
//

#import <Foundation/Foundation.h>
#import "DJXPublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class DJXDrawVideoViewController, DJXPlayletConfig, DJXPlayletInfoModel;

@interface DJXPlayletManager : NSObject

+ (instancetype)shareInstance;

#pragma mark - 旧接口，即将过期

/*! @abstract   分页拉取所有短剧
 *  @param      page 第几页，从1开始
 *  @param      num 每页多少个
 *  @param      order 排序，0：正序，1：倒序
 *  @param      completeHandler 结果回调
 */
- (void)requestAllPlayletListPage:(NSInteger)page
                              num:(NSInteger)num
                            order:(DJXPlayletOrderType)order
                       completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *,NSObject *> *info))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧推荐列表 */
- (void)requestRecommendedPlayletListPage:(NSInteger)page
                                      num:(NSInteger)num
                               completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *,NSObject *> *info))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧全部列表 */
- (void)requestAllPlayletListWithOrder:(DJXPlayletOrderType)order
                            completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *, NSObject *> *info))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧列表(根据短剧id获取) */
- (void)requestPlayletListWithPlayletId:(NSArray<NSString *> *)playletIdArray
                        completeHandler:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 获取短剧剧集解锁情况(根据短剧id和免费集数获取) */
- (void)requestPlayletDetailsUnlockInfo:(NSInteger)playletId
                       freeEpisodeCount:(NSInteger)freeEpisodeCount
                        completeHandler:(void (^)(BOOL success, NSArray<NSNumber *> *unlockStatusArray))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧分类列表 */
- (void)requestCategoryList:(void (^)(BOOL success, NSArray<NSString *> *categoryList))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 根据分类获取列表 */
- (void)requestCategoryPlayletLisWithCategory:(NSString *)category
                                         page:(NSInteger)page
                                          num:(NSInteger)num
                                   completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 根据搜索关键词获取列表 */
- (void)requestCategoryPlayletLisWithSearchWord:(NSString *)searchWord
                                        isFuzzy:(BOOL)isFuzzy
                                           page:(NSInteger)page
                                            num:(NSInteger)num
                                     completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList, BOOL hasMore))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧历史记录列表 */
- (void)requestPlayletHistoryListWithPage:(NSInteger)page
                                      num:(NSInteger)num
                               completion:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *playletList))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 短剧历史记录清除 */
- (void)requestPlayletHistoryCleanWithCompletion:(void (^)(BOOL success))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/// 点赞某一集短剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - episode_index: 第几集
///   - completeHandler: 结果回调
- (void)likeShortplay:(NSInteger)shortplay_id episode_index:(NSInteger)episode_index completeHandler:(void (^)(BOOL success))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/// 取消点赞某一集短剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - episode_index: 第几集
///   - completeHandler: 结果回调
- (void)cancelLikeShortplay:(NSInteger)shortplay_id episode_index:(NSInteger)episode_index completeHandler:(void (^)(BOOL success))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/// 收藏某部剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - completeHandler: 结果回调
- (void)collectShortplay:(NSInteger)shortplay_id completeHandler:(void (^)(BOOL success))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/// 取消收藏某部剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - completeHandler: 结果回调
- (void)cancelCollectShortplay:(NSInteger)shortplay_id completeHandler:(void (^)(BOOL success))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/// 请求搜藏列表
/// - Parameters:
///   - page: 第几页
///   - number: 一页多少个
///   - completeHandler: 结果回调
- (void)requestCollectionList:(NSInteger)pageIndex pageSize:(NSInteger)pageSize completeHandler:(void (^)(BOOL success, NSArray<DJXPlayletInfoModel *> *list, BOOL hasMore))completeHandler DJX_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用带success 和 failure回调接口");

/* @abstract 获取一个播放页实例 */
- (DJXDrawVideoViewController *)playletViewControllerWithParams:(DJXPlayletConfig *)params;

#pragma mark - 新接口
///*! @abstract   分页拉取所有短剧
/// *  @param      page 第几页，从1开始
/// *  @param      num 每页多少个
/// *  @param      order 排序，0：正序，1：倒序
/// *  @param      successHandler 成功回调
/// *  @param      failureHandler 失败回调
/// */
- (void)requestAllPlayletListPage:(NSInteger)page
                              num:(NSInteger)num
                            order:(DJXPlayletOrderType)order
                          success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *,NSObject *> *info))successHandler
                          failure:(void (^)(NSError *error))failureHandler;


///* @abstract 短剧推荐列表 */
- (void)requestRecommendedPlayletListPage:(NSInteger)page
                                      num:(NSInteger)num
                                  success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *,NSObject *> *info))successHandler
                                  failure:(void (^)(NSError *error))failureHandler;

///* @abstract 短剧全部列表 */
- (void)requestAllPlayletListWithOrder:(DJXPlayletOrderType)order
                               success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList, NSDictionary<NSString *,NSObject *> *info))successHandler
                               failure:(void (^)(NSError *error))failureHandler;

///* @abstract 短剧列表(根据短剧id获取) */
- (void)requestPlayletListWithPlayletId:(NSArray<NSString *> *)playletIdArray
                                success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList))successHandler
                                failure:(void (^)(NSError *error))failureHandler;

///* @abstract 获取短剧剧集解锁情况(根据短剧id和免费集数获取) */
- (void)requestPlayletDetailsUnlockInfo:(NSInteger)playletId
                       freeEpisodeCount:(NSInteger)freeEpisodeCount
                                success:(void (^)(NSArray<NSNumber *> *unlockStatusArray))successHandler
                                failure:(void (^)(NSError *error))failureHandler;

///* @abstract 短剧分类列表 */
- (void)requestCategoryList:(void (^)(NSArray<NSString *> *categoryList))successHandler
                    failure:(void (^)(NSError *error))failureHandler;

/// @abstract 根据分类获取列表
/// @param      category 分类，如"霸总"
/// @param      page 页数，从1开始
/// @param      num 每页个数
/// @param      order 按照短剧更新（上线时间）日期排序请求，0正序，1倒序
/// @param      successHandler 成功回调
/// @param      failureHandler 失败回调
- (void)requestCategoryPlayletLisWithCategory:(NSString *)category
                                         page:(NSInteger)page
                                          num:(NSInteger)num
                                        order:(DJXPlayletOrderType)order
                                      success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList))successHandler
                                      failure:(void (^)(NSError *error))failureHandler;

///* @abstract 根据搜索关键词获取列表 */
- (void)requestCategoryPlayletLisWithSearchWord:(NSString *)searchWord
                                        isFuzzy:(BOOL)isFuzzy
                                           page:(NSInteger)page
                                            num:(NSInteger)num
                                        success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList, BOOL hasMore))successHandler
                                        failure:(void (^)(NSError *error))failureHandler;

///* @abstract 短剧历史记录列表 */
- (void)requestPlayletHistoryListWithPage:(NSInteger)page
                                      num:(NSInteger)num
                                  success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList))successHandler
                                  failure:(void (^)(NSError *error))failureHandler;

///* @abstract 短剧历史记录清除 */
- (void)requestPlayletHistoryCleanWithCompletion:(void (^)(void))successHandler
                                         failure:(void (^)(NSError *error))failureHandler;

/// 点赞某一集短剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - episode_index: 第几集
///   - successHandler 成功回调
///   - failureHandler 失败回调
- (void)likeShortplay:(NSInteger)shortplay_id
        episode_index:(NSInteger)episode_index
              success:(void (^)(void))successHandler
              failure:(void (^)(NSError *error))failureHandler;

/// 取消点赞某一集短剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - episode_index: 第几集
///   - successHandler 成功回调
///   - failureHandler 失败回调
- (void)cancelLikeShortplay:(NSInteger)shortplay_id
              episode_index:(NSInteger)episode_index
                    success:(void (^)(void))successHandler
                    failure:(void (^)(NSError *error))failureHandler;

/// 收藏某部剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - successHandler 成功回调
///   - failureHandler 失败回调
- (void)collectShortplay:(NSInteger)shortplay_id
                 success:(void (^)(void))successHandler
                 failure:(void (^)(NSError *error))failureHandler;

/// 取消收藏某部剧
/// - Parameters:
///   - shortplay_id: 短剧id
///   - successHandler 成功回调
///   - failureHandler 失败回调
- (void)cancelCollectShortplay:(NSInteger)shortplay_id
                       success:(void (^)(void))successHandler
                       failure:(void (^)(NSError *error))failureHandler;

/// 请求搜藏列表
/// - Parameters:
///   - page: 第几页
///   - number: 一页多少个
///   - successHandler 成功回调
///   - failureHandler 失败回调
- (void)requestCollectionList:(NSInteger)pageIndex
                     pageSize:(NSInteger)pageSize
                      success:(void (^)(NSArray<DJXPlayletInfoModel *> *playletList, BOOL hasMore))successHandler
                      failure:(void (^)(NSError *error))failureHandler;

#pragma mark - 媒体埋点

/*! @abstract   发送事件埋点 */
- (void)trackEvent:(DJXPlayletTrackEvent)event withPlayletInfo:(DJXPlayletInfoModel *)playletInfo;

#pragma mark - 全局播放档位设置

///* @abstract 获取全局播放的倍速档位 */
- (CGFloat)globalPlaySpeed;
///* @abstract 设置全局播放的倍速档位（取值0<speed<=3, speed<=0时=1，speed>3时=3） */
- (void)setGlobalPlaySpeed:(CGFloat)speed;

@end

NS_ASSUME_NONNULL_END
