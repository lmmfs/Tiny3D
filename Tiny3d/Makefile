DEVKITPRO ?= /opt/devkitpro
# Match devkitPro examples: set ARCH (including float ABI / FPU) before including rules
ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mfpu=vfp -mtp=soft
include $(DEVKITPRO)/devkitARM/3ds_rules

TARGET      := tiny3d
BUILD       := build
SOURCE_DIR  := Source

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
	@mkdir -p $(dir $@)
	@echo Linking Static Library...
	$(AR) rcs $@ $(OBJS)

$(BUILD)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo Compiling $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(LIBRARY)
