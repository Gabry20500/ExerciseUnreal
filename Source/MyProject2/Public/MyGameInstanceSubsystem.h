// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerSaveGame.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 * 
 */

UCLASS()
class MYPROJECT2_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
    void SaveGameData(int32 Health, int32 Power);

    UFUNCTION(BlueprintCallable)
    void LoadGame();


protected:
    void SetPlayerStatsFromSaveGame(UPlayerSaveGame* LoadedSaveGame);
    
    FGameData SavedGameData;
};
