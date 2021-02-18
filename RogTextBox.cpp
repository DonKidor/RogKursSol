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
			else if(isascii(cTab.keys[i])&&WRONGASCII(cTab.keys[i])&&(!cTab.isContain(0)||cTab.keys[i]!=77))
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
	if(isSelected&&counter>15) otext+='_';
	outtextxy(pos.x,pos.y+size.y/2-textheight((char*)text.c_str())/2,(char*)otext.c_str());
}

RogTextBox::RogTextBox() {
	counter=0;
	textColor=BLACK;
	PaintBox();
}
