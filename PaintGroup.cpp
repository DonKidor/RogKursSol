#include "PaintGroup.h"
#include "rog.h"
#include <iostream>

bool PaintGroup::updatePb(allContr cTab,bool canLayer) {
	updated(cTab);
	bool flagLayer=canLayer;
	for(int i=0;i<groupObj.size();++i)
		flagLayer=groupObj[i]->updatePb(cTab,flagLayer);
	return flagLayer;
}

PaintGroup::~PaintGroup() {
	for(int i=0;i<groupObj.size();++i) delete groupObj[i];
}

void PaintGroup::setScene(Scene *s) {
	PaintObject::setScene(s);
	for(int i=0;i<groupObj.size();++i) groupObj[i]->setScene(s);
}

void PaintGroup::paint(sf::RenderWindow &w) {
	for(int i=0;i<groupObj.size();++i) if(groupObj[i]->getVisible())groupObj[i]->paint(w);
}

void PaintGroup::setVisible(bool v) {
	PaintObject::setVisible(v);
	for(int i=0;i<groupObj.size();++i) groupObj[i]->setVisible(v);
}

void PaintGroup::add(PaintObject* p) {
	groupObj.push_back(p);
}

void PaintGroup::setPos(coord npos) {
	coord offset=npos-pos;
	for(int i=0;i<groupObj.size();++i) groupObj[i]->setPos(groupObj[i]->getPos()+offset);
	PaintObject::setPos(npos);
}
