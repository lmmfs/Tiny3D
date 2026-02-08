DEVKITPRO ?= /opt/devkitpro
# Match devkitPro examples: set ARCH (including float ABI / FPU) before including rules
ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mfpu=vfp -mtp=soft
include $(DEVKITPRO)/devkitARM/3ds_rules

TARGET      := tiny3d
BUILD       := build
SOURCE_DIR  := Source

# Match the 3DS architecture and ABI exactly
ARCH        := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft
CFLAGS      := -g -Wall -O2 -mword-relocations $(ARCH) -ffunction-sections

INCLUDES    := -I. -I$(SOURCE_DIR) -I$(DEVKITPRO)/libctru/include
CXXFLAGS    := $(CFLAGS) $(INCLUDES) -D__3DS__ -fno-rtti -fno-exceptions -std=gnu++11

SOURCES     := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS        := $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD)/%.o, $(SOURCES))

# Added $(LIBCTR) check to prevent -I/include error
LIBCTR      := $(DEVKITPRO)/libctr
INCLUDES    := -I. -I$(SOURCE_DIR) -I$(LIBCTR)/include

# Use $(ARCH) provided by 3ds_rules
# Use $(ARCH) provided by 3ds_rules
CFLAGS      := $(ARCH) -g -O2 -Wall $(INCLUDES) -D__3DS__
CXXFLAGS    := $(CFLAGS) -fno-rtti -fno-exceptions

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
