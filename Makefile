# 编译器与选项
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 找到所有 .c 文件
SRC := $(wildcard *.c)

# 把 .c 替换为无后缀的可执行文件
TARGETS := $(SRC:.c=)

# 默认目标：编译全部
all: $(TARGETS)

# 模式规则：每个可执行文件由对应的 .c 文件生成
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# 清理
clean:
	rm -f $(TARGETS)
