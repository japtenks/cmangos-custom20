#pragma once
#include "Module.h"
#include "Custom20ModuleConfig.h"

namespace cmangos_module
{
    class Custom20Module : public Module
    {
    public:
        Custom20Module();
        const Custom20ModuleConfig* GetConfig() const override;

#if EXPANSION == 0
        // Fires on every level-up (live bots and players leveling up in the world)
        void OnGiveLevel(Player* player, uint32 level) override;

        // Fires when a player/bot is loaded from DB (covers factory-built bots at level 20-39)
        void OnLoadFromDB(Player* player) override;
#endif

    private:
        void LearnCustomMount(Player* player);
        bool HasAnyCustomMount(Player* player) const;
    };
}

static cmangos_module::Custom20Module custom20Module;
