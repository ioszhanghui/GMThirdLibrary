//
//  GMFileTransferManager.h
//  GMFileTransfer
//
//  Created by onpalm on 11/13/16.
//  Copyright © 2016 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GMFileTransferManagerDelegate <NSObject>

-(void)didUploadNetworkIsNotWifi;

@end

@interface GMFileTransferManager : NSObject

@property(nonatomic,weak) id<GMFileTransferManagerDelegate> delegate;

+ (GMFileTransferManager *)sharedInstance;


/**
 大文件上传

 @param path 要上传的文件路径
 @param aProgressCompletion 上传进度
 @param completeBlock 完成block
 */
-(void)uploadFile:(NSString *)path traceId:(NSString *)traceId progress:(void (^)(float progress))aProgressCompletion completeBlock:(void(^)(NSString *hashValue,NSError *error))completeBlock;


/**
 大文件下载

 @param downloadPath 下载后的文件路径
 @param hashValue 要下载文件的标识
 @param aProgressCompletion 下载进度
 @param completeBlock 完成block
 */
-(void)downloadFile:(NSString *)downloadPath traceId:(NSString *)traceId hashValue:(NSString *)hashValue progress:(void (^)(float progress))aProgressCompletion completeBlock:(void(^)(NSString *hashValue,NSError *error))completeBlock;

-(void)cancel:(NSString *)traceId;


/**
 查询文件进度

 @param traceId 上传
 @return float
 */
-(float)queryProgress:(NSString *)traceId;


/**
 是否继续

 @param isContinue 是否继续
 */
-(void)clickContinue:(BOOL)isContinue;
@end
