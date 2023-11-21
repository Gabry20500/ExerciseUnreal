// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"
#include <PlayerSaveGame.h>
#include "Kismet/GameplayStatics.h"

void UMyGameInstanceSubsystem::SaveGameData(int32 Health, int32 Power)
{
    SavedGameData.Health = Health;
    SavedGameData.Power = Power;

    UPlayerSaveGame* SaveGameInstance = Cast<UPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveGame::StaticClass()));

    if (SaveGameInstance) {

        SaveGameInstance->PlayerStats = SavedGameData;

        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
    }
}

void UMyGameInstanceSubsystem::LoadGame()
{
    UPlayerSaveGame* LoadedSaveGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));

    if (LoadedSaveGame) {
        SetPlayerStatsFromSaveGame(LoadedSaveGame);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Not load"));
    }
}

void UMyGameInstanceSubsystem::SetPlayerStatsFromSaveGame(UPlayerSaveGame* LoadedSaveGame)
{
    APlayerPawn* ply = GetWorld()->GetFirstPlayerController()->GetPawn<APlayerPawn>();
    ply->SetPlayerStatistics(LoadedSaveGame->PlayerStats);
}
