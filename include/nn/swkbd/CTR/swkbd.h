#pragma once

#include <nn/applet.h>
#include <nn/types.h>

// Credits to libctru for these struct definitions
namespace nn::swkbd::CTR
{

// `SwkbdState` in libctru
struct Config {
    enum class EType : u32 {
        SWKBD_TYPE_NORMAL,
        SWKBD_TYPE_QWERTY,
        SWKBD_TYPE_NUMPAD,
        SWKBD_TYPE_WESTERN
    };

    enum class EValidInput : u32 {
        SWKBD_ANYTHING,
        SWKBD_NOTEMPTY,
        SWKBD_NOTEMPTY_NOTBLANK,
        SWKBD_NOTBLANK_NOTEMPTY,
        SWKBD_NOTBLANK,
        SWKBD_FIXEDLEN
    };

    enum class EPasswordMode : u32 {
        SWKBD_PASSWORD_NONE,
        SWKBD_PASSWORD_HIDE,
        SWKBD_PASSWORD_HIDE_DELAY
    };

    enum EFilterFlags : u32 {
        // Disallow the use of more than a certain number of digits (0 or more)
        SWKBD_FILTER_DIGITS = 0x01,
        // Disallow the use of the @ sign.
        SWKBD_FILTER_AT = 0x02,
        // Disallow the use of the % sign.
        SWKBD_FILTER_PERCENT = 0x04,
        // Disallow the use of the \ sign.
        SWKBD_FILTER_BACKSLASH = 0x08,
        // Disallow profanity using Nintendo's profanity filter.
        SWKBD_FILTER_PROFANITY = 0x10,
        // Use a callback in order to check the input.
        SWKBD_FILTER_CALLBACK = 0x14
    };

    enum class ECallbackResult : u32 {
        SWKBD_CALLBACK_OK,
        SWKBD_CALLBACK_CLOSE,
        SWKBD_CALLBACK_CONTINUE
    };

    EType type;
    s32 numButtonsM1;
    EValidInput validInput;
    EPasswordMode passwordMode;
    s32 isParentalScreen;
    s32 darkenTopScreen;
    EFilterFlags filterFlags;
    u32 saveStateFlags;
    u16 maxTextLength
    u16 dictWordCount;
    u16 maxDigits;
    u16 buttonText[3][17];
    u16 numKeypadKeys[2];
    u16 hintText[65];
    bool predictiveInput;
    bool multiLine;
    bool fixedWidth;
    bool allowHome;
    bool allowReset;
    bool allowPower;
    bool unk_0x118; // communicateWithOtherRegions ?
    bool defaultQwerty;
    bool buttonSubmitsText[4];
    u8 unk_0x11e;
    u8 unk_0x11f;
    s32 initialTextOffset;
    s32 dictOffset;
    s32 initialStatusOffset;
    s32 initialLearningOffset;
    u32 sharedMemorySize;
    s16 unk_0x134;
    s16 unk_0x136;
    s32 unk_0x138;
    s32 unk_0x13c;
    s32 unk_0x140;
    s32 unk_0x144;
    s16 unk_0x148;
    s16 unk_0x14a;
    ECallbackResult callbackResult;
    u16 callbackMessage[257];
    s16 unk_0x352;
    u8 unk_0x354[172];
};

struct Parameter {
    Config config;
};

struct UserWord {

};

typedef AppTextCheckResult (*AppTextCheckCallback)(const wchar_t**, const wchar_t*, u16);

bool SetInputData(Config*, void*, u32, const wchar_t*, const UserWord*, const void*, const void*);
void InitializeConfig(Config*);
u32 CTR::GetSharedMemorySize(const Config*, const void*, const void*);
bool StartKeyboardApplet(nn::applet::CTR::WakeupState*, Parameter*, void*, u32, const wchar_t*, const UserWord*, const void*, const void*, AppTextCheckResult);

}  // namespace nn::swkbd::CTR
