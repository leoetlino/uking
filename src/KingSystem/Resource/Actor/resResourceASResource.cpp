#include "KingSystem/Resource/Actor/resResourceASResource.h"
#include <limits>
#include <prim/seadSafeString.h>
#include "KingSystem/ActorSystem/AS/ASList.h"
#include "KingSystem/Resource/Actor/resResourceAS.h"

namespace ksys::as {
class Element;
}

namespace ksys::res {

namespace {

using as::ASKey;

struct ASElementFactory {
    const char* name;
    ASResource* (*make_res)(int type_index, const ASResource::ParseArgs& args);
    // FIXME: signature
    as::Element* (*make)();
    ASKey key;
};

sead::SafeString sStr_default = "default";

template <typename T>
ASResource* resFactoryImpl_(int type_index, const ASResource::ParseArgs& arg) {
    return new (arg.heap) T(type_index, arg.index);
}

// FIXME: make functions
sead::SafeArray<ASElementFactory, 107> sFactories{{
    /* 000 */ {"AbsTemperatureBlender", resFactoryImpl_<ASBlenderResource>, nullptr,
               ASKey::AbsTemperature},
    /* 001 */
    {"AbsTemperatureSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::AbsTemperature},
    /* 002 */ {"ArmorSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Armor},
    /* 003 */ {"ArrowSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Arrow},
    /* 004 */ {"AttentionSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Attention},
    /* 005 */ {"BoneBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Bone},
    /* 006 */ {"BoneVisibilityAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},
    /* 007 */ {"BoolSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Bool},
    /* 008 */ {"ButtonSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Button},
    /* 009 */ {"ChargeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Charge},

    /* 010 */ {"ClearMatAnmAsset", resFactoryImpl_<ASResource>, nullptr, ASKey::None},
    /* 011 */ {"ComboSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Combo},
    /* 012 */ {"DiffAngleYBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::DiffAngleY},
    /* 013 */
    {"DiffAngleYSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::DiffAngleY},
    /* 014 */
    {"DirectionAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::DirectionAngle},
    /* 015 */
    {"DirectionAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::DirectionAngle},
    /* 016 */ {"DistanceBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Distance},
    /* 017 */ {"DistanceSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Distance},
    /* 018 */
    {"DungeonClearSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::DungeonClear},
    /* 019 */
    {"DungeonNumberSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::DungeonNumber},

    /* 020 */ {"EmotionSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Emotion},
    /* 021 */ {"EventFlagSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::EventFlag},
    /* 022 */ {"EyeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Eye},
    /* 023 */ {"EyebrowSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Eyebrow},
    /* 024 */
    {"FaceEmotionSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::FaceEmotion},
    /* 025 */
    {"FootBLLifeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::FootBLLife},
    /* 026 */
    {"FootBRLifeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::FootBRLife},
    /* 027 */
    {"FootFLLifeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::FootFLLife},
    /* 028 */
    {"FootFRLifeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::FootFRLife},
    /* 029 */
    {"ForwardBentBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::ForwardBent},

    /* 030 */
    {"ForwardBentSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::ForwardBent},
    /* 031 */ {"GearSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Gear},
    /* 032 */
    {"GenerationSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Generation},
    /* 033 */ {"GrabTypeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::GrabType},
    /* 034 */
    {"GroundNormalBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::GroundNormal},
    /* 035 */
    {"GroundNormalSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::GroundNormal},
    /* 036 */
    {"GroundNormalSideBlender", resFactoryImpl_<ASBlenderResource>, nullptr,
     ASKey::GroundNormalSide},
    /* 037 */
    {"GroundNormalSideSelector", resFactoryImpl_<ASSelectorResource>, nullptr,
     ASKey::GroundNormalSide},
    /* 038 */ {"MaskSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Mask},
    /* 039 */ {"MatVisibilityAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},

    /* 040 */ {"MouthSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Mouth},
    /* 041 */ {"NoAnmAsset", resFactoryImpl_<ASResource>, nullptr, ASKey::None},
    /* 042 */
    {"NoLoopStickAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr,
     ASKey::NoLoopStickAngle},
    /* 043 */
    {"NoLoopStickAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr,
     ASKey::NoLoopStickAngle},
    /* 044 */ {"NodePosSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::NodePos},
    /* 045 */
    {"PersonalitySelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Personality},
    /* 046 */ {"PostureSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Posture},
    /* 047 */ {"PreASSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::PreAS},
    /* 048 */
    {"PreExclusionRandomSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Random},
    /* 049 */ {"RandomSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Random},

    /* 050 */ {"RideSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Ride},
    /* 051 */
    {"RightStickAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::RightStickAngle},
    /* 052 */
    {"RightStickAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr,
     ASKey::RightStickAngle},
    /* 053 */
    {"RightStickValueBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::RightStickValue},
    /* 054 */
    {"RightStickValueSelector", resFactoryImpl_<ASSelectorResource>, nullptr,
     ASKey::RightStickValue},
    /* 055 */
    {"RightStickXBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::RightStickX},
    /* 056 */
    {"RightStickXSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::RightStickX},
    /* 057 */
    {"RightStickYBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::RightStickY},
    /* 058 */
    {"RightStickYSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::RightStickY},
    /* 059 */
    {"SelfHeightSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::SelfHeight},

    /* 060 */
    {"SelfWeightSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::SelfWeight},
    /* 061 */
    {"SequencePlayContainer", resFactoryImpl_<ASSequencePlayContainerResource>, nullptr,
     ASKey::None},
    /* 062 */ {"ShaderParamAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},
    /* 063 */ {"ShaderParamColorAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},
    /* 064 */ {"ShaderParamTexSRTAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},
    /* 065 */ {"SizeBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Size},
    /* 066 */ {"SizeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Size},
    /* 067 */ {"SkeltalAsset", resFactoryImpl_<ASSkeltalAssetResource>, nullptr, ASKey::None},
    /* 068 */ {"SpeedBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Speed},
    /* 069 */ {"SpeedSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Speed},

    /* 070 */ {"StickAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::StickAngle},
    /* 071 */
    {"StickAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::StickAngle},
    /* 072 */ {"StickValueBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::StickValue},
    /* 073 */
    {"StickValueSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::StickValue},
    /* 074 */ {"StickXBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::StickX},
    /* 075 */ {"StickXSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::StickX},
    /* 076 */ {"StickYBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::StickY},
    /* 077 */ {"StickYSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::StickY},
    /* 078 */ {"StressBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Stress},
    /* 079 */ {"StressSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Stress},

    /* 080 */ {"SyncPlayContainer", resFactoryImpl_<ASResourceWithChildren>, nullptr, ASKey::None},
    /* 081 */
    {"TemperatureBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Temperature},
    /* 082 */
    {"TemperatureSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Temperature},
    /* 083 */ {"TexturePatternAsset", resFactoryImpl_<ASAssetExResource>, nullptr, ASKey::None},
    /* 084 */ {"TimeSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Time},
    /* 085 */ {"TiredBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Tired},
    /* 086 */ {"TiredSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Tired},
    /* 087 */ {"UseItemSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::UseItem},
    /* 088 */ {"UserAngle2Blender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::UserAngle2},
    /* 089 */
    {"UserAngle2Selector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::UserAngle2},

    /* 090 */ {"UserAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::UserAngle},
    /* 091 */ {"UserAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::UserAngle},
    /* 092 */ {"UserSpeedBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::UserSpeed},
    /* 093 */ {"UserSpeedSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::UserSpeed},
    /* 094 */ {"VariationSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Variation},
    /* 095 */ {"WallAngleBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::WallAngle},
    /* 096 */ {"WallAngleSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::WallAngle},
    /* 097 */
    {"WeaponDetailSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::WeaponDetail},
    /* 098 */ {"WeaponSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Weapon},
    /* 099 */ {"WeatherSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Weather},

    /* 100 */ {"WeightBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::Weight},
    /* 101 */ {"WeightSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::Weight},
    /* 102 */
    {"WindVelocityBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::WindVelocity},
    /* 103 */ {"YSpeedBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::YSpeed},
    /* 104 */ {"YSpeedSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::YSpeed},
    /* 105 */
    {"ZEx00ExposureBlender", resFactoryImpl_<ASBlenderResource>, nullptr, ASKey::ZEx00Exposure},
    /* 106 */
    {"ZEx00ExposureSelector", resFactoryImpl_<ASSelectorResource>, nullptr, ASKey::ZEx00Exposure},
}};

}  // namespace

bool ASResource::parse(const ASResource::ParseArgs& args) {
    if (!doParse(args))
        return false;

    ASExtensions::ParseArgs parse_args{};
    parse_args.heap = args.heap;
    parse_args.list = &mList;
    parse_args.res_list = args.list;
    return mExtensions.parse(parse_args);
}

int ASResource::findStringIndex(const sead::SafeString& value) const {
    auto* parser = sead::DynamicCast<ASStringArrayParser>(
        mExtensions.getParser(ASParamParser::Type::StringArray));

    if (!parser)
        return -1;

    const u32 size = parser->getValues().size();
    if (size == 0)
        return -1;

    for (u32 i = 0; i < size; ++i) {
        if (value == *parser->getValues()[i].value)
            return i;
    }

    const int default_idx = int(size - 1);
    if (default_idx < 0)
        return -1;
    if (getDefaultStr() == *parser->getValues()[default_idx].value)
        return default_idx;
    return -1;
}

int ASResource::findIntIndex(int value) const {
    auto* parser =
        sead::DynamicCast<ASIntArrayParser>(mExtensions.getParser(ASParamParser::Type::IntArray));
    if (parser) {
        const u32 size = parser->getValues().size();
        if (size == 0)
            return -1;

        for (u32 i = 0; i < size; ++i) {
            if (*parser->getValues()[i].value == value)
                return i;
        }

        const int default_idx = int(size - 1);
        if (default_idx >= 0 &&
            *parser->getValues()[default_idx].value == std::numeric_limits<int>::min()) {
            return default_idx;
        }
    }
    return -1;
}

const sead::SafeString& ASResource::getDefaultStr() {
    return sStr_default;
}

ASResourceWithChildren::~ASResourceWithChildren() {
    mChildren.freeBuffer();
}

// NON_MATCHING: getParameterData (redundant uxtw which leads to localised regalloc diffs)
bool ASResourceWithChildren::doParse(const ASResource::ParseArgs& args) {
    const auto Children = agl::utl::getResParameterObj(args.list, "Children");
    if (!Children)
        return true;

    const auto size = Children.getNum();
    if (size == 0)
        return true;

    if (!mChildren.tryAllocBuffer(size, args.heap))
        return false;
    mChildren.fill(nullptr);

    for (auto it = mChildren.begin(), end = mChildren.end(); it != end; ++it) {
        const auto idx = *Children.getParameterData<int>(it.getIndex());
        *it = args.as->getElementResources()[idx];
    }

    return true;
}

int ASResourceWithChildren::callOnChildren_(MemberFunction fn) {
    int ret = 0;
    for (int i = 0; i < mChildren.size(); ++i)
        ret += (mChildren[i]->*fn)();
    return ret;
}

bool ASSequencePlayContainerResource::doParse(const ASResource::ParseArgs& args) {
    if (!ASResourceWithChildren::doParse(args))
        return false;

    mSequenceLoop.init(false, "SequenceLoop", "シーケンスループ", &mObj);

    mList.addObj(&mObj, "Parameters");
    return true;
}

int ASSequencePlayContainerResource::callOnChildren_(ASResourceWithChildren::MemberFunction fn) {
    int ret = 0;
    for (int i = 0; i < mChildren.size(); ++i) {
        int value = (mChildren[i]->*fn)();
        if (u32(ret) <= u32(value))
            ret = value;
    }
    return ret;
}

int ASSequencePlayContainerResource::needsExtraSkeletalAnims() {
    auto* parser = sead::DynamicCast<ASFloatArrayParser>(
        mExtensions.getParser(ASParamParser::Type::FloatArray));
    if (!parser)
        return 0;

    for (int i = 0, n = parser->getValues().size(); i < n; ++i) {
        if (*parser->getValues()[i].value < 1.0)
            return 1;
    }
    return 0;
}

float ASSequencePlayContainerResource::getValue(int index) const {
    auto* parser = sead::DynamicCast<ASFloatArrayParser>(
        mExtensions.getParser(ASParamParser::Type::FloatArray));
    if (!parser || parser->getValues().size() <= index)
        return 1.0;
    return *parser->getValues()[index].value;
}

bool ASSelectorResource::doParse(const ASResource::ParseArgs& args) {
    if (!ASResourceWithChildren::doParse(args))
        return false;

    mNoSync.init(false, "NoSync", "非同期", &mObj);
    mJudgeOnce.init(true, "JudgeOnce", "初期化時のみ判定", &mObj);

    mList.addObj(&mObj, "Parameters");
    return true;
}

int ASSelectorResource::callOnChildren_(ASResourceWithChildren::MemberFunction fn) {
    int ret = 0;
    for (int i = 0; i < mChildren.size(); ++i) {
        int value = (mChildren[i]->*fn)();
        if (u32(ret) <= u32(value))
            ret = value;
    }
    return ret;
}

bool ASBlenderResource::doParse(const ASResource::ParseArgs& args) {
    if (!ASResourceWithChildren::doParse(args))
        return false;

    mNoSync.init(false, "NoSync", "非同期", &mObj);
    mJudgeOnce.init(false, "JudgeOnce", "初期化時のみ判定", &mObj);
    mInputLimit.init(-1.0, "InputLimit", "入力変化制限", &mObj);

    mList.addObj(&mObj, "Parameters");
    return true;
}

int ASBlenderResource::callOnChildren_(ASResourceWithChildren::MemberFunction fn) {
    if (mChildren.size() == 0)
        return 0;

    const u32 first = (mChildren[0]->*fn)();

    u32 max = first;
    u32 previous = first;
    for (int i = 1; i < mChildren.size(); ++i) {
        const u32 current = (mChildren[i]->*fn)();
        if (max <= previous + current)
            max = previous + current;
        previous = current;
    }

    if (max <= first + previous)
        max = first + previous;

    return max;
}

bool ASAssetResource::doParse(const ASResource::ParseArgs& args) {
    mFileName.init("", "FileName", "ファイル名", &mObj);

    mList.addObj(&mObj, "Parameters");
    return true;
}

bool ASSkeltalAssetResource::doParse(const ASResource::ParseArgs& args) {
    ASAssetResource::doParse(args);

    mMorph.init(5.0, "Morph", "補間", "Min=0.f,Max=20.f", &mObj);
    mResetMorph.init(5.0, "ResetMorph", "リセット時補間", "Min=0.f,Max=20.f", &mObj);
    mInitAnmDriven.init(false, "InitAnmDriven", "初期アニメドリブン", "", &mObj);

    return true;
}

ASResource* ASResource::make(const ASResource::ParseArgs& args) {
    const auto Parameters = agl::utl::getResParameterObj(args.list, "Parameters");

    const auto TypeIndex = agl::utl::getResParameter(Parameters, "TypeIndex");
    if (!TypeIndex.ptr())
        return nullptr;

    const auto type_index = *TypeIndex.getData<int>();
    if (u32(type_index) >= u32(sFactories.size()))
        return nullptr;

    return sFactories[type_index].make_res(type_index, args);
}

}  // namespace ksys::res
