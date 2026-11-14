#pragma once

#include "KingSystem/Resource/resResource.h"
#include "KingSystem/Utils/ParamIO.h"

namespace ksys::act {

class AISchedule : public ParamIO, public res::Resource {
    SEAD_RTTI_OVERRIDE(AISchedule, res::Resource)
public:
    AISchedule() : ParamIO("baischedule", 0) {}

    void doCreate_(u8* buffer, u32 buffer_size, sead::Heap* heap) override;
    bool needsParse() const override { return false; }

    u8* getData() const { return mData; }

private:
    u8* mData{};
};

}  // namespace ksys::act
