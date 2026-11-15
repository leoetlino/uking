#include "KingSystem/Utils/Thread/MessageTransceiver.h"
#include "KingSystem/Utils/Thread/MessageTransceiverCommon.h"

namespace ksys {

MessageTransceiver::MessageTransceiver(IHandler& handler) : mReceiver(handler) {
    registerReceiver(mReceiver);
}

MessageTransceiver::~MessageTransceiver() {
    deregisterReceiver(mReceiver);
}

MessageReceiverEx* MessageTransceiver::getReceiver() {
    return &mReceiver;
}

bool MessageTransceiver::sendMessage(const MesTransceiverId& dest, const MessageType& type,
                                     void* user_data, bool ack) {
    return sendMessageImpl(this, dest, type, user_data, ack);
}

bool MessageTransceiver::sendMessageOnProcessingThread(const MesTransceiverId& dest,
                                                       const MessageType& type, void* user_data,
                                                       bool ack) {
    return sendMessageOnProcessingThreadImpl(this, dest, type, user_data, ack);
}

bool MessageTransceiver::sendMessage(IMessageBroker& broker, const MessageType& type,
                                     void* user_data, bool ack) {
    return sendMessageImpl(this, broker, type, user_data, ack);
}

bool MessageTransceiver::sendMessageOnProcessingThread(IMessageBroker& broker,
                                                       const MessageType& type, void* user_data,
                                                       bool ack) {
    return sendMessageOnProcessingThreadImpl(this, broker, type, user_data, ack);
}

MessageTransceiver::Receiver::~Receiver() = default;

void MessageTransceiver::Receiver::handleAck(const MessageAck& ack) {
    mHandler.handleAck(ack);
}

}  // namespace ksys
