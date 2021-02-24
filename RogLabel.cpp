#include "rog.h"
#include "RogLabel.h"

RogLabel::RogLabel(std::string text, sf::Font font) {
	PaintBox();
	this->font=font;
	this->text=text;
	backVisible=true;
	textShape = sf::Text();
}

void RogLabel::setTextOutline(int thick, sf::Color color) {
	textShape.setOutlineColor(color);
	textShape.setOutlineThickness(thick);
}

void RogLabel::paint(sf::RenderWindow &w) {
	if(backVisible)
		PaintBox::paint(w);
	textShape.setString(text);
	textShape.setColor(textColor);
	textShape.setFillColor(textColor);
	textShape.setFont(font);
	textShape.setScale(1,1);
	textShape.setCharacterSize(charSize);
	textShape.setPosition(pos.x+(size.x/2),pos.y+(size.y/2));
	textShape.setOrigin(textShape.getLocalBounds().left+textShape.getLocalBounds().width/2,textShape.getLocalBounds().top+textShape.getLocalBounds().height/2);
	
	w.draw(textShape);
	//outtextxy(pos.x+size.x/2-textwidth((char*)text.c_str())/2,pos.y+size.y/2-textheight((char*)text.c_str())/2,(char*)text.c_str());
}
void RogLabel::setDefault() {
	charSize=26;
	PaintBox::setDefault();
	textColor=sf::Color::Black;
}
