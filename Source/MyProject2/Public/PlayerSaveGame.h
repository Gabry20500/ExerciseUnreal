// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStats {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 Power;
};

UCLASS()
class MYPROJECT2_API UPlayerSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, Category = "SaveGame")
	FPlayerStatistics PlayerStats;

	UPlayerSaveGame();
};
