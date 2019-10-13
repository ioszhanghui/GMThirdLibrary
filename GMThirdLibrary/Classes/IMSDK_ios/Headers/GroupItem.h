//
//  Group.h
//  GomePlus
//
//  Created by illScholar on 15/12/4.
//  Copyright © 2015年 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMEnum.h"

@class ImMsg;
@class Message;

///会话数据模型  Conversation  表示一条会话
@interface GroupItem : NSObject
/**
 *	@brief	群组id
 */
@property (nonatomic, copy) NSString *groupId;
/**
 *	@brief	群组类型 1:单聊、2:群聊等 默认为ChatTypeSingle
 */
@property (nonatomic, assign) ChatType groupType;
/**
 *	@brief	群聊名字
 */
@property (nonatomic, copy) NSString *groupName;
/**
 *	@brief	消息类型
 */
@property (nonatomic, assign) MsgType msgType;
/**
 群组聊天类型
 */
@property (nonatomic, assign) int groupChatType;
/**
 *	@brief	消息发送者id
 */
@property (nonatomic, assign) SInt64 senderId;
/**
 *	@brief	消息发送者名字
 */
@property (nonatomic, copy) NSString *senderName;
/**
 *	@brief	消息发送者在该群中的昵称
 */
@property (nonatomic, copy) NSString *senderRemark;
/**
 *	@brief	消息 最大 seq id
 */
@property (nonatomic, assign) SInt64 maxSeqId;
/**
 *	@brief	进群时seq id
 */
@property (nonatomic, assign) SInt64 initSeqId;
/**
 *	@brief	已读seq id
 */
@property (nonatomic, assign) SInt64 readSeqId;

/**
 本地收到的消息SeqId
 */
@property (nonatomic, assign) SInt64 receiveSeqId;
/**
 *	@brief	发送时间
 */
@property (nonatomic, assign) SInt64 sendTime;
/**
 *	@brief	最后发送的内容
 */
@property (nonatomic, copy) NSString *lastContent;
/**
 *	@brief	最后发送的消息的时间(针对草稿显示时间添加的字段)(有草稿时收到被踢的圈子通知死锁问题)
 */
@property (nonatomic, assign) SInt64 lastMsgSendTime;
/**
 *	@brief	消息状态  eg；发送 状态 默认为MsgStatePending
 */
@property (nonatomic, assign) GroupState msgStatus;
/**
 *	@brief	@用户的  imUserId 的集合
 */
@property (nonatomic, strong) NSMutableArray *atUidList;
/**
 *	@brief	屏蔽群信息
 */
@property (nonatomic, assign) BOOL shieldInfo;
/**
 *	@brief	新消息提醒
 */
@property (nonatomic, assign) BOOL infoRemind;
/**
 *	@brief	排序值
 */
@property (nonatomic, assign) SInt64 sortOrder;
/**
 *	@brief	群退出标志
 */
@property (nonatomic, assign) SInt64 isQuit;
/**
 *	@brief	是否删除默认为0
 */
@property (nonatomic, assign) SInt64 isDeleteNum;
/**
 *  @brief  群消息免打扰
 */
@property (nonatomic, assign) SInt64 isMsgBlocked;
/**
 *  @brief  群未读消息数 cache 未读数
 */
@property (nonatomic, assign) SInt64 unreadCount;

@property (nonatomic, copy) NSString *extra;

@property (nonatomic, strong) Message *lastMsg;
/**
 拉取方式
 */
@property (nonatomic, assign) IMPullType pullType;

#pragma mark -
#pragma mark groupItem 常用方法
/**
 *	@brief	获取单聊对方UserId
 *
 *	@return	NSString 单聊：对方Uid，群聊：群Id
 */
- (NSString *)getOtherUserId;

//获取虚拟会话中客服item的groupId
+(NSString *)getVirtualCustomerGroupID;

/**
 *	@brief	获取 shopID
 *
 *	@return	NSString 店铺id
 */
- (NSString *)getShopID;

/**
 *	@brief	通过单聊的 groupId 获取对方的userID
 *
 *	@param 	groupId 	单聊的 groupId
 *	@return	SInt64    对方的userID
 */
+ (SInt64)getOtherUserIdFromGrouId:(NSString *)groupId;

/**
 *	@brief	通过对方的userID 获取单聊的 groupId
 *
 *	@param 	otherUserId 	对方的userID
 *	@return	NSString     单聊的 groupId
 */
+ (NSString *)groupIdWithOtherUserId:(SInt64)otherUserId;

#pragma mark -
#pragma mark groupItem 构造方法
/**
 *	@brief	获取GroupItem
 *
 *	@param 	groupId  群ID
 *	@param 	groupName 群名称
 *	@param 	isChatGroup 是否群聊
 *
 *	@return	GroupItem
 */
+ (GroupItem *)groupItemWithGroupId:(NSString *)groupId groupName:(NSString *)groupName isChatGroup:(BOOL)isChatGroup;

/**
 *	@brief	获取GroupItem
 *
 *	@param 	chatterId  对方的uid 或者 群id
 *	@param 	isGroupChat  是否群聊
 *	@param 	chatterName  对方的昵称 或者 群名称
 *
 *	@return	GroupItem
 */
+ (GroupItem *)groupItemWithChatId:(NSString *)chatterId isGroupChat:(BOOL)isGroupChat  chatterName:(NSString *)chatterName;

/**
 *	@brief	获取客服GroupItem
 *
 *	@param  serverId  店铺客服ID（999 999 999 7）
 *	@param 	shopId  店铺ID
 *	@param 	shopName  店铺名称
 *
 *	@return	GroupItem（参数有问题时返回 nil） 
 */
+ (GroupItem *)groupItemWithServerId:(NSString *)serverId shopId:(NSString *)shopId shopName:(NSString *)shopName;


/**
 构造美号会话

 @param mhId 美号Id
 @return GroupItem
 */
+ (GroupItem *)groupItemWithMhId:(NSString *)mhId;


/**
 是否是美号聚合会话 /只适用美信列表item！！！！/

 @return BOOL
 */
- (BOOL)isMeihaoIntegratedGroupItem;

@end
