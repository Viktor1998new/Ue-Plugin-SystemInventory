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
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG",
			}
			);

		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/Inventory"),
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/InventoryUMG"),

				// ... add public include paths required here ...
			});
		
		PrivateIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/Inventory"),
				Path.Combine(PluginDirectory,"Source/Inventory/Classes/InventoryUMG"),

				// ... add public include paths required here ...
			});
    }
}
