#include "rog.h"
#include "PaintObject.h"
#include <iostream>

PaintObject::PaintObject() {
	settedScene=false;
	visible=true;
}

PaintObject::PaintObject(Scene *s) {
	atScene=s;
	settedScene=true;
}

PaintObject::~PaintObject() {
	std::cout <<"deleted PaintObject\n";
}

bool PaintObject::updatePb(allContr cTab,bool canLayer) {
	updated(cTab);
	bool flagLayer=false;
	if(visible&&!canLayer) {
		if(checkBound(cTab.RBtn)) {
			clickedRBM();
			atScene->onClickedRObj(this);
			flagLayer=true;
		}
		if(checkBound(cTab.LBtn)) {
			clickedLBM();
			atScene->selectObj(this);
			atScene->onClickedLObj(this);
			flagLayer=true;
		}
		if(checkBound(cTab.MPos)) {
			mousemove();
			atScene->onMovedObj(this);
			flagLayer=true;
		}
	}
	return flagLayer||canLayer;
}

void PaintObject::setScene(Scene *s) {
	settedScene=true;
	atScene=s;
}

void PaintObject::setVisible(bool v) {
	visible=v;
	if(!v) isSelected=false;
}

bool PaintObject::getVisible() {
	return visible;
}
