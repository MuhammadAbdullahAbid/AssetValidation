// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshValidation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/StaticMesh.h"

#define LOCTEXT_NAMESPACE "StaticMeshValidator"


UStaticMeshValidation::UStaticMeshValidation()
	:Super()
{
	bIsEnabled = true;
}

bool UStaticMeshValidation::CanValidateAsset_Implementation(UObject* InAsset) const
{
	UStaticMesh* StaticMesh = Cast<UStaticMesh>(InAsset);

	if (StaticMesh)
	{
		return true;
	}

	return false;
}

EDataValidationResult UStaticMeshValidation::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
	UStaticMesh* StaticMesh = Cast<UStaticMesh>(InAsset);
	bool bIsClear = false;

	if (StaticMesh)
	{
		FString FileName = UKismetSystemLibrary::GetObjectName(StaticMesh);

		if (FileName.StartsWith(Prefix,ESearchCase::CaseSensitive))
		{
			AssetPasses(StaticMesh);
			bIsClear = true;
		}
		else
		{
			AssetFails(StaticMesh, FText::Format(LOCTEXT("StaticMeshValidator", "Missing Prefix: {0}"), FText::FromString(Prefix)), ValidationErrors);
			bIsClear = false;
		}
	}
	if (bIsClear)
	{
		return EDataValidationResult::Valid;
	}
	return EDataValidationResult::Invalid;
}

