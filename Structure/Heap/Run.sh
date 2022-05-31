#!/bin/bash

CC=clang

function Compile() {
    echo "compile ${1}"
    ${CC} "${1}".c -o "${1}"
}

function ValgrindRun() {
    echo "valgrind run ${1}"
    Compile "${1}"
    valgrind -v --leak-check=full --track-origins=yes \
    --log-file="ValgrindLog.txt" \
    ./"${1}" > "Output.txt"
}

function Main() {

    ps $$
    echo
    ValgrindRun "${1}"
    echo -e "\n退出状态 $?"

    return 0;
}

# 获取命令行参数
Main "$*"

# 退出脚本
exit 0