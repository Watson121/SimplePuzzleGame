// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyPad.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "KeyCodeNumber.h"

void UKeyPad::NativeConstruct()
{
	Super::NativeConstruct();

	ConfirmButton->OnClicked.AddUniqueDynamic(this, &UKeyPad::CheckIfCorrect);
}

FString UKeyPad::GetCorrectCode()
{
	return correctCode;
}

void UKeyPad::CheckIfCorrect()
{
	FString currentCode;

	currentCode = FString::FromInt(KeyCodeNumberOne->GetValue()) 
		+ FString::FromInt(KeyCodeNumberTwo->GetValue()) 
		+ FString::FromInt(KeyCodeNumberThree->GetValue())
		+ FString::FromInt(KeyCodeNumberFour->GetValue());

	UE_LOG(LogTemp, Warning, TEXT("Current Value is %s"), *currentCode);

	if (currentCode == correctCode) {
		UE_LOG(LogTemp, Warning, TEXT("Code is correct"));
		ConfirmationText->SetText(FText::FromString("Code is correct! Well Done!"));
	}
	else {
		ConfirmationText->SetText(FText::FromString("Code is incorrect! Try Again!"));
	}

}

// Generate a brand new code
void UKeyPad::GenerateCode()
{
	int newCode = FMath::RandRange(1000, 9999);
	correctCode = FString::FromInt(newCode);

	UE_LOG(LogTemp, Warning, TEXT("Correct Code: %s"), *correctCode);
}
