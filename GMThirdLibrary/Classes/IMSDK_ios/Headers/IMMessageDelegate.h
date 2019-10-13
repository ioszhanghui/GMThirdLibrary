//
//  IMMessageDelegate.h
//  GomePlus
//
//  Created by illScholar on 15/12/15.
//  Copyright © 2015年 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMEnum.h"

typedef NS_ENUM(SInt32,GMIMAuthErrorType) {
    GMIMTokenError,   //token错误
    GMIMTokenExpired   //token过期
};


#pragma mark - 登录、登出相关代理（IMLoginOutDelegate）

@protocol IMLoginOutDelegate <NSObject>

@optional
/**
 *	@brief	输出IM获取服务器资源失败的信息
 *
 *	@param 	errorMessage 	errorMessage
 *
 */
- (void)getResourcesWithErrorMessage:(NSString *)errorMessage;

/**
 *	@brief	im 初始化成功
 */
- (void)initIMSuccess;

/**
 *  @brief  用户不存在
 */
- (void)isNoThereUser;

/**
 *  @brief  用户被登出
 */
-(void)userKickout;

/**
 *  @brief  用户的im token过期或者错误,App需要退出到登录界面
 */
-(void)userAuthFail:(GMIMAuthErrorType)errorType;

/**
 *  @brief  强制登出成功
 */
- (void)logoutSuccess;

/**
 *  @brief  登录参数错误
 */
- (void)paramterError;

@end


#pragma mark - 聊天消息相关代理（IMChatDelegate）

@class Message;

@protocol IMChatDelegate <NSObject>

@optional
/**
 *	@brief	消息发送回调
 *
 *	@param 	message 	刚刚发送的消息体
 *
 */
- (void)didSendMessage:(Message *)message;

/**
 *	@brief	新消息接收回调
 *
 *	@param 	message 	接收的新消息
 *
 */
- (void)didReceiveMessage:(Message *)message;

/**
 *	@brief	更新带附件消息的下载状态
 *
 *	@param 	message 	下载的附件消息
 *
 */
- (void)didUpdateReceiveMessageForAttach:(Message *)message;

/**
 *	@brief	用户拉取离线消息回调
 *
 *	@param 	messages 	拉取的离线数据
 *
 */
- (void)didReceiveOfflineMessage:(NSArray *)messages;

/**
 *	@brief	更新消息发送与接收附件的时候进度
 *
 *	@param 	message 	message附件
 *  @param progress 进度
 *
 */
- (void)didUpdateMessageProgressForAttach:(Message *)message progress:(float)progress;

/**
 *	@brief 新来消息 解决readseqid计数不准确问题
 */
- (void)didReceiveChangeReadIdMessage;

/**
 *	@brief	消息发送回调
 *
 *	@param 	message 	撤回的消息
 *	@param 	code        撤回状态
 *
 */
- (void)didRevokeMessage:(Message *)message code:(ResultCode)code;

/**
 *	@brief	收到功能性消息回调
 *
 *	@param 	message 	修改过的消息
 *	@param 	code        状态码
 *  @param  noticeTpye  功能性消息类型
 *
 */
- (void)didReceiveNoticeMessage:(Message *)message code:(ResultCode)code noticeType:(NoticeMsgType)noticeTpye;

/**
 *	@brief	用户拉取离线功能性向消息回调
 *
 *	@param 	messages 	拉取的，处理过的，离线数据
 *  @param  noticeType  功能性消息类型
 *
 */
- (void)didReceiveOfflineNoticeMessage:(NSArray *)messages noticeType:(NoticeMsgType)noticeType;

/**
 *	@brief	1分钟内发送了过多消息回调（暂时没有实现）
 *
 *	@param 	message   刚刚发送的消息体
 *
 */
- (void)didSendTooMuchMessageInOneMunite:(Message *)message;

/**
 *	@brief	悄悄话对方已读
 *
 *	@param 	message 	消息
 *
 */
- (void)didWhisperMessageRead:(Message *)message;

/**
 *	@brief	离线消息全部拉取完毕
 */
- (void)didReceiveOfflineMessagesFinished;


//生成对应的extra字段，发送给业务服务器
-(void) getCustomerMessageExtra:(Message *)message;
@end


#pragma mark - 会话相关代理（IMConversationDelegate）

@class GroupItem;

@protocol IMConversationDelegate <NSObject>

@optional
/**
 *	@brief	监听im的状态
 *
 *	@param 	state 	状态
 *
 */
- (void)monitoringClientState:(IMClientState)state;

/**
 *  @brief  清空 im push计数完成
 */
- (void)didCleanPushCount;

/**
 *  @brief  群免打扰设置结果
 *
 *  @param  error (nil时，设置成功；否则设置失败)
 *
 */
- (void)didMsgBlock:(NSError *)error;

/**
 *	@brief	监听拉取离线消息的状态
 *
 *	@param 	state 	状态
 *
 */
- (void)monitoringMessageState:(IMMessageState)state;

/**
 *	@brief	会话排序变化回调
 *
 *	@param 	groupItem 	会话
 *	@param 	oldLoc 	以前的位置
 *	@param 	newLoc 	现在的位置
 *
 */
-(void)conversationUpdate:(GroupItem *)groupItem oldLoc:(NSUInteger )oldLoc newLoc:(NSUInteger)newLoc;


/**
 会话未读数变化回调

 @param groupItem 会话item
 */
- (void)conversationUnreadCountUpdate:(GroupItem *)groupItem;


//会话草稿发生变化
-(void)conversationDraftChanged:(GroupItem *)groupItem;

@end


#pragma mark - 提示性消息代理（IMTipsMessageDelegate）

@protocol IMTipsMessageDelegate <NSObject>

@optional
/**
 *  @brief  提示性消息代理方法（消息走IM通道，但不入库）
 *
 *  @param  aMessage 提示性消息(msgSeqId == 0)
 *
 */
- (void)receiveTipsMessage:(Message *)aMessage;

@end


#pragma mark - 文件传输相关代理（GMIMFTDelegate）

@protocol GMIMFTDelegate <NSObject>

@optional
/**
 *  @brief  文件传输模块过程中断网切到非wifi网络
 */
-(void)didFTNetworkIsNotWifi;

@end


#pragma mark -全局监听
@protocol GMIncomingMessageListener <NSObject>

@optional
/**
 是否在聊天界面
 
 @ param groupId
 @ return 当前会话是否在前台
 */
-(BOOL) wasMessageSeenInGroup:(NSString *) groupId;

@end



#pragma mark - IM总代理（IMMessageDelegate）

@protocol IMMessageDelegate <IMLoginOutDelegate,
                             IMChatDelegate,
                             IMConversationDelegate,
                             IMTipsMessageDelegate,
                             GMIMFTDelegate>

@end




