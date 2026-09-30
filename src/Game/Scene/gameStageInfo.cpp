#include "Game/Scene/gameStageInfo.h"
#include "Game/Scene/gameScene.h"
#include "KingSystem/Game/StageInfo.h"
#include "KingSystem/Utils/InitTimeInfo.h"

namespace uking {

static ksys::util::InitConstants sConstants;
sead::FixedSafeString<256> StageInfo::sStr;
StageInfo StageInfo::sInfo;

const sead::SafeString& GameScene::getCurrentMapType() {
    return ksys::StageInfo::getCurrentMapType();
}

const sead::SafeString& GameScene::getCurrentMapName() {
    return ksys::StageInfo::getCurrentMapName();
}

}  // namespace uking
