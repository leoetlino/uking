#include "KingSystem/Chemical/chmRes.h"

namespace ksys::chm {

SEAD_SINGLETON_DISPOSER_IMPL(Res)

Res::~Res() {
    mMaterials.freeBuffer();
    mWorlds.freeBuffer();
}

void Res::init(sead::Heap* heap) {
    mMaterials.allocBufferAssert(128, heap);
    mElements.allocBufferAssert(128, heap);
    mWorlds.allocBufferAssert(8, heap);

    addList(&mWorldList, "world");
    addList(&mMaterialList, "material");
    addList(&mElementList, "element");

    for (auto it = mWorlds.begin(), end = mWorlds.end(); it != end; ++it)
        mWorldList.addObj(&*it, sead::FormatFixedSafeString<1024>("%d", it.getIndex()));
    for (auto it = mMaterials.begin(), end = mMaterials.end(); it != end; ++it)
        mMaterialList.addObj(&*it, sead::FormatFixedSafeString<1024>("%d", it.getIndex()));
    for (auto it = mElements.begin(), end = mElements.end(); it != end; ++it)
        mElementList.addObj(&*it, sead::FormatFixedSafeString<1024>("%d", it.getIndex()));
}

const Res::World& Res::getWorld(const sead::SafeString& name) const {
    for (auto it = mWorlds.begin(), end = mWorlds.end(); it != end; ++it) {
        if (name == it->id.ref())
            return *it;
    }
    return mDummyWorld;
}

const Res::Material& Res::getMaterial(const sead::SafeString& name) const {
    for (auto it = mMaterials.begin(), end = mMaterials.end(); it != end; ++it) {
        if (name == it->id.ref())
            return *it;
    }
    return mDummyMaterial;
}

const Res::Element& Res::getElement(const sead::SafeString& name) const {
    for (auto it = mElements.begin(), end = mElements.end(); it != end; ++it) {
        if (name == it->name.ref())
            return *it;
    }
    return mDummyElement;
}

}  // namespace ksys::chm
