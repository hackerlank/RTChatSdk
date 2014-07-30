//
//  RTChatSdk.h
//  RTChat
//
//  Created by raymon_wang on 14-7-29.
//  Copyright (c) 2014年 yunwei. All rights reserved.
//

#ifndef RTChat_RTChatSdk_h
#define RTChat_RTChatSdk_h

typedef std::function<void (long long roomid)> pMsgCallFunc;

class RTChatSDKMain {
public:
    static RTChatSDKMain& sharedInstance();
    
    void initSDK(const std::string& uniqueid);
    
    void registerMsgCallback(const pMsgCallFunc& func);
    
    //创建房间
    void createRoom();
    
    //加入房间
    void joinRoom(uint64_t roomid);
    
    //获取当前的输入mic静音状态
    bool getMuteSelf();
    
    //设置本人Mac静音
    void setMuteSelf(bool isMute);
    
    //申请房间列表
    void requestRoomList();
};

#endif