DEVKITPRO ?= /opt/devkitpro
include $(DEVKITPRO)/devkitARM/3ds_rules

TARGET      := Sandbox
BUILD       := build
SOURCES     := Source
ENGINE_PATH := ../Tiny3d

# DIRECT PATHS - These are standard for dkp-pacman 3ds-dev
CTR_INC     := $(DEVKITPRO)/libctru/include
CTR_LIB     := $(DEVKITPRO)/libctru/lib

# Includes: Sandbox source, Engine root, and 3DS hardware headers
INCLUDES    := -I$(SOURCES) -I$(ENGINE_PATH) -I$(CTR_INC)
# Libs: Engine folder and 3DS hardware libs folder
LIBDIRS     := -L$(ENGINE_PATH) -L$(CTR_LIB)

# Use $(ARCH) from 3ds_rules
CFLAGS      := $(ARCH) -O2 -mword-relocations -Wall $(INCLUDES) -DARM11 -D_3DS
CXXFLAGS    := $(CFLAGS) -fno-rtti -fno-exceptions

# Order is vital: Engine -> Hardware Lib -> Math Lib
LIBS        := -ltiny3d -lctru -lm

CPPFILES    := $(wildcard $(SOURCES)/*.cpp)
OBJS        := $(patsubst $(SOURCES)/%.cpp, $(BUILD)/%.o, $(CPPFILES))

.PHONY: all clean

all: $(BUILD) $(TARGET).3dsx

$(BUILD):
	@mkdir -p $(BUILD)

$(TARGET).3dsx: $(TARGET).elf
	@3dsxtool $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(ARCH) $(LIBDIRS) $^ $(LIBS) -o $@

$(BUILD)/%.o: $(SOURCES)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET).3dsx $(TARGET).elf
