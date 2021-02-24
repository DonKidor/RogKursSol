#include "rog.h"
#include "SpriteText.h"
#include <iostream>

SpriteText::SpriteText(int length) {
	PaintBox();
	numCount=length;
	sf::Texture tex=TextureManager::getNumbers();
	nums=new RogSprite*[length];
	numSize=coord{tex.getSize().x/10,tex.getSize().y/4};
	for(int i=0;i<length;++i)  {
		nums[i] = new RogSprite(tex);
		nums[i]->setTexOffset(coord{0,0},numSize);
		nums[i]->setScale(coord{4,4});
	}
	depth=0;
	setValue(0);
}

void SpriteText::setValue(int v) {
	value=v;
	int t=v;
	for(int i=numCount-1;i>=0;--i) {
		nums[i]->setTexOffset(coord{(numSize.x)*((9+t%10)%10),depth*numSize.y},numSize);
		t/=10;
	}
}



SpriteText::~SpriteText() {
	std::cout << "SpriteText: ";
	for(int i=0;i<numCount;++i) delete nums[i];
}

void SpriteText::paint(sf::RenderWindow &w) {
	for(int i=0;i<numCount;++i)  {
		nums[i]->setPos(pos+coord{i*(numSize.x-1)*4,0});
		nums[i]->paint(w);
	}
}
