# 编译当前目录下无依赖 C 文件的 Makefile

$(info $(SHELL))

# CC = clang

CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g 

# VPATH = src:../headers 当前目录优先，其他目录冒号分隔

sources := $(wildcard *.c)
objects := $(patsubst %.c, %.o, $(sources))
names := $(basename $(sources))

# $(addsuffix <suffix>,<names...>)

all : $(names)

$(names) : $(objects)
	$(CC) $(CFLAGS) $(addsuffix .o, $@) -o $@ -lm

# Programme : 
# 	@for i in $(objects); do \
# 		echo $$i; \
# 	done;

# Windows -> del
# Linux -> rm

.PHONY : clean
clean : 
	rm -f $(objects)

# ifeq (0,${MAKELEVEL})
# cur-dir   := $(shell pwd)
# whoami    := $(shell whoami)
# host-type := $(shell arch)
# MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
# endif