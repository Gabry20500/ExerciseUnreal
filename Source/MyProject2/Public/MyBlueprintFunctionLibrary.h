// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UMyBlueprintFunctionLibrary();

	UFUNCTION(BlueprintPure, CustomThunk, meta = (CustomStructureParam = "InValue"))
	static int64 GetAddressOfVariable(const int32& InValue);

	UFUNCTION(BlueprintPure, CustomThunk, meta = (CustomStructureParam = "OutValue"))
	static void GetValueByAddress(const int64& Address, int32& OutValue);

	UFUNCTION(BlueprintPure, CustomThunk, meta = (CustomStructureParam = "Address"))
	static const int32& GetReferenceByAddress(const int64& Address);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (CustomStructureParam = "Address"))
	static void SetValueByAddress(int64 Address, int32 NewValue);

	UFUNCTION(BlueprintPure, Category = "Memory", meta = (DisplayName = "Allocate Memory", Keywords = "memory allocate"))
	static int64 AllocateMemory(int32 NumBytes);

	UFUNCTION(BlueprintCallable, Category = "Memory", meta = (DisplayName = "Deallocate Memory", Keywords = "memory free"))
	static void DeallocateMemory(int64 Address);

	DECLARE_FUNCTION(execGetAddressOfVariable)
	{
		Stack.StepCompiledIn<FStructProperty>(nullptr);
		const void* InValuePtr = Stack.MostRecentPropertyAddress;

		if (!InValuePtr) {
			return;
		}

		P_FINISH;

		P_NATIVE_BEGIN;

		*(int64*)RESULT_PARAM = reinterpret_cast<int64>(InValuePtr);

		P_NATIVE_END;
	}

	DECLARE_FUNCTION(execGetValueByAddress) {

		Stack.StepCompiledIn<FInt64Property>(nullptr);
		const int64 Address = *(int64*)Stack.MostRecentPropertyAddress;

		Stack.StepCompiledIn<FStructProperty>(nullptr);
		void* OutValuePtr = Stack.MostRecentPropertyAddress;
		const auto* OutValueProp = Stack.MostRecentProperty;

		P_FINISH;

		P_NATIVE_BEGIN;

		OutValueProp->CopyCompleteValue(OutValuePtr, (void*)Address);

		P_NATIVE_END;
	}

	DECLARE_FUNCTION(execGetReferenceByAddress)
	{
		Stack.StepCompiledIn<FStructProperty>(nullptr);
		const int64 Address = *(int64*)Stack.MostRecentPropertyAddress;

		P_GET_PROPERTY_REF(FIntProperty, ReturnValue);
		P_FINISH;

		P_NATIVE_BEGIN;

		ReturnValue = GetReferenceByAddress(Address);

		P_NATIVE_END;
	}

	DECLARE_FUNCTION(execSetValueByAddress)
	{
		Stack.StepCompiledIn<FStructProperty>(nullptr);
		const int64 Address = *(int64*)Stack.MostRecentPropertyAddress;

		P_GET_PROPERTY(FIntProperty, NewValue);
		P_FINISH;

		P_NATIVE_BEGIN;

		SetValueByAddress(Address, NewValue);

		P_NATIVE_END;
	}
};