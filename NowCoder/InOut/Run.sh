#!/bin/bash

CC=clang
CXX=clang++

# shellcheck disable=SC2317  # Don't warn about unreachable commands in this function
function Compile() {
    $CC "${1}".c -o "${1}"
}

function NormalRun() {
    $CXX "${1}".cpp -o "${1}"
    ./"${1}"
}

# shellcheck disable=SC2317  # Don't warn about unreachable commands in this function
function ValgrindRun() {
    Compile "${1}"
    valgrind -v --leak-check=full --track-origins=yes \
    --log-file="ValgrindLog" \
    ./"${1}" > Output
}

function Main() {

    ps $$
    echo
    # ValgrindRun "${1}"
    NormalRun "${1}"
    echo -e "\n退出状态 $?"

    return 0;
}

# 获取命令行参数
Main "$*"

# 退出脚本
exit 0