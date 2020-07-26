// Fill out your copyright notice in the Description page of Project Settings.


#include "ProfilerWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UProfilerWidget::SetProfilerInformation(FName Name, FText Description, FText FlavorText, FVector ActorLocation)
{

	//Setting all the necessary information
	FullName = Name.ToString();
	FullDescription = Description.ToString();
	FullFlavorText = FlavorText.ToString();
	ProfiledActorLocation = ActorLocation;

	C_FullName = FullName.GetCharArray();
	C_FullDescription = FullDescription.GetCharArray();
	C_FullFlavorText = FullFlavorText.GetCharArray();
	
	//Setting every string to zero before we start
	CurrentName = "";
	CurrentDescription = "";
	CurrentFlavorText = "";

	GetWorld()->GetTimerManager().SetTimer(TextTimer, this, &UProfilerWidget::UpdateProfiler, TextSpeed, true);
}

void UProfilerWidget::ClearProfilerInformation()
{
	ObjectName->SetText(FText::GetEmpty());
	ObjectDescription->SetText(FText::GetEmpty());
	ObjectFlavorText->SetText(FText::GetEmpty());
}

void UProfilerWidget::UpdateProfiler()
{
	bool bRun = false;
	if(C_FullName.Num() > 0)
	{
		bRun = true;
		CurrentName.AppendChar(C_FullName[0]);
		C_FullName.RemoveAt(0);
		ObjectName->SetText(FText::FromString(CurrentName));
	}
	if(C_FullDescription.Num() > 0)
	{
		CurrentDescription.AppendChar(C_FullDescription[0]);
		C_FullDescription.RemoveAt(0);
		ObjectDescription->SetText(FText::FromString(CurrentDescription));
		bRun = true;
	}
	if(C_FullFlavorText.Num() > 0)
	{
		
		CurrentFlavorText.AppendChar(C_FullFlavorText[0]);
		C_FullFlavorText.RemoveAt(0);
		ObjectFlavorText->SetText(FText::FromString(CurrentFlavorText));
		bRun = true;
		
	}
	if(!bRun)
	{
		GetWorld()->GetTimerManager().ClearTimer(TextTimer);
	}
	else
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ClickSound, GetWorld()->GetFirstPlayerController()->GetFocalLocation(), FRotator(0, 0, 0), 1, FMath::FRandRange(0.6f, 0.9f));
	}

}

////font still not set
//FullDialogue = InDialogue;
//FullDialogueInChars = FullDialogue.GetCharArray();
//DialogueCharIndex = 0;
//this->Dialogue = "";
//Responses = InResponses;
//// UE_LOG(LogTemp, Warning, TEXT("SETTING DIALOGUE"))
//float TextSpeedChecker = TextSpeed;
//if (TextSpeedChecker < 0.00001f)
//{
//	TextSpeedChecker = 0.03f;
//}
//bCurrentlyWriting = true;
//GetWorld()->GetTimerManager().SetTimer(DialogueTimerHandle, this, &UDialogueWidget::AppendDialogueString,
//	TextSpeedChecker, true);