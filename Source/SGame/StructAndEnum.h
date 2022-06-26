// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "StructAndEnum.generated.h"

/**
 * 
 */

 ///UI 配置表
 USTRUCT(BlueprintType)
struct FUIConfig:public FTableRowBase
 {
	GENERATED_USTRUCT_BODY()
 public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(MetaClass=UserWidget,AllowAbstract=0,DisplayName="UI界面"))
		FSoftClassPath WidgetClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="层级"))
		int32 Level=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="是否入栈"))
		bool IsStack=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="是否关闭其他界面"))
		bool IsCloseOther=false;

 };



UCLASS()
class SGAME_API UStructAndEnum : public UObject
{
	GENERATED_BODY()
	
};
