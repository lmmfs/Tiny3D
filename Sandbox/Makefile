DEVKITPRO ?= /opt/devkitpro

# Set ARCH before including 3ds_rules (required)
ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

include $(DEVKITPRO)/devkitARM/3ds_rules

TARGET      := Sandbox
BUILD       := build
SOURCES     := Source
ENGINE_PATH := ../Tiny3d

# Compiler flags
CFLAGS      := -g -Wall -O2 -mword-relocations $(ARCH) -ffunction-sections
CXXFLAGS    := $(CFLAGS) -D__3DS__ -fno-rtti -fno-exceptions -std=gnu++14

# Include and library paths
INCLUDES    := -I$(SOURCES) -I$(ENGINE_PATH) -I$(DEVKITPRO)/libctru/include
LIBDIRS     := -L$(ENGINE_PATH) -L$(DEVKITPRO)/libctru/lib
CXXFLAGS    += $(INCLUDES)

# Linker specs for 3DS (includes crt0.o and startup code)
LDFLAGS     := -specs=3dsx.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

# Libraries in correct order
LIBS        := -ltiny3d -lctru -lm

CFILES      := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES    := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))

OFILES_SOURCES := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o)
OFILES      := $(OFILES_SOURCES)

export VPATH := $(foreach dir,$(SOURCES),$(CURDIR)/$(dir))

.PHONY: all clean

all: $(BUILD) $(TARGET).3dsx

$(BUILD):
	mkdir -p $(BUILD)

$(TARGET).3dsx: $(TARGET).elf
	3dsxtool $< $@

$(TARGET).elf: $(addprefix $(BUILD)/,$(OFILES))
	$(CXX) $(LDFLAGS) $(LIBDIRS) $^ $(LIBS) -o $@

$(BUILD)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -std=gnu99 $(INCLUDES) -D__3DS__ -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET).3dsx $(TARGET).elf
