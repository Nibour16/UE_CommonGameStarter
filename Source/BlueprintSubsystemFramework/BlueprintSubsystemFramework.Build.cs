using UnrealBuildTool;
using System.IO;

public class BlueprintSubsystemFramework : ModuleRules
{
    public BlueprintSubsystemFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine"
        });
    }
}