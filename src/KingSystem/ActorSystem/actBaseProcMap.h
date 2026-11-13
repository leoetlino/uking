#pragma once

#include "KingSystem/Utils/Container/StrTreeMap.h"

namespace ksys::act {

class BaseProc;

class BaseProcMapNode final : public util::StrTreeMapNode {
public:
    explicit BaseProcMapNode(BaseProc* proc) : mProc(proc) {}
    ~BaseProcMapNode() override;

    void erase_() override {
        unlink_();
        StrTreeMapNode::erase_();
        mInserted = false;
        mPrev = mNext = nullptr;
    }

    util::StrTreeMapKey& key() { return mKey; }
    const util::StrTreeMapKey& key() const { return mKey; }
    BaseProc* proc() const { return mProc; }
    BaseProcMapNode* prev() const { return mPrev; }
    BaseProcMapNode* next() const { return mNext; }

    void add(BaseProcMapNode* node) {
        auto next = mNext;
        node->mPrev = this;
        node->mNext = next;
        mNext = node;
        if (next)
            next->mPrev = node;
    }

    bool isInserted() const { return mInserted; }
    void setInserted() { mInserted = true; }

private:
    void unlink_() {
        if (mPrev)
            mPrev->mNext = mNext;

        if (mNext)
            mNext->mPrev = mPrev;
    }

    BaseProc* mProc = nullptr;
    BaseProcMapNode* mPrev = nullptr;
    BaseProcMapNode* mNext = nullptr;
    bool mInserted = false;
};

}  // namespace ksys::act
