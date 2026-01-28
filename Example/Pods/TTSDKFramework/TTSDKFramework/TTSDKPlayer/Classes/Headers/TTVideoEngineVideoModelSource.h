//
//  TTVideoEngineVideoModelSource.h
//  TTVideoEngine
//
//  Created by sjc on 6.2.23.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"
#import "TTVideoEngineModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngineVideoModelSource : NSObject <TTVideoEngineMediaSource>

/// video id
@property (nonatomic, copy) NSString *vid;

/// resolution type
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;

@property (nonatomic, strong) TTVideoEngineModel *videoModel;

- (instancetype)initWithVid:(NSString *)vid resolution:(TTVideoEngineResolutionType)resolution;

@end

NS_ASSUME_NONNULL_END
