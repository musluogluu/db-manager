CC = gcc
CFLAGS = -Wall -Wextra -Isrc/include -Isrc/storage -Isrc/parser -Isrc/executor -Isrc/common -g
LDFLAGS =

SRC_DIR = src/
STORAGE_SRC = $(wildcard $(SRC_DIR)storage/*.c)
PARSER_SRC = $(wildcard $(SRC_DIR)parser/*.c)
EXECUTOR_SRC = $(wildcard $(SRC_DIR)executor/*.c)
COMMON_SRC = $(wildcard $(SRC_DIR)common/*.c)
ALL_SRC = $(STORAGE_SRC) $(PARSER_SRC) $(EXECUTOR_SRC) $(COMMON_SRC) $(SRC_DIR)main.c

OBJ_DIR = obj/
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(ALL_SRC))

TARGET = my_db_engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	rm -rf $(OBJ_DIR) $(TARGET)