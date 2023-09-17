// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "StaticMeshValidation.generated.h"

/**
 * 
 */
UCLASS()
class ASSETS_VALIDATION_API UStaticMeshValidation : public UEditorValidatorBase
{
	GENERATED_BODY()
public:
	UStaticMeshValidation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Texture")
	FString Prefix = "SM_";

protected:

	virtual bool CanValidateAsset_Implementation(UObject* InAsset) const override;
	virtual EDataValidationResult ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors) override;



	
};
