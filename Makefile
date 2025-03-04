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
TESTS = $(shell find $(TESTS_DIR) -name test_main.c -prune -o -name 'test_*.c' -print | sort)
# all test files' binaries
TESTS_BINS = $(TESTS:$(TESTS_DIR)/%.c=$(TESTS_BIN_DIR)/%)
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
C_STANDARD := --std=gnu89
WARN_FLAGS := -pedantic -Wall -Wextra -Wno-format -Werror

INSTRUMENTATION_FLAGS = $(ADDRESS_SANITISER) $(UNDEFINED_SANITISER)
CFLAGS = $(C_STANDARD) $(WARN_FLAGS) $(INCL_FLAGS) $(CPPFLAGS) $(OPTIMISATION_FLAGS) $(DEBUG_FLAGS) $(INSTRUMENTATION_FLAGS)

.PHONY: all-tests
all-tests:
# $^ - names of all the prerequisites
all-tests: $(TESTS_BINS)
	$(shell for file in $^; \
		do ./$$file; \
		done \
	)

# https://www.gnu.org/software/make/manual/html_node/Static-versus-Implicit.html
$(TESTS_BINS):$(TESTS_BIN_DIR)/test_%: $(filter-out %_write.o,$(OBJS))
# $@ - the name of the target
$(TESTS_BINS):$(TESTS_BIN_DIR)/test_%: $(TESTS_DIR)/test_%.c $(TESTS_DIR)/test_main.c $(TESTS_DIR)/_write.c
	@mkdir -p $(@D)
	$(CC) --std=c2x $(filter-out --std=gnu89,$(CFLAGS)) -o $@ $^

# @D - the directory of the target
# $< - name of only the first prequisite
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) -vdr --preserve-root -- $(OBJS_DIR) $(TESTS_BIN_DIR)

sinclude $(DEP_FILES)
