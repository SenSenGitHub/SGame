// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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


	virtual void Init() override;
	virtual void Shutdown() override;

};
