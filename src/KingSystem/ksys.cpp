#include "KingSystem/ksys.h"
#include <heap/seadHeapMgr.h>
#include <thread/seadThread.h>
#include "KingSystem/ActorSystem/actActorCreator.h"
#include "KingSystem/Framework/frmBaseProcInitializer.h"
#include "KingSystem/Framework/frmBaseProcMgr.h"
#include "KingSystem/System/HavokWorkerMgr.h"
#include "KingSystem/System/Profiler.h"
#include "KingSystem/System/UI/LayoutResourceMgr.h"

namespace ksys {

void initBaseProcMgr(sead::Heap* heap) {
    sead::ScopedCurrentHeapSetter setter(heap);

    frm::BaseProcMgr::createInstance(heap);
    act::BaseProcCreateTaskSelector::createInstance(heap);
    auto* worker_mgr = HavokWorkerMgr::instance();

    frm::BaseProcInitializerArgs args{};
    args.queue_size = 1024;
    args.thread_name = "ActorCreate";
    args.task_selector = &act::BaseProcCreateTaskSelector::instance()->getDelegate();
    frm::BaseProcMgr::instance()->init(
        heap, u32(frm::JobType::Invalid), sead::ThreadMgr::instance()->getMainThread()->getId(),
        worker_mgr->getWorkerThreadId(1), worker_mgr->getWorkerThreadId(2), args);

    frm::BaseProcMgr::sPreCalcJobType = u32(frm::JobType::PreCalc);
    frm::BaseProcMgr::sPostBgJobType = u32(frm::JobType::PostBg);
    frm::BaseProcMgr::sPostSensorJobType = u32(frm::JobType::PostSensor);
    frm::BaseProcMgr::sFrameEndJobType = u32(frm::JobType::FrameEnd);
}

void preInitializeApp(const InitParams& params) {
    ksys::Profiler::Scope profiler_scope("ksys::PreInitializeApp");

    // TODO - other parts

    {
        ksys::Profiler::Scope profiler_scope("RequestFontLoad");
        // TODO: FontMgr::createInstance()
        ui::LayoutResourceMgr::createInstance(params.king_sys_heap);
        ui::LayoutResourceMgr::instance()->init(params.king_sys_heap);
        ui::LayoutResourceMgr::instance()->loadLangFont(params.king_sys_heap);
        ui::LayoutResourceMgr::instance()->loadExtraLangFonts(params.king_sys_heap);
    }

    // TODO - other parts
}

}  // namespace ksys
