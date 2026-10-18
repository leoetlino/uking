#include "KingSystem/Resource/Actor/resResourceAS.h"
#include <memory>
#include <random/seadGlobalRandom.h>
#include "KingSystem/Utils/HeapUtil.h"
#include "KingSystem/Utils/SafeDelete.h"
#include "resResourceASResource.h"

namespace ksys::res {

namespace {
sead::SafeString str_Elements = "Elements";
sead::SafeString str_CommonParams = "CommonParams";
}  // namespace

AS::AS() : ParamIO("as", 0) {}

AS::~AS() = default;

void AS::doCreate_(u8*, u32, sead::Heap*) {}

bool AS::parse_(u8* data, size_t size, sead::Heap* parent_heap) {
    mHeap = util::tryCreateDualHeap(parent_heap);
    if (!mHeap)
        return false;

    mHeap->enableWarning(false);
    auto* heap = mHeap;

    agl::utl::ResParameterArchive archive{data};
    const auto root = archive.getRootList();

    const auto Elements = agl::utl::getResParameterList(root, str_Elements);
    if (!Elements) {
        mHeap->adjust();
        return true;
    }

    const int num_elements = Elements.getResParameterListNum();
    if (num_elements == 0) {
        mHeap->adjust();
        return true;
    }

    if (!mElementResources.tryAllocBuffer(num_elements, heap)) {
        mHeap->adjust();
        return false;
    }

    mElementResources.fill(nullptr);

    ASResource::ParseArgs args;
    args.list = {};
    args.heap = heap;
    args.as = this;
    args.index = 0;

    auto res_it = Elements.listBegin();
    const auto res_end = Elements.listEnd();

    sead::FixedSafeString<16> name{"Element"};
    const auto name_prefix_len = name.calcLength();

    for (auto it = mElementResources.begin(), end = mElementResources.end();
         it != end && res_it != res_end; ++it, ++res_it) {
        args.list = res_it.getList();
        *it = ASResource::make(args);
        if (*it == nullptr) {
            mHeap->adjust();
            return false;
        }

        name.trim(name_prefix_len);
        name.appendWithFormat("%d", args.index);
        mElementsList.addList(&(*it)->getList(), name);
        ++args.index;
    }

    addList(&mElementsList, str_Elements);

    mRandomRateMin.init(1.0, "RandomRateMin", "ランダム再生率小", "Min=0.f,Max=10.f",
                        &mCommonParams);
    mRandomRateMax.init(1.0, "RandomRateMax", "ランダム再生率大", "Min=0.f,Max=10.f",
                        &mCommonParams);
    mForbidPartialDemoAS.init(false, "ForbidPartialDemoAS", "一括再生する", "", &mCommonParams);
    mUseIK.init(true, "UseIK", "IKする", "", &mCommonParams);

    addObj(&mCommonParams, str_CommonParams);

    mAssetExKinds = 0;

    res_it = Elements.listBegin();
    args.index = 0;
    for (auto it = mElementResources.begin(), end = mElementResources.end();
         it != end && res_it != res_end; ++it, ++res_it) {
        args.list = res_it.getList();
        if (!(*it)->parse(args)) {
            mHeap->adjust();
            return false;
        }

        mNeedsExtraSkeletalAnims |= (*it)->needsExtraSkeletalAnims() & 1;

        switch ((*it)->getTypeIndex()) {
        case as::ASElementType::ShaderParamAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::ShaderParam);
            break;
        case as::ASElementType::ShaderParamColorAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::ShaderParamColor);
            break;
        case as::ASElementType::ShaderParamTexSRTAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::ShaderParamTexSRT);
            break;
        case as::ASElementType::TexturePatternAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::TexturePattern);
            break;
        case as::ASElementType::BoneVisibilityAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::BoneVisibility);
            break;
        case as::ASElementType::MatVisibilityAsset:
            mAssetExKinds |= u8(ASAssetExKindFlags::MatVisibility);
            break;
        default:
            break;
        }
        ++args.index;
    }

    applyResParameterArchive(archive);

    if (auto* first = getFirstResource()) {
        u32 x = first->getMaxSkeletalAnimCount();
        x = x >= 0xff ? 0xff : x;
        u32 y = first->getMaxNonSkeletalAnimCount();
        y = y >= 0xff ? 0xff : y;

        mMaxSkeletalAnimCount = x;
        mMaxNonSkeletalAnimCount = y;
    } else {
        mMaxSkeletalAnimCount = 0;
        mMaxNonSkeletalAnimCount = 0;
    }

    mHeap->adjust();
    return true;
}

ASResource* AS::getFirstResource() const {
    if (mElementResources.size() == 0)
        return nullptr;
    return mElementResources[0];
}

void AS::finalize_() {
    for (auto* ptr : mElementResources) {
        if (ptr)
            std::destroy_at(ptr);
    }

    util::safeDeleteHeap(mHeap);
}

float AS::getRandomRate() const {
    const auto max = getRandomRateMax();
    const auto min = getRandomRateMin();
    if (max - min > 0.0)
        return sead::GlobalRandom::instance()->getF32Range(min, max);
    return min;
}

}  // namespace ksys::res
