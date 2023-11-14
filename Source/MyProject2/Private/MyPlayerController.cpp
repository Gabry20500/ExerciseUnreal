// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PlayerPawn.h"


AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    APlayerPawn* PlyPawn = nullptr;
    //for (TActorIterator<APlayerPawn> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
    //{
    //    PlyPawn = *ActorIterator;
    //    break; // Esci dal ciclo dopo aver trovato il SpecificPawn
    //}

    if (PlyPawn)
    {
       /* Possess(PlyPawn);*/
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlyPawn non trovato!"));
    }
}

void AMyPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (GetPawn())
    {
        FVector NewLocation = GetPawn()->GetActorLocation() + (MovementInput * DeltaTime * 500.0f); // Adjust the multiplier based on desired movement speed
        GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Cyan, FString::Printf(TEXT("%s"), *(MovementInput * DeltaTime * 500.0f).ToString()));
        GetPawn()->SetActorLocation(NewLocation);
    }
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind movement input functions to axis mappings
    InputComponent->BindAxis("MoveX", this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis("MoveY", this, &AMyPlayerController::MoveRight);

}

void AMyPlayerController::MoveForward(float Value)
{
    MovementInput.X = Value;
}

void AMyPlayerController::MoveRight(float Value)
{
    MovementInput.Y = Value;
}

void AMyPlayerController::OnMouseX(float Value)
{
}

void AMyPlayerController::OnMouseY(float Value)
{
}