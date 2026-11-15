#include "KingSystem/Utils/Thread/MessageReceiverExAdapter.h"

namespace ksys {

MessageReceiverExAdapter::MessageReceiverExAdapter(MessageReceiver* wrapped) : mReceiver(wrapped) {}

MessageReceiverExAdapter::~MessageReceiverExAdapter() = default;

int MessageReceiverExAdapter::handleMessage(const Message& message) {
    return mReceiver->receive(message);
}

void MessageReceiverExAdapter::handleAck(const MessageAck& ack) {
    return mReceiver->receive(ack);
}

}  // namespace ksys
