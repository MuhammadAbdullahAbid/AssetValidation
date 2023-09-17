// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Assets_Validation : ModuleRules
{
	public Assets_Validation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
