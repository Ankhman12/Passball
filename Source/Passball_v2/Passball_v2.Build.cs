// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Passball_v2 : ModuleRules
{
	public Passball_v2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
