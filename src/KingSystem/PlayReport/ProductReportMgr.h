#pragma once

#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>
#include "KingSystem/PlayReport/ProductReporter.h"
#include "KingSystem/Utils/Types.h"

namespace ksys {

namespace act {
class PlayerLink;
}

class ProductReporter;

class ProductReportMgr {
    SEAD_SINGLETON_DISPOSER(ProductReportMgr)
    ProductReportMgr() = default;
    virtual ~ProductReportMgr();

public:
    void init(sead::Heap* heap);

    void calc();

    void reportDebug(const sead::SafeString& message, const sead::SafeString& data);

    bool auto0() const;
    PlayerTrackReporter* getPlayerTrackReporter() const;

    void setPlayerTrackReporter28();
    void setPlayerTrackReporter29();
    void setPlayerTrackReporter30();

    ProductReporter* getReporter() const { return mReporter; }

    bool get30() const { return _30; }
    void set30(bool arg_30) { _30 = arg_30; }

private:
    ProductReporter* mReporter = nullptr;
    bool _30 = false;
    act::PlayerLink* mPlayerLink = nullptr;
};
KSYS_CHECK_SIZE_NX150(ProductReportMgr, 0x40);

}  // namespace ksys
