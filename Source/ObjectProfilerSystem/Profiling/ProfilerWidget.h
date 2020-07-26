// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProfilerWidget.generated.h"

/**
 * 
 */

UCLASS()
class OBJECTPROFILERSYSTEM_API UProfilerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* ObjectName;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* ObjectDescription;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* ObjectFlavorText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USoundBase* ClickSound;


	UFUNCTION(BlueprintCallable)
	void SetProfilerInformation(FName Name, FText Description, FText FlavorText, FVector ActorLocation);
	UFUNCTION(BlueprintCallable)
		void ClearProfilerInformation();

	void UpdateProfiler();

	UPROPERTY(EditAnywhere)
		float TextSpeed = 0.05f;
	FTimerHandle TextTimer;

	FString FullName;
	FString FullDescription;
	FString FullFlavorText;
	FVector ProfiledActorLocation;

	TArray<wchar_t> C_FullName;
	TArray<wchar_t> C_FullDescription;
	TArray<wchar_t> C_FullFlavorText;


	FString CurrentName;
	FString CurrentDescription;
	FString CurrentFlavorText;
};
