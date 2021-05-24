// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unidad5 : ModuleRules
{
	public Unidad5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
