// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SGame/StructAndEnum.h"
#include "PawnComponentDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SGAME_API UPawnComponentDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FCharacterComponentConfig Config;
};
