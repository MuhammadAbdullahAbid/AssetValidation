// Fill out your copyright notice in the Description page of Project Settings.


#include "TextureValidation.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Engine/Texture2D.h>

#define LOCTEXT_NAMESPACE "TextureValidator"

UTextureValidation::UTextureValidation()
	: Super()
{
	bIsEnabled = true;
}


bool UTextureValidation::CanValidateAsset_Implementation(UObject* InAsset) const
{
	UTexture2D* Texture = Cast<UTexture2D>(InAsset);

	if (Texture)
	{
		return true;
	}
	return false;
}

EDataValidationResult UTextureValidation::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
	UTexture2D* Texture = Cast<UTexture2D>(InAsset);
	bool bIsClear = false;

	if (Texture)
	{
		FString FileName = UKismetSystemLibrary::GetObjectName(Texture);
		
		if (FileName.StartsWith(Prefix,ESearchCase::CaseSensitive))
		{
			AssetPasses(Texture);

			bIsClear = true;
			
		}
		else
		{
			AssetFails(Texture,FText::Format(LOCTEXT("TextureValidator","Missing Prefix : {0}"),FText::FromString(Prefix)), ValidationErrors);
			bIsClear = false;
		}
	}

	if (bIsClear)
	{
		return EDataValidationResult::Valid;
	}

	return EDataValidationResult::Invalid;
}
