#include "KingSystem/Game/Action/actionObservationPointAction.h"

namespace ksys::game {

ObservationPointAction::ObservationPointAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

ObservationPointAction::~ObservationPointAction() = default;

void ObservationPointAction::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void ObservationPointAction::leave_() {
    ksys::act::ai::Action::leave_();
}

void ObservationPointAction::loadParams_() {
    getMapUnitParam(&mPointName_m, "PointName");
}

void ObservationPointAction::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
