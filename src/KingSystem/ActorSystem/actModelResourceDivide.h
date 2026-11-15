#pragma once

#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Resource/resResourceBinder.h"

namespace al {
class ByamlIter;
}

namespace ksys::act {

class ModelResourceDivide {
    SEAD_SINGLETON_DISPOSER(ModelResourceDivide)
    ModelResourceDivide() = default;
    virtual ~ModelResourceDivide();

public:
    void init(sead::Heap* heap);

    const char* getModelResource(const sead::SafeString& model_name,
                                 const sead::SafeString& fmdb_name) const;

private:
    al::ByamlIter* mIter{};
    res::ResourceBinder mHandle;
};
KSYS_CHECK_SIZE_NX150(ModelResourceDivide, 0x80);

}  // namespace ksys::act
