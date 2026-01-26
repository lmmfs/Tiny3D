DEVKITPRO ?= /opt/devkitpro
include $(DEVKITPRO)/3ds_rules

TARGET      := Sandbox
BUILD       := build
SOURCES     := Source
ENGINE_PATH := ../Tiny3d

# We point to ENGINE_PATH so we can do #include "tiny.h"
INCLUDES    := -I$(SOURCES) -I$(ENGINE_PATH) -I$(LIBCTR)/include
LIBDIRS     := -L$(ENGINE_PATH) -L$(LIBCTR)/lib

ARCH        := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft
CFLAGS      := $(ARCH) -O2 -mword-relocations -Wall $(INCLUDES)
CXXFLAGS    := $(CFLAGS) -fno-rtti -fno-exceptions

LIBS        := -ltiny3d -lctru -lm

# Standard devkitPro logic to build the .3dsx
all: $(BUILD) $(TARGET).3dsx

$(TARGET).3dsx: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(arm-none-eabi-g++) $(ARCH) $(LIBDIRS) $^ $(LIBS) -o $@
