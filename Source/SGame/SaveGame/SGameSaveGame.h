// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SGameSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SGAME_API USGameSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString Test;
	
};
