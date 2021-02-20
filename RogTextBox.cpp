#include "rog.h"
#include "RogTextBox.h"
#include <ctype.h>

#define WRONGASCII(X) (X!=13&&X!=72&&X!=80&&X!=75&&X!=0)

void RogTextBox::updated(allContr cTab) {
	counter++;
	counter%=30;
	if(isSelected) {
		for(int i=0;i<cTab.keys.size();++i) {
			if(cTab.keys[i]==8) {
				if(text.size()>0)text.erase(text.end()-1);
			}
			else if(cTab.keys[i]==13) isSelected=false;
			else if(text.size()<maxCharSize&&(isascii(cTab.keys[i]))&&WRONGASCII(cTab.keys[i])&&(!cTab.isContain(0)||cTab.keys[i]!=77))
				text+=(char)cTab.keys[i];
		}
	}
}
void RogTextBox::paint() {
	PaintBox::paint();
	setbkcolor(baseColor);
	setcolor(textColor);
	settextstyle(0,0,1);
	std::string otext=text;
	bool underMax=false;
	if(text.size()<maxCharSize && textwidth((char*)(text+"_").c_str())>size.x) maxCharSize=text.size();
	if(isSelected&&counter>15) {
		if(text.size()<maxCharSize)
			otext+='_';
		else underMax=true;
	}
	outtextxy(pos.x,pos.y+size.y/2-textheight("A")/2,(char*)otext.c_str());
	if(underMax) outtextxy(pos.x+textwidth(" ")*(maxCharSize-1),pos.y+size.y/2-textheight((char*)text.c_str())/2,"_");
}

RogTextBox::RogTextBox() {
	counter=0;
	PaintBox();
}

void RogTextBox::setCharSize(int charSize) {
	maxCharSize=charSize;
}

void RogTextBox::setDefault() {
	PaintBox::setDefault();
	textColor=BLACK;
	maxCharSize=20;
}
