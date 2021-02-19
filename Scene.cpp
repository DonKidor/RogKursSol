#include "rog.h"
#include <iostream>

Scene::Scene(coord &wSize) {
	this->wSize=wSize;
	MAXLayer=0;
	
	selectedObj=0;
}

Scene::~Scene() {
	std::map<int, std::set<PaintObject*> >::iterator it2=pObjects.begin();
	for(;it2!=pObjects.end();++it2) {
		std::set<PaintObject*>::iterator it=(it2->second).begin();
		for(;it!=(it2->second).end();++it) delete *it;
	}
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
	add(p,0);
}

void Scene::add(PaintObject* p,int layer) {
	if(pObjects[layer].find(p)==pObjects[layer].end()) 
	{
		pObjects[layer].insert(p);
		p->setScene(this);
	}
}

void Scene::updateObjects() {
	bool flagLayer=false;
	std::map<int, std::set<PaintObject*> >::reverse_iterator it2=pObjects.rbegin();
	for(;it2!=pObjects.rend();++it2) {
		std::set<PaintObject*>::iterator it=(it2->second).begin();
		for(;it!=(it2->second).end();++it) flagLayer=(*it)->updatePb(cTab,flagLayer);
	}
}

void Scene::paintObjects() {
	std::map<int, std::set<PaintObject*> >::iterator it2=pObjects.begin();
	for(;it2!=pObjects.end();++it2) {
		std::set<PaintObject*>::iterator it=(it2->second).begin();
		for(;it!=(it2->second).end();++it) if((*it)->getVisible()) (*it)->paint();
	}
}

void Scene::selectObj(PaintObject *p) {
	if(selectedObj!=0) selectedObj->setSelected(false);
	p->setSelected(true);
	selectedObj=p;
}
