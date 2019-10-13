//
//  IMMergeMessageBody.h
//  GMIMOriginalSDK
//
//  Created by 孟祥京 on 2017/10/27.
//  Copyright © 2017年 IMDevelop. All rights reserved.
//

#import "IMMessageBody.h"

@interface IMMergeMessageBody : IMMessageBody

/**
 消息对象集合
 */
@property (nonatomic,copy) NSArray *msgArray;

/**
 消息来源群组groupId
 */
@property (nonatomic,copy) NSString *groupId;

- (void)mergeValuesForKeysWithDictionary:(NSDictionary<NSString *,id> *)keyedValues;

@end
