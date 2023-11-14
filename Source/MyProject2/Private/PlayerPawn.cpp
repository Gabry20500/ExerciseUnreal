// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"

APlayerPawn::APlayerPawn()
{
    PlayerStats = FPlayerStatistics();

	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MyMesh(TEXT("/Game/ControlRig/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
    if (MyMesh.Succeeded())
    {
        PlayerMesh->SetSkeletalMesh(MyMesh.Object);
    }
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
	PlayerStats.VogliaDiVivere = false;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

