#pragma once

#include <container/seadSafeArray.h>
#include <math/seadVector.h>
#include <utility/aglParameter.h>
#include <utility/aglParameterObj.h>
#include "KingSystem/Utils/Types.h"
#include "KingSystem/World/worldJob.h"

namespace ksys::world {

// TODO
class SkyMgr : public Job {
    SEAD_RTTI_OVERRIDE(SkyMgr, Job)
public:
    struct PrCloud {
        agl::utl::Parameter<float> mScrollSpd;
        agl::utl::Parameter<float> mNoiseAdd1;
        agl::utl::Parameter<float> mNoiseAdd2;
        agl::utl::Parameter<float> mNoiseAdd1_side;
        agl::utl::Parameter<float> mNoiseAdd2_side;
        agl::utl::Parameter<float> mPosDensityChgRange;
        agl::utl::Parameter<float> mPosDensityChgPower;
        agl::utl::Parameter<float> mPosDensityChgSpeed;
        u32 _100;
        u8 mPosDensityChgState;
        agl::utl::Parameter<float> mWindVecAdd;
        float mWindVecAddRandom;
        u32 _12c;
        agl::utl::Parameter<int> mBaseTextureNo;
        agl::utl::Parameter<int> mNoiseTextureNo;
        agl::utl::Parameter<bool> mbCloudTexBlend;
        agl::utl::Parameter<float> mCloudTexBlendRate;
        agl::utl::Parameter<int> mBaseTextureNo_Blend;
        agl::utl::Parameter<int> mNoiseTextureNo_Blend;
        agl::utl::ParameterObj mObj;
    };
    KSYS_CHECK_SIZE_NX150(PrCloud, 0x220);

    struct PrCloudV {
        agl::utl::Parameter<float> mDistotion;
        agl::utl::Parameter<float> mDensity;
        agl::utl::Parameter<float> mAlphaMul;
        agl::utl::Parameter<float> mAlphaThreshold;
        agl::utl::Parameter<float> mBaseTexScale;
        agl::utl::Parameter<float> mEmbossWidth;
        agl::utl::Parameter<float> mEmbossDensity;
        agl::utl::Parameter<float> mShadowPower;
        agl::utl::Parameter<float> mHighlightPower;
        agl::utl::Parameter<float> mHighlightRange;
        agl::utl::Parameter<float> mHighlightAmbient;
        agl::utl::Parameter<float> mSkyHeight;
        agl::utl::Parameter<float> mDensityMax;
        agl::utl::Parameter<float> mDensityMin;
        agl::utl::Parameter<float> mDensitySinSeedAdd;
        float mDensitySinPhase;
        bool mDensitySinOff;
        agl::utl::Parameter<float> mAlphaMulMax;
        agl::utl::Parameter<float> mAlphaMulMin;
        agl::utl::Parameter<float> mAlphaMulSinSeedAdd;
        float mAlphaMulSinPhase;
        bool mAlphaMulSinOff;
        agl::utl::Parameter<float> mDistotionMax;
        agl::utl::Parameter<float> mDistotionMin;
        agl::utl::Parameter<float> mDistotionSinSeedAdd;
        float mDistotionSinPhase;
        bool mDistotionSinOff;
        agl::utl::Parameter<float> mAlphaThresholdMax;
        agl::utl::Parameter<float> mAlphaThresholdMin;
        agl::utl::Parameter<float> mAlphaThresholdSinSeedAdd;
        float mAlphaThresholdSinPhase;
        bool mAlphaThresholdSinOff;
        agl::utl::Parameter<float> mSkyHeightMax;
        agl::utl::Parameter<float> mSkyHeightMin;
        agl::utl::Parameter<float> mSkyHeightSinSeedAdd;
        float mSkyHeightSinPhase;
        bool mSkyHeightSinOff;
        agl::utl::Parameter<float> mBaseTexScaleMax;
        agl::utl::Parameter<float> mBaseTexScaleMin;
        agl::utl::Parameter<float> mBaseTexScaleSinSeedAdd;
        float mBaseTexScaleSinPhase;
        bool mBaseTexScaleSinOff;
        agl::utl::Parameter<float> mBacklightPowe;
        agl::utl::Parameter<float> mBacklightRange;
        agl::utl::Parameter<float> mBacklightParam0;
        agl::utl::Parameter<float> mBacklightParam1;
        agl::utl::Parameter<float> mDarkSideNoiseParam;
        agl::utl::Parameter<float> mLightSideNoiseParam;
        agl::utl::ParameterObj mObj;
    };
    KSYS_CHECK_SIZE_NX150(PrCloudV, 0x4e0);

    struct SkyPalette {
        agl::utl::Parameter<float> mPosDensityChgPower;
        agl::utl::Parameter<float> mHeight;
        agl::utl::Parameter<float> mDistotion;
        agl::utl::Parameter<float> mDensity;
        agl::utl::Parameter<float> mAlphaMul;
        agl::utl::Parameter<float> mAlphaThreshold;
        agl::utl::Parameter<float> mBaseTexScale;
        agl::utl::Parameter<float> mSkyTexBlendRatio;
        agl::utl::ParameterObj mObj;
    };
    KSYS_CHECK_SIZE_NX150(SkyPalette, 0x130);

    static constexpr int NumSkyPalettes = 8;

    struct CloudPat {
        agl::utl::Parameter<float> mHeight;
        agl::utl::Parameter<float> mDistotion;
        agl::utl::Parameter<float> mDensity;
        agl::utl::Parameter<float> mAlphaMul;
        agl::utl::Parameter<float> mAlphaThreshold;
        agl::utl::Parameter<float> mTexBlendRatio;
        agl::utl::ParameterObj mObj;
    };
    KSYS_CHECK_SIZE_NX150(CloudPat, 0xf0);

    static constexpr int NumCloudPats = 3;

    struct CloudSpd {
        agl::utl::Parameter<float> mCloudPatNoisePow;
        agl::utl::Parameter<float> mCloudPatWindPow;
        agl::utl::ParameterObj mObj;
    };
    KSYS_CHECK_SIZE_NX150(CloudSpd, 0x70);

    SkyMgr();
    ~SkyMgr() override;

    void init_(sead::Heap* heap) override;
    void calcType2_() override;
    JobType getType() const override { return JobType::Sky; }

    void reset();
    void onTimeUpdate();

private:
    friend class Manager;

    struct LightDirs {
        sead::Vector3f mEnvDifLightDir;
        sead::Vector3f mLightDirRaw;
        sead::Vector3f _18;
        sead::Vector3f _24;
        sead::Vector3f _30;
        sead::Vector3f _3c;
    };
    LightDirs mLightDirs;
    u16 _68;
    sead::SafeArray<PrCloud, 3> mPrCloud;
    sead::SafeArray<sead::SafeArray<PrCloudV, 2>, 3> mPrCloudV;
    sead::SafeArray<SkyPalette, NumSkyPalettes> mSkyPalette0;
    sead::SafeArray<SkyPalette, NumSkyPalettes> mSkyPalette2;
    sead::SafeArray<CloudPat, NumCloudPats> mCloudPat0;
    sead::SafeArray<CloudPat, NumCloudPats> mCloudPat2;
    sead::SafeArray<CloudSpd, NumCloudPats> mCloudSpd;
    u8 _3e00[8];
    agl::utl::Parameter<float> mSunSlope;
    agl::utl::Parameter<float> mSunMoonDispDist;
    agl::utl::Parameter<float> mSunScale;
    agl::utl::Parameter<float> mMoonScale;
    agl::utl::Parameter<float> mSunDirYStop;
    agl::utl::ParameterObj mSunParamObj;
    sead::Vector3f mSunDir;
    sead::Vector3f mWindDir;
    sead::Vector3f mSunMoonLightDir;
    sead::Vector3f mSunMoonDir;
    sead::Vector3f mLightDir;
    sead::Vector3f mSunPathAxis;
    sead::Vector2f mCloudShadowOffset;
    sead::Vector2f mCloudShadowSpeed;
    int _3f30;
    int _3f34;
    float mLightChangeSpeed;
    float mCloudyRate;
    float mPeriodicRandom;
    float mSunMoonPathRate;
    float mWindAngle;
    float mWindSpeed;
    float mCloudShadowFade;
    float mCloudTexBlendSpeed;
    float mCloudShadowRatio;
    float mDepthShadowLightningFade;
    int _3f60;
    int _3f64;
    float mCloudShadowEnvRate;
    float mCloudShadowOutdoorRate;
    float mMoonlightRate;
    float mNewMoonLightRate;
    float mDepthShadowBluesky;
    float mDepthShadowRain;
    float mDepthShadowHeavyRain;
    float mDepthShadowThunderRain;
    float mDepthShadowSnow;
    float mDepthShadowHeavySnow;
    float mDepthShadowRate;
    float mCloudVisibleRate;
    float _3f98;
    int mCloudShadowOffFrames;
    int mCloudShadowSpeedOverrideFrames;
    int mSkyPaletteType;
    int mSkyPaletteTypeFrames;
    bool mIsNight;
    bool _3fad;
    bool mUseEnvDifLightDir;
    bool _3faf;
    bool _3fb0;
    bool mEnvDifLightDirTransition;
};
KSYS_CHECK_SIZE_NX150(SkyMgr, 0x3fb8);

}  // namespace ksys::world
