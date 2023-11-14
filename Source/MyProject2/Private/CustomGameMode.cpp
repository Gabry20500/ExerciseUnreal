// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameMode.h"

ACustomGameMode::ACustomGameMode()
{
    DefaultPawnClass = APawn::StaticClass();
    DefaultControllerClass = APlayerController::StaticClass();
}

void ACustomGameMode::BeginPlay()
{
    Super::BeginPlay();

}