LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := AndroidImageFilter
LOCAL_SRC_FILES := cn_Ragnarok_NativeFilterFunc.cpp

LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)
