// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "BlueprintValidator.generated.h"

/**
 * 
 */
UCLASS()
class ASSETS_VALIDATION_API UBlueprintValidator : public UEditorValidatorBase
{
	GENERATED_BODY()
public:
	UBlueprintValidator();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Texture")
	FString Prefix = "BP_";
protected: 

	virtual bool CanValidateAsset_Implementation(UObject* InAsset) const override;
	virtual EDataValidationResult ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors) override;


	
};
