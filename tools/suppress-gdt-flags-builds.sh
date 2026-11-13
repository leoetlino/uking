#!/bin/bash

array=(
    src/Game/gdtCommonFlags.cpp
    src/Game/gdtCommonFlagsAccessorDefs.inc
    src/Game/gdtCommonFlagsHandleDefs.inc
)

for file in "${array[@]}"
do
    echo > $file
    git update-index --assume-unchanged $file
done
