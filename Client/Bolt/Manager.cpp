#include "Manager.h"
#include "Category/Category.h"

Manager::Manager(Client* client) {
	this->client = client;

	this->initHooks();

	this->initCategories();
	this->initModules();
};

auto Manager::initModules(void) -> void {
	
	//

};

auto Manager::initHooks(void) -> void {
	
	//

};

auto Manager::initCategories(void) -> void {
	
	for(auto First = (int)CategoryType::Combat; First <= (int)CategoryType::World; First++) {

		CategoryType currType = static_cast<CategoryType>(First);
		this->categories[currType] = new Category(currType, this);

		Util::debugLog("Category Initialized: " + this->categories[currType]->getName());

	};

};

auto Manager::getCategory(CategoryType type) -> std::string {

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

	};

	return res;

};