// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCodeNumber.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UKeyCodeNumber::NativeConstruct()
{
	Super::NativeConstruct();

	// Binding Buttons
	IncreaseValueButton->OnClicked.AddUniqueDynamic(this, &UKeyCodeNumber::IncreaseValue);
	DecreaseValueButton->OnClicked.AddUniqueDynamic(this, &UKeyCodeNumber::DecreaseValue);
	
	// Setting Value
	value = 0;

	FString valueString = FString::FromInt(value);
	CurrentValue->SetText(FText::FromString(valueString));
}

// Return Key Code Value
int UKeyCodeNumber::GetValue() const
{
	return value;
}

// Increaase the Key Code Number Value
void UKeyCodeNumber::IncreaseValue()
{
	value++;

	if (value > 9) {
		value = 0;
	}

	// Updating Current Value Text
	FString valueString = FString::FromInt(value);
	CurrentValue->SetText(FText::FromString(valueString));
}

// Decrease the Key Code Number Value
void UKeyCodeNumber::DecreaseValue()
{
	value--;

	if (value < 0) {
		value = 9;
	}

	// Updating Current Value Text
	FString valueString = FString::FromInt(value);
	CurrentValue->SetText(FText::FromString(valueString));
}
