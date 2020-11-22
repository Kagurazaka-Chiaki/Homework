#!/bin/bash

# 普通的 Shell 脚本

# 抛出异常
function RaiseError() {
    echo -e "Input Error: ${2}"
    exit ${1}
}

function MakeNewFile() {
    FileName="Test0$i"
    echo "Create $FileName"
    mkdir $FileName
    return 0;
}

function Remove() {
    FileName="Test0$i"
    echo "Remove $FileName"
    rm -rf $FileName
    return 0;
}

function Loop() {
    case ${1} in
        1) for i in $(ls); do echo "$i"; done; ;;
        2) for i in {4..9..1}; do Remove $i; done; ;;
        3) for ((i=3;i<10;i++)); do MakeNewFile $i; done; ;;
        4) i=0; while (($i<5)); do echo $i; let i++; done; ;;
        5) while true; do echo "Loop"; done; ;;
    esac
    return 0;
}

function Switch() {
    case ${1} in
        1) Loop 4; ;;
        2) echo "2"; ;;
    esac
    return 0;
}

function Main() {

    ps $$
    echo
    Switch 2
    echo -e "\n退出状态 $?"

    return 0;
}

# 获取命令行参数
Main $*

# 退出脚本
exit 0