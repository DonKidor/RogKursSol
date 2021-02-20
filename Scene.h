#pragma once

#include <graphics.h>
#include "rog.h"
#include "PaintObject.h"
#include "postcodes.h"
#include <map>


class Scene {
	public:
		virtual void initScene() {};
		PostCode doNext(Scene *&scene);
		Scene(sf::RenderWindow &window);
		void add(PaintObject *p);
		void add(PaintObject *p, int layer);
		~Scene();
		void virtual onMovedObj(PaintObject *p) {};
		void virtual onClickedLObj(PaintObject *p) {};
		void virtual onClickedRObj(PaintObject *p) {};
		void selectObj(PaintObject *p);
		
	private:
		std::map<int,std::set<PaintObject*> > pObjects;
		virtual void paint() = 0;
		virtual void update() = 0;
		void control();
		void prepaint();
		void updateObjects();
		void paintObjects();
		int MAXLayer;
		PaintObject *selectedObj;
		Scene *tScene;
		PostCode postcode;
		
		
	protected:
		void loadScene(Scene *scene);
		void closeScene();
		int backColor;
		allContr cTab;
		sf::RenderWindow &window;
		
		
		
};

