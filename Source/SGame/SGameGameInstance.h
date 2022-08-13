// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructAndEnum.h"
#include "Engine/GameInstance.h"
#include "SGameGameInstance.generated.h"

/**
 *
 */
UCLASS()
class SGAME_API USGameGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	static TWeakObjectPtr<USGameGameInstance> SelfPtr;

	UFUNCTION(BlueprintCallable)
	static USGameGameInstance* GET();

	UFUNCTION(BlueprintCallable, Category="Tool")
	static const FCharacterComponentConfig GetCharacterComponentConfig(ACharacter* Character);

	virtual void Init() override;
	virtual void Shutdown() override;

protected:
	UPROPERTY()
	TMap<FName, FCharacterComponentConfig> CharacterComponentCfg;
};
