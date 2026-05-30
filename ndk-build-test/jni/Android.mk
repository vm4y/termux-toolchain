LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hello
LOCAL_SRC_FILES := \
				   ../src/hello.c

LOCAL_CFLAGS += -DABI=\"$(TARGET_ARCH_ABI)\"

include $(BUILD_SHARED_LIBRARY)
