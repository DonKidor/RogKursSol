#include "rog.h"
#include "RogButton.h"


void RogButton::paint() {
	int t=baseColor;
	if(hgLight)
		baseColor=hgColor;
	RogLabel::paint();
	baseColor=t;
}

void RogButton::mousemove() {
	hgLight=true;
}

void RogButton::updated(allContr cTab) {
	hgLight=false;
}

void RogButton::setDefault() {
	RogLabel::setDefault();
	hgColor=GREEN;
}
