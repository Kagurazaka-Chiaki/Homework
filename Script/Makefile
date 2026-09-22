# # 编译当前目录下无依赖 C 文件的 Makefile

# $(info $(SHELL))

# # CC = clang

# CC = gcc
# CFLAGS = -Wall -Werror -std=c11 -g

# # VPATH = src:../headers 当前目录优先，其他目录冒号分隔

# sources := $(wildcard *.c)
# objects := $(patsubst %.c, %.o, $(sources))
# names := $(basename $(sources))

# # $(addsuffix <suffix>,<names...>)

# all : $(names)

# $(names) : $(objects)
# 	$(CC) $(CFLAGS) $(addsuffix .o, $@) -o $@ -lm

# # Programme :
# # 	@for i in $(objects); do \
# # 		echo $$i; \
# # 	done;

# # Windows -> del
# # Linux -> rm

# .PHONY : clean
# clean :
# 	rm -f $(objects)

# # ifeq (0,${MAKELEVEL})
# # cur-dir   := $(shell pwd)
# # whoami    := $(shell whoami)
# # host-type := $(shell arch)
# # MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
# # endif

CXX := g++

# 本地算法题构建的通用编译选项。
WARN := -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op
STD := -std=c++23
DBG := -g
OPT := -O2
GLIBCXX_DEBUG := -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
FORTIFY := -D_FORTIFY_SOURCE=2
STACK := -fstack-protector
SAN_FLAGS := -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all

# heaptrack 不适合跑 ASan/UBSan 版本，因此单独使用一组编译选项。
TRACK_FLAGS := -O1 -g3 -fno-omit-frame-pointer -fno-inline

SRC := current/main.cpp
BUILD_DIR := build
TARGET := $(BUILD_DIR)/main
TRACK_TARGET := $(BUILD_DIR)/track

# 单样例命令使用 CASE；test-all 默认使用根目录下所有 *.in。
CASE ?= 1
CASES ?= $(basename $(wildcard *.in))
IN ?= $(CASE).in
OUT ?= $(CASE).out
ANS ?= $(CASE).ans
SUBMIT_SRC ?= $(SRC)
SUBMIT_OUT ?= $(BUILD_DIR)/submit.cpp
SUBMIT_TARGET := $(BUILD_DIR)/submit

.PHONY: all run run-file diff test test-all submit track clean

all: $(TARGET)

# 默认调试二进制：低优化、开启调试检查和 sanitizer，方便本地排错。
$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(WARN) $(STD) $(DBG) -O0 $(GLIBCXX_DEBUG) $(FORTIFY) $(STACK) $(SAN_FLAGS) $(SRC) -o $(TARGET) $(SAN_FLAGS)

run: $(TARGET)
	./$(TARGET)

run-file: $(TARGET)
	./$(TARGET) < $(IN) > $(OUT)

diff:
	diff -u --strip-trailing-cr $(ANS) $(OUT)

test: run-file diff

# 运行所有选中的样例，并把输出保存为对应的 <case>.out。
test-all: $(TARGET)
	@failed=0; \
	for case in $(CASES); do \
		echo "== case $$case =="; \
		./$(TARGET) < $$case.in > $$case.out; \
		if [ -f $$case.ans ]; then \
			diff -u --strip-trailing-cr $$case.ans $$case.out || failed=1; \
		else \
			echo "missing $$case.ans, skipped diff"; \
		fi; \
	done; \
	exit $$failed

# 在 build/ 下生成去注释的提交副本。
submit:
	./submit.sh $(SUBMIT_SRC) $(SUBMIT_OUT)
	$(CXX) $(WARN) $(STD) $(OPT) $(SUBMIT_OUT) -o $(SUBMIT_TARGET)

track: $(TRACK_TARGET)
	heaptrack ./$(TRACK_TARGET) < $(IN)

# 专用于 heaptrack 的性能分析二进制，不链接 sanitizer 运行时。
$(TRACK_TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(WARN) $(STD) $(TRACK_FLAGS) $(FORTIFY) $(STACK) $(SRC) -o $(TRACK_TARGET)

clean:
	rm -rf $(BUILD_DIR)
