//
//  Message.h
//  GomePlus
//
//  Created by illScholar on 15/12/2.
//  Copyright © 2015年 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMEnum.h"
#import "IMMessageBody.h"
#import "IMMergeMessageBody.h"

@class ImMsg, GroupItem;

/**
 *	@brief	语音、图片、位置、视频 使用的附件类
 */
@interface MessageAttach : NSObject
/**
 *	@brief	附件id image、voice、position、video
 */
@property (nonatomic, copy) NSString *attachId;
/**
 *	@brief	附件类型 image、voice、position、video
 */
@property (nonatomic, assign) UInt32 attachType;
/**
 *	@brief	附件大小 image、voice、position、video
 */
@property (nonatomic, assign) UInt32 attachSize;
/**
 *	@brief	附件播放时长(秒) voice、video
 */
@property (nonatomic, assign) UInt32 attachPlayTime;
/**
 *	@brief	附件的状态 image、voice、position、video
 */
@property (nonatomic, assign) MsgAttachState attachStatus;
/**
 *	@brief  是否已读 只有voice
 */
@property (nonatomic, assign) BOOL attachIsRead;
/**
 *	@brief	附件名称 image、voice、position、video
 */
@property (nonatomic, copy) NSString *attachName;

/**
 本地存储路径(仅是文件名称)
 */
@property (nonatomic, copy) NSString *attachLocalPath;
/**
 *	@brief	附件地址的后缀 image、voice、position、video(第一帧的图片)
 */
@property (nonatomic, copy) NSString *attachUrl;
/**
 *	@brief  宽度 image、position
 */
@property (nonatomic) UInt32 attachWidth;
/**
 *	@brief  高度 image、position
 */
@property (nonatomic) UInt32 attachHeight;
/**
 *	@brief	经度 position
 */
@property (nonatomic, assign) double attachLongitude;
/**
 *	@brief	纬度 position
 */
@property (nonatomic, assign) double attachLatitude;
/**
 *	@brief	上传时间 image、voice、position、video
 */
@property (nonatomic, assign) SInt64 attachUploadtime;
/**
 *	@brief	position 地名
 */
@property (nonatomic, copy) NSString *attachContent;
/**
 *	@brief	是否为原图 image
 */
@property (nonatomic, assign) BOOL attachOrigiImg;
/**
 *	@brief	扩展 image、voice、position、video
 */
@property (nonatomic, copy) NSString *attachExtra;
/**
 *	@brief	针对语音是否正在播放
 */
@property (nonatomic) BOOL attachIsPlaying;
/**
 *	@brief	针对附件的上传下载进度
 */
@property (nonatomic, strong) NSNumber *attachProgress;

/**
 位置具体地址
 */
@property (nonatomic, copy) NSString *attachLocationDescribe;

/**
 *	@brief	初始化
 *
 *	@param 	type 	消息类型
 *	@param 	attachid 	附件id
 *	@param 	size 	附件大小
 *	@param 	playTime 	附件播放时长(秒)
 *	@param 	status 	附件的状态
 *	@param 	isRead 	针对语音是否已读
 *	@param 	name 	附件名称
 *	@param 	url 	附件地址
 *	@param 	width 	针对图片 宽
 *	@param 	height 	针对图片 高
 *	@param 	longitude 	经度
 *	@param 	latitude 	纬度
 *	@param 	uploadTime 	上传时间
 *	@param 	content 	内容
 *	@param 	origiImg 	是否原图
 *	@param 	extra 	扩展
 *
 *	@return	MessageAttach实例
 */
- (instancetype)initWithType:(MsgType)type
                    attachId:(NSString *)attachid
                  attachSize:(UInt32)size
              attachPlayTime:(UInt32)playTime
                attachStatus:(MsgAttachState)status
                attachIsRead:(BOOL)isRead
                  attachName:(NSString *)name
             attachLocalPath:(NSString *)localPath
                   attachUrl:(NSString *)url
                 attachWidth:(UInt32)width
                attachHeight:(UInt32)height
             attachLongitude:(double)longitude
              attachLatitude:(double)latitude
            attachUploadtime:(SInt64)uploadTime
               attachContent:(NSString *)content
              attachOrigiImg:(BOOL)origiImg
      attachLocationDescribe:(NSString *)attachLocationDescribe
                 attachExtra:(NSString *)extra;

#pragma mark -
#pragma mark MessageAttach 常用方法
/**
 *	@brief	获取小视频的地址
 *
 *	@return	NSString
 */
- (NSString *)attachVideoUrl;

/**
 *	@brief	获取图片的原图url,如果没有原图就返回大图url
 *
 *	@return	NSString
 */
- (NSString *)attachOrigiImgUrl;

/**
 *	@brief	获取附件下载url
 *
 *	@return	NSString
 */
- (NSString *)attachDownloadUrl;

/**
 *	@brief	获取图片的大图url
 *
 *	@return	NSString
 */
- (NSString *)attachBigImgUrl;

@end

/**
 *	@brief	红包消息（发送方）
 */
@interface IMRedEnvelopesMsg : NSObject <NSCopying,NSMutableCopying>
/**
 *	@brief	redEnvelopesId  红包id
 */
@property (nonatomic, copy) NSString *redEnvelopesId;
/**
 *	@brief	title  标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *	@brief  redEnvelopeType  红包类型，1:定额,2:拼手气
 */
@property (nonatomic, assign) RedEnvelopeType redEnvelopeType;
/**
 *	@brief	redEnvelopeCount  红包个数
 */
@property (nonatomic, assign) UInt32 redEnvelopeCount;
/**
 *	@brief	totalAmount  红包总金额
 */
@property (nonatomic, assign) Float64 totalAmount;
/**
 *	@brief	redEnvelopesExtra  红包消息扩展
 */
@property (nonatomic, copy) NSString *redEnvelopesExtra;

@end


/**
 *	@brief  红包提醒消息
 */
@interface IMRedEnvelNoticeMsg : NSObject <NSCopying,NSMutableCopying>
/**
 *	@brief	redEnvelopesId  红包id
 */
@property (nonatomic, copy) NSString *redEnvelopesId;
/**
 *	@brief	content  提示文案
 */
@property (nonatomic, copy) NSString *content;
/**
 *	@brief  redEnvelopeType  红包类型，1:定额,2:拼手气
 */
@property (nonatomic, assign) RedEnvelopeType redEnvelopeType;
/**
 *	@brief	amount  红包金额
 */
@property (nonatomic, assign) Float64 amount;
/**
 *	@brief	redEnvelUid  拆红包用户id
 */
@property (nonatomic, assign) UInt64 redEnvelUid;
/**
 *	@brief	redEnvelNoticeExtra  红包提醒扩展
 */
@property (nonatomic, copy) NSString *redEnvelNoticeExtra;
/**
 *	@brief	是否最后一个红包，0：还有红包；1：最后一个红包
 */
@property (nonatomic, assign) BOOL whetherEnd;

@end


/**
 *	@brief  推送数据体
 */
@interface IMPushDataMsg : NSObject <NSCopying,NSMutableCopying>
/**
 *	@brief	msgId  消息id
 */
@property (nonatomic, copy) NSString *msgId;
/**
 *	@brief	content  提示文案
 */
@property (nonatomic, copy) NSString *content;
/**
 *	@brief	title  标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *	@brief	activity  活动标语
 */
@property (nonatomic, copy) NSString *activity;
/**
 *	@brief	url  链接
 */
@property (nonatomic, copy) NSString *url;
/**
 *	@brief	pushDataExtra  推送扩展
 */
@property (nonatomic, copy) NSString *pushDataExtra;

/**
 *	@brief	初始化推送数据体
 *
 *	@param 	msgId 	        推送消息Id
 *	@param 	content         推送消息内容
 *	@param 	title 	        推送消息标题
 *	@param 	activity        推送活动标题
 *	@param 	url 	        推送活动链接
 *	@param 	pushDataExtra 	推送消息拓展
 *
 *	@return	IMPushDataMsg实例
 */
- (instancetype)initWithMsgId:(NSString *)msgId
                      content:(NSString *)content
                        title:(NSString *)title
                     activity:(NSString *)activity
                          url:(NSString *)url
                pushDataExtra:(NSString *)pushDataExtra;

@end


@interface Message : NSObject

/**
 *	@brief	消息id 唯一的uuid
 */
@property (nonatomic, copy) NSString *msgId;
/**
 *	@brief	消息类型；1:文本、2:语音、3:图片、4:视频、5:位置、6:附件等 默认为MsgTypeText消息
 */
@property (nonatomic, assign) MsgType msgType;
/**
 *	@brief	消息内容
 */
@property (nonatomic, copy) NSString *msgBody;
/**
 *	@brief	消息发送者id
 */
@property (nonatomic) SInt64 senderId;
/**
 *	@brief	消息发送者名字
 */
@property (nonatomic, copy) NSString *senderName;
/**
 *	@brief	消息发送者在该群中的昵称
 */
@property (nonatomic, copy) NSString *senderRemark;
/**
 *	@brief	群组id
 */
@property (nonatomic, copy) NSString *groupId;
/**
 *	@brief	群组类型 1:单聊、2:群聊等 5为客服默认为ChatTypeSingle
 */
@property (nonatomic) ChatType groupType;
/**
 群组聊天类型
 */
@property (nonatomic, assign) int groupChatType;
/**
 *	@brief	群聊名字
 */
@property (nonatomic, copy) NSString *groupName;
/**
 *	@brief	发送时间
 */
@property (nonatomic) SInt64 sendTime;
/**
 *	@brief	消息seq id
 */
@property (nonatomic) SInt64 msgSeqId;
/**
 *	@brief	消息url
 */
@property (nonatomic, copy) NSString *msgUrl;
/**
 *	@brief	消息读取状态
 */
@property (nonatomic, assign) BOOL msgIsRead;
/**
 *	@brief	消息发送状态  eg；发送 下载相关状态 默认为MsgStatePending
 */
@property (nonatomic) MsgState msgStatus;
/**
 *	@brief	消息删除状态
 */
@property (nonatomic, assign) BOOL msgIsDelete;
/**
 *	@brief	消息扩展
 */
@property (nonatomic, copy) NSString *extra;
/**
 *	@brief	消息状态 ，撤回、删除
 */
@property (nonatomic, assign) MsgFunctionState status;
/**
 *	@brief	语音、图片、位置、视频
 */
@property (nonatomic, strong) MessageAttach *msgAttach;
/**
 *	@brief	@用户的  imUserId 的集合
 */
@property (nonatomic, strong) NSMutableArray *atUidList;
/**
 *	@brief	客服系统专用字段 客服编号(9999999999，999999997)
 */
@property (nonatomic, assign) UInt64 customerId;

/**SDK内部使用标记*/
@property (nonatomic, assign) UInt32 msgFuncTag;

/**
 *	@brief	是否是悄悄话
 */
@property (nonatomic, assign) BOOL isWhispered;
/**
 *	@brief	是否隐藏
 */
@property (nonatomic, assign) BOOL whetherHide;
/**
 *	@brief	是否不计数
 */
@property (nonatomic, assign) BOOL whetherNonCount;
/**
 *	@brief	是否不push
 */
@property (nonatomic, assign) BOOL whetherNonPush;
/**
 *	@brief  红包消息
 */
@property (nonatomic, strong) IMRedEnvelopesMsg *redEnvelopesMsg;
/**
 *	@brief  拆红包通知发红包者消息
 */
@property (nonatomic, strong) IMRedEnvelNoticeMsg *redEnvelNoticeMsg;
/**
 *	@brief  推送数据体
 */
@property (nonatomic, strong) IMPushDataMsg *pushData;

/***** 定制字段 **********/
/**
 *	@brief	定制字段 消息触发者类型
 */
@property (nonatomic, copy) NSString *msgProperty;
/**
 *	@brief	定制字段 消息模板类型
 */
@property (nonatomic, copy) NSString *msgTempletType;
/**
 *	@brief	定制字段 消息提示语
 */
@property (nonatomic, copy) NSString *errorMsgCode;
/**
 *	@brief	定制字段 消息的UI高度
 */
@property (nonatomic, assign) double msgHeight;

@property (nonatomic, strong) IMMessageBody *body;
//数据来源，0：聊天；1：文章
@property (nonatomic, assign) UInt32 sourceType;
/**
 父类会话ID
 */
@property (nonatomic, assign) SInt64 pId;

//渠道商ID
@property (nonatomic,copy) NSString *channelId;

//平台ID
@property (nonatomic,copy) NSString *platformId;

//店铺id，无店铺id为自营（我）客服
@property (nonatomic,copy) NSString *shopId;
/***** 定制字段 **********/

#pragma mark -
#pragma mark Message 常用方法
/**
 *	@brief	获取单聊对方UserId
 *
 *	@return	NSString 单聊：对方Uid，群聊：群Id
 */
- (NSString *)getOtherUserId;

/**
 *	@brief	通过单聊的 groupId 获取对方的userID
 *
 *	@param 	groupId 	单聊的 groupId
 *	@return	SInt64    对方的userID
 */
+ (SInt64)getOtherUserIdFromGrouId:(NSString *)groupId;

#pragma mark -
#pragma mark Message 构造方法
/**
 *	@brief  构造文本Message
 *
 *  @param content 文本内容
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initTextMessageWithContent:(NSString *)content groupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造文本Message
 *
 *  @param content 文本内容
 *  @param groupItem 群组对象
 *  @param extraDict 拓展字典
 *
 *  @return message
 */
- (instancetype)initTextMessageWithContent:(NSString *)content groupItem:(GroupItem *)groupItem andExtra:(NSDictionary *)extraDict;

/**
 *	@brief  构造离线文件Message
 *
 *  @param filePath 要上传的文件路径
 *  @param groupItem 群组对象
 *  @param isOtherApp 是否其他应用
 *
 *  @return message
 */
- (instancetype)initFileMessageWithFilePath:(NSString *)filePath groupItem:(GroupItem *)groupItem isOtherApp:(BOOL)isOtherApp;

/**
 *	@brief  构造转发Message
 *
 *  @param oldMessage 被转发的消息
 *  @param groupItem 转发到的群组对象
 *
 *  @return message
 */
- (instancetype)initMessageWithOldMessage:(Message *)oldMessage groupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造文本Message
 *
 *  @param text 文本内容
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initTextMessage:(NSString *)text
                      withGroupItem:(GroupItem *)groupItem;

/**
 *	@brief  @所有人Message
 *
 *  @param text 文本内容
 *  @param groupItem 群聊对象
 *
 *  @return message
 */
- (instancetype)initAtAllMessage:(NSString *)text
                  withGroupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造图片Message
 *
 *  @param imageData 图片二进制数据
 *  @param isSource 是否原图
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initImageMessage:(NSData *)imageData
                        isSource:(BOOL)isSource
                   withGroupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造位置Message
 *
 *  @param latitude 纬度
 *  @param longitude 经度
 *  @param address 位置名称
 *  @param image 位置截图
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initLocationMessageWithLatitude:(double)latitude
                                      longitude:(double)longitude
                                     andAddress:(NSString *)address
                                          Image:(UIImage *)image
                                      groupItem:(GroupItem *)groupItem;

- (instancetype)initLocationMessageWithLatitude:(double)latitude
                                      longitude:(double)longitude
                                     andAddress:(NSString *)address
                                       describe:(NSString *)describe
                                          Image:(UIImage *)image
                                      groupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造视频Message
 *
 *  @param fileUrl 资源路径
 *  @param groupItem 群组对象
 *  @param deleteSource 是否删除原数据
 *
 *  @return message
 */
- (instancetype)initVideoWithFileUrl:(NSURL *)fileUrl
                           groupItem:(GroupItem *)groupItem
                        deleteSource:(BOOL)deleteSource;

/**
 *	@brief  构造需要转发的视频Message
 *
 *  @param fileUrl 资源路径（如果有）
 *  @param attachUrl 视频在服务器的名称
 *  @param attachPlayTime 播放时长
 *  @param groupItem 群组对象
 *  @param deleteSource 是否删除原数据
 *
 *  @return message
 */
- (instancetype)initVideoWithFileUrl:(NSURL *)fileUrl
                           AttachUrl:(NSString *)attachUrl
                      attachPlayTime:(UInt32)attachPlayTime
                           groupItem:(GroupItem *)groupItem
                        deleteSource:(BOOL)deleteSource;

/**
 *	@brief  构造语音Message
 *
 *  @param url 资源路径
 *  @param size 资源大小
 *  @param playtime 时长
 *  @param attachID 附件标示
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initVoiceWithUrl:(NSString *)url
                            size:(UInt32)size
                        playTime:(UInt32)playtime
                        attachID:(NSString *)attachID
                       groupItem:(GroupItem *)groupItem;

/**
 *	@brief  构造红包Message
 *
 *  @param redEnvelopesId 红包id
 *  @param redEnvelopeType 红包类型
 *  @param title 标题
 *  @param redEnvelopeCount 红包个数
 *  @param totalAmount 总金额，单位元
 *  @param redEnvelopesExtra 扩展
 *  @param groupItem 群组对象
 *
 *  @return message
 */
- (instancetype)initRedEnvelopesWithRedEnvelopesId:(NSString *)redEnvelopesId
                                   redEnvelopeType:(RedEnvelopeType)redEnvelopeType
                                             title:(NSString *)title
                                  redEnvelopeCount:(UInt32)redEnvelopeCount
                                       totalAmount:(Float64)totalAmount
                                 redEnvelopesExtra:(NSString *)redEnvelopesExtra
                                         groupItem:(GroupItem *)groupItem;


/**
 构造合并消息

 @param body 消息体
 @param groupItem groupItem
 @param extra 扩展
 @return Message 对象
 */
- (instancetype)initMergeMessageWithBody:(IMMergeMessageBody *)body
                               groupItem:(GroupItem *)groupItem
                                   extra:(NSString *)extra;

#pragma mark 转发消息构造

/**
 构造图片消息

 @param imageUrl 图片URL
 @param groupItem groupItem
 @return 消息对象
 */
- (instancetype)initImageMessageWithUrl:(NSString *)imageUrl
                              groupItem:(GroupItem *)groupItem;


/**
 构造视频消息

 @param videoUrl URL
 @param videoPlayTime 播放时长
 @param groupItem groupItem
 @return 消息对象
 */
- (instancetype)initVideoMessageWithUrl:(NSString *)videoUrl
                          videoPlayTime:(UInt32)videoPlayTime
                              groupItem:(GroupItem *)groupItem;


/**
 构造语音消息

 @param voiceUrl URL
 @param sourcePlayTime 播放时长
 @param groupItem groupItem
 @return 消息对象
 */
- (instancetype)initVoiceMessageWithUrl:(NSString *)voiceUrl
                         sourcePlayTime:(UInt32)sourcePlayTime
                              groupItem:(GroupItem *)groupItem;


/**
 构造位置消息

 @param title 标题
 @param desc 位置描述
 @param latitude 维度
 @param longitude 经度
 @param groupItem groupItem
 @return 消息对象
 */
- (instancetype)initPositionMessageWithTitle:(NSString *)title
                                        desc:(NSString *)desc
                                    latitude:(double)latitude
                                   longitude:(double)longitude
                                   groupItem:(GroupItem *)groupItem;


/**
 构造文件消息

 @param attachId 文件标识
 @param fileName 文件名
 @param sourceSize 文件大小
 @param groupItem groupItem
 @return 消息对象
 */
- (instancetype)initFileMessageWithAttachId:(NSString *)attachId
                                   fileName:(NSString *)fileName
                                 sourceSize:(UInt32)sourceSize
                                  groupItem:(GroupItem *)groupItem;

@end
