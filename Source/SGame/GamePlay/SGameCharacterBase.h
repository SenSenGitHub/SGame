// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SGame/Component/SGameAbilitySystemComponent.h"
#include "SGameCharacterBase.generated.h"

UCLASS()
class SGAME_API ASGameCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// 构造函数
	ASGameCharacterBase();

protected:
	//开始事件
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void LoadCharacterComponent();


	//------------------------------  IAbilitySystemInterface接口实现  ------------------------------------

	//获取技能组件
	UFUNCTION(BlueprintPure, meta=(DisplayName="获取当前的技能组件"))
	static USGameAbilitySystemComponent* GetSGameGASComponent(AActor* Actor);

	//当角色被控制器控制时调用
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	//UPROPERTY(VisibleAnywhere)
	//USGameAbilitySystemComponent* AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="组件设置", meta=(DispalayName="组件列表"))
	TObjectPtr<UDataTable> ComponentConfig;
};
