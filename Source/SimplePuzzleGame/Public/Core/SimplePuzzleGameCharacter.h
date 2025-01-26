// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SimplePuzzleGameCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPaperCollected);

UCLASS(Blueprintable)
class ASimplePuzzleGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASimplePuzzleGameCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UFUNCTION(BlueprintCallable)
	void IncreaseBitsOfPaper();

	UPROPERTY(BlueprintAssignable)
	FOnAllPaperCollected AllPaperCollected;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY()
	int bitsOfPaper = 0;
	
	int maxBitsOfPaperToFind = 4;

};

