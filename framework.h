#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include "SDK/SDK.hpp"

using namespace SDK;
inline uintptr_t ImageBase = InSDKUtils::GetImageBase();

namespace Addresses {
    inline uint64_t Step = 0x13e0650;
    inline uint64_t StepExplicitProperty = 0x13e0680;
    inline uint64_t CreateNetDriver = 0x244d040;
    inline uint64_t InitListen = 0x391e3e0;
    inline uint64_t SetWorld = 0x223c500;
    inline uint64_t GetNetMode = 0x249c7c0;
    inline uint64_t TickFlush = 0x223db40;
    inline uint64_t GetMaxTickRate = 0x24543e0;
    inline uint64_t DispatchRequest = 0x3b559a0;
    inline uint64_t Realloc = 0x123e4c0;
    inline uint64_t StaticFindObject = 0x13de630;
    inline uint64_t StaticLoadObject = 0x13df8b0;
    inline uint64_t GIsClient = 0x6536b65;
    inline uint64_t GameSessionPatch = 0x417536;
    inline uint64_t EncryptionPatch = 0x249e40f;
    inline std::vector<uint64_t, 4> NullFuncs = { 0x1b56650, 0x593690, 0x6ddbd0 };
    inline std::vector<uint64_t, 1> RetTrueFuncs = { 0x6e89c0 };
    // vector is better
};

struct FFrame
{

};

namespace Funcs {
    inline auto Step = (void (*)(FFrame*, SDK::UObject*, void* const)) (ImageBase + Addresses::Step);
    inline auto StepExplicitProperty = (void (*)(FFrame*, void* const, SDK::UField*)) (ImageBase + Addresses::StepExplicitProperty);
    inline auto CreateNetDriver = (SDK::UNetDriver * (*)(SDK::UEngine*, SDK::UWorld*, SDK::FName)) (ImageBase + Addresses::CreateNetDriver);
    inline auto InitListen = (bool (*)(SDK::UNetDriver*, SDK::UWorld*, SDK::FURL&, bool, UC::FString)) (ImageBase + Addresses::InitListen);
    inline auto SetWorld = (void (*)(SDK::UNetDriver*, SDK::UWorld*)) (ImageBase + Addresses::SetWorld);
    inline auto Realloc = (void* (*)(void*, __int64, unsigned int)) (ImageBase + Addresses::Realloc);
    inline auto StaticFindObject = (SDK::UObject * (*)(SDK::UClass*, SDK::UObject*, const wchar_t*, bool)) (ImageBase + Addresses::StaticFindObject);
    inline auto StaticLoadObject = (SDK::UObject * (*)(SDK::UClass*, SDK::UObject*, const wchar_t*, const wchar_t*, uint32_t, SDK::UObject*, bool)) (ImageBase + Addresses::StaticLoadObject);
};

