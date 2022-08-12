// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameCharacterBase.h"
// Sets default values
ASGameCharacterBase::ASGameCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent=CreateDefaultSubobject<USGameAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ASGameCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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

USGameAbilitySystemComponent* ASGameCharacterBase::GetSGameAbilitySystemComponent()
{
	return  Cast<USGameAbilitySystemComponent>(GetAbilitySystemComponent()) ;
}

UAbilitySystemComponent* ASGameCharacterBase::GetAbilitySystemComponent() const
{
	check(this->AbilitySystemComponent);
	return  this->AbilitySystemComponent;

}

