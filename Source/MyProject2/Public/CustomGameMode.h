// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

protected:
	UPROPERTY(EditDEfaultsOnly, BlueprintReadOnly, Category = "Custom GameMode")
	TSubclassOf<APawn> DefaultPawnClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Custom GameMode")
	TSubclassOf<APlayerController> DefaultControllerClass;
};
