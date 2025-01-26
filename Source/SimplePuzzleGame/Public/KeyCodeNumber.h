// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KeyCodeNumber.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEPUZZLEGAME_API UKeyCodeNumber : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* CurrentValue;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* IncreaseValueButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* DecreaseValueButton;

	UFUNCTION(BlueprintPure)
	int GetValue() const;

protected:

	UPROPERTY(BlueprintReadOnly)
	int value;

	UFUNCTION()
	void IncreaseValue();

	UFUNCTION()
	void DecreaseValue();

};
