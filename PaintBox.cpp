#include "rog.h"
#include "PaintBox.h"

bool PaintBox::checkBound(coord c) {
	if(c.x<0 || c.y<0) return false;
	return c.x>=pos.x && c.y>=pos.y && c.x<=pos.x+size.x&&c.y<=pos.y+size.y;
}

void PaintBox::paint() {
	setcolor(baseColor);
	setfillstyle(1,baseColor);
	bar(pos.x,pos.y,pos.x+size.x,pos.y+size.y);
}
