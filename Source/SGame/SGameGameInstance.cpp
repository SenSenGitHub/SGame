// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameGameInstance.h"
#include "UnLuaBase.h"
#include "UnLua.h"

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
	UnLua::CallTableFunc(UnLua::GetState(),"UI","CloseAllUI");
}

void USGameGameInstance::Shutdown()
{
	Super::Shutdown();
	UnLua::CallTableFunc(UnLua::GetState(),"UI","CloseAllUI");
}
