// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialValidation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Materials/Material.h"

#define LOCTEXT_NAMESPACE "MaterialValidator"

UMaterialValidation::UMaterialValidation()
	:Super()
{
	bIsEnabled = true;
}

bool UMaterialValidation::CanValidateAsset_Implementation(UObject* InAsset) const
{
	UMaterial* Material = Cast<UMaterial>(InAsset);

	if (Material)
	{
		return true;
	}
	return false;
}

EDataValidationResult UMaterialValidation::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
	UMaterial* Material = Cast<UMaterial>(InAsset);
	bool bIsClear = false;

	if (Material)
	{
		 FString FileName = UKismetSystemLibrary::GetObjectName(Material);

		if (FileName.StartsWith(Prefix,ESearchCase::CaseSensitive))
		{
			AssetPasses(Material);
			bIsClear = true;
		}
		else
		{
			AssetFails(Material, FText::Format(LOCTEXT("MaterialValidator", "Missing Prefix: {0}"), FText::FromString(Prefix)), ValidationErrors);
			bIsClear = false;
		}
	}
	if (bIsClear)
	{
		return EDataValidationResult::Valid;
	}
	return EDataValidationResult::Invalid;
}
