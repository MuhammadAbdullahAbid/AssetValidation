// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "TextureValidation.generated.h"

/**
 * 
 */
UCLASS()
class ASSETS_VALIDATION_API UTextureValidation : public UEditorValidatorBase
{
	GENERATED_BODY()
public:

	UTextureValidation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Texture")
	FString Prefix = "T_";

protected:

	virtual bool CanValidateAsset_Implementation(UObject* InAsset) const override;
	virtual EDataValidationResult ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors) override;
	
};
