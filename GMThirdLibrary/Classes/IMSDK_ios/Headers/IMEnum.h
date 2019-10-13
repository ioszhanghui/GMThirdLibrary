//
//  IMEnum.h
//  GomePlus
//
//  Created by illScholar on 15/12/2.
//  Copyright © 2015年 Gome. All rights reserved.
//

#ifndef IMEnum_h
#define IMEnum_h

//群组类型
typedef NS_ENUM(UInt32, ChatType) {
    /**
     *	@brief	单聊 默认
     */
    ChatTypeSingle = 1,
    /**
     *	@brief	群聊
     */
    ChatTypeGroup = 2,
    /**
     *	@brief	系统消息
     */
    ChatTypeSystem =3,
    /**
     *	@brief	小秘书
     */
    ChatTypeHelper = 5

};

//result返回状态码
typedef NS_ENUM(SInt32,ResultCode) {
    /**
     *	@brief	成功
     */
    ResultCodeOk = 0,
    /**
     *	@brief	错误，细分再详细定义
     */
    ResultCodeError = -1,
    /**
     *	@brief	token错误
     */
    ResultCodeTokenError = -2,
    /**
     *	@brief	用户不存在
     */
    ResultCodeUserNotExit = -3,
    /**
     *	@brief	token过期
     */
    ResultCodeTokenTimeout = -4,
    /**
     *    @brief    用户已不在群组||取消订阅||非好友
     */
    ResultCodeUserQuit = -5,
    /**
     *  撤销消息时间已过
     */
    ResultCodeRevokeMsgOutTime = -6,
    /**
     *  撤销消息超时失败
     */
    ResultCodeRevokeMsgError = -7,
    /**
     *  登录超时
     */
    ResultCodeLoginOutTime = -8,
    /**
     *  参数错误
     */
    ResultCodeParamterError = -9,
    /**
     *  IM已连接
     */
    ResultCodeAreayConnected
};

//IMClientState 连接状态
typedef NS_ENUM(NSInteger, IMClientState) {
    /**
     *	@brief	离线
     */
    IMClientStateOffLine = 0x01,
    /**
     *	@brief	连接中
     */
    IMClientStateConnecting,
    /**
     *	@brief	在线
     */
    IMClientStateOnLine
};

typedef NS_ENUM(NSInteger, IMMessageState) {
    /**
     *	@brief	正常
     */
    IMMessageStateNormal = 0,
    /**
     *	@brief	收取中
     */
    IMMessageStateReceiving

};


//消息类型
typedef NS_ENUM(UInt32, MsgType) {
    /**
     *	@brief	文本 默认
     */
    MsgTypeText = 1,
    /**
     *	@brief	语音
     */
    MsgTypeVoice = 2,
    /**
     *	@brief	图片
     */
    MsgTypeImage = 3,
    /**
     *	@brief	视频
     */
    MsgTypeVideo = 4,
    /**
     *	@brief	位置
     */
    MsgTypePosition = 5,
    /**
     *	@brief	附件
     */
    MsgTypeAttach = 6,
    /**
     *  @brief  红包
     */
    MsgTypeRedEnvelopes = 7,
    /**
     *  @brief  拆红包通知
     */
    MsgTypeRedEnvelNotice = 8,
    /**
     *  @brief  合并转发
     */
    MsgTypeMerge = 9,
    
    MsgTypeEmoticon = 10,
    
    MsgTypePredifinedBigEmotion = 11,
    /**
     *	@brief	分享卡片
     */
    MsgTypeShareCard = 96,
    /**
     *	@brief	音频聊天
     */
    MsgTypeAudioChat = 97,
    /**
     *	@brief	视频聊天
     */
    MsgTypeVedioChat = 98,
    /**
     *	@brief	消息透传，在扩展字段中
     */
    MsgTypePassThrough = 99,
    /*
     106美号单个消息
     */
    MsgTypeMeiHaoSingle = 106,
    /*
     107美号多图文消息
     */
    MsgTypeMeiHaoMulti = 107
};

// 功能性消息类型
typedef NS_ENUM(UInt32, NoticeMsgType){
    /**
     *	@brief 退/踢群
     */
    NoticeMsgTypeQuitGroup = 1,
    /**
     *	@brief 撤回
     */

    NoticeMsgTypeRevoke = 2,
    /**
     *	@brief 阅后即焚
     */
    NoticeMsgTypeWhispered = 3
};

typedef NS_ENUM(UInt32, MsgState) {
    /**
     *	@brief	待发送、待接收
     */
    MsgStatePending = 0,
    /**
     *	@brief	发送中、接收中
     */
    MsgStateDelivering,
    /**
     *	@brief	发送成功、接收成功
     */
    MsgStateDelivered,
    /**
     *	@brief	发送失败、接收失败
     */
    MsgStateFailure
};

typedef NS_ENUM(UInt32, MsgFunctionState) {
    /**
     *	@brief	正常
     */
    MsgFunctionStateNormal = 0,
    /**
     *	@brief	撤回
     */
    MsgFunctionStateRevoked = 1,
    /**
     *	@brief	删除
     */
    MsgFunctionStateDeleted = 2,
    /**
     *	@brief	阅后即焚
     */
    MsgFunctionStateWhispered = 3

};

typedef NS_ENUM(UInt32, MsgAttachState) {
    /**
     *	@brief	待发送、待下载
     */
    MsgAttachStatePending = 0,
    /**
     *	@brief	上传中、下载中
     */
    MsgAttachStateDelivering,
    /**
     *	@brief	上传成功、下载成功
     */
    MsgAttachStateDelivered,
    /**
     *	@brief	上传失败、下载失败
     */
    MsgAttachStateFailure,
    
    /**已取消、已暂停*/
    MsgAttachStateCancel
};

typedef NS_ENUM(SInt32, GroupState) {

    /**
     *	@brief	阅后即焚
     */
    GroupStateWhispered = -12,
    /**
     *	@brief	撤回
     */
    GroupStateRevoked = -11,
    /**
     *	@brief	待发送、待接收
     */
    GroupStatePending = 0,
    /**
     *	@brief	发送中、接收中
     */
    GroupStateDelivering = 1,
    /**
     *	@brief	发送成功、接收成功
     */
    GroupStateDelivered = 2,
    /**
     *	@brief	发送失败、接收失败
     */
    GroupStateFailure = 3
};

typedef NS_ENUM(UInt32, MsgFuncTag) {

    /**
     *	@brief	阅后即焚消息
     */
    MsgFuncTagWhispered = 1,
    /**
     *	@brief	已读回执消息
     */
    MsgFuncTagRead = 2
};

typedef NS_ENUM (UInt32,RedEnvelopeType) {

    /**
     *	@brief	定额红包
     */
    RedEnvelopeTypeEqual = 1,
    /**
     *	@brief	拼手气红包
     */
    RedEnvelopeTypeRandom = 2
};
// 拉取方式
typedef NS_ENUM(unsigned int,IMPullType){
    // 自动拉取
    IMPullTypeAuto = 0,
    // 手动拉取
    IMPullTypeManual = 1
} ;

#endif /* IMEnum_h */
