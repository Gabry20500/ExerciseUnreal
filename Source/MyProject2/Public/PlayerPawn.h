// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "IDamageable.h"
#include "PlayerPawn.generated.h"


UENUM(BlueprintType)
enum class EPlayerClass : uint8{
	Warrior,
	Mage,
	Archer
};


USTRUCT(BlueprintType)
struct MYPROJECT2_API FPlayerStatistics {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	bool VogliaDiVivere;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	EPlayerClass PlayerClass;

	FPlayerStatistics(): Health(100), Power(100), VogliaDiVivere(true), PlayerClass(EPlayerClass::Warrior)
	{}
};

UCLASS()
class MYPROJECT2_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	
	UFUNCTION(BlueprintCallable, Category = "Player")
	FPlayerStatistics GetPlayerStatistics() const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetPlayerStatistics(const FPlayerStatistics& NewStatistics);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void Kill();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = "true"))
	FPlayerStatistics PlayerStats;
};
