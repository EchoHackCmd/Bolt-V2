#ifndef CLIENT_BOLT_MODULE_PLAYER_AUTOTOOL
#define CLIENT_BOLT_MODULE_PLAYER_AUTOTOOL

#include "../Module.h"

class AutoTool : public Module {
public:
    AutoTool(Category* c) : Module("AutoTool", c) {};
public:
 enum Tool {
		Pickaxe,
		Axe,
		Shovel,
		Sword
	};
    auto onGameMode(GameMode*) -> void override;
    auto selectItem(AutoTool::Tool tool) -> bool;
};

#endif /* CLIENT_BOLT_MODULE_PLAYER_AUTOTOOL */