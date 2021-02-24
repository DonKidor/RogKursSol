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
	
	
	itemsOffset=coord{1,82};
	
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
	
	items=new PaintGroup();
	items->setPos(coord{0,0});
	for(int j=0;j<2;++j)
	for(int i=0;i<3;++i) {
		invItems[j][i]=new RogItem();
		invItems[j][i]->setTexOffset(coord{18*i,18*((j+4)%5)},coord{19,19});
		invItems[j][i]->setScale(coord{4,4});
		invItems[j][i]->setPos(coord{invItems[j][i]->getSize().x*i,invItems[j][i]->getSize().y*j});
		invItems[j][i]->tag=100+i+j*3;
		items->add(invItems[j][i]);
	}
	invItems[0][1]->setVisible(false);
}

void RogInventory::updated(allContr cTab) {
	
	doRightPos(hp,hpOffset);
	doRightPos(gold,goldOffset);
	doRightPos(att,attOffset);
	doRightPos(def,defOffset);
	doRightPos(items,itemsOffset);
	

	if(hp->getValue()!=hits) hp->setValue(hits);
	if(gold->getValue()!=golds) gold->setValue(golds);
	if(att->getValue()!=attack) att->setValue(attack);
	if(def->getValue()!=defense) def->setValue(defense);
}

void RogInventory::setScene(Scene *s) {
	RogSprite::setScene(s);
	s->add(items,10);
}

void RogInventory::setPos(coord npos) {
	std::cout << pos.x<<"yayayapos\n";
	RogSprite::setPos(npos);
	
}

RogInventory::~RogInventory() {
	std::cout << "RogInventory: ";
	delete hp,def,att,gold;
}

void RogInventory::doRightPos(PaintObject *t,coord off) {
	t->setPos(pos+(off*scale));
}

void RogInventory::paint(sf::RenderWindow &w) {
	RogSprite::paint(w);
	hp->paint(w); gold->paint(w); att->paint(w); def->paint(w);
	
}

