#include "rog.h"
#include "RogButton.h"

RogButton::RogButton(std::string text) {
	PaintBox();
	this->text=text;
	textColor=BLACK;
}

void RogButton::paint() {
	int t=baseColor;
	if(hgLight)
		baseColor=hgColor;
	PaintBox::paint();
	setbkcolor(baseColor);
	setcolor(textColor);
	settextstyle(0,0,1);
	outtextxy(pos.x+size.x/2-textwidth((char*)text.c_str())/2,pos.y+size.y/2-textheight((char*)text.c_str())/2,(char*)text.c_str());
	baseColor=t;
	
}

void RogButton::mousemove() {
	hgLight=true;
}

void RogButton::updated(allContr cTab) {
	hgLight=false;
}
