#include "Custom20Module.h"
#include "Custom20ModuleConfig.h"
#include "Entities/Player.h"
#include "Log.h"
#include "Util.h"

namespace cmangos_module
{
    Custom20Module::Custom20Module()
        : Module("Custom20Module", new Custom20ModuleConfig())
    {
    }

    const Custom20ModuleConfig* Custom20Module::GetConfig() const
    {
        return (const Custom20ModuleConfig*)Module::GetConfig();
    }

    // Fires on every level-up — handles a bot or player crossing level 20 live
    // Mirrors the logic in AutoLearnSpellAction::LearnSpells()
    void Custom20Module::OnGiveLevel(Player* player, uint32 level)
    {
#if EXPANSION == 0
        if (!GetConfig()->enabled)
            return;

        if (level == 20)
            LearnCustomMount(player);
#endif
    }

    // Fires when a player/bot is loaded from DB — handles factory-built bots already at level 20-39
    // Mirrors the logic in PlayerbotFactory::InitMounts()
    void Custom20Module::OnLoadFromDB(Player* player)
    {
#if EXPANSION == 0
        if (!GetConfig()->enabled)
            return;

        if (player->GetLevel() >= 20 && player->GetLevel() < 40)
            LearnCustomMount(player);
#endif
    }

    bool Custom20Module::HasAnyCustomMount(Player* player) const
    {
        static const uint32 allMounts[] =
        {
            34000, 34001, // Human:     Honor Steed, Harvest Steed
            34002, 34003, // Undead:    White Skeleton Horse, Scarlet Skeleton Horse
            34004, 34005, // Night Elf: White Sabertooth, Black Sabertooth
            34006, 34007, // Gnome:     Emerlight Mechanostrider, Whiteflare Mechanostrider
            34008, 34009, // Dwarf:     Coal Ram, Glacier Ram
            34010, 34011, // Troll:     Bwon'Scara Raptor, Jin'Roka Raptor
            34012, 34013, // Orc:       Frostfang Wolf, Embermane Wolf
            34014, 34015, // Tauren:    Mosshide Kodo, Skyhide Kodo
        };

        for (uint32 spell : allMounts)
        {
            if (player->HasSpell(spell))
                return true;
        }

        return false;
    }

    void Custom20Module::LearnCustomMount(Player* player)
    {
        if (!player)
            return;

        // Don't grant a second mount if they already have one
        if (HasAnyCustomMount(player))
            return;

        std::vector<uint32> raceMounts;
        switch (player->getRace())
        {
            case RACE_HUMAN:    raceMounts = {34000, 34001}; break; // Honor Steed, Harvest Steed
            case RACE_UNDEAD:   raceMounts = {34002, 34003}; break; // White Skeleton Horse, Scarlet Skeleton Horse
            case RACE_NIGHTELF: raceMounts = {34004, 34005}; break; // White Sabertooth, Black Sabertooth
            case RACE_GNOME:    raceMounts = {34006, 34007}; break; // Emerlight Mechanostrider, Whiteflare Mechanostrider
            case RACE_DWARF:    raceMounts = {34008, 34009}; break; // Coal Ram, Glacier Ram
            case RACE_TROLL:    raceMounts = {34010, 34011}; break; // Bwon'Scara Raptor, Jin'Roka Raptor
            case RACE_ORC:      raceMounts = {34012, 34013}; break; // Frostfang Wolf, Embermane Wolf
            case RACE_TAUREN:   raceMounts = {34014, 34015}; break; // Mosshide Kodo, Skyhide Kodo
            default: return;
        }

        uint32 index = urand(0, raceMounts.size() - 1);
        uint32 spell = raceMounts[index];

        player->learnSpell(spell, false);
        sLog.outDetail("[Custom20] Player/Bot %u (level %u, race %u) learned custom level 20 mount spell %u",
            player->GetGUIDLow(), player->GetLevel(), player->getRace(), spell);
    }

} // namespace cmangos_module
