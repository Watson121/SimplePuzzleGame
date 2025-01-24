// This interface is responsible for interactions

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/SimplePuzzleGameCharacter.h"
#include "InteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SIMPLEPUZZLEGAME_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Use(ASimplePuzzleGameCharacter* player);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	bool CanBeUsed() const;

};
