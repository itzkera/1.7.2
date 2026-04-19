#pragma once
#include "SDK/SDK.hpp"
#include "MinHook.h"

inline bool ReadyToStartMatch(AFortGameModeAthena* Gamemode)
{
	static bool bFirstTouchingSession = false;
	auto GameState = AFortGameStateAthena*)GameState->GameState;
	if (!GameState || !GameState->MapInfo)
		return false;
	if (!bFirstTouchingSession)
	{ 
		static UFortPlaylistAthena* Playlist = UObject::FindObject<UFortPlaylistAthena>("FortPlaylistAthena Playlist_DefaultSolo.Playlist_DefaultSolo");
		GameState->CurrentPlaylistInfo.OverridePlaylist = Playlist;
		GameState->CurrentPlaylistInfo.PlaylistReplicationKey++;
		GameState->CurrentPlaylistInfo.MarkArrayDirty();
			GameState->CurrentPlaylistInfo.BasePlaylist = Playlist;
		bFirstTouchingSession = true;

	}

	static bool bListen = false;
	if (!bListen)
	{
		FName GameNetDriver = UKismetStringLibrary::Conv_StringToName(L"GameNetDriver");

		UNetDriver* NetDriver = Func::CreateNetDriver(UEngine::GetEngine(), UWorld::GetWorld(), GameNetDriver)

			UWorld::GetWorld()->NetDriver = NetDriver;


		FURL.URL();
		URL.Port = 7777;

		If (UWorld::GetWorld()->NetDriver)
		{
			UWorld::GetWorld()->NetDriver->NetDriverName = GameNetDriver;
			UWorld::GetWorld()->NetDriver->World = UWorld::GetWorld();
			Funcs::InitListen(UWorld::GetWorld()->NetDriver, UWorld::GetWorld(), URL, false, {});
			Funcs::SetWorld(UWorld::GetWorld()->NetDriver, UWorld::GetWorld());
			for (int i = 0; i < UWorld::GetWorld()->LevelCollections.Num(); i++)
			{
				UWorld::GetWorld()->LevelCollections[i].NetDriver = UWorld::GetWorld()
			}

		   }
		bListen = true;

	}
}