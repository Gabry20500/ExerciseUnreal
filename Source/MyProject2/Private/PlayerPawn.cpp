// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerStats.Health = 100;
	PlayerStats.Power = 100;
	PlayerStats.VogliaDiVivere = false;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

FPlayerStatistics APlayerPawn::GetPlayerStatistics() const
{
	return PlayerStats;
}

void APlayerPawn::SetPlayerStatistics(const FPlayerStatistics& NewStatistics)
{
	PlayerStats = NewStatistics;
}

void APlayerPawn::Kill()
{
	PlayerStats.Health = 0;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

