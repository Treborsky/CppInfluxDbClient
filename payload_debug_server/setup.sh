#!/bin/bash

export PAYLOAD_DEBUG_SERVER_ROOT=${GIT_ROOT}/payload_debug_server

alias build_payload_debug_server="cmake -S ${PAYLOAD_DEBUG_SERVER_ROOT} -B ${BUILD_DIR}/payload_debug_server; make -C ${BUILD_DIR}/payload_debug_server"
alias run_payload_debug_server="${BUILD_DIR}/payload_debug_server/PayloadDebugServer"
