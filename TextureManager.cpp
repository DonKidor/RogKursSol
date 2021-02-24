#include "rog.h"
#include "TextureManager.h"

sf::Texture& TextureManager::getInventory() {
	static sf::Texture inv;
	inv.loadFromFile("res/inventory.png");
	return inv;
}

sf::Texture& TextureManager::getNumbers() {
	static sf::Texture num;
	num.loadFromFile("res/numbers.png");
	return num;
}


sf::Texture& TextureManager::getItems() {
	static sf::Texture num;
	num.loadFromFile("res/items.png");
	return num;
}

