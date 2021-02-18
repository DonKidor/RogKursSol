#include "rog.h"
#include "SmileScene.h"

void SmileScene::update() {
	if(cTab.isContain(27)) closeScene();
}

void SmileScene::paint() {
	setcolor(RED);
	circle(250,250,60);
}

void SmileScene::initScene() {
	backColor=BLACK;
}
