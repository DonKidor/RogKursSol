#include "rog.h"
#include "TextureManager.h"

sf::Texture TextureManager::getInventory() {
	sf::Texture tex;
	tex.loadFromFile("res/inventory.png");
	return tex;
}

sf::Texture TextureManager::getNumbers() {
	sf::Texture tex;
	tex.loadFromFile("res/numbers.png");
	return tex;
}
