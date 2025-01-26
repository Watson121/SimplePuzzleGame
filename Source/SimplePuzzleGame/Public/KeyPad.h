// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KeyPad.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEPUZZLEGAME_API UKeyPad : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UKeyCodeNumber* KeyCodeNumberOne;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UKeyCodeNumber* KeyCodeNumberTwo;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UKeyCodeNumber* KeyCodeNumberThree;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UKeyCodeNumber* KeyCodeNumberFour;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ConfirmButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ConfirmationText;

protected:

	UPROPERTY(BlueprintReadOnly)
	FString correctCode;

	// Checking if the code entered is correct
	UFUNCTION()
	void CheckIfCorrect();

	UFUNCTION(BlueprintCallable)
	void GenerateCode();


};
