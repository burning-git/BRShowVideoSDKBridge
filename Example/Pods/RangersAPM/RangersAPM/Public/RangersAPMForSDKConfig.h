//
//  RangersAPMForSDKConfig.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/3/9.
//

#import <Foundation/Foundation.h>
#import "RangersAPMAddressConfig.h"
#import "RangersAPMCommon.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPMForSDKConfig : NSObject

/*! @abstract The ID of your sdk that you registered from APMPlus.
 @discussion Nonnull & required.
 */
@property (atomic, copy) NSString *sdkID;

/*! @abstract The ID of your sdk's host app in your own account system if you have.
 @discussion We will show it on APMPlus for you, nullable & optional.
 */
@property (atomic, copy, nullable) NSString *hostAppID;

/*! @abstract The token of your app that you registered from APMPlus.
 @discussion Nonnull & require.
 */
@property (atomic, copy) NSString *sdkToken;

/*! @abstract Current version of your sdk
 @discussion Nonnull & required.
 */
@property (atomic, copy) NSString *sdkVersion;

/*! @abstract The channel where your SDK will be published.
 @discussion Nonnull & require. Default : "Other"
 */
@property (atomic, strong) NSString *channel;

/*!@abstract The source where we will get the device ID.
 @discussion Nonnull & require. Default : RAPMDeviceIDSourceFromAPMService
 */
@property (atomic, assign) RAPMDeviceIDSource deviceIDSource;

/*!@abstract The domain address where apm logs should be uploaded to.
 @discussion If you are using APMPlus Saas version, just ignore this.
 @discussion Set the domain with 'http://' or 'https://' to specify the scheme, else 'https://' is default.
 */
@property (nonatomic, copy, nullable) NSString *domain;

/*! @abstract The domain type SDK should choose.
 @discussion The default value is RangersAPMDomainTypeSingle, which means only one of the domain subspecs, such as CN/Global, should be added to your project.
 @discussion If you have to involve multiple domain subspecs, please set domainType to a specific value, such as RangersAPMDomainTypeCN by which the domain in CN subspec will be pick to upload logs.
 */
@property (nonatomic, assign) RangersAPMDomainType domainType;

/*!
 @abstract The address ranges of your sdk in the main mach-o.
 @discussion Only when the fault address is in the address ranges, we will upload the crash log. Nullable & optional.
 */
@property (atomic, strong, nullable) RangersAPMAddressConfig *addressConfig;

/*!
 @abstract The name of your SDK.
 @discussion Set this property with your SDK name. Nullable & optional.
 */
@property (atomic, copy) NSArray<NSString *> *libNames;

/*!
 @abstract Check extra top n non-system stacks of the crash thread to determine whether the SDK cause this crash.
 @discussion Default value 0, only the top non-system stack will be check.
 */
@property (nonatomic, assign) NSInteger extraTopAddresses;

/*!@abstract Custom filters for PV.
 @discussion Only valid for PV logs. Modifications after [RangersAPMForSDK initWithConfig:] may not take effect.
 */
@property (atomic, copy) NSDictionary<NSString *, NSString *> *PVFilters;


/*!@abstract To prohibit reporting PV.
 @discussion This property is used for a historical issue. You don't need to care about it unless under specific circumstances.
 */
@property (atomic, assign) BOOL prohibitReportingPV;

/**
 Initialize a config with appID.
 
 @param sdkID The ID of your sdk that you registered from APMPlus. Nonnull & require.
 @param sdkToken The token of your app that you  registered from APMPlus. Nonnull & require.
 @result A RangersAPMForSDKConfig instance.
 */
+ (instancetype)configWithSDKID:(NSString *)sdkID SDKToken:(NSString *)sdkToken;

+ (instancetype)configWithSDKID:(NSString *)sdkID __attribute__((deprecated("please use configWithSDKID:SDKToken:")));
- (id)init __attribute__((unavailable("please use configWithSDKID:SDKToken:")));
+ (instancetype)new __attribute__((unavailable("please use configWithSDKID:SDKToken:")));

@end

NS_ASSUME_NONNULL_END
