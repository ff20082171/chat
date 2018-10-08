#ifndef ITEMSTRUCT_H
#define ITEMSTRUCT_H

struct ItemData
{
    int     iFlag;              //区别消息发送还是接收
    double  dfTime;             //消息时间，1970年毫秒数
    char    szContent[255];     //消息内容
};

#endif // ITEMSTRUCT_H
