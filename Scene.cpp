#include "rog.h"
#include <iostream>

Scene::Scene(coord &wSize) {
	this->wSize=wSize;
}

Scene::~Scene() {
	std::set<PaintObject*>::iterator it=pObjects.begin();
	for(;it!=pObjects.end();++it) delete *it;
	std::cout << "deleted scene\n";
}

void Scene::control() {
	cTab.resetKeys();
	int code;
	int x,y;
	while(kbhit()){
		code=getch();
		std::cout << code<<std::endl;
		cTab.keys.push_back(code);
	}
	if(ismouseclick(WM_MOUSEMOVE)) {
		getmouseclick(WM_MOUSEMOVE,x,y);
		coord c{x,y};
		cTab.MPos=c;
	}
	if(ismouseclick(WM_LBUTTONDOWN)) {
		getmouseclick(WM_LBUTTONDOWN,x,y);
		coord c{x,y};
		cTab.LBtn=c;
	}  else cTab.LBtn={-1,-1};
	if(ismouseclick(WM_RBUTTONDOWN)) {
		getmouseclick(WM_RBUTTONDOWN,x,y);
		coord c{x,y};
		cTab.RBtn=c;
	} else cTab.RBtn={-1,-1};
}

void Scene::prepaint() {
	int t=getactivepage();
	setactivepage(1-t);
	setvisualpage(t);
	setfillstyle(1,backColor);
	bar(0,0,wSize.x,wSize.y);
	paint();
	paintObjects();
}

PostCode Scene::doNext(Scene *&scene) {
	postcode=OK;
	control();
	updateObjects();
	update();
	prepaint();
	delay(1000/60);
	scene=tScene;
	return postcode;
}
void Scene::loadScene(Scene *scene) {
	postcode=LOAD;
	tScene=scene;
}

void Scene::closeScene() {
	std::cout << "closed\n";
	postcode=DESTROY;
}

void Scene::add(PaintObject* p) {
	if(pObjects.find(p)==pObjects.end()) 
	{
		pObjects.insert(p);
		p->setScene(this);
	}
}

void Scene::updateObjects() {
	std::set<PaintObject*>::iterator it=pObjects.begin();
	for(;it!=pObjects.end();++it) (*it)->updatePb(cTab);
}

void Scene::paintObjects() {
	std::set<PaintObject*>::iterator it=pObjects.begin();
	for(;it!=pObjects.end();++it) (*it)->paint();
}

void Scene::selectObj(PaintObject *p) {
	std::set<PaintObject*>::iterator it=pObjects.begin();
	for(;it!=pObjects.end();++it) (*it)->setSelected(false);
	p->setSelected(true);
}
