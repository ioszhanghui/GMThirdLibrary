//
//  GMFileTransferClient.h
//  GMFileTransfer
//
//  Created by onpalm on 11/13/16.
//  Copyright © 2016 Gome. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GMFileTransferClient : NSObject

@property (nonatomic, copy) NSString *hostName;
@property (nonatomic, assign) UInt16 hostPort;
@property (nonatomic, assign) SInt64 uid;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy)NSString *appId;

+ (GMFileTransferClient *)sharedClient;

- (void)registerWith:(NSString *)appId
                 uid:(SInt64)uid
               token:(NSString *)token
                host:(NSString *)host
                port:(UInt16)port;
@end
