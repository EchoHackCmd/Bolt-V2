#include "Manager.h"


Manager::Manager(Client* client) {
	this->client = client;
	this->initHooks();
	this->initModules();
};

auto Manager::initModules(void) -> void {
	//
}

auto Manager::initHooks(void) -> void {
	//
}

auto Manager::initCategories(void) -> void {
	//
}