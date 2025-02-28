#!/usr/bin/make -f

CC := gcc

SRCS_DIR := .
OBJS_DIR := obj
TESTS_DIR := tests
TESTS_BIN_DIR := $(TESTS_DIR)/bin
# directories with header files
INCLUDE_DIRS := $(SRCS_DIR)

# all .c files
SRCS = $(shell find $(SRCS_DIR) -maxdepth 1 -name '*.c')
# .o file names
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
# all test files
TESTS = $(shell find $(TESTS_DIR) -name 'test_*.c')
# auto-genarated files for .h files make rules
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-M
DEP_FILES = $(OBJS:.o=.d)

# https://clang.llvm.org/docs/AddressSanitizer.html
ADDRESS_SANITISER := -fsanitize=address
# https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
UNDEFINED_SANITISER := -fsanitize=undefined

# Include flags
INCL_FLAGS = $(addprefix -iquote,$(INCLUDE_DIRS))
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MMD
CPPFLAGS := -MMD
OPTIMISATION_FLAGS := -O0
DEBUG_FLAGS := -g3 -fno-omit-frame-pointer
WARN_FLAGS := --std=gnu89 -pedantic -Wall -Wextra -Wno-format -Werror

INSTRUMENTATION_FLAGS = $(ADDRESS_SANITISER) $(UNDEFINED_SANITISER) -fsanitize-trap=all
CFLAGS = $(WARN_FLAGS) $(INCL_FLAGS) $(CPPFLAGS) $(OPTIMISATION_FLAGS) $(DEBUG_FLAGS) $(INSTRUMENTATION_FLAGS)

# $^ - names of all the prerequisites
# $@ - the name of the target
$(TESTS_BIN_DIR)/test_%: $(OBJS) $(TESTS_DIR)/test_%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^

# @D - the directory of the target
# @< - name of only the first prequisite
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

sinclude $(DEP_FILES)
