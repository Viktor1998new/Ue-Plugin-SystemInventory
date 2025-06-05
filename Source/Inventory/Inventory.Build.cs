// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Inventory : ModuleRules
{
	public Inventory(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Json",
                "JsonUtilities",
                "GameplayTags"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG"
			}
			);

		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory,"Source/Inventory/Classes"),
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/InventoryUMG")
			});
		
		PrivateIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/"),
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/InventoryUMG")
			});
    }
}
