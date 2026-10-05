#pragma once

#include <container/seadSafeArray.h>
#include <prim/seadBitFlag.h>
#include "KingSystem/Game/Physics/physDefines.h"

namespace ksys::phys {

class LayerMaskBuilder {
public:
    struct Masks {
        sead::BitFlag32 layers;
        sead::BitFlag32 no_callback_delay_layers;
    };

    LayerMaskBuilder() = default;
    // XXX: this doesn't need to be virtual...
    virtual ~LayerMaskBuilder() = default;

    LayerMaskBuilder& addLayer(ContactLayer layer);
    LayerMaskBuilder& removeLayer(ContactLayer layer);
    bool hasLayer(ContactLayer layer) const;

    LayerMaskBuilder& addNoCallbackDelayLayer(ContactLayer layer);
    LayerMaskBuilder& removeNoCallbackDelayLayer(ContactLayer layer);
    bool hasNoCallbackDelayLayer(ContactLayer layer) const;

    const auto& getMasks() const { return mMasks; }

private:
    sead::SafeArray<Masks, NumContactLayerTypes> mMasks;
};

inline LayerMaskBuilder& LayerMaskBuilder::addLayer(ContactLayer layer) {
    mMasks[int(getContactLayerType(layer))].layers.set(makeContactLayerMask(layer));
    return *this;
}

inline LayerMaskBuilder& LayerMaskBuilder::removeLayer(ContactLayer layer) {
    mMasks[int(getContactLayerType(layer))].layers.reset(makeContactLayerMask(layer));
    return *this;
}

inline bool LayerMaskBuilder::hasLayer(ContactLayer layer) const {
    return (mMasks[int(getContactLayerType(layer))].layers & makeContactLayerMask(layer)) != 0;
}

inline LayerMaskBuilder& LayerMaskBuilder::addNoCallbackDelayLayer(ContactLayer layer) {
    mMasks[int(getContactLayerType(layer))].no_callback_delay_layers.set(
        makeContactLayerMask(layer));
    return *this;
}

inline LayerMaskBuilder& LayerMaskBuilder::removeNoCallbackDelayLayer(ContactLayer layer) {
    mMasks[int(getContactLayerType(layer))].no_callback_delay_layers.reset(
        makeContactLayerMask(layer));
    return *this;
}

inline bool LayerMaskBuilder::hasNoCallbackDelayLayer(ContactLayer layer) const {
    return (mMasks[int(getContactLayerType(layer))].no_callback_delay_layers &
            makeContactLayerMask(layer)) != 0;
}

}  // namespace ksys::phys
