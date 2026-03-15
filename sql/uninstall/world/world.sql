-- ============================================================
-- Custom20 Module - World Database Uninstall
-- Version: 1.1
-- Description: Removes all data added by the Custom20 module.
-- Apply to: World DB
-- WARNING: This will permanently remove all custom20 data.
--          Back up your database before running this script.
-- ============================================================

-- Custom creature spawns (GUIDs 9000453-9000471)
DELETE FROM `creature` WHERE `guid` IN (9000453, 9000454, 9000455, 9000456, 9000457, 9000458, 9000459, 9000461, 9000462, 9000463, 9000464, 9000466, 9000468, 9000469, 9000470, 9000471);

-- Custom quest relations (quests 9700-9723)
DELETE FROM `creature_involvedrelation` WHERE `quest` BETWEEN 9700 AND 9723;

-- Custom creature model info (model IDs 18000-18001)
DELETE FROM `creature_model_info` WHERE `modelid` IN (18000, 18001);

-- Custom mount spell templates (spell IDs 34000-34015)
DELETE FROM `spell_template` WHERE `Id` BETWEEN 34000 AND 34015;

-- Custom creature templates (vendor NPCs)
-- NOTE: These are vanilla NPC entries that were modified.
--       This restores them to the state before Custom20 was applied
--       by removing them entirely. Re-apply your base DB if needed.
DELETE FROM `creature_template` WHERE `Entry` IN (240, 1139, 1261, 1265, 1268, 1515, 1745, 2930, 3054, 3338, 3428, 3431, 3432, 3690, 4730, 5613, 5782, 6749, 7937, 7954, 9979, 10054, 12481, 14392);
