// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameGameInstance.h"

TWeakObjectPtr<USGameGameInstance> USGameGameInstance::SelfPtr = nullptr;

USGameGameInstance* USGameGameInstance::GET()
{
	if (SelfPtr.IsValid())
	{
		return SelfPtr.Get();
	}
	return nullptr;
}

void USGameGameInstance::Init()
{
	Super::Init();
	SelfPtr = this;
}

void USGameGameInstance::Shutdown()
{
	Super::Shutdown();
}
