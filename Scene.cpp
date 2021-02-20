#include "rog.h"
#include <iostream>

Scene::Scene(sf::RenderWindow &window) : window(window) {
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
	sf::Event ev;
	cTab.LBtn={-1,-1};
	cTab.RBtn={-1,-1};
	while(window.pollEvent(ev)){
		if (ev.type == sf::Event::Closed) {
        	postcode=CLOSE;
        }
		if(ev.type==sf::Event::KeyPressed)
			cTab.keys.push_back(1);
			
		if(ev.type==sf::Event::TextEntered)
			cTab.chars.push_back(ev.text.unicode);
	
		if(ev.type==sf::Event::MouseMoved) {
			coord c{ev.mouseMove.x,ev.mouseMove.y};
			cTab.MPos=c;
		}
		if(ev.type==sf::Event::MouseButtonPressed && ev.mouseButton.button==sf::Mouse::Left) {
			coord c{ev.mouseButton.x,ev.mouseButton.y};
			cTab.LBtn=c;
		}
		if((ev.type==sf::Event::MouseButtonPressed) && (ev.mouseButton.button==sf::Mouse::Right)) {
			coord c{ev.mouseButton.x,ev.mouseButton.y};
			cTab.RBtn=c;
		}
	}
}

void Scene::prepaint() {
	window.clear();
	paint();
	paintObjects();
	window.display();
}

PostCode Scene::doNext(Scene *&scene) {
	postcode=OK;
	control();
	updateObjects();
	update();
	prepaint();
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
		for(;it!=(it2->second).end();++it) if((*it)->getVisible()) (*it)->paint(window);
	}
}

void Scene::selectObj(PaintObject *p) {
	if(selectedObj!=0) selectedObj->setSelected(false);
	p->setSelected(true);
	selectedObj=p;
}
