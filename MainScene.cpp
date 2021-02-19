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
	RogButton *b[20][20];
	for(int i=0;i<20;++i)
		for(int j=0;j<20;++j) {
			b[i][j]=new RogButton("but");
			b[i][j]->baseColor=BLUE;
			b[i][j]->hgColor=GREEN;
			b[i][j]->pos=coord{i*30,j*30};
			b[i][j]->size=coord{29,29};
			b[i][j]->tag=(20*i)+j;
			add(b[i][j]);
		}
	RogButton *b2;
	b2=new RogButton("Big Button");
	b2->baseColor=BLUE;
	b2->hgColor=GREEN;
	b2->pos=coord{45,45};
	b2->size=coord{60,60};
	b2->tag=-5;
	tt=b2;
	add(b2,1);
	
	RogTextBox *g=new RogTextBox();
	g->baseColor=BLUE;
	g->pos=coord{520,100};
	g->size=coord{150,50};
	add(g,2);
	
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	if(p->tag>0) tt->setVisible(!tt->getVisible());
}
