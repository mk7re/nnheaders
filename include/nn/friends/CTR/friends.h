#pragma once

#include <nn/types.h>

struct nnfriendsFriendKey {
    u32 principalId;
    u32 padding;
    u64 friendCode;
};

namespace nn {
namespace friends {
namespace CTR {
namespace detail {

s32 GetFriendKeyList(nnfriendsFriendKey *, u32 *, u32, u32);
bool IsFromFriendList(nnfriendsFriendKey *);
void GetFriendScreenName(wchar_t(*)[11], const nnfriendsFriendKey *, u32, bool, u8 *);
void GetFriendScreenNameEx(wchar_t(*)[11], const nnfriendsFriendKey *, u32, bool, u8 *, bool);
s32 GetFriendAttributeFlags(u32 *, const nnfriendsFriendKey *, u32);

namespace Friends
{

s32 GetMyFriendKey(nnfriendsFriendKey *);
s32 GetFriendKeyList(nnfriendsFriendKey *, u32 *, u32, u32);
s32 GetFriendScreenName(wchar_t *, u8 *, const nnfriendsFriendKey *, u32, u32, u32, bool, bool);
s32 GetFriendAttributeFlags(u32 *, const nnfriendsFriendKey *, u32);

} // namespace Friends

} // namespace detail
} // namespace CTR
} // namespace friends
} // namespace nn
