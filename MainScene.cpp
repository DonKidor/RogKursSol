#include "rog.h"
#include "MainScene.h"
#include "SmileScene.h"
#include <iostream>

void MainScene::update() {
	if(cTab.isContain(27)) closeScene();
}

void MainScene::paint() {
	coord c=circ;
	
}

void MainScene::initScene() {
	sf::Font font;
	if(!font.loadFromFile("19783.ttf"))
		std::cout << "Error on loading font\n";
	RogInventory *b=new RogInventory();
	b->setPos(coord{420,0});
	b->setScale(coord{4,4});
	add(b);
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	
}
