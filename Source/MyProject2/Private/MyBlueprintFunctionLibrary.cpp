// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

UMyBlueprintFunctionLibrary::UMyBlueprintFunctionLibrary()
{
}

int64 UMyBlueprintFunctionLibrary::GetAddressOfVariable(const int32& InValue)
{
	return reinterpret_cast<int64>(&InValue);
}

void UMyBlueprintFunctionLibrary::GetValueByAddress(const int64& Address, int32& OutValue)
{
	*reinterpret_cast<const int32*>(Address);
}

const int32& UMyBlueprintFunctionLibrary::GetReferenceByAddress(const int64& Address)
{
	return *reinterpret_cast<const int32*>(Address);
}


void UMyBlueprintFunctionLibrary::SetValueByAddress(int64 Address, int32 NewValue)
{
	*reinterpret_cast<int32*>(Address) = NewValue;
}

int64 UMyBlueprintFunctionLibrary::AllocateMemory(int32 NumBytes)
{
	void* MemoryAddress = FMemory::Malloc(NumBytes);
	return reinterpret_cast<int64>(MemoryAddress);
}

void UMyBlueprintFunctionLibrary::DeallocateMemory(int64 Address)
{
	void* MemoryAddress = reinterpret_cast<void*>(Address);
	FMemory::Free(MemoryAddress);
}
