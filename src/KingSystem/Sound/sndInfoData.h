#pragma once

#include <Byaml/Byaml.h>
#include <heap/seadDisposer.h>
#include "KingSystem/Resource/resResourceBinder.h"

namespace ksys::snd {

class InfoData {
    SEAD_SINGLETON_DISPOSER(InfoData)

    InfoData() = default;
    virtual ~InfoData();

public:
    void init(sead::Heap* heap);

    al::ByamlIter getInfo(const sead::SafeString& key) const;
    sead::SafeString getSoundSettingUserName(const sead::SafeString& key) const;

    sead::SafeString getReactionSettingLandType(const al::ByamlIter& iter,
                                                const sead::SafeString& key) const;
    float getReactionSettingLandPitch(const al::ByamlIter& iter) const;
    float getReactionSettingLandVolume(const al::ByamlIter& iter) const;
    float getReactionSettingLandVelocityRatio(const al::ByamlIter& iter) const;

    sead::SafeString getReactionSettingSlideType(const al::ByamlIter& iter) const;
    sead::SafeString getReactionSettingSlideSlideType(const al::ByamlIter& iter) const;
    float getReactionSettingSlidePitch(const al::ByamlIter& iter) const;
    float getReactionSettingSlideVolume(const al::ByamlIter& iter) const;
    float getReactionSettingSlideVelocityRatio(const al::ByamlIter& iter) const;

    sead::SafeString getWeaponOwnerSettingOwnerType(const al::ByamlIter& iter) const;

    sead::SafeString getEquipSoundSettingEquipMaterial(const al::ByamlIter& iter) const;

    bool getMiscInDoorOcclusion(const al::ByamlIter& iter) const;

    sead::SafeString getMiscPlantShakeType(const al::ByamlIter& iter) const;

private:
    void loadSoundInfo(sead::Heap* heap);

    al::ByamlIter* mRootIter{};
    res::ResourceBinder mResHandle{};
};

}  // namespace ksys::snd
