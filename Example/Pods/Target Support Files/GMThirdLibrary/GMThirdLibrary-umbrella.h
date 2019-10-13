#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "WechatAuthSDK.h"
#import "WXApi.h"
#import "WXApiObject.h"
#import "WBHttpRequest.h"
#import "WeiboSDK.h"
#import "UMSocialQQHandler.h"
#import "UMSocialSinaHandler.h"
#import "UMSocialWechatHandler.h"
#import "GMKeyChainHeader.h"
#import "KeychainItemWrapper.h"
#import "DownLoadManger.h"
#import "GMFileDefine.h"
#import "GMFileSdk.h"
#import "GMFileTransferClient.h"
#import "GMFileTransferManager.h"
#import "GroupItem+Customer.h"
#import "GroupItem+MeiHao.h"
#import "GroupItem.h"
#import "IMConstantDef.h"
#import "IMEnum.h"
#import "IMMergeMessageBody.h"
#import "IMMessageBody.h"
#import "IMMessageDelegate.h"
#import "IMMessageManager+Attachment.h"
#import "IMMessageManager.h"
#import "IMSDK.h"
#import "Message.h"

FOUNDATION_EXPORT double GMThirdLibraryVersionNumber;
FOUNDATION_EXPORT const unsigned char GMThirdLibraryVersionString[];

