#include "rog.h"
#include "RogLabel.h"

RogLabel::RogLabel(std::string text) {
	PaintBox();
	this->text=text;
}

void RogLabel::paint() {
	PaintBox::paint();
	setbkcolor(baseColor);
	setcolor(textColor);
	settextstyle(0,0,1);
	outtextxy(pos.x+size.x/2-textwidth((char*)text.c_str())/2,pos.y+size.y/2-textheight((char*)text.c_str())/2,(char*)text.c_str());
}
void RogLabel::setDefault() {
	PaintBox::setDefault();
	textColor=BLACK;
}
