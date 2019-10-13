//
//  IMMessageManager+Attachment.h
//  GMIMOriginalSDK
//
//  Created by IM-ios on 2017/9/7.
//  Copyright © 2017年 IMDevelop. All rights reserved.
//

#import "IMMessageManager.h"

@interface IMMessageManager (Attachment)

#pragma mark - 附件拷贝、移动

/**
 附件是否存在

 @param attach MessageAttach
 @param groupId groupId
 @return success
 */
- (BOOL)attachExistWithAttach:(MessageAttach *)attach groupId:(NSString *)groupId;


/**
 拷贝附件

 @param attach MessageAttach
 @param fromGroupId 从哪个groupId
 @param toGroupId 到哪个groupId
 @return success
 */
- (BOOL)copyAttach:(MessageAttach *)attach fromGroupId:(NSString *)fromGroupId ToGroupId:(NSString *)toGroupId;

- (BOOL)copyAttach:(MessageAttach *)attach newAttach:(MessageAttach *)newAttach fromGroupId:(NSString *)fromGroupId ToGroupId:(NSString *)toGroupId;

/**
 移动附件

 @param attach MessageAttach
 @param fromGroupId 从哪个groupId
 @param toGroupId 到哪个groupId
 @return success
 */
- (BOOL)moveAttach:(MessageAttach *)attach fromGroupId:(NSString *)fromGroupId ToGroupId:(NSString *)toGroupId;

- (BOOL)moveAttach:(MessageAttach *)attach newAttach:(MessageAttach *)newAttach fromGroupId:(NSString *)fromGroupId ToGroupId:(NSString *)toGroupId;

#pragma mark - 文件下载上传操作
/**
 *	@brief  取消大文件下载
 *
 *  @param  message 文件消息
 *
 */
-(void)cancelDownload:(Message *)message;


/**
 暂停下载

 @param traceId traceId
 */
- (void)cancelDownloadWithTraceId:(NSString *)traceId;

/**
 *	@brief  取消大文件上传
 *
 *  @param  message 文件消息
 *
 */
-(void)cancelUpload:(Message *)message;

/**
 *  @brief  是否继续上传、下载(网络切换后的弹窗后操作)
 *
 *  @param isContinue 是否继续
 */
-(void)continueUpload:(BOOL)isContinue;

/**
 *  @brief  查询当前上传、下载文件的进度
 *
 *  @param  message  文件消息
 *
 *  @return  进度progress
 */
-(float)queryProgress:(Message *)message;


#pragma mark - image message//消息中图片的处理
/**
 *	@brief	返回消息附件的存储路径 如果不存在创建
 *
 *	@param 	groupId 	群id
 *
 *	@return	 file path 绝对路径
 */
- (NSString *)filePathForMsgAttachWithGroupId:(NSString *)groupId;

/**
 *	@brief	根据图片的uuid、所在群id获取图片存储的整个绝对路径(包含图片的名字)
 *
 *	@param 	uuid 	图片的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 file path 绝对路径
 */
- (NSString *)imagePathWithUUID:(NSString *)uuid
                        groupId:(NSString *)groupId;

/**
 *	@brief	大图图路径（新
 *
 *	@param 	attachName 	attachName
 *	@param 	groupId 	群id
 *
 *	@return	 path
 */
- (NSString *)imagePathWithAttachName:(NSString *)attachName
                              groupId:(NSString *)groupId;

/**
 *	@brief	根据图片的uuid、所在群id，保存图片数据
 *
 *	@param 	data 	图片的data数据
 *	@param 	uuid 	图片的uuid
 *	@param 	groupId 	群id
 *
 */
- (void)saveImageData:(NSData *)data
                 uuid:(NSString *)uuid
              groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid、所在群id 判断图片是否存在
 *
 *	@param 	uuid 	图片的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 BOOL YES 存在，NO 不存在
 */
- (BOOL)imageExistsAtPathWithUUID:(NSString *)uuid
                          groupId:(NSString *)groupId;

/**
 *	@brief	根据attachName、所在群id 判断图片是否存在
 *
 *	@param 	attachName 	图片的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 BOOL YES 存在，NO 不存在
 */
- (BOOL)imageExistsAtPathWithAttachName:(NSString *)attachName
                                groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid生成jpg格式的名字
 *
 *	@param 	uuid 	图片的uuid
 *
 *	@return	 图片的名字 eg:uuid.JPG
 */
- (NSString *)imageNameForJPGWithUUID:(NSString *)uuid;

/**
 *	@brief	根据图片的uuid、所在群id，获取缩略图存储的整个绝对路径(包含缩略图的名字)
 *
 *	@param 	uuid 	缩略图的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 file path 缩略图的路径
 */
- (NSString *)thumbnailImagePathWithUUID:(NSString *)uuid
                                 groupId:(NSString *)groupId;

/**
 *	@brief	缩略图路径（新）
 *
 *	@param 	attachName 	attachName
 *	@param 	groupId 	群id
 *
 *	@return	 path
 */
- (NSString *)thumbnailImagePathWithAttachName:(NSString *)attachName
                                       groupId:(NSString *)groupId;

/**
 *	@brief	根据图片的uuid、所在群id，保存缩略图数据
 *
 *	@param 	data 	缩略图的data数据
 *	@param 	uuid 	缩略图的uuid
 *	@param 	groupId 	群id
 *
 */
- (void)saveThumbnailImageData:(NSData *)data
                          uuid:(NSString *)uuid
                       groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid、所在群id 判断缩略图是否存在
 *
 *	@param 	uuid 	缩略图的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 BOOL YES 存在，NO 不存在
 */
- (BOOL)thumbnailImageExistsAtPathWithUUID:(NSString *)uuid
                                   groupId:(NSString *)groupId;

/**
 *	@brief	判断是否有缩略图（新）
 *
 *	@param 	attachName 	附件名字
 *	@param 	groupId 	群id
 *
 *	@return  BOOL YES 存在，NO 不存在
 */
- (BOOL)thumbnailImageExistsAtPathWithAttachName:(NSString *)attachName
                                         groupId:(NSString *)groupId;

/**
 *	@brief	移除图片的JPG后缀
 *
 *	@param 	name 	图片的名字
 *
 *	@return	 图片的uuid
 */
- (NSString *)removeImageSuffixWithName:(NSString *)name;


#pragma mark - voice message//消息中语音的处理
/**
 *	@brief	根据语音uuid、所在群id，获取语音类消息存储的路径
 *
 *	@param 	uuid 	语音uuid
 *	@param 	groupId 	群id
 *
 *	@return	 file path
 */
- (NSString *)voicePathWithUUID:(NSString *)uuid
                        groupId:(NSString *)groupId;

/**
 *	@brief	根据语音消息的名字、所在群id，获取语音类消息存储的路径
 *
 *	@param 	name 	语音的名字
 *	@param 	groupId 	群id
 *
 *	@return	 file path
 */
- (NSString *)voicePathWithName:(NSString *)name
                        groupId:(NSString *)groupId;

/**
 *	@brief	根据语音uuid、所在群id，判断语音消息是否存在
 *
 *	@param 	uuid 	语音uuid
 *	@param 	groupId 	群id
 *
 *	@return	 YES 存在，NO 不存在
 */
- (BOOL)voiceExistsAtPathWithUUID:(NSString *)uuid
                          groupId:(NSString *)groupId;

/**
 *	@brief	根据语音uuid、所在群id，生成语音的名字
 *
 *	@param 	uuid 	语音uuid
 *
 *	@return	 语音的名字 eg:uuid.AMR
 */
- (NSString *)voiceNameForAMRWithUUID:(NSString *)uuid;


#pragma mark - Position message//消息中位置的处理
/**
 *	@brief	根据位置图片uuid、所在群id，获取位置类消息存储的路径
 *
 *	@param 	uuid 	位置uuid
 *	@param 	groupId 	群id
 *
 *	@return	 file path
 */
- (NSString *)positionPathWithUUID:(NSString *)uuid
                           groupId:(NSString *)groupId;

/**
 *	@brief	根据位置图片uuid、所在群id，保存位置类图片数据
 *
 *	@param 	data 	图片的data数据
 *	@param 	uuid 	图片的uuid
 *	@param 	groupId 	群id
 *
 */
- (void)savePositionData:(NSData *)data
                    uuid:(NSString *)uuid
                 groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid生成jpg格式的名字
 *
 *	@param 	uuid 	图片的uuid
 *
 *	@return  位置图片的名字 eg:uuid.JPG
 */
- (NSString *)positionNameForJPGWithUUID:(NSString *)uuid;

/**
 *  @brief  根据uuid 判断位置图片是否存在
 *
 *  @param  uuid   图片的uuid
 *	@param 	groupId 	群id
 *
 *  @return  是否存在
 */
- (BOOL)positionExistsAtPathWithUUID:(NSString *)uuid
                             groupId:(NSString *)groupId;


#pragma mark - video message//消息中视频的处理
/**
 *	@brief	根据uuid、所在群id，获取视频消息第一帧图片存储的绝对路径
 *
 *	@param 	uuid 	视频图片的uuid
 *	@param 	groupId 	群id
 *
 *	@return	 file path 视频第一帧图片的路径
 */
- (NSString *)videoImagePathWithUUID:(NSString *)uuid
                             groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid、所在群id，保存视频类消息第一帧图片
 *
 *	@param 	data 	图片的data
 *	@param 	uuid 	图片的uuid
 *	@param 	groupId 	群id
 *
 */
- (void)saveVideoImageData:(NSData *)data
                      uuid:(NSString *)uuid
                   groupId:(NSString *)groupId;

/**
 *	@brief	根据uuid、所在群id，得到视频第一帧图片的名字
 *
 *	@param 	uuid 	视频的uuid
 *
 *	@return	 视频第一帧图片的名字
 */
- (NSString *)videoImageNameForJPGWithUUID:(NSString *)uuid;

/**
 *	@brief	根据uuid 得到视频的名字
 *
 *	@param 	uuid 	视频的uuid
 *
 *	@return	 视频的名字
 */
- (NSString *)videoNameForJPGWithUUID:(NSString *)uuid;

/**
 *	@brief	保存视频数据
 *
 *	@param 	uuid 	视频uuid
 *	@param 	groupId 	群id
 *
 *	@return	 视频路径
 */
- (NSString *)videoPathWithUUID:(NSString *)uuid
                        groupId:(NSString *)groupId;

/**
 *  @brief  根据uid 判断视频图片是否存在
 *
 *  @param  uuid uid
 *	@param 	groupId 	群id
 *
 *  @return  bool
 */
- (BOOL)videoImageExistsAtPathWithUUID:(NSString *)uuid
                               groupId:(NSString *)groupId;

/**
 *  @brief  根据uid 判断视频是否存在
 *
 *  @param  uuid uid
 *	@param 	groupId 	群id
 *
 *  @return  bool
 */
- (BOOL)videoExistAtPathWithUUID:(NSString *)uuid
                         groupId:(NSString *)groupId;

/**
 *  @brief  获取下载路径 具体是指：图片的大图、原图、视频的路径
 *
 *  @param  groupId 	群id
 *  @param  fileName 文件名称
 *
 *  @return  NSString 绝对路径
 */
- (NSString *)downloadFilePathWithGroupId:(NSString *)groupId
                           sourceFileName:(NSString *)fileName;


/**
 收藏目录

 @return 全路径
 */
- (NSString *)collectFilePath;

@end
