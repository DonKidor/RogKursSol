#include "rog.h"
#include "PaintObject.h"
#include <iostream>

PaintObject::PaintObject() {
	settedScene=false;
}

PaintObject::PaintObject(Scene *s) {
	atScene=s;
	settedScene=true;
}

PaintObject::~PaintObject() {
	std::cout <<"deleted PaintObject\n";
}

void PaintObject::updatePb(allContr cTab) {
	updated(cTab);
	if(checkBound(cTab.RBtn)) {
		clickedRBM();
		atScene->onClickedRObj(this);
	}
	if(checkBound(cTab.LBtn)) {
		clickedLBM();
		atScene->selectObj(this);
		atScene->onClickedLObj(this);
	}
	if(checkBound(cTab.MPos)) {
		mousemove();
		atScene->onMovedObj(this);
	}
}

void PaintObject::setScene(Scene *s) {
	settedScene=true;
	atScene=s;
}
