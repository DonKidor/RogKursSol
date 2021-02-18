#include "rog.h"
#include "MainScene.h"
#include "SmileScene.h"
#include <iostream>

void MainScene::update() {
	if(cTab.isContain(27)) closeScene();
	if(cTab.isContain(103)) {
		Scene *s=new SmileScene(wSize);
		s->initScene();
		loadScene(s);
	}
}

void MainScene::paint() {
	coord c=circ;
	setcolor(1);
	
}

void MainScene::initScene() {
	backColor=BLACK;
	RogTextBox *b,*b2;
	b=new RogTextBox();
	b->baseColor=BLUE;
	b->pos=coord{50,50};
	b->size=coord{100,40};
	b->tag=5;
	add(b);
	
	b2=new RogTextBox();
	b2->baseColor=BLUE;
	b2->pos=coord{50,100};
	b2->size=coord{100,50};
	b2->tag=6;
	add(b2);
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	
}
