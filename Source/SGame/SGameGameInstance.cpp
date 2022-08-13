// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameGameInstance.h"
#include "UnLuaBase.h"
#include "UnLua.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"

TWeakObjectPtr<USGameGameInstance> USGameGameInstance::SelfPtr = nullptr;

USGameGameInstance* USGameGameInstance::GET()
{
	if (SelfPtr.IsValid())
	{
		return SelfPtr.Get();
	}
	return nullptr;
}

const FCharacterComponentConfig USGameGameInstance::GetCharacterComponentConfig(ACharacter* Character)
{
	FCharacterComponentConfig Config;
	static FString Path = TEXT("/Game/Character/Config/CharacterComponentConfig.CharacterComponentConfig");
	static UDataTable* CharacterComponentConfig;
	CharacterComponentConfig = LoadObject<UDataTable>((UObject*)GetTransientPackage(), *Path);
	check(CharacterComponentConfig);
	const TMap<FName, uint8*>& RowMap = CharacterComponentConfig->GetRowMap();
	for (auto& KV : RowMap)
	{
		auto Find = CharacterComponentConfig->FindRow<FCharacterComponentConfig>(KV.Key, Path);
		if (Find && Find->Character.Get() == Character->GetClass())
		{
			return *Find;
		}
	}
	return Config;
}


void USGameGameInstance::Init()
{
	Super::Init();
	SelfPtr = this;
	UnLua::CallTableFunc(UnLua::GetState(), "UI", "CloseAllUI");
}

void USGameGameInstance::Shutdown()
{
	UnLua::CallTableFunc(UnLua::GetState(), "UI", "CloseAllUI");
	Super::Shutdown();
}
