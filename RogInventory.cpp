#include "rog.h"

#include "RogInventory.h"
#include <iostream>



RogInventory::RogInventory() : RogSprite(TextureManager::getInventory()) {
	setTexOffset(coord{0,0},coord{60,122});
	sf::Font font;
	if(!font.loadFromFile("19783.ttf"))
		std::cout << "Error on loading font\n";
		
	hpOffset=coord{15,3}; 		goldOffset=coord{43,3};
	attOffset=coord{15,13}; 	defOffset=coord{43,13};	
	
	hp=new SpriteText(3);
	hp->depth=0;
	hits=123;
	
	gold=new SpriteText(3);
	gold->depth=1;
	golds=456;
	
	att=new SpriteText(2);
	att->depth=2;
	attack=78;
	
	def=new SpriteText(3);
	def->depth=3;
	defense=902;
	
}

RogInventory::~RogInventory() {
	delete hp,def,att,gold;
}

void RogInventory::doRightPos(SpriteText *t,coord off,sf::RenderWindow &w) {
	t->setPos(pos+(off*scale));
	t->paint(w);
}

void RogInventory::paint(sf::RenderWindow &w) {
	RogSprite::paint(w);
	if(hp->getValue()!=hits) hp->setValue(hits);
	if(gold->getValue()!=golds) gold->setValue(golds);
	if(att->getValue()!=attack) att->setValue(attack);
	if(def->getValue()!=defense) def->setValue(defense);
	doRightPos(hp,hpOffset,w);
	doRightPos(gold,goldOffset,w);
	doRightPos(att,attOffset,w);
	doRightPos(def,defOffset,w);
}
