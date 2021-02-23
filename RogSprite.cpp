#include "rog.h"
#include "RogSprite.h"

RogSprite::RogSprite(sf::Texture tex) {
	PaintBox();
	rect=sf::RectangleShape(sf::Vector2f(100,100));
	texUV=coord{0,0};
	texSize=coord{20,20};
	this->tex=tex;
}

void RogSprite::paint(sf::RenderWindow &w) {
	rect.setPosition(sf::Vector2f(pos.x,pos.y));
	rect.setTexture(&tex);
	rect.setTextureRect(sf::IntRect(texUV.x,texUV.y,texSize.x,texSize.y));
	rect.setSize(sf::Vector2f(size.x,size.y));
	w.draw(rect);
}

void RogSprite::setDefault() {
	
}

void RogSprite::setTexture(sf::Texture tex) {
	this->tex=tex;
}
