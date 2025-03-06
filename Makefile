#!/usr/bin/make -f
PROJECT_NAME := _printf
CC := gcc

SRCS_DIR := .
OBJS_DIR := obj
TESTS_DIR := tests
TESTS_BIN_DIR := $(TESTS_DIR)/bin
# directories with header files
INCLUDE_DIRS := $(SRCS_DIR)

SHARED_LIB := lib$(PROJECT_NAME).so
STATIC_LIB := lib$(PROJECT_NAME).a
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
DEP_FILES = $(OBJS:.o=.d) $(TESTS_BINS:%=%.d)

# https://clang.llvm.org/docs/AddressSanitizer.html
ADDRESS_SANITISER := -fsanitize=address
# https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
UNDEFINED_SANITISER := -fsanitize=undefined

# Include flags
INCL_FLAGS = $(addprefix -iquote,$(INCLUDE_DIRS))
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MMD
CPPFLAGS := -MMD
OPTIMISATION_FLAGS := -O2
DEBUG_FLAGS := -g3 -fno-omit-frame-pointer
# Original project required compilation with --std=gnu89
C_STANDARD := --std=gnu89
WARN_FLAGS := -pedantic -Wall -Wextra -Wno-format -Werror

INSTRUMENTATION_FLAGS = $(ADDRESS_SANITISER) $(UNDEFINED_SANITISER)
CFLAGS = $(C_STANDARD) $(WARN_FLAGS) $(INCL_FLAGS) $(CPPFLAGS) $(OPTIMISATION_FLAGS) $(DEBUG_FLAGS) $(INSTRUMENTATION_FLAGS)

ARFLAGS := -rvcsD

install: $(SHARED_LIB)
	sudo cp $(PROJECT_NAME).h /usr/local/include
	sudo mv $< /usr/local/lib
	sudo ldconfig

$(SHARED_LIB): ADDRESS_SANITISER :=
$(SHARED_LIB): UNDEFINED_SANITISER :=
$(SHARED_LIB): DEBUG_FLAGS :=
$(SHARED_LIB): CPPFLAGS += -DNDEBUG
$(SHARED_LIB): C_STANDARD := --std=c99
$(SHARED_LIB): INSTRUMENTATION_FLAGS += -fpic
# $^ - names of all the prerequisites
$(SHARED_LIB): $(OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(STATIC_LIB): ADDRESS_SANITISER :=
$(STATIC_LIB): UNDEFINED_SANITISER :=
$(STATIC_LIB): DEBUG_FLAGS :=
$(STATIC_LIB): CPPFLAGS += -DNDEBUG
$(STATIC_LIB): C_STANDARD := --std=c99
$(STATIC_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all-tests
all-tests: $(TESTS_BINS)
	$(shell for file in $^; \
		do ./$$file; \
		done \
	)

# $@ - the name of the target
$(OBJS_DIR):
	@mkdir -p $@

# https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
# $< - name of only the first prequisite
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(TESTS_BIN_DIR):
	@mkdir -p $@

$(TESTS_BIN_DIR)/test_%: OPTIMISATION_FLAGS := -Og
# https://www.gnu.org/software/make/manual/html_node/Static-versus-Implicit.html
$(TESTS_BINS):$(TESTS_BIN_DIR)/test_%: | $(TESTS_BIN_DIR)
$(TESTS_BINS):$(TESTS_BIN_DIR)/test_%: $(filter-out %_write.o,$(OBJS))
$(TESTS_BINS):$(TESTS_BIN_DIR)/test_%: $(TESTS_DIR)/test_%.c $(TESTS_DIR)/test_main.c $(TESTS_DIR)/_write.c
	$(CC) --std=c2x $(filter-out --std=gnu89,$(CFLAGS)) -o $@ $^
# Need to compile with atleast --std=c23 for the __VA_OPT__(, ) macro.

.PHONY: clean
clean:
	$(RM) -vdr --preserve-root -- $(OBJS_DIR) $(TESTS_BIN_DIR) $(SHARED_LIB) $(STATIC_LIB)

sinclude $(DEP_FILES)
