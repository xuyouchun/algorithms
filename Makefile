.PHONY: all clean

CMD_CC       ?= g++
INCLUDES     ?= -I./include
CPPFLAGS     ?= -std=c++14 $(INCLUDES)

__CPP_FILES  ?= $(wildcard src/*.cpp)
SRC_FILES    ?= $(__CPP_FILES)
OBJ_FILES    ?= $(__CPP_FILES:.cpp=.o)

TARGET_PATH  ?= bin
TARGET_NAME  ?= algorithm

__TARGET_NAME = $(TARGET_PATH)/$(TARGET_NAME)

all: $(__TARGET_NAME)

$(__TARGET_NAME): Makefile.dep $(OBJ_FILES)
	@mkdir -p $(TARGET_PATH) > /dev/null 2>&1;
	$(CMD_CC) $(CPPFLAGS) -o $(__TARGET_NAME) $(OBJ_FILES)

Makefile.dep:
	$(CMD_CC) -MM $(INCLUDES) $(SRC_FILES) > ./Makefile.dep 2> /dev/null || true;
	@if ! test -s ./Makefile.dep; then rm -f ./Makefile.dep > /dev/null; fi;

-include Makefile.dep

