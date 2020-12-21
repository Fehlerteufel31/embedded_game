CROSSTOOL_HOME := /media/ubuntu/9bee6cb9-766f-425f-bf5b-2e5fd011415c/buildroot_qt_sdl_ubi/buildroot/output/host/arm-buildroot-linux-gnueabihf
SYSROOT := $(CROSSTOOL_HOME)/sysroot
SDL_FLAGS := `$(SYSROOT)/usr/bin/sdl2-config --cflags`
CXX := /media/ubuntu/9bee6cb9-766f-425f-bf5b-2e5fd011415c/buildroot_qt_sdl_ubi/buildroot/output/host/bin/arm-buildroot-linux-gnueabihf-g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb3 $(SDL_FLAGS)
BIN	:= bin
SRC	:= src
INCLUDE	:= include
LIB := lib

LIBRARIES := `$(SYSROOT)/usr/bin/sdl2-config --libs`
EXECUTABLE := gs-cross-compile

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	rm -rf $(BIN)/*
