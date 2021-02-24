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

	sf::Texture tex;
	tex.loadFromFile("res/tiles.png");
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j) {
			RogSprite *sprite=new RogSprite(tex);
			sprite->setPos(coord{268+i*90,10+j*90});
			sprite->setTexOffset(coord{j*20+20,i*20},coord{20,20});
			sprite->setScale(coord{4,4});
			add(sprite);
		}
	sf::Texture tex2;
	tex2.loadFromFile("res/field_tiles.png");
	RogSprite *sp=new RogSprite(tex2);
	sp->setTexOffset(coord{0,0},coord{62,122});
	sp->setPos(coord{0,0});
	sp->setScale(coord{4,4});
	add(sp,-1);
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	
}
