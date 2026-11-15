#pragma once

#include <container/seadBuffer.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Utils/Types.h"

namespace nn::prepo {
class PlayReport;
}

namespace ksys {

class PlayReport {
public:
    inline PlayReport(const sead::FixedSafeString<32>& event_id, s32 num_entries,
                      sead::Heap* heap) {
        init(num_entries, heap);
        sead::FixedSafeString<32> event_id_ = event_id;
        setEventId(event_id_);
    }

    ~PlayReport();

    bool setEventId(sead::BufferedSafeString& event_id);

    bool add(const sead::FixedSafeString<48>& key, u32 value);
    bool add(const sead::FixedSafeString<48>& key, s32 value);
    bool add(const sead::FixedSafeString<48>& key, f32 value);
    bool add(const sead::FixedSafeString<48>& key, const sead::SafeString& value);

    // TODO: requires LayoutResourceMgr
    void addRomVersions();

    void addPlayTimes();
    void addPosition(const sead::Vector2f& position);

    bool save();

private:
    void init(s32 num_entries, sead::Heap* heap);

    bool mHasNinPrepoReport = false;
    nn::prepo::PlayReport* mNinPlayReport = nullptr;
    sead::Buffer<u8> mBuffer;
};
KSYS_CHECK_SIZE_NX150(PlayReport, 0x20);

}  // namespace ksys
