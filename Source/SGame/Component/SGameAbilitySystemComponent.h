// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SGame/Ability/SGameGameplayAbility.h"
#include "SGameAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SGAME_API USGameAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	USGameAbilitySystemComponent();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(DisplayName="普通攻击技能"))
	TSoftClassPtr<USGameGameplayAbility> Attack;
};
