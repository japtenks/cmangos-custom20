#pragma once
#include "ModuleConfig.h"

namespace cmangos_module
{
    class Custom20ModuleConfig : public ModuleConfig
    {
    public:
        Custom20ModuleConfig();
        bool OnLoad() override;

    public:
        bool enabled;
    };
}