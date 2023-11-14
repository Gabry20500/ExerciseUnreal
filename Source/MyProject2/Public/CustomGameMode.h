// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerPawn.h"
#include "MyPlayerController.h"
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

	virtual void BeginPlay() override;
};
