// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyRPG : ModuleRules
{
	public MyRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        PrivateDependencyModuleNames.AddRange(new string[] {
    "RenderCore", "RHI"
});

        PublicDefinitions.Add("ALLOW_CUSTOM_SHADER_COMPILATION=1");

    }
}
