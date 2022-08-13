// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameCharacterBase.h"

#include "SGame/SGameGameInstance.h"
// Sets default values
ASGameCharacterBase::ASGameCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AbilitySystemComponent=CreateDefaultSubobject<USGameAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ASGameCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	LoadCharacterComponent();
}

// Called every frame
void ASGameCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASGameCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASGameCharacterBase::LoadCharacterComponent()
{
	FCharacterComponentConfig Cfg = USGameGameInstance::GetCharacterComponentConfig(this);
	for (FSoftClassPath SoftClassPath : Cfg.Components)
	{
		AddComponentByClass(SoftClassPath.TryLoadClass<UActorComponent>(), false, FTransform(), false);
		//ActorComponent//AddComponent();//ActorComponent;
	}
}

USGameAbilitySystemComponent* ASGameCharacterBase::GetSGameGASComponent(AActor* Actor)
{
	if (Actor)
	{
		return Actor->FindComponentByClass<USGameAbilitySystemComponent>();
	}
	return nullptr;
}


UAbilitySystemComponent* ASGameCharacterBase::GetAbilitySystemComponent() const
{
	return FindComponentByClass<USGameAbilitySystemComponent>();
}
