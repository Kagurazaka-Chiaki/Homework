#!/bin/bash

CMAKE_ARGS="-DCMAKE_TOOLCHAIN_FILE=/mnt/d/Develop/Linux/vcpkg/scripts/buildsystems/vcpkg.cmake"

function Switch() {
    case ${1} in
    setup) mkdir LinuxBuild ;;
    build) cd LinuxBuild && cmake .. "$CMAKE_ARGS" ;;
    make) make ;;
    remove) rm -rf LinuxBuild ;;
    remake) Remake ;;
    esac
    return 0
}

function Remake() {
    Switch remove
    Switch setup
    Switch build
    cd ..
    Switch make
}

function Main() {

    ps $$
    echo
    Switch "${1}"
    echo -e "\n退出状态 $?"

    return 0
}

# 获取命令行参数
Main "$*"

# 退出脚本
exit 0
