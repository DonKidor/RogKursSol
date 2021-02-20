#include "rog.h"
#include "MainScene.h"
#include "SmileScene.h"
#include <iostream>

void MainScene::update() {
	if(cTab.isContain(27)) closeScene();
}

void MainScene::paint() {
	coord c=circ;
	setcolor(1);
	
}

void MainScene::initScene() {
	sf::Font font;
	if(!font.loadFromFile("19783.ttf"))
		std::cout << "Error on loading font\n";
	
	PaintGroup *gg=new PaintGroup();
	gg->setPos(coord{100,100});
	RogButton *b[10][10];
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j) {
			b[i][j]=new RogButton("but",font);
			b[i][j]->setDefault();
			b[i][j]->setPos(coord{i*40,j*40});
			b[i][j]->size=coord{39,39};
			b[i][j]->tag=(10*i)+j;
			b[i][j]->charSize=40;
			gg->add(b[i][j]);
		}
	tt=gg;
	add(gg);
	RogTextBox *f=new RogTextBox(font);
	f->setDefault();
	f->setPos(coord{350,100});
	f->size=coord{100,50};
	f->tag=-5;
	add(f,2);
	
	
}

void MainScene::onMovedObj(PaintObject *p) {
	
}
void MainScene::onClickedLObj(PaintObject *p) {
	
	if(p->tag>=0) std::cout << "clicked"<<p->tag<<"\n";
}
