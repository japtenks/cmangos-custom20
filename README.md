# Custom20
Custom20 introduces a new tier of mounts available at level 20 for all races in World of Warcraft (1.12.1). The goal is to enhance early-game exploration and mobility while preserving the original pacing and feel of the game.

Before now, traveling long distances on foot before level 40 could feel restrictive, and AI PlayerBots were limited by legacy restrictions. Custom20 solves both problems by introducing:
Level 20 mounts with a modest ~40% speed bonus, sitting between walking and the standard level 40 mounts.
Full support for AI PlayerBots, allowing them to learn and use these mounts autonomously.
Restoration of pre-1.4 unarmored mount models, bringing back assets that were removed from the game.

# Available Cores
Classic

# How to install
1. Follow the instructions in https://github.com/davidonete/cmangos-modules?tab=readme-ov-file#how-to-install
2. Enable the `BUILD_MODULE_CUSTOM20` flag in cmake and run cmake. The module should be installed in `src/modules/custom20`
3. Copy the configuration file from `src/modules/custom20/src/custom20.conf.dist.in` and place it where your mangosd executable is. Also rename it to `custom20.conf`.
4. Remember to edit the config file and modify the options you want to use.
5. You will have to install the database changes located in the `src/modules/custom20/sql/install` folder, each folder inside represents where you should execute the queries. E.g. The queries inside of `src/modules/custom20/sql/install/world` will need to be executed in the world/mangosd database, the ones in `src/modules/custom20/sql/install/characters` in the characters database, etc...
6. Lastly, you will have to replace the server dbcs with the modified ones located in the `src/modules/custom20/dbc` to data folder. Backup the orginals. (rename the extenstion)

# How to uninstall
To remove the Custom20 from your server you have multiple options, the first and easiest is to disable it from the `custom20.conf` file. The second option is to completely remove it from the server and db:
1. Remove the `BUILD_MODULE_custom20` flag from your cmake configuration and recompile the game
2. Execute the sql queries located in the `src/modules/custom20/sql/uninstall` folder. Each folder inside represents where you should execute the queries. E.g. The queries inside of `src/modules/custom20/sql/uninstall/world` will need to be executed in the world/mangosd database, the ones in `src/modules/custom20/sql/uninstall/characters` in the characters database, etc...
3. Restore the orginal dbcs.