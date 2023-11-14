// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

UINTERFACE(Blueprintable)
class MYPROJECT2_API UIDamageable : public UInterface
{
    GENERATED_BODY()
};

class MYPROJECT2_API IDamageable
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float TakeDamage(float DamageAmount);
};