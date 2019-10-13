//
//  IMMessageManager.h
//  GomePlus
//
//  Created by illScholar on 15/12/15.
//  Copyright © 2015年 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IMMessageDelegate.h"
#import "Reachability.h"

@class GMMemoryCache;
@class ImGroup;
@class GMIMNetwrokQueue;
@class ImSubMsg;

typedef NS_ENUM(NSInteger, LogsLevel) {
    /**
     *	@brief	不输出 默认
     */
    LogsLevelNone,
    /**
     *	@brief	低级
     */
    LogsLevelLow,
    /**
     *	@brief	高级
     */
    LogsLevelHigh
};

typedef NS_ENUM(NSInteger, GroupMemberStaus){
    GroupMemberDelete,
    GroupMemberAdd
};

/** 群组列表变更通知 */
UIKIT_EXTERN NSString * const ListGroupChangedNotification;


@class ImMsg;
@class Message;
@class GroupItem;

@interface IMMessageManager : NSObject{
    dispatch_queue_t callBackQueue;
    dispatch_queue_t sendMessageQueue;
    dispatch_queue_t receiveMessageQueue;
    dispatch_queue_t DBQueue;
    dispatch_queue_t initDBQueue;
    dispatch_queue_t imSafeQueue;
    NSTimer *timerRevokeTimeout;
    __weak id<GMIncomingMessageListener> _incomingMessgageListener;
}
/**
  *	@brief  跟SDK绑定的app id
  */
@property (nonatomic, copy) NSString *imAppId;
/**
 *	@brief  服务端分配的im userid 需要第三方设置
 */
@property (nonatomic, assign) SInt64 imUserId;
@property (nonatomic, copy) NSString *imToken;
@property (nonatomic, assign) NetworkStatus status;

//是否关闭客服模块
@property (nonatomic, assign) BOOL customerServiceOff;
/**
 *	@brief  log级别 默认不输出
 */
@property (nonatomic, assign) LogsLevel logsLevel;

/**
 *	@brief	IM服务器的主机域名
 */
@property (nonatomic, readonly) NSString *hostURL;
@property (nonatomic, strong) GMMemoryCache *imConversationDict;
/**
 *	@brief  代理集合
 */
@property (nonatomic, strong) NSMutableSet *delegates;
//// 是否拉下来会话列表
@property (nonatomic, assign) BOOL isPullList;
@property (nonatomic, assign) IMMessageState state;
@property (nonatomic, assign) SInt64 updateTime;
//@property (nonatomic, strong) GMIMNetwrokQueue *networkQueue;
@property (nonatomic, strong) GMMemoryCache *imSubConversationDict;

@property (nonatomic, strong) GMMemoryCache *imCustomerConversationDict;
+ (instancetype)sharedInstance;


-(void) setIncomingMessageListener:(id<GMIncomingMessageListener>) listener;
/**
 *	@brief	添加IMMessageDelegate代理
 *
 *	@param 	delegate 	将要实现IMMessageDelegate的
 *
 */
- (void)addIMDelegate:(id<IMMessageDelegate>)delegate;
/**
 *	@brief	移除IMMessageDelegate代理
 *
 *	@param 	delegate 	已经实现IMMessageDelegate的 注意:不能传nil
 *
 */
- (void)removeIMDelegate:(id<IMMessageDelegate>)delegate;

- (NSString *)downloadFileUrl;

#pragma mark -
#pragma mark client
/**
 *	@brief	设定相关参数，执行启动socket，并开始用户登录
 *
 *	@param 	apnsToken 	用户推送的设备apns token
 *	@param 	imUserID 	im服务器分配的userid
 *	@param 	userNickName	im服务器分配的userNickName
 *  @param  token   im服务端分配的token
 *	@param 	appID 	im服务端分配的应用id
 *	@param 	url 	im服务器的主机域名
 *  @param  isAutoLogin 是否是自动登录
 *
 */
- (void)executeStartUpClient:(NSString *)apnsToken
                      userID:(SInt64)imUserID
                userNickName:(NSString *)userNickName
                       token:(NSString *)token
                       appID:(NSString *)appID
                     hostURL:(NSString *)url
                 isAutoLogin:(BOOL)isAutoLogin;

/**
 *  @brief  上传 pushtoken
 *
 *  @param  pushToken  pushToken
 *  @param  completeBlock  block 回调
 *
 */
- (void)uploadPushToken:(NSString *)pushToken
          completeBlock:(void (^)(BOOL success))completeBlock;

/**
 *  @brief  修改用户的昵称
 *
 *  @param  newUserNickName   新昵称
 *
 */
- (void)changeUserNickName:(NSString *)newUserNickName;

/**
 *	@brief	执行用户登出，关闭socket 切换用户时候使用
 *
 *	@return	 BOOL YES，发出命令成功 NO，发出命令失败
 */
- (BOOL)executeUserLogout;

/**
 *	@brief	返回im client的状态
 *
 *	@return	 IMClientState
 */
+ (IMClientState)clientState;

/**
 *	@brief	返回离线消息的状态
 *
 *	@return	 IMClientState
 */
+ (IMMessageState)messageState;


#pragma mark - 会话相关方法(GroupItem)
/**
 *	@brief	返回当前会话列表中的数据
 */
- (NSArray *)conversationListFromImConversationDict;

/**
 *	@brief	根据groupId 获取会话列表中的单条会话数据
 *
 *	@param 	groupId 	群id
 *
 *	@return	 GroupItem
 */
- (GroupItem *)groupItemFromImConversationDictWithGroupId:(NSString *)groupId;


- (GroupItem *)updateGroupItem:(GroupItem *)groupItem withisQuit:(BOOL)isQuit;


/**
 *  @brief  删除会话操作方法
 *
 *  @param  aItem 会话模型数据
 *
 */
- (void)deleteConversionWithGroupItem:(GroupItem *)aItem;

/**
 *  @brief  群组添加删除成员
 *
 *  @param  groupId    群id
 *  @param  meberStaus  删除或添加
 *  @param  isChatGroup  是否是群组
 *
 */
- (void)deleteOrAddGroupMemberWithGroupId:(NSString *)groupId
                     withGroupMemberStaus:(GroupMemberStaus)meberStaus
                              isChatGroup:(BOOL)isChatGroup;

/**
 *	@brief	获取在某个群最后一条消息
 *
 *	@param 	groupId 	群id
 *
 *	@return	 Message
 */
- (Message *)lastMessageFromAllwithGroupID:(NSString *)groupId;

#pragma mark -
#pragma mark 免打扰相关方法(msgBlock)
/**
 *  @brief  发送群消息免打扰请求
 *
 *  @param  item    当前群模型
 *  @param  state   当前免打扰状态
 *
 */
- (void)msgBlockWithGroupItem:(GroupItem *)item
                        state:(BOOL)state;

/**
 *  @brief  判断群组是否为免打扰
 *
 *  @param  groupId  群id
 *
 *  @return  YES/NO
 */
- (BOOL)isExistMsgBlockedWithGroupId:(NSString *)groupId;

#pragma mark -
#pragma mark 置顶相关
/**
 *  @brief  群置顶
 *
 *  @param  isTop  是否置顶
 *  @param  item  群
 *  @param  completeBlock  block 回调
 *
 */
- (void)markGroupItemTop:(BOOL) isTop groupItem:(GroupItem *)item complete:(void(^)(BOOL success))completeBlock;

/**
 *  @brief  判断群组是否为置顶
 *
 *  @param  item 群
 *
 *  @return  YES/NO
 */
- (BOOL)isTopWithGroupItem:(GroupItem *)item;

#pragma mark -
#pragma mark 消息相关方法
/**
 *	@brief	文件消息的路径
 */
- (NSString *)getOfflineDirPath;

/**
 *	@brief	发送Message，追加发送状态
 *
 *	@param 	message 	将要发送的message
 *
 *	@return	 Message
 */
- (Message *)asyncSendMessage:(Message *)message;

- (Message *)asyncSendMessage:(Message *)message
                     progress:(void (^)(float progress))aProgressBlock;

/**
 *	@brief	重发Message，追加发送状态
 *
 *	@param 	message 	将要重发的message
 *
 *	@return	 Message
 */
- (Message *)resendMessage:(Message *)message;

- (Message *)resendMessage:(Message *)message
                  progress:(void (^)(float progress))aProgressBlock;

/**
 *	@brief	转发Message，追加发送状态
 *
 *	@param 	message 	将要转发的message(图片、位置、视频)
 *	@param 	fromGroupId 	从那个群转发的
 *	@param 	toGroupId 	转发到那个群的
 *
 *	@return	 Message
 */
- (Message *)forwardMessage:(Message *)message
                fromGroupId:(NSString *)fromGroupId
                  toGroupId:(NSString *)toGroupId;

- (Message *)forwardMessage:(Message *)message
                fromGroupId:(NSString *)fromGroupId
                  toGroupId:(NSString *)toGroupId
                   progress:(void (^)(float progress))aProgressBlock;

/**
 *  @brief  更新消息的状态、语音图片的下载上传状态
 *
 *  @param  aMessage 需要更新的消息
 *
 *  @return  是否更新成功
 */
- (BOOL)executeUpdateChatLogReceiveStatus:(Message *)aMessage;

/**
 *  @brief  保存消息UI高度数据
 *
 *  @param  message 需要保存的消息
 *
 */
- (void)saveMessageHeightWithMeesage:(Message *)message;

/**
 *  @brief  重置消息UI高度数据
 *
 *  @param  item 需要重置的会话
 *
 */
- (void)resetMessageHeightWithGroupItem:(GroupItem *)item;

- (void)updateMessage:(Message *)msg withExtra:(NSString *)extra;

#pragma mark - 插入消息
/**
 *  @brief  往数据库存储消息
 *
 *  @param  messages 存储的消息
 *
 */
-(void)importMessages:(NSArray *)messages;

//本地欢迎消息使用
-(void)importMessages:(NSArray *)messages extra:(NSDictionary *)extra;

#pragma mark - 阅后即焚相关
/**
 *  @brief  悄悄话已读回执
 *
 *  @param  message 消息
 *
 */
-(void)sendReadAckMessage:(Message *)message;

/**
 *  @brief  悄悄话倒计时后的移除本地消息
 *
 *  @param  msgIdArr 悄悄话倒计时后要本地删除的数组
 *
 */
-(void)removeMessageAfterTimer:(NSArray *)msgIdArr;


#pragma mark - 客户端插入被踢消息
/**
 *  @brief  客户端存储被踢的提示消息
 *
 *  @param  message  待入库提示消息
 *  @param  chatMsg  聊天的消息
 *  @param  isSuccess  block 回调
 *
 */
- (void)insertMessage:(Message *)message
           forMessage:(Message *)chatMsg
            isSuccess:(void(^)(BOOL isSuccess))isSuccess;


#pragma mark -
#pragma mark 撤回消息
/**
 *	@brief	主动撤回消息
 *
 *  @param  message  要撤回的消息
 *
 */
- (void)executeRevokeMessage:(Message *)message;


#pragma mark -
#pragma mark 删除消息
/**
 *	@brief	删除单条消息
 *
 *	@param 	message	 将要删除的消息
 *
 *	@return	 BOOL
 */
- (BOOL)deleteSingleMessage:(Message *)message;

/**
 *	@brief	清空某个群的聊天记录
 *
 *	@param 	groupItem 	群
 *
 *	@return	 BOOL
 */
- (BOOL)deleteGroupMessagesWithGroupItem:(GroupItem *)groupItem;


#pragma mark -
#pragma mark 标记消息已读
/**
 *  @brief	单条标记已读
 *
 *  @param  message 需要标记的消息
 *
 *  @return  BOOL
 */
- (BOOL)markReadSingleMessage:(Message *)message;

/**
 *  @brief	标记群消息已读
 *
 *  @param  item  群
 *
 *  @return  BOOL
 */
- (BOOL)markReadMessagesWithGroupItem:(GroupItem *)item;


#pragma mark -
#pragma mark @功能相关方法(atDict)
/**
 *  @brief	判断是否有被@
 *
 *  @param  groupId 群id
 *
 *  @return  BOOL
 */
- (BOOL)isExistAtDictWithGroupId:(NSString *)groupId;

/**
 *  @brief	移除被@状态
 *
 *  @param  groupId 群id
 */
- (void)removeUserAtDictWithGroupId:(NSString *)groupId;


#pragma mark -
#pragma mark 草稿相关方法(userDraftDict)
/**
 *	@brief	判断是否存在草稿
 *
 *	@param 	groupId 	群id
 *
 *	@return	 BOOL
 */
- (BOOL)isExistDraftWithGroupId:(NSString *)groupId;

/**
 *	@brief	获取草稿内容
 *
 *	@param 	groupId 	群id
 *
 *	@return	 NSString
 */
- (NSString *)draftWithGroupId:(NSString *)groupId;

/**
 *	@brief	获取草稿生成时间
 *
 *	@param 	groupId 	群id
 *
 *	@return	 UInt64  毫秒计
 */
- (UInt64)draftTimeWithGroupId:(NSString *)groupId;

/**
 *	@brief	移除用户草稿
 *
 *	@param 	item 	会话item
 *
 */
- (void)removeUserDraftWithGroupItem:(GroupItem *)item;

/**
 *	@brief	保存用户草稿
 *
 *	@param 	text 	草稿内容
 *	@param 	item 	会话item
 *
 */
- (void)saveUserDraftWithText:(NSString *)text
                      groupItem:(GroupItem *)item;


#pragma mark -
#pragma mark 拉取数据库消息
/**
 *  @brief  下拉更多数据
 *
 *  @param  message    起始message
 *  @param  kcount     拉取条数
 *  @param  completion 结果回调
 *
 */
- (void)executeMoreMessagesWithStarMessage:(Message *)message
                                     count:(UInt32)kcount
                                completion:(void(^)(NSArray *list))completion;

/**
 *  @brief  上拉更多数据
 *
 *  @param  message    起始message
 *  @param  kcount     拉取条数
 *  @param  completion 结果回调
 *
 */
- (void)executeNewMessagesWithStarMessage:(Message *)message
                                    count:(UInt32)kcount
                               completion:(void(^)(NSArray *list))completion;

/**
 *	@brief	获取本地数据前 count 条消息
 *
 *	@param 	item 	群
 *	@param 	kcount 	获取消息的条数
 *  @param  completion 结果回调
 *
 */
- (void)executeLastMessagesWithGroupItem:(GroupItem *)item
                                 count:(UInt32)kcount
                            completion:(void(^)(NSArray *list))completion;

/**
 *	@brief	搜索消息的聊天详情获取
 *
 *	@param 	searchMessage 	搜索出来的消息
 *	@param 	kcount 	获取消息的条数
 *  @param  completion 结果回调
 *
 */
- (void)executeMessagesWithSearchMessage:(Message *)searchMessage
                                   count:(UInt32)kcount
                              completion:(void(^)(NSArray *list))completion;

#pragma mark - 异步从数据库取消息
/**
 *  @brief  异步下拉更多数据
 *
 *  @param  message    起始message
 *  @param  kcount     拉取条数
 *  @param  completion 结果回调
 *
 */
- (void)executeAsyncMoreMessagesWithStarMessage:(Message *)message
                                          count:(UInt32)kcount
                                     completion:(void(^)(NSArray *list))completion;

/**
 *  @brief  异步上拉更多数据
 *
 *  @param  message    起始message
 *  @param  kcount     拉取条数
 *  @param  completion 结果回调
 *
 */
- (void)executeAsyncNewMessagesWithStarMessage:(Message *)message
                                         count:(UInt32)kcount
                                    completion:(void(^)(NSArray *list))completion;

/**
 *	@brief	异步获取本地数据前 count 条消息
 *
 *	@param 	item 	群
 *	@param 	kcount 	获取消息的条数
 *  @param  completion 结果回调
 *
 */
- (void)executeAsyncLastMessagesWithGroupItem:(GroupItem *)item
                                        count:(UInt32)kcount
                                   completion:(void(^)(NSArray *list))completion;

/**
 *	@brief	异步搜索消息的聊天详情获取
 *
 *	@param 	searchMessage 	搜索出来的消息
 *	@param 	kcount 	获取消息的条数
 *  @param  completion 结果回调
 *
 */
- (void)executeAsyncMessagesWithSearchMessage:(Message *)searchMessage
                                        count:(UInt32)kcount
                                   completion:(void(^)(NSArray *list))completion;

#pragma mark -
#pragma mark 搜索历史消息(search local messages)
/**
 *	@brief	搜索历史消息
 *
 *	@param 	keyword 	关键词
 *	@param 	resultBlock 	结果回调
 *
 */
- (void)searchLocalMessagesWithKeyword:(NSString *)keyword
                           resultBlock:(void (^)(NSArray *list))resultBlock;

/**
 *  @brief    异步获取未读消息
 *
 *  @param  groupId  群id
 *  @param  completion 结果回调
 *
 */
- (void)executeAsyncUnreadMessagesWithGroupId:(NSString *)groupId completion:(void(^)(NSArray *list))completion;

/**
 *	@brief	查询最近下载的附件消息
 */
- (NSArray *)getResentAttachMessage;

/**
 搜索本地消息
 
 @param aParam 参数(NSDictionary *)
 {
 key:message-value:(Message *)
 key:count-value:(int)
 key:msgType-value:(int)
 key:groupId-value:(NSString *)
 }
 @param resultBlock 消息集合
 */
- (void)searchLocalMessagesWithParam:(NSDictionary *)aParam
                         resultBlock:(void(^)(NSArray *list))resultBlock;


#pragma mark -
#pragma mark 下载消息附件(download attach)
/**
 *	@brief	下载消息附件 仅限于image缩略图、voice、position、video第一帧图片、attach
 *
 *	@param 	message 	需要下载的消息
 *
 */
- (void)executeDownloadMessageAttach:(Message *)message;


/**
 下载文件

 @param attachId 文件标识
 @param fileName 文件名
 @param success 成功
 @param progresse 进度
 @param failure 失败
 */
- (void)downloadFileWithAttachId:(NSString *)attachId
                        fileName:(NSString *)fileName
                        progress:(void(^)(float))progresse
                         success:(void(^)(NSString *))success
                         failure:(void(^)())failure;


/**
 下载语音

 @param voiceUrl 语音全路径
 @param success 成功(本地路径)
 @param failure 失败
 */
- (void)downloadVoiceWithUrl:(NSURL *)voiceUrl
                     success:(void(^)(NSString *))success
                     failure:(void(^)())failure;

#pragma mark - 合并转发

/**
 取合并转发消息

 @param msgIds msgId集合
 @param groupId 消息来源groupId
 @param sourceMessage 第一个点进去的合并消息
 @param message 内层的合并消息，如果是一层，则与sourceMessage传相同message即可
 @param compelteBlock 消息对象集合完成回调
 */
- (void)fetchMergeMsgIdArray:(NSArray *)msgIds
                     groupId:(NSString *)groupId
               sourceMessage:(Message *)sourceMessage
                     message:(Message *)message
                competeBlock:(void (^)(NSArray *))compelteBlock;

/**
 下载合并转发消息里的附件消息

 @param sourceMessage 第一个点进去的合并消息
 @param message 需要下载附件的消息
 */
- (void)downLoadMergeMsgAttach:(Message *)sourceMessage message:(Message *)message completeBlock:(void(^)(BOOL success,NSString *filePath))completeBlock;

#pragma mark - 美号相关

/**
 美号列表

 @return groupItem数组
 */
- (NSArray *)meiHaoListFromIMWithGroupId:(NSString *)groupId;


/**
 获取单个美号会话

 @param groupId groupId
 @return 美号groupItem
 */
- (GroupItem *)groupItemFromImSubConversationDict:(NSString *)groupId;

/**
 标记本地订阅

 @param isSubScribe 0 订阅 1 取消订阅
 @param groupId groupId
 @return 是否成功
 */
- (BOOL)markIsSubcribe:(int)isSubScribe groupId:(NSString *)groupId;


#pragma mark -客服系统相关
/**
 获取单个客服会话
 
 @param groupId groupId
 @return 美号groupItem
 */
- (GroupItem *)groupItemFromImCustomerConversationDict:(NSString *)groupId;

//查询客服列表
- (NSArray *)queryCustomerList;
#pragma mark - 消息搜索
// add  by wk 2018-4-27
/**
 根据关键字查询pageSize消息
 
 @param keyword 关键字
 @param pageSize 消息条数
 @param groupId groupID
 @param sendTime 最新消息的发送时间(0为当前时间,查询更多则为上查询的最后一条消息的sendTime)
 */
- (void)queryMessagesWithKeywork:(NSString *)keyword
                        pageSize:(SInt32)pageSize
                         groupId:(NSString *)groupId
                        sendTime:(SInt64)sendTime
                      completion:(void(^)(NSArray *list, BOOL hasMore))completion;
/**
 查询会话的文件消息
 
 @param groupId groupID
 @return 消息数
 */
- (NSArray *)queryFileMessagesWithGroupId:(NSString *)groupId;

/**
 根据关键字查询会话的文件消息
 
 @param keyword 关键字
 @param groupId groupID
 @return 消息数
 */
- (NSArray *)queryFileMessagesWithKeywork:(NSString *)keyword groupId:(NSString *)groupId;

/**
 根据关键字分页查询指定条数文件消息
 
 @param keyword keyword
 @param pageSize pageSize
 @param groupId groupId
 @param sendTime sendTime
 @return count
 */
- (NSArray *)queryFileMessagesWithKeywork:(NSString *)keyword pageSize:(SInt32)pageSize groupId:(NSString *)groupId sendTime:(SInt64)sendTime;
/**
 分页查询指定条数文件消息
 
 @param pageSize pageSize
 @param groupId groupId
 @param sendTime sendTime
 @return count
 */
- (NSArray *)queryFileMessagesWithPageSize:(SInt32)pageSize groupId:(NSString *)groupId sendTime:(SInt64)sendTime;

/**
 查询会话的图片和视频消息
 
 @param groupId groupID
 */
- (void)queryImgAndVideoMessagesWithGroupId:(NSString *)groupId
                                 completion:(void(^)(NSArray *list))completion;


#pragma mark - private
- (Message *)bridgeMessageWithImMsg:(ImMsg *)imMsg;
- (BOOL)isAtSelf:(SInt64)selfImUserId withGroupItem:(GroupItem *)aGroupItem withMessage:(Message *)aMessage;
- (void)saveUserAtDictWithGroupId:(NSString *)groupId;
- (GroupState)groupItemStateFromMessage:(Message *)msg;
- (BOOL)selectorCanPerformWithObject:(id)object selector:(SEL)selector protocol:(Protocol *)protocol;
- (void)loginTokenInvalid;
- (GroupItem *)bridgeGroupItemWithImGroup:(ImGroup *)imGroup;
- (void)submitInitSeqId:(SInt64)msgSeqId WithGroupId:(NSString *)groupId groupType:(int)grouptype;
- (void)handleInDBQueue:(void (^)())block;
-(void)processUserTokenError;
- (void)updateGroupItemLastMsgWithMessage:(Message *)message lastMessage:(Message *)lastMsg;
- (Message *)bridgeMessageWithImSubMsg:(ImSubMsg *)imSubMsg;
- (void)updateImConversationDict4Meihao;

- (void)updateImConversationDict4Customer;
@end
