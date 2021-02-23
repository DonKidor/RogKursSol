#include "rog.h"
#include "RogTextBox.h"
#include <ctype.h>

#include <iostream>
#define WRONGASCII(X) (X!=27&&X!=0)

void RogTextBox::updated(allContr cTab) {
	counter++;
	counter%=1000;
	if(isSelected) {
		
		for(int i=0;i<cTab.chars.size();++i) {
			std::cout << cTab.chars[i]<<std::endl;
			if(cTab.chars[i]==8) {
				if(text.size()>0)text.erase(text.end()-1);
			}
			else if(cTab.chars[i]==13) isSelected=false;
			else if(text.size()<maxCharSize&&WRONGASCII(cTab.chars[i]))
				text+=(char)cTab.chars[i];
		}
	}
}
void RogTextBox::paint(sf::RenderWindow &w) {
	PaintBox::paint(w);
	std::string otext=text;
	
	textShape.setString("ABC");
	
	textShape.setColor(textColor);
	textShape.setFillColor(textColor);
	textShape.setFont(font);
	textShape.setScale(1,1);
	textShape.setCharacterSize(charSize);
	textShape.setPosition(pos.x,pos.y+size.y/2);
	textShape.setOrigin(textShape.getLocalBounds().left,textShape.getLocalBounds().top+textShape.getLocalBounds().height/2);
	
	
	
	bool underMax=false;
	textShape.setString(otext+"_");
	if(text.size()<maxCharSize && textShape.getLocalBounds().width>=size.x) maxCharSize=text.size();
	if(isSelected&&counter>500) {
		if(text.size()<maxCharSize)
			otext+='_';
		else underMax=true;
	}
	
	textShape.setString(otext);
	
	w.draw(textShape);
	//outtextxy(pos.x,pos.y+size.y/2-textheight("A")/2,(char*)otext.c_str());
	if(underMax)  {
		
		textShape.setPosition(textShape.findCharacterPos(maxCharSize-1).x,pos.y+size.y/2);
		textShape.setString("_");
		w.draw(textShape);
		//outtextxy(pos.x+textwidth(" ")*(maxCharSize-1),pos.y+size.y/2-textheight((char*)text.c_str())/2,"_");
	}
}

RogTextBox::RogTextBox(sf::Font font) {
	this->font=font;
	counter=0;
	PaintBox();
}

void RogTextBox::setCharSize(int charSize) {
	maxCharSize=charSize;
}

void RogTextBox::setDefault() {
	PaintBox::setDefault();
	textColor=sf::Color::Black;
	maxCharSize=20;
	charSize=26;
}
