//
//  RTChatBuffStream.h
//  RTChat
//
//  Created by wang3140@hotmail.com on 14-8-26.
//  Copyright (c) 2014年 RTChatTeam. All rights reserved.
//

#ifndef __RTChat__RTChatBuffStream__
#define __RTChat__RTChatBuffStream__

#include <iostream>
#include <common_types.h>

namespace rtchatsdk {

class RTChatBuffStream : public webrtc::OutStream, public webrtc::InStream {
public:
    typedef std::vector<unsigned char> BuffVec;
public:
    RTChatBuffStream(int maxbuffsize);
    virtual ~RTChatBuffStream();
    
    virtual bool Write(const void *buf,int len);
    
    virtual int Read(void *buf,int len);
    
//    virtual int Rewind();
    
    const BuffVec& getBuffVec();
    
    ///获得实际数据长度
    int get_datasize();
    
    //重置BUFF等待写入
    void resetBuffStream();
    
    //复位读
    void resetReadPosition();
    
private:
    BuffVec                         _buffVec;
    int                             _curWriteSize;
    int                             _curReadSize;
};
    
}

#endif /* defined(__RTChat__RTChatBuffStream__) */
