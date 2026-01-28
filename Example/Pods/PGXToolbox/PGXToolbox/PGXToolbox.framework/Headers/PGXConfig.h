//
//  PGXConfig.h
//  PGXToolbox
//
//  Created by ByteDance on 2024/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DJXSDKLogLevel) {
    DJXSDKLogLevelNone  = 0,   // 不打印
    DJXSDKLogLevelDebug = 1    // 控制台打印日志
};

typedef NS_OPTIONS(NSUInteger, DJXToastMessageType) {
    DJXToastMessageType_NetworkError = 1 << 0,
    DJXToastMessageType_Other = 1 << 1
};

@protocol DJXAuthorityConfigDelegate <NSObject>
@optional
/// 是否打开青少年模式，默认不打开
- (BOOL)turnOnTeenMode;

/// 是否允许获取idfa
- (BOOL)allowAccessIDFA;

@end

@interface PGXConfig : NSObject

/*! @abstract 是否禁用AB测试，默认为NO不禁用
*/
@property (nonatomic, assign) BOOL disableABTest;

/*! @abstract 控制台是否打印日志。release版本请设置为NO */
@property (nonatomic, assign) DJXSDKLogLevel logLevel;

/*! @abstract 传过来的用户内容类型偏好，并做为首次展示内容兴趣类型，从接入文档查看对应兴趣类型传入 */
@property (nonatomic, assign) int interestType;

/*! @abstract 传入媒体新手保护设置的参数，isNewUser 媒体对当前是否是新用户的判断;   aliveSeconds媒体设置新用户保护的时间，单位秒*/
@property (nonatomic, assign) BOOL isNewUser;
@property (nonatomic, assign) int aliveSeconds;

/*! @abstract 自定义toast提示，若为nil则使用SDK默认的toast
 containerView: toast将要展示在哪个view上
 message: toast的内容
 *stillShowDJXToast(注意，这里是一个指针)，是否需要展示内容合作SDK的toast，默认 *stillShowDJXToast为 NO
 */
@property (nonatomic, copy) void(^ _Nullable customShowToastBlock)(UIView *containerView, NSString *message, BOOL *stillShowDJXToast);
/*!
 隐藏指定类型的toast
 */
@property (nonatomic, assign) DJXToastMessageType hideToastType;
/*! @abstract 权限控制相关的代理 */
@property (nonatomic, weak) id<DJXAuthorityConfigDelegate> authorityDelegate;

/*! @abstract 默认为NO，DJXSDK内部会在AVAudioSession.category为默认值AVAudioSessionCategorySoloAmbient时，
 将category修改为AVAudioSessionCategoryPlayback，以保证手机静音开关打开时可以播放视频声音。
 若修改为YES，则DJXSDK不再修改AVAudioSession.category默认值 */
@property (nonatomic, assign) BOOL customAudioSession;

@end

NS_ASSUME_NONNULL_END
