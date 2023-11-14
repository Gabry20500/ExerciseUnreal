// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameMode.h"
#include "PlayerPawn.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"

ACustomGameMode::ACustomGameMode()
{
    DefaultPawnClass = APlayerPawn::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
}

void ACustomGameMode::RestartPlayer(AController* PlayerController)
{
    Super::RestartPlayer(PlayerController);
    LoadGame();
}


void ACustomGameMode::BeginPlay()
{
    Super::BeginPlay();
}




void ACustomGameMode::SaveGame()
{
    UPlayerSaveGame* SaveGameInstance = Cast<UPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveGame::StaticClass()));

    if (SaveGameInstance) {
        
        APlayerPawn* ply = GetWorld()->GetFirstPlayerController()->GetPawn<APlayerPawn>();

        SaveGameInstance->PlayerStats = ply->GetPlayerStatistics();

        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
    }
}

void ACustomGameMode::LoadGame()
{
    UPlayerSaveGame* LoadedSaveGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));

    if (LoadedSaveGame) {
        SetPlayerStatsFromSaveGame(LoadedSaveGame);
    }
}

void ACustomGameMode::SetPlayerStatsFromSaveGame(UPlayerSaveGame* LoadedSaveGame)
{
    APlayerPawn* ply = GetWorld()->GetFirstPlayerController()->GetPawn<APlayerPawn>();
    ply->SetPlayerStatistics(LoadedSaveGame->PlayerStats);
}
