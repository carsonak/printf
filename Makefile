#!/usr/bin/make -f

CC := gcc

SRCS_DIR := .
OBJS_DIR := obj
TESTS_DIR := tests
TESTS_BIN_DIR := $(TESTS_DIR)/bin
# directories with header files
INCLUDE_DIRS := $(SRCS_DIR)

# all .c files
SRCS = $(SRCS_DIR)/*.c
# .o file names
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
# auto-genarated files for .h files make rules
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-M
DEP_FILES = $(OBJS:.o=.d)

# https://clang.llvm.org/docs/AddressSanitizer.html
ADDRESS_SANITISER := -fsanitize=address
# https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
UNDEFINED_SANITISER := -fsanitize=undefined

# Include flags
INCL_FLAGS = $(addprefix -iquote,$(INCLUDE_DIRS))
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MMD
CPPFLAGS := -MMD
OPTIMISATION_FLAGS := -Og
DEBUG_FLAGS := -g3 -fno-omit-frame-pointer
WARN_FLAGS := --std=gnu89 -pedantic -Wall -Wextra -Wno-format -Werror


INSTRUMENTATION_FLAGS = $(ADDRESS_SANITISER) $(UNDEFINED_SANITISER) -fsanitize-trap=all
CFLAGS = $(WARN_FLAGS) $(INCL_FLAGS) $(CPPFLAGS) $(OPTIMISATION_FLAGS) $(DEBUG_FLAGS) $(INSTRUMENTATION_FLAGS)

# $^ - names of all the prerequisites
# $@ - the name of the target
test_main: $(TESTS_BIN_DIR)
test_main: $(OBJS) $(TESTS_DIR)/test_main.c
	$(CC) $(CFLAGS) -o $@ $(TESTS_DIR)/$^

# @D - the directory of the target
$(TESTS_BIN_DIR):
	@mkdir -p $(@D)

$(OBJS_DIR):
	@mkdir -p $(@D)

# @< - name of only the first prequisite
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
