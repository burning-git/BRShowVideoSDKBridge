//
//  RangersAPMCommon.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/4/11.
//

#ifndef RangersAPMCommon_h
#define RangersAPMCommon_h

/**
 The source where we will get the device ID.
 */
typedef NS_ENUM(NSInteger, RAPMDeviceIDSource){
    /**
     From RangersApplog. If the RangersAppLog SDK is not included, an assertion will be triggered.
     */
    RAPMDeviceIDSourceFromRAppLog = 0,
    /**
     From user. You can call [RangersAPM setDeviceID:] to set the device ID later. If the device ID has not been set when we upload logs, you may not search these logs by device ID.
     */
    RAPMDeviceIDSourceFromUser = 1,
    /**
     From APMService. We will register the device by our service and set the device ID.
     */
    RAPMDeviceIDSourceFromAPMService = 2
};

/**
 The domain type SDK should choose.
 */
typedef enum {
    /**
     Only one of the domian subspecs should be involved.
     */
    RangersAPMDomainTypeSingle,
    /**
     No need for any domain subspec.
     ⚠️ You must set config.domain as your own host which is necessary to avoid exceptions.
     */
    RangersAPMDomainTypePrivate,
    /**
     Muiltiple domain subspecs can be involved, and use CN.
     ⚠️ The config.domain you set will be ignored.
     */
    RangersAPMDomainTypeCN,
    /**
     Muiltiple domain subspecs can be involved, and use Global.
     ⚠️ The config.domain you set will be ignored.
     */
    RangersAPMDomainTypeGlobal,
    /**
     Muiltiple domain subspecs can be involved, and use BytePlus.
     ⚠️ The config.domain you set will be ignored.
     */
    RangersAPMDomainTypeBytePlus
    
} RangersAPMDomainType;

#endif /* RangersAPMCommon_h */
