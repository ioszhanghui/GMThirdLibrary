//
//  DownLoadManger.h
//  GomePlus
//
//  Created by quyanhuiqu on 16/4/12.
//  Copyright © 2016年 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class Message;

typedef NS_ENUM(NSInteger,DownLoadType){
    DownLoadBigImage = 0,
    DownLoadVideo = 1,
    DownLoadOrigiImage = 2,
    DownLoadTypeVoice = 3,
    DownLoadTypeFile = 4
};
typedef void (^DownloadResponseBlock)(BOOL isSuccess,NSString*filePath,Message * msg,NSError *error);//成功失败,isSuccess true返回成功路径 isSuccess false 返回路径为空并返回错误error
@interface DownLoadManger : NSObject

+ (instancetype)sharedInstance;

/**
 *  下载资源管理
 *
 *  @param resourceType 下载类型
 *  @param msg          消息数据
 *  @param respones     返回数据
 */
- (void)downLoadResource:(DownLoadType)resourceType withMsg:(Message *)msg withResponseisSuccess:(DownloadResponseBlock)respones;
/**
 *  切换用户取消管理器
 */
- (void)changeUserCancelOperation;

/**
 *  下载小视频
 *
 *  @param msg      消息数据
 *  @param groupid  群组ID
 *  @param progressBlock 下载进度
 *  @param success  请求成功后的回调(小视频的路径)
 *  @param failure  请求失败后的回调
 */
- (void)downloadVideoWithMessage:(Message *)msg groupId:(NSString *)groupid progress:(void (^)(CGFloat progress))progressBlock success:(void (^)(NSString *filePath))success failure:(void (^)(NSError *error))failure;


/**
 下载大图

 @param message 消息
 @param completeBlock 完成block
 */
- (void)downLoadImage:(Message *)message completeBlock:(DownloadResponseBlock)completeBlock;

- (void)downloadVoiceWithUrl:(NSURL *)voiceUrl success:(void(^)(NSString *))success failure:(void(^)())failure;

@end
