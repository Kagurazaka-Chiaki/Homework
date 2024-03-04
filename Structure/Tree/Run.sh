#!/usr/bin/env bash

function Run() {
    clang++ "${1}".cpp -o "${1}"
    valgrind -v --leak-check=full --track-origins=yes --log-file="ValgrindLog.txt" ./"${1}" > Output
}


function Main() {

    ps $$
    echo
    # Run BinaryTree
    Run BiTree
    echo -e "\n退出状态 $?"

    return 0;
}

# 获取命令行参数
Main "$@"

# 退出脚本
exit 0