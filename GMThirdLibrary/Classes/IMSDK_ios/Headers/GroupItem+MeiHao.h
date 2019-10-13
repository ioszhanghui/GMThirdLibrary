//
//  GroupItem+MeiHao.h
//  GMIMOriginalSDK
//
//  Created by 抑郁的小馒头 on 2017/11/14.
//  Copyright © 2017年 IMDevelop. All rights reserved.
//

#import "GroupItem.h"

@interface GroupItem ()
//@property (nonatomic, copy) NSString *groupId;

/**
 父类ID
 */
@property (nonatomic, assign) SInt64 pId;

/**
 美号ID
 */
@property (nonatomic, assign) SInt64 mhId;

/**
 是否订阅；0:订阅、1:取消订阅
 */
@property (nonatomic, assign) SInt64 isSubscribe;

/**
 文章最大seq id
 */
@property (nonatomic, assign) SInt64 maxArtSeqId;

/**
 消息最大seq id
 */
@property (nonatomic, assign) SInt64 maxMsgSeqId;

/**
 订阅时文章最大seq id
 */
@property (nonatomic, assign) SInt64 initArtSeqId;

/**
 订阅时消息最大seq id
 */
@property (nonatomic, assign) SInt64 initMsgSeqId;

/**
 文章读取至seq id
 */
@property (nonatomic, assign) SInt64 readArtSeqId;

/**
 消息读取至seq id
 */
@property (nonatomic, assign) SInt64 readMsgSeqId;

/**
 接收到文章最大seqId
 */
@property (nonatomic, assign) SInt64 receivedArtSeqId;

/**
 接收到聊天最大seqId
 */
@property (nonatomic, assign) SInt64 receivedMsgSeqId;
@end
