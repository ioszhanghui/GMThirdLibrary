//
//  GroupItem+Customer.h
//  GMIMOriginalSDK
//
//  Created by onpalm on 10/17/18.
//  Copyright © 2018 IMDevelop. All rights reserved.
//
#import "GroupItem.h"
@interface GroupItem ()

/**
 客服ID
 */
@property (nonatomic, assign) SInt64 uid;

/**
 渠道商ID
 */
@property (nonatomic, copy) NSString *channelId;

/**
 群组类型；1:咨询客服
 */
@property (nonatomic, assign) SInt64 type;

/**
 咨询次数递增id
 */
@property (nonatomic, assign) SInt64 askSeq;

-(BOOL)isCustomerIntegratedGroupItem;
@end
