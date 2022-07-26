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

	};

};