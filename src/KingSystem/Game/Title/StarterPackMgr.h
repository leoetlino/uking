#pragma once

#include <devenv/seadEnvUtil.h>
#include <heap/seadExpHeap.h>
#include <prim/seadSafeString.h>
#include "KingSystem/AOC/aocManager.h"
#include "KingSystem/Resource/resEntryFactory.h"
#include "KingSystem/Resource/resLoadRequest.h"
#include "KingSystem/Resource/resMemoryMgr.h"
#include "KingSystem/Resource/resResourceArchive.h"
#include "KingSystem/Resource/resResourceBinder.h"
#include "KingSystem/Resource/resResourceMgrTask.h"
#include "KingSystem/Resource/resSystem.h"
#include "KingSystem/System/GameConfig.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::game {

class StarterPackMgr {
    SEAD_SINGLETON_DISPOSER(StarterPackMgr)
    StarterPackMgr();
    ~StarterPackMgr();

public:
    void registerPackFactoryAndMakeMemoryMgr(bool reduced_heap_size);
    void deleteArenaAndHeapAndUnregisterFactory();
    void loadBootupGraphicsPack();
    void loadBootupPacks();
    void loadTitlePack();
    void loadTitleBGPacks();
    void loadAocMainFieldPack();
    void unloadBootupGraphicsPack();
    bool bootupGraphicsPackReady();
    void setPackToBootupGraphics();
    void unloadBootupAndBootupLangPack();
    bool bootupPacksReady();
    void setPackToBootupPack();
    void unloadTitlePack();
    bool isTitlePackReady();
    bool isTitlePackK();
    void setPackToTitlePack();
    void setPackToTitleBGPack();
    void unloadTitleBGAndAocMainFieldPacksAndStuff();
    void failedLoadTitlePack();
    res::ResourceBinder* getBootupLangPack();
    res::ResourceBinder* getTitleBGLangPack();

private:
    res::ResourceBinder mBootupGfxPack;
    res::ResourceBinder mBootupPack;
    res::ResourceBinder mUnusedPack;
    res::ResourceBinder mBootupLangPack;
    res::ResourceBinder mTitlePack;
    res::ResourceBinder mTitleBGPack;
    res::ResourceBinder mTitleBGLangPack;
    res::MemoryMgr* mMemoryMgr = nullptr;
    sead::ExpHeap* mExpHeap = nullptr;
    res::EntryFactory<res::Archive> mArchiveFac;
};
KSYS_CHECK_SIZE_NX150(StarterPackMgr, 0x348);

}  // namespace ksys::game
