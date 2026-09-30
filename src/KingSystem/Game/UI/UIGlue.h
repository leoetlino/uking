#pragma once

#include <prim/seadSafeString.h>

namespace ksys::game {

int getPorchNum(const sead::SafeString& name);
int getItemValue(const sead::SafeString& name);
void initRupeeCounter();
bool isRupeeCounterActive();

}  // namespace ksys::game

namespace ksys::ui {

void applyScreenFade(float progress);

}  // namespace ksys::ui
