// Fill out your copyright notice in the Description page of Project Settings.


#include "BPFunLib.h"

UUserWidget* UBPFunLib::GetWidgetOuter(UWidget* InWidget)
{
	if (nullptr == InWidget) return  nullptr;
	if (const auto SelfWidget = Cast<UUserWidget>(InWidget)) return SelfWidget;
	UObject* OuterObj = InWidget->GetOuter();
	while (OuterObj) {
		if (const auto OuterWidget = Cast<UUserWidget>(OuterObj)) return OuterWidget;
		OuterObj = OuterObj->GetOuter();
	}
	return nullptr;
}

void UBPFunLib::LoadUIConfig(TMap<FString, FUIConfig>& Config)
{
	Config.Empty();
	static FString Path = TEXT("/Game/UI/Config/UIConfig.UIconfig");
	static UDataTable* UIConfig;
	UIConfig = LoadObject<UDataTable>((UObject*)GetTransientPackage(), *Path);
	if (!UIConfig) return;
	UIConfig->AddToRoot();

	const TMap<FName, uint8*>& RowMap = UIConfig->GetRowMap();
	for (auto& KV : RowMap)
	{
		auto Find = UIConfig->FindRow<FUIConfig>(KV.Key, Path);
		if (Find)
		{
			Config.Add(KV.Key.ToString(), *Find);
		}
	}

}

void UBPFunLib::AddToRoot(UObject* Obj)
{
	if (Obj)
	{
		Obj->AddToRoot();
	}
}

void UBPFunLib::RemoveToRoot(UObject* Obj)
{
	if (Obj)
	{
		Obj->RemoveFromRoot();
	}
}
