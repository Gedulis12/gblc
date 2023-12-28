CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TEST_FILES))

.PHONY: all clean test

all: library

library: $(OBJ_FILES)
	ar rcs libgblc.a $(OBJ_FILES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do \
		echo "Running test: $$test_bin"; \
		./$$test_bin; \
	done

$(BIN_DIR)/%: $(TEST_DIR)/%.c library | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L. -lgblc $(LDFLAGS) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

install: library
	mkdir -p $(INSTALL_DIR)/include
	mkdir -p $(INSTALL_DIR)/lib
	cp include/*.h $(INSTALL_DIR)/include
	cp libgblc.a $(INSTALL_DIR)/lib

clean:
	rm -f $(OBJ_DIR)/*.o libgblc.a $(TEST_BINS)
