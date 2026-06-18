#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <cwchar> 
#include "SDK/SDK.hpp"
//#include "MinHook.h"  // Comment out if not needed

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
    inline std::vector<uint64_t> NullFuncs = { 0x1b56650, 0x593690, 0x6ddbd0 };
    inline std::vector<uint64_t> RetTrueFuncs = { 0x6e89c0 };
};

// Define function pointer types - all void* for compatibility
typedef void* (*StepFn)(void*, void*, void*);
typedef void* (*StepExplicitPropertyFn)(void*, void*, void*);
typedef void* (*CreateNetDriverFn)(void*, void*, void*);
typedef bool (*InitListenFn)(void*, void*, void*, bool, void*);
typedef void* (*SetWorldFn)(void*, void*);
typedef void* (*ReallocFn)(void*, void*, void*);
typedef void* (*StaticFindObjectFn)(void*, void*, void*, void*);
typedef void* (*StaticLoadObjectFn)(void*, void*, void*, void*, void*, void*, void*);

namespace Funcs {
    inline StepFn Step = (StepFn)(ImageBase + Addresses::Step);
    inline StepExplicitPropertyFn StepExplicitProperty = (StepExplicitPropertyFn)(ImageBase + Addresses::StepExplicitProperty);
    inline CreateNetDriverFn CreateNetDriver = (CreateNetDriverFn)(ImageBase + Addresses::CreateNetDriver);
    inline InitListenFn InitListen = (InitListenFn)(ImageBase + Addresses::InitListen);
    inline SetWorldFn SetWorld = (SetWorldFn)(ImageBase + Addresses::SetWorld);
    inline ReallocFn Realloc = (ReallocFn)(ImageBase + Addresses::Realloc);
    inline StaticFindObjectFn StaticFindObject = (StaticFindObjectFn)(ImageBase + Addresses::StaticFindObject);
    inline StaticLoadObjectFn StaticLoadObject = (StaticLoadObjectFn)(ImageBase + Addresses::StaticLoadObject);
};