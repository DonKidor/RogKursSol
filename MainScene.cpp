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
	PaintGroup *gg=new PaintGroup();
	gg->setPos(coord{100,100});
	RogButton *b[10][10];
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j) {
			b[i][j]=new RogButton("but");
			b[i][j]->baseColor=BLUE;
			b[i][j]->hgColor=GREEN;
			b[i][j]->setPos(coord{i*30,j*30});
			b[i][j]->size=coord{29,29};
			b[i][j]->tag=(20*i)+j;
			gg->add(b[i][j]);
		}
	tt=gg;
	add(gg);
	
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	if(p->tag>=0) tt->setPos(tt->getPos()+coord{20,20});
}
