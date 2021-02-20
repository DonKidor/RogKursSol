#include "rog.h"
#include "PaintBox.h"

#include <iostream>

PaintBox::PaintBox() : PaintObject() {

	rect= sf::RectangleShape();
}

bool PaintBox::checkBound(coord c) {
	if(c.x<0 || c.y<0) return false;
	return c.y>=pos.y && c.x>=pos.x && c.x<=pos.x+size.x&&c.y<=pos.y+size.y;
}

void PaintBox::paint(sf::RenderWindow &w) {
	rect.setSize(sf::Vector2f(size.x,size.y));
	rect.setPosition(pos.x,pos.y);
	rect.setFillColor(baseColor);
	w.draw(rect);
}

void PaintBox::setDefault() {
	PaintObject::setDefault();
	baseColor=sf::Color::Blue;
}
