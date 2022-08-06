#include "Manager.h"

#include "Category/Category.h"
#include "../Client.h"

Manager::Manager(Client* client) {

	this->client = client;
	client->manager = this;

	this->isRunning = true;

	this->initHooks();

	this->initCategories();
	this->initModules();
	this->baseTick();

};

#include "Hook/Hooks/ClientInstance/ClientInstance.h"
#include "Hook/Hooks/SwapChain/SwapChain.h"
#include "Hook/Hooks/GameMode/GameMode.h"
#include "Hook/Hooks/Entity/Entity.h"
#include "Hook/Hooks/Packet/Packet.h"
#include "Hook/Hooks/Gamma/Gamma.h"
#include "Hook/Hooks/Key/Key.h"

auto Manager::initHooks(void) -> void {
	
	if(MH_Initialize() == MH_OK) {

		new ClientInstance_Hook(this);
		new SwapChain_Hook(this);
		new GameMode_Hook(this);
		new Entity_Hook(this);
		new Packet_Hook(this);
		new Gamma_Hook(this);
		new Key_Hook(this);


	} else {

		Utils::debugLog("MinHook failed to initialize!");

	};

};

auto Manager::initCategories(void) -> void {
	
	for(auto First = (int)CategoryType::Combat; First <= (int)CategoryType::Other; First++) {

		CategoryType currType = static_cast<CategoryType>(First);
		this->categories[currType] = new Category(currType, this);

		Utils::debugLog("Category Initialized: " + this->categories[currType]->getName());

	};

};

auto Manager::getCategory(CategoryType type) -> std::pair<std::string, Category*> {

	auto res = std::string("Unknown");
	
	switch(type) {

		case CategoryType::Combat:
			res = "Combat";
		break;

		case CategoryType::Movement:
			res = "Movement";
		break;

		case CategoryType::Player:
			res = "Player";
		break;

		case CategoryType::Render:
			res = "Render";
		break;

		case CategoryType::World:
			res = "World";
		break;

		case CategoryType::Other:
			res = "Other";
		break;

	};

	return std::pair<std::string, Category*>(res, (res.rfind("Unknown") == std::string::npos ? this->categories[type] : nullptr));

};

/* Combat */


#include "Module/Combat/Criticals.h"
#include "Module/Combat/Killaura.h"
#include "Module/Combat/Hitbox.h"


/* Movement */


#include "Module/Movement/NoSlow.h"


/* Player */



/* Render */


#include "Module/Render/TabGui.h"
#include "Module/Render/FluxSwing.h"
#include "Module/Render/NoCameraClip.h"


/* Other */


#include "Module/Other/TestModule.h"
#include "Module/Other/Uninject.h"


auto Manager::initModules(void) -> void {
	
	/* Combat */

	
	new Criticals(this->categories[CategoryType::Combat]);
	new Killaura(this->categories[CategoryType::Combat]);
	new Hitbox(this->categories[CategoryType::Combat]);
	

	/* Movement */

	
	new NoSlow(this->categories[CategoryType::Movement]);
	
	
	/* Player */

	
	// WIP

	
	/* Render */

	
	new TabGui(this->categories[CategoryType::Render]);
	new FluxSwing(this->categories[CategoryType::Render]);
	new NoCameraClip(this->categories[CategoryType::Render]);
	
	
	/* Other */

	
	new Uninject(this->categories[CategoryType::Other]);
	new TestModule(this->categories[CategoryType::Other]);
	

};

auto Manager::baseTick(void) -> void {

	while(this->isRunning) {

		this->isRunning = (this->client != nullptr ? this->client->manager != nullptr : false);

		for(auto [ type, category ] : this->categories) {

			category->baseTick();

		};

		Sleep(1);

	};

	
	for(auto [ type, category ] : this->categories) {

		for(auto mod : category->modules) {

			for(auto [ addr, bytes ] : mod->patches) {

				mod->patchBytes((void*)addr, bytes);

			};

			mod->patches.clear();
			mod->onDisable();

		};

	};


	kiero::shutdown();
	MH_Uninitialize();

	Sleep(100);
	
	FreeLibraryAndExitThread(Utils::getDll(), 1);

};

auto Manager::isUsingKey(uint64_t key) -> bool {

	return (this->keyMap.contains(key) ? this->keyMap[key] : false);

};

auto Manager::cleanEntityMap(void) -> void {

	auto instance = Minecraft::getClientInstance();
	
	auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
	auto level = (player != nullptr ? player->getLevel() : nullptr);

	if(level == nullptr)
		return this->entityMap.clear();
	
	for(auto [ runtimeId, entity] : this->entityMap) {

		if(level->getRuntimeEntity(runtimeId, false) == nullptr)
			this->entityMap.erase(runtimeId);

	};

};

auto Manager::getLocalPlayer(void) -> class Player* {

	for(auto [ runtimeId, entity ] : this->entityMap) {

		auto level = entity->getLevel();

		if(level == nullptr)
			continue;
		
		return level->getPrimaryLocalPlayer();

	};

	return nullptr;

};