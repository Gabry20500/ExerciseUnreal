// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameMode.h"
#include "PlayerPawn.h"
#include "MyPlayerController.h"

ACustomGameMode::ACustomGameMode()
{
    DefaultPawnClass = APlayerPawn::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
}

void ACustomGameMode::BeginPlay()
{
    Super::BeginPlay();
}