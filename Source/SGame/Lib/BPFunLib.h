// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Components/Widget.h"
#include "UObject/ObjectMacros.h"
#include "../StructAndEnum.h"
#include "BPFunLib.generated.h"

/**
 *
 */
UCLASS()
class SGAME_API UBPFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**************         UMG         ***************/
	UFUNCTION(BlueprintCallable, Category = "UMG")
		static UUserWidget* GetWidgetOuter(UWidget* InWidget);
	UFUNCTION(BlueprintCallable, Category = "UMG")
		static void LoadUIConfig(TMap<FString, FUIConfig>& Config);
	UFUNCTION(BlueprintCallable, Category = "UMG")
		static void AddToRoot(UObject* Obj);
	UFUNCTION(BlueprintCallable, Category = "UMG")
		static void RemoveToRoot(UObject* Obj);


};
