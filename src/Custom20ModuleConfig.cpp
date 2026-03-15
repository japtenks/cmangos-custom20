#include "Custom20ModuleConfig.h"

namespace cmangos_module
{
    Custom20ModuleConfig::Custom20ModuleConfig()
    : ModuleConfig("custom20.conf")
    , enabled(false)
    {

    }

    bool Custom20ModuleConfig::OnLoad()
    {
        enabled = config.GetBoolDefault("Custom20.Enable", false);
        return true;
    }
}