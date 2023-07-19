#!/bin/bash

export GIT_ROOT=$(git rev-parse --show-toplevel)

export BUILD_DIR=${GIT_ROOT}/build

source payload_debug_server/setup.sh
source cpp_influxdb_client/setup.sh
