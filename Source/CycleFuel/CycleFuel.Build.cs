using UnrealBuildTool;
using System.IO;
using System;

public class CycleFuel : ModuleRules
{
	public CycleFuel(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;

		// FactoryGame transitive dependencies
		// Not all of these are required, but including the extra ones saves you from having to add them later.
		// Some entries are commented out to avoid compile-time warnings about depending on a module that you don't explicitly depend on.
		// You can uncomment these as necessary when your code actually needs to use them.
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", 
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"EnhancedInput",
			"DeveloperSettings",
			"FactoryGame"		
		});

		// FactoryGame plugins
		PublicDependencyModuleNames.AddRange(new string[] {
			//"AbstractInstance",
			//"InstancedSplinesComponent",
			//"SignificanceISPC"
		});

		// Header stubs
		PublicDependencyModuleNames.AddRange(new string[] {
			"DummyHeaders",
		});

		if (Target.Type == TargetRules.TargetType.Editor) {
			PublicDependencyModuleNames.AddRange(new string[] {/*"OnlineBlueprintSupport",*/ "AnimGraph"});
		}
		PublicDependencyModuleNames.AddRange(new string[] {"FactoryGame", "SML"});
		
		PublicIncludePaths.AddRange(new string[] {
			// ... add public include paths required here ...
		});
		
		PrivateIncludePaths.AddRange(new string[] {
			// ... add private include paths required here ...
		});
		
		PublicDependencyModuleNames.AddRange(new string[] {
			// ... add public dependencies that you statically link with here ...
		});
		
		PrivateDependencyModuleNames.AddRange(new string[] {
			// ... add private dependencies that you statically link with here ...	
		});
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {
			// ... add any modules that your module loads dynamically here ...
		});
	}
}
