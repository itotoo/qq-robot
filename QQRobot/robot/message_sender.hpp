#include "group_message.hpp"
#include "cqp.h"

using namespace QQRobot;

namespace QQRobot
{
    class MessageSender
    {
    public:
        void sendPrivateMessage(Message msg)
        {
            CQ_sendPrivateMsg(authCode, atoi(msg.to.c_str()), msg.getContent().c_str());
        }

        void sendGroupMessage(GroupMessage msg)
        {
            if(msg.type == 0)
                CQ_sendGroupMsg(authCode, atoi(msg.to.c_str()), msg.getContent().c_str());
            else if(msg.type == 1)
                CQ_sendDiscussMsg(authCode, atoi(msg.to.c_str()), msg.getContent().c_str());
        }


        void setAuthCode(int authCode)
        {
            this->authCode = authCode;
        }

    private:
        int authCode;
    };
}