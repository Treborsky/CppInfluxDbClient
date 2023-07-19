#!/bin/bash

export CPP_INFLUXDB_CLIENT_ROOT=${GIT_ROOT}/cpp_influxdb_client

alias build_cpp_influxdb_client="cmake -S ${CPP_INFLUXDB_CLIENT_ROOT} -B ${BUILD_DIR}/cpp_influxdb_client; make -C ${BUILD_DIR}/cpp_influxdb_client"
alias run_cpp_influxdb_client="${BUILD_DIR}/cpp_influxdb_client/CppInfluxDbClient"