#include "KingSystem/Utils/Thread/PhysicsTaskThread.h"

namespace ksys {

PhysicsTaskThread::PhysicsTaskThread(const sead::SafeString& name, sead::Heap* heap, s32 priority,
                                     sead::MessageQueue::BlockType block_type, long quit_msg,
                                     s32 stack_size, s32 message_queue_size)
    : TaskThread(name, heap, priority, block_type, quit_msg, stack_size, message_queue_size) {}

void PhysicsTaskThread::quit(bool) {
    mMessageQueue.push(cMessage_PhysicsThreadQuit, sead::MessageQueue::BlockType::Blocking);
    Thread::quit(false);
}

}  // namespace ksys
