//
//  IMConstantDef.h
//  GMBuy
//
//  Created by onpalm on 16/5/19.
//  Copyright © 2016年 cn. All rights reserved.
//

#ifndef IMConstantDef_h
#define IMConstantDef_h

#define DocumentPath  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define CurrentUID [[IMMessageManager sharedInstance] imUserId]
#define APPID [[IMMessageManager sharedInstance] imAppId]
#define CurrentToken [[IMMessageManager sharedInstance] imToken]
#define IMServer [[IMMessageManager sharedInstance] hostURL]
#define CurrentTime [[IMMessageManager sharedInstance] dateOfNow]

#define kTimeOutMessage 20
#define kTimeOutRequest 30


#define kOSType 10
#define kVersion 1

//
#define kGroupChatTypeNormal 0
#define kGroupChatTypeSystem 2000
#define kGroupChatTypeCustom 3000
#define kGroupChatTypeMeihao 4000
#define kGroupChatTypeRobot 5000

#define kCustomerGroupId [GroupItem getVirtualCustomerGroupID]
//
#define kSourceTypeMsg 0
#define kSourceTypeArt 1


#define WeakSelf(weakSelf)                __weak __typeof(&*self)weakSelf = self;
#define StrongSelf(strongSelf, weakSelf)  __strong __typeof(&*weakSelf)strongSelf = weakSelf;


//#if DEBUG
//#define IMSDKLog(FORMAT, ...) do {\
//fprintf(stderr, "<%s : %d>    %s\n%s    %s\n",\
//[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],\
//__LINE__, __func__,[[[NSString stringWithFormat:@"%@",[NSDate date]] substringToIndex:19] UTF8String],[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);\
//fprintf(stderr, "--------\n");\
//} while (0)
//
//#else
//
//#define IMSDKLog(FORMAT, ...) ((void)0)
//#endif
#define IMSDKLog(format, ...) [GMIMLogger log:(@"%s " format),__PRETTY_FUNCTION__, ##__VA_ARGS__]

#endif /* IMConstantDef_h */
