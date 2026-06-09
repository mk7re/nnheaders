#pragma once

#include <nn/types.h>

namespace nw::snd::internal
{
// Forward declaration
class BasicSound;
}

namespace nw::snd
{

enum class PanMode : u8
{

};

enum class PanCurve : u8
{

};

class SoundHandle {
    void DetachSound();
    void detail_AttachSound(internal::BasicSound *);
    void detail_AttachSoundAsTempHandle(internal::BasicSound *);

    internal::BasicSound *basicSound;
};

}

namespace nw::snd::internal
{

class BasicSound {
public:
    void *GetRuntimeTypeInfo() const;
    void DetachGeneralHandle();
    void SetPanMode(nw::snd::PanMode);
    void Initialize();
    void SetPanCurve(nw::snd::PanCurve);
    void SetPriority(s32, s32);
    void UpdateParam();
    void StartPrepared();
    void SetAmbientInfo(const void * /* const nw::snd::internal::BasicSound::AmbientInfo & */);
    void SetFrontBypass(bool);
    void SetBiquadFilter(s32, f32);
    void UpdateMoveValue();
    void DetachPlayerHeap(const void * /* nw::snd::internal::PlayerHeap * */);
    void DetachSoundActor(const void * /* nw::snd::SoundActor * */);
    void SetInitialVolume(f32);
    void DetachSoundPlayer(const void * /* nw::snd::SoundPlayer * */);
    void SetPlayerPriority(s32);
    s32 GetAmbientPriority(const void * /* const nw::snd::internal::BasicSound::AmbientInfo & */, u32);
    void SetAutoStopCounter(s32);
    void OnUpdatePlayerPriority();
    void DetachTempGeneralHandle();
    bool IsAttachedGeneralHandle();
    void DetachExternalSoundPlayer(const void * /* nw::snd::internal::ExternalSoundPlayer * */);
    bool IsAttachedTempGeneralHandle();
    void Stop(s32);
    void Pause(bool, s32);
    void FadeIn(s32);
    void SetPan(f32);
    void Update();
    void Finalize();
    void SetPitch(f32);
    void SetVolume(f32, s32);
    BasicSound();

    u8 field_0x00[80];
    s32 priority;
    u8 field_0x54[51];
    bool autoStopFlag;
    u8 field_0x88[8];
    s32 autoStopCounter;
    u8 field_0x94[4];
    u8 playerPriority;
    u8 field_0x99[3];
    s32 field_0x9c;
    f32 field_0xa0;
    f32 volume;
    s32 field_0xa8;
    s32 field_0xac;
    f32 initialVolume;
    f32 pan;
    f32 pitch;
};

}