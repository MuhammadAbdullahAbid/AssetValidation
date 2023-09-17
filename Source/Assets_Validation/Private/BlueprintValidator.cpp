// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintValidator.h"
#include "Kismet/KismetSystemLibrary.h"

#define LOCTEXT_NAMESPACE "BlueprintValidator"

UBlueprintValidator::UBlueprintValidator()
	:Super()
{
	bIsEnabled = true;
}

bool UBlueprintValidator::CanValidateAsset_Implementation(UObject* InAsset) const
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InAsset);
	
	if (Blueprint)
	{
		return true;
	}
	return false;
}

EDataValidationResult UBlueprintValidator::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InAsset);
	bool bIsClear = false;

	if (Blueprint)
	{
		FString FileName = UKismetSystemLibrary::GetObjectName(Blueprint);

		if (FileName.StartsWith(Prefix, ESearchCase::CaseSensitive))
		{
			AssetPasses(Blueprint);
			bIsClear = true;
		}
		else
		{
			AssetFails(Blueprint, FText::Format(LOCTEXT("StaticMeshValidator", "Missing Prefix: {0}"), FText::FromString(Prefix)), ValidationErrors);
			bIsClear = false;
		}
	}
	if (bIsClear)
	{
		return EDataValidationResult::Valid;
	}
	return EDataValidationResult::Invalid;
}
