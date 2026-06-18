#pragma once
#include "SDK/SDK.hpp"
#include "framework.h"
#include <Windows.h>

inline void SetTitle(const std::string& Text)
{
    SetConsoleTitleA(Text.c_str());
}

inline bool ReadyToStartMatch(AFortGameModeAthena* Gamemode)
{
    if (!Gamemode)
    {
        SetTitle("Starting gamemode...");
        return false;
    }

    auto GameState = (AFortGameStateAthena*)Gamemode->GameState;

    if (!GameState)
    {
        SetTitle("No GameState");
        return false;
    }

    if (!GameState->MapInfo)
    {
        SetTitle("No MapInfo");
        return false;
    }

    static bool bFirstTouchingSession = false;

    if (!bFirstTouchingSession)
    {
        bFirstTouchingSession = true;

        SetTitle("Initializing Session...");

        GameState->CurrentPlaylistId = 1;
        Gamemode->CurrentPlaylistId = 1;
    }

    static bool bListen = false;

    if (!bListen)
    {
        UWorld* World = UWorld::GetWorld();

        if (!World || !World->NetDriver)
        {
            SetTitle("No NetDriver");
            return false;
        }

        FName GameNetDriver = UKismetStringLibrary::Conv_StringToName(L"GameNetDriver");

        World->NetDriver->NetDriverName = GameNetDriver;
        World->NetDriver->World = World;

        FURL URL{};
        URL.Port = 7777;

        FString Error;

        SetTitle("Starting Listen");

        if (Funcs::InitListen(
            (void*)World->NetDriver,
            (void*)World,
            (void*)&URL,
            false,
            (void*)&Error))
        {
            Funcs::SetWorld((void*)World->NetDriver, (void*)World);

            SetTitle("Listening");
        }
        else
        {
            SetTitle("Listen Failed");
            return false;
        }

        bListen = true;
    }

    if (Gamemode->GetMatchState().ToString() == "WaitingToStart")
    {
        Gamemode->StartMatch();
    }


    SetTitle("InProgress");
    return true;
}