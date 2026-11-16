#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Utils/Types.h"

namespace sead {
class Heap;
}

namespace ksys {

class Event;

namespace res {

class MemoryMgr;

class TextureArchiveWork {
public:
    struct InitArg {
        bool arena_set_flag_8;
        u32 arena_size;
        sead::Heap* heap;
        sead::Heap* arena_heap;
        sead::Heap* arena_heap2;
        sead::SafeString name;
    };
    KSYS_CHECK_SIZE_NX150(InitArg, 0x30);

    TextureArchiveWork();
    ~TextureArchiveWork();

    bool init(const InitArg& arg);
    u32 getHeapSize() const;
    MemoryMgr* getArena() const;

    bool waitForEvent(u32 milliseconds = 0);
    void setEvent();

private:
    Event* mEvent = nullptr;
    MemoryMgr* mArena = nullptr;
};
KSYS_CHECK_SIZE_NX150(TextureArchiveWork, 0x10);

}  // namespace res

}  // namespace ksys
