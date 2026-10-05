#pragma once

#include <prim/seadSafeString.h>
#include <resource/seadResource.h>

class hkRootLevelContainer;

namespace ksys::phys {

class ClothResource : public sead::DirectResource {
public:
    enum class StatusFlag : u8 {
        Loaded = 1 << 0,
        PackfileLoaded = 1 << 1,
        PackfileLoadFailed = 1 << 2,
        NoAnimationContainer = 1 << 3,
        NoClothContainerData = 1 << 4,
        ClothEntryInitFailed = 1 << 5,
        HasOperatorType6 = 1 << 6,
    };

    ClothResource();
    ~ClothResource() override;

    void doCreate_(u8* buffer, u32 bufferSize, sead::Heap* heap) override;

private:
    void* mPackfileData{};
    int mNumClothDatas{};
    void* mClothDatas{};
    int _38{};
    hkRootLevelContainer* mRootLevelContainer{};
    u8 mStatusFlags{};
    sead::FixedSafeString<128> _50;
};

}  // namespace ksys::phys
