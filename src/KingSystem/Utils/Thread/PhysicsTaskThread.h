#pragma once

#include "KingSystem/Utils/Thread/TaskThread.h"
#include "KingSystem/Utils/Types.h"

namespace ksys {

class PhysicsTaskThread : public TaskThread {
    SEAD_RTTI_OVERRIDE(PhysicsTaskThread, TaskThread)
public:
    PhysicsTaskThread(const sead::SafeString& name, sead::Heap* heap, s32 priority,
                      sead::MessageQueue::BlockType block_type, long quit_msg, s32 stack_size,
                      s32 message_queue_size);
    ~PhysicsTaskThread() override { ; }

    void quit(bool is_jam) override;

protected:
    static constexpr s32 cMessage_PhysicsThreadQuit = 4;

    void calc_(sead::MessageQueue::Element msg) override;
    u8 _1a0 = 0;
    s32 _1a4 = -1;
};
KSYS_CHECK_SIZE_NX150(PhysicsTaskThread, 0x1a8);

}  // namespace ksys
