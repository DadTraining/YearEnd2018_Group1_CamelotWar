LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES :=  $(LOCAL_PATH)/hellocpp/main.cpp \
$(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
$(LOCAL_PATH)/../../../Classes/Model.cpp \
$(LOCAL_PATH)/../../../Classes/Character.cpp \
$(LOCAL_PATH)/../../../Classes/Arrow.cpp \
$(LOCAL_PATH)/../../../Classes/Knife.cpp \
$(LOCAL_PATH)/../../../Classes/Fire.cpp \
$(LOCAL_PATH)/../../../Classes/Troll.cpp \
$(LOCAL_PATH)/../../../Classes/HammerTroll.cpp \
$(LOCAL_PATH)/../../../Classes/BoneTroll.cpp \
$(LOCAL_PATH)/../../../Classes/AxeOrk.cpp \
$(LOCAL_PATH)/../../../Classes/SwordOrk.cpp \
$(LOCAL_PATH)/../../../Classes/HammerOrk.cpp \
$(LOCAL_PATH)/../../../Classes/AxeKnight.cpp \
$(LOCAL_PATH)/../../../Classes/SpearKnight.cpp \
$(LOCAL_PATH)/../../../Classes/SwordKnight.cpp \
$(LOCAL_PATH)/../../../Classes/Archer.cpp \
$(LOCAL_PATH)/../../../Classes/Archer_Fire.cpp \
$(LOCAL_PATH)/../../../Classes/Archer_knife.cpp \
$(LOCAL_PATH)/../../../Classes/pedestal.cpp \
$(LOCAL_PATH)/../../../Classes/coin/CoinModel.cpp \
$(LOCAL_PATH)/../../../Classes/Boat.cpp \
$(LOCAL_PATH)/../../../Classes/Castle.cpp \
$(LOCAL_PATH)/../../../Classes/utils/animation/GetAnimation.cpp  \
$(LOCAL_PATH)/../../../Classes/utils/physics/CustomPhysicsBody.cpp \
$(LOCAL_PATH)/../../../Classes/PopUp.cpp \
$(LOCAL_PATH)/../../../Classes/PopUpSetting.cpp \
$(LOCAL_PATH)/../../../Classes/TitleScene.cpp \
$(LOCAL_PATH)/../../../Classes/HelloWorldScene.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
$(LOCAL_PATH)/../../../Classes/coin/CoinModel.h \
$(LOCAL_PATH)/../../../Classes/animation/GetAnimation.h \
$(LOCAL_PATH)/../../../Classes/physics/CustomPhysicsBody.h 

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/../../../cocos2d)
$(call import-module, cocos)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
