#include <iostream>
#include "rog.h"
#include "MainScene.h"
#include <queue>
#include <ctime>

#define WIDTH 700
#define HEIGHT 700




void startInit() {
	
	srand(time(0));
}



void sceneCycle(sf::RenderWindow& window) {
	Scene *m;
	
	m=new MainScene(window);
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
		} else if(code==CLOSE) {
			window.close();
			delete m;
			while(q.size()>0) {
				delete q.front();
				q.pop();
			}
		}
	}while(window.isOpen() && code<ERR);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window",sf::Style::Titlebar | sf::Style::Close);
	startInit();
	sceneCycle(window);
	std::cout << "PROGRAM END\n";
	return 0;
}
