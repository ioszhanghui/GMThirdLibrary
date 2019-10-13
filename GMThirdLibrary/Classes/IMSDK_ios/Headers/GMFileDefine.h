//
//  GMFileDefine.h
//  GMFileTransfer
//
//  Created by onpalm on 11/13/16.
//  Copyright © 2016 Gome. All rights reserved.
//

#ifndef GMFileDefine_h
#define GMFileDefine_h

#define GMFileSDKError @"GMIMFileSDKError"

typedef NS_ENUM(NSInteger, GMFileSDKErrorCode) {
    /**GMFileSdk define Begin**/
    /**普通code*/
    GMFileSDKDefaultError = -100,
    
    /**请求超时*/
    GMFileSDKRequestTimeOut = -101,
    
    /**输入参数错误*/
    GMFileSDKParamterError  = -102,
    
    /**本地文件读取错误*/
    GMFileSDKFileError = -103,
    
    /**文件0字节错误*/
    GMFileSDKFileEmptyError = -104,
    
    /**在上传、下载中*/
    GMFileSDKRequestingError = -105,
    
    /**用户正常取消*/
    GMFileSDKUserCancel = -106,
    
    /**服务器连接不上*/
    GMFileSDKServerNotConnected = -107,
    
    /**网络导致的连接断开*/
    GMFileSDKServerNetworkError =-108,
    /**GMFileSdk define End**/
    
    
    /***Server define Begin***/
    /**错误，细分再详细定义*/
    GMFileResultError = -1,
    
    /**token错误*/
    GMFileResultTokenError = -2,
    
    /**用户不存在*/
    GMFileResultUserNotExit = -3,
    
    /**服务端内部错误*/
    GMFileResultServerInternalError = -4,
    
    /**上传内容大于总文件大小*/
    GMFileResultUploadedGreaterThanTotal = -5,
    
    /**上传内容为空*/
    GMFileResultUploadContentIsEmpty = -6,
    
    /**文件不存在*/
    GMFileResultFileNotExsit = -7,
    
    /**文件过期*/
    GMFileResultFileExpired = -8,
    
    /**文件错误*/
    GMFileResultFileError = -9
    /***Server define End***/
};


#endif /* GMFileDefine_h */
