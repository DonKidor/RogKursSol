#pragma once

#include <graphics.h>
#include "rog.h"
#include "PaintObject.h"
#include "postcodes.h"


class Scene {
	public:
		virtual void initScene() {};
		PostCode doNext(Scene *&scene);
		Scene(coord &wSize);
		void add(PaintObject *p);
		~Scene();
		void virtual onMovedObj(PaintObject *p) {};
		void virtual onClickedLObj(PaintObject *p) {};
		void virtual onClickedRObj(PaintObject *p) {};
		void selectObj(PaintObject *p);
		
	private:
		std::set<PaintObject*> pObjects;
		virtual void paint() = 0;
		virtual void update() = 0;
		void control();
		void prepaint();
		void updateObjects();
		void paintObjects();
		
		
	protected:
		void loadScene(Scene *scene);
		void closeScene();
		int backColor;
		allContr cTab;
		coord wSize;
		PostCode postcode;
		Scene *tScene;
		
};

