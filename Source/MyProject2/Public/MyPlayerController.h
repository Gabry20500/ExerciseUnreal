// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT2_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AMyPlayerController();

    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // Function to handle movement input
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Mouse input functions
    void OnMouseX(float Value);
    void OnMouseY(float Value);

protected:
    FVector MovementInput;
};