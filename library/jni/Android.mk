LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := AndroidImageFilter
LOCAL_SRC_FILES := cn_Ragnarok_NativeFilterFunc.cpp \
					AverageSmoothFilter.cpp \
					GaussianBlurFilter.cpp \
					HDRFilter.cpp \
					SoftGlowFilter.cpp \
					LightFilter.cpp \
					LomoAddBlackRound.cpp \
					NeonFilter.cpp \
					OilFilter.cpp \
					SketchFilter.cpp \
					TvFilter.cpp \
					SharpenFilter.cpp \
					ReliefFilter.cpp \
					PixelateFilter.cpp \
					BlockFilter.cpp \
					GammaCorrectionFilter.cpp \
					MotionBlurFilter.cpp \
					BrightContrastFilter.cpp \
					ColorTranslator.cpp \
					HueSaturationFilter.cpp \
					GothamFilter.cpp \

LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)
