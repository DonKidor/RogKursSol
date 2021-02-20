#include <iostream>
#include "rog.h"
#include "MainScene.h"
#include <queue>
#include <ctime>

#define WIDTH 700
#define HEIGHT 700

void startInit() {
	initwindow(WIDTH,HEIGHT);
	srand(time(0));
	setvisualpage(1);
	setactivepage(0);
}

void sceneCycle() {
	coord size={getmaxx()+1,getmaxy()+1};
	Scene *m;
	m=new MainScene(size);
	m->initScene();
	int code;
	Scene *t;
	std::queue<Scene*> q;
	do {
		code=m->doNext(t);
		if(code==LOAD) {
			q.push(m);
			m=t;
		} else if(code==DESTROY) {
			delete m;
			if(q.size()>0) {
				m=q.front();
				q.pop();
			} else break;
		}
	}while(code<ERR);
}

int main() {
	startInit();
	sceneCycle();
	std::cout << "PROGRAM END\n";
	return 0;
}
