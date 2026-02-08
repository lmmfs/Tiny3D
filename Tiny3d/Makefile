DEVKITPRO ?= /opt/devkitpro

# Set ARCH before including 3ds_rules (required)
ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

include $(DEVKITPRO)/devkitARM/3ds_rules

TARGET      := tiny3d
BUILD       := build
SOURCE_DIR  := Source

# Compiler flags
CFLAGS      := -g -Wall -O2 -mword-relocations $(ARCH) -ffunction-sections
CXXFLAGS    := $(CFLAGS) -D__3DS__ -fno-rtti -fno-exceptions -std=gnu++14

# Include paths for 3DS development
INCLUDES    := -I. -I$(SOURCE_DIR) -I$(DEVKITPRO)/libctru/include
CXXFLAGS    += $(INCLUDES)

# Source files
SOURCES     := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS        := $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD)/%.o, $(SOURCES))

LIBRARY     := lib$(TARGET).a

.PHONY: all clean

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $@ $(OBJS)

$(BUILD)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(LIBRARY)
