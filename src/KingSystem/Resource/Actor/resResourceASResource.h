#pragma once

#include <container/seadBuffer.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <utility/aglParameterList.h>
#include <utility/aglResParameter.h>
#include "KingSystem/Resource/Actor/resResourceASResourceExtension.h"

namespace ksys::as {

enum class ASElementType : u16 {
    AbsTemperatureBlender = 0,
    AbsTemperatureSelector = 1,
    ArmorSelector = 2,
    ArrowSelector = 3,
    AttentionSelector = 4,
    BoneBlender = 5,
    BoneVisibilityAsset = 6,
    BoolSelector = 7,
    ButtonSelector = 8,
    ChargeSelector = 9,
    ClearMatAnmAsset = 10,
    ComboSelector = 11,
    DiffAngleYBlender = 12,
    DiffAngleYSelector = 13,
    DirectionAngleBlender = 14,
    DirectionAngleSelector = 15,
    DistanceBlender = 16,
    DistanceSelector = 17,
    DungeonClearSelector = 18,
    DungeonNumberSelector = 19,
    EmotionSelector = 20,
    EventFlagSelector = 21,
    EyeSelector = 22,
    EyebrowSelector = 23,
    FaceEmotionSelector = 24,
    FootBLLifeSelector = 25,
    FootBRLifeSelector = 26,
    FootFLLifeSelector = 27,
    FootFRLifeSelector = 28,
    ForwardBentBlender = 29,
    ForwardBentSelector = 30,
    GearSelector = 31,
    GenerationSelector = 32,
    GrabTypeSelector = 33,
    GroundNormalBlender = 34,
    GroundNormalSelector = 35,
    GroundNormalSideBlender = 36,
    GroundNormalSideSelector = 37,
    MaskSelector = 38,
    MatVisibilityAsset = 39,
    MouthSelector = 40,
    NoAnmAsset = 41,
    NoLoopStickAngleBlender = 42,
    NoLoopStickAngleSelector = 43,
    NodePosSelector = 44,
    PersonalitySelector = 45,
    PostureSelector = 46,
    PreASSelector = 47,
    PreExclusionRandomSelector = 48,
    RandomSelector = 49,
    RideSelector = 50,
    RightStickAngleBlender = 51,
    RightStickAngleSelector = 52,
    RightStickValueBlender = 53,
    RightStickValueSelector = 54,
    RightStickXBlender = 55,
    RightStickXSelector = 56,
    RightStickYBlender = 57,
    RightStickYSelector = 58,
    SelfHeightSelector = 59,
    SelfWeightSelector = 60,
    SequencePlayContainer = 61,
    ShaderParamAsset = 62,
    ShaderParamColorAsset = 63,
    ShaderParamTexSRTAsset = 64,
    SizeBlender = 65,
    SizeSelector = 66,
    SkeltalAsset = 67,
    SpeedBlender = 68,
    SpeedSelector = 69,
    StickAngleBlender = 70,
    StickAngleSelector = 71,
    StickValueBlender = 72,
    StickValueSelector = 73,
    StickXBlender = 74,
    StickXSelector = 75,
    StickYBlender = 76,
    StickYSelector = 77,
    StressBlender = 78,
    StressSelector = 79,
    SyncPlayContainer = 80,
    TemperatureBlender = 81,
    TemperatureSelector = 82,
    TexturePatternAsset = 83,
    TimeSelector = 84,
    TiredBlender = 85,
    TiredSelector = 86,
    UseItemSelector = 87,
    UserAngle2Blender = 88,
    UserAngle2Selector = 89,
    UserAngleBlender = 90,
    UserAngleSelector = 91,
    UserSpeedBlender = 92,
    UserSpeedSelector = 93,
    VariationSelector = 94,
    WallAngleBlender = 95,
    WallAngleSelector = 96,
    WeaponDetailSelector = 97,
    WeaponSelector = 98,
    WeatherSelector = 99,
    WeightBlender = 100,
    WeightSelector = 101,
    WindVelocityBlender = 102,
    YSpeedBlender = 103,
    YSpeedSelector = 104,
    ZEx00ExposureBlender = 105,
    ZEx00ExposureSelector = 106,
};

enum class InitAnmDriven {
    FromAnmLoop = 0,
    None = 1,
    TranslationOnly = 2,
    RotationOnly = 3,
    TranslationAndRotation = 4,
};

}  // namespace ksys::as

namespace ksys::res {

class AS;

class ASResource {
    SEAD_RTTI_BASE(ASResource)
public:
    struct ParseArgs {
        agl::utl::ResParameterList list;
        sead::Heap* heap;
        AS* as;
        int index;
    };

    ASResource(int type_index, int index)
        : mTypeIndex(static_cast<as::ASElementType>(type_index)), mIndex(index) {}
    virtual ~ASResource() = default;

    bool parse(const ParseArgs& args);

    virtual int getMaxSkeletalAnimCount() { return 0; }
    virtual int getMaxNonSkeletalAnimCount() { return 0; }
    virtual int getMaxElementWorkCount() { return 1; }
    virtual int needsExtraSkeletalAnims() { return 0; }

    static const sead::SafeString& getDefaultStr();
    static ASResource* make(const ParseArgs& args);

    as::ASElementType getTypeIndex() const { return mTypeIndex; }
    u16 getIndex() const { return mIndex; }
    int findStringIndex(const sead::SafeString& value) const;
    int findIntIndex(int value) const;

    agl::utl::ParameterList& getList() { return mList; }

protected:
    virtual bool doParse(const ParseArgs& args) { return true; }

    as::ASElementType mTypeIndex{};
    u16 mIndex{};
    agl::utl::ParameterList mList;
    ASExtensions mExtensions;
};

class ASResourceWithChildren : public ASResource {
    SEAD_RTTI_OVERRIDE(ASResourceWithChildren, ASResource)
public:
    using ASResource::ASResource;
    ~ASResourceWithChildren() override;
    ASResourceWithChildren(const ASResourceWithChildren&) = delete;
    auto operator=(const ASResourceWithChildren&) = delete;

    int getMaxSkeletalAnimCount() override {
        return callOnChildren_(&ASResource::getMaxSkeletalAnimCount);
    }
    int getMaxNonSkeletalAnimCount() override {
        return callOnChildren_(&ASResource::getMaxNonSkeletalAnimCount);
    }
    int getMaxElementWorkCount() override {
        return callOnChildren_(&ASResource::getMaxElementWorkCount) + 1;
    }

protected:
    using MemberFunction = int (ASResource::*)();

    bool doParse(const ParseArgs& args) override;
    virtual int callOnChildren_(MemberFunction fn);

    sead::Buffer<ASResource*> mChildren;
};

class ASSequencePlayContainerResource : public ASResourceWithChildren {
    SEAD_RTTI_OVERRIDE(ASSequencePlayContainerResource, ASResourceWithChildren)
public:
    using ASResourceWithChildren::ASResourceWithChildren;

    const auto& getSequenceLoop() const { return *mSequenceLoop; }
    float getValue(int index) const;

protected:
    bool doParse(const ParseArgs& args) override;
    int callOnChildren_(MemberFunction fn) override;
    int needsExtraSkeletalAnims() override;

    agl::utl::ParameterObj mObj;
    agl::utl::Parameter<bool> mSequenceLoop;
};

class ASSelectorResource : public ASResourceWithChildren {
    SEAD_RTTI_OVERRIDE(ASSelectorResource, ASResourceWithChildren)
public:
    using ASResourceWithChildren::ASResourceWithChildren;

    const auto& getNoSync() const { return *mNoSync; }
    const auto& getJudgeOnce() const { return *mJudgeOnce; }

protected:
    bool doParse(const ParseArgs& args) override;
    int callOnChildren_(MemberFunction fn) override;

    agl::utl::ParameterObj mObj;
    agl::utl::Parameter<bool> mNoSync;
    agl::utl::Parameter<bool> mJudgeOnce;
};

class ASBlenderResource : public ASResourceWithChildren {
    SEAD_RTTI_OVERRIDE(ASBlenderResource, ASResourceWithChildren)
public:
    using ASResourceWithChildren::ASResourceWithChildren;

    const auto& getNoSync() const { return *mNoSync; }
    const auto& getJudgeOnce() const { return *mJudgeOnce; }
    const auto& getInputLimit() const { return *mInputLimit; }

protected:
    bool doParse(const ParseArgs& args) override;
    int callOnChildren_(MemberFunction fn) override;

    agl::utl::ParameterObj mObj;
    agl::utl::Parameter<bool> mNoSync;
    agl::utl::Parameter<bool> mJudgeOnce;
    agl::utl::Parameter<float> mInputLimit;
};

class ASAssetResource : public ASResource {
    SEAD_RTTI_OVERRIDE(ASAssetResource, ASResource)
public:
    using ASResource::ASResource;

    const sead::SafeString& getFileName() const { return *mFileName; }

protected:
    bool doParse(const ParseArgs& args) override;

    agl::utl::ParameterObj mObj;
    agl::utl::Parameter<sead::SafeString> mFileName;
};

class ASAssetExResource : public ASAssetResource {
    SEAD_RTTI_OVERRIDE(ASAssetExResource, ASAssetResource)
public:
    using ASAssetResource::ASAssetResource;

protected:
    int getMaxNonSkeletalAnimCount() override { return 1; }
};

class ASSkeltalAssetResource : public ASAssetResource {
    SEAD_RTTI_OVERRIDE(ASSkeltalAssetResource, ASAssetResource)
public:
    using ASAssetResource::ASAssetResource;

    const auto& getInitAnmDriven() const { return *mInitAnmDriven; }
    const auto& getMorph() const { return *mMorph; }
    const auto& getResetMorph() const { return *mResetMorph; }

protected:
    int getMaxSkeletalAnimCount() override { return 1; }
    bool doParse(const ParseArgs& args) override;

    agl::utl::Parameter<int> mInitAnmDriven;
    agl::utl::Parameter<float> mMorph;
    agl::utl::Parameter<float> mResetMorph;
};

}  // namespace ksys::res
