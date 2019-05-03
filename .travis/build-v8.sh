#!/bin/bash

set -x

ARGS="$@"

echo "Building ${ARGS}"

cd ./v8build

# export necessary variables nonetheless
export PATH=${PATH}:$(pwd)/depot_tools

cd ./v8

export RELEASE=out.gn/x64.release

# finally build
ninja -C ${RELEASE} ${ARGS}