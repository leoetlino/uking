#include "KingSystem/PlayReport/ProductReportMgr.h"
#include "KingSystem/PlayReport/ProductReporter.h"

namespace ksys {

SEAD_SINGLETON_DISPOSER_IMPL(ProductReportMgr)

ProductReportMgr::~ProductReportMgr() {
    if (mReporter)
        delete mReporter;
}

void ProductReportMgr::calc() {
    if (!_30 && mReporter)
        mReporter->updateTimers();
}

void ProductReportMgr::reportDebug(const sead::SafeString& message, const sead::SafeString& data) {
    // Stubbed in release builds
}

bool ProductReportMgr::auto0() const {
    return true;
}

PlayerTrackReporter* ProductReportMgr::getPlayerTrackReporter() const {
    if (!mReporter)
        return nullptr;
    return mReporter->getPlayerTrackReporter();
}

void ProductReportMgr::setPlayerTrackReporter28() {
    if (auto* reporter = getPlayerTrackReporter())
        reporter->_28 = true;
}

void ProductReportMgr::setPlayerTrackReporter29() {
    if (auto* reporter = getPlayerTrackReporter())
        reporter->_29 = true;
}

void ProductReportMgr::setPlayerTrackReporter30() {
    if (auto* reporter = getPlayerTrackReporter())
        reporter->_30 = true;
}

}  // namespace ksys
