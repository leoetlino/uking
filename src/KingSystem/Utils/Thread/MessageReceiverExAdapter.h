#pragma once

#include "KingSystem/Utils/Thread/MessageReceiverEx.h"

namespace ksys {

class MessageReceiverExAdapter : public MessageReceiverEx {
    SEAD_RTTI_OVERRIDE(MessageReceiverExAdapter, MessageReceiverEx)
public:
    explicit MessageReceiverExAdapter(MessageReceiver* wrapped);
    ~MessageReceiverExAdapter() override;

protected:
    int handleMessage(const Message& message) override;
    void handleAck(const MessageAck& ack) override;

private:
    MessageReceiver* mReceiver;
};

}  // namespace ksys
