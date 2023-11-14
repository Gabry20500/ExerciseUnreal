// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerPawn.h"
#include "MyPlayerController.h"
#include "PlayerSaveGame.h"
#include "CustomGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ACustomGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACustomGameMode();

	void RestartPlayer(AController* PlayerController) override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void LoadGame();

protected:
	void SetPlayerStatsFromSaveGame(UPlayerSaveGame* LoadedSaveGame);
};
