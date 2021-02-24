#pragma once


#include "postcodes.h"
#include "Scene.h"

class Scene;

class PaintObject {
	public:
		int tag;
		~PaintObject();
		PaintObject();
		void virtual setPos(coord npos);
		coord getPos();
		void virtual setScene(Scene *s);
		bool virtual updatePb(allContr cTab,bool canLayer);
		void virtual paint(sf::RenderWindow &w) = 0;
		void setSelected(bool f) { isSelected=f;};
		void virtual setVisible(bool v);
		bool getVisible();
		void virtual setDefault();
		void virtual setSize(coord c) { size=c;};
		coord virtual getSize() {return size;};
		
	private:
		Scene *atScene;
		bool virtual checkBound(coord c)=0;
		void virtual updated(allContr cTab) {};
		bool settedScene;
		void virtual clickedLBM(){};
		void virtual clickedRBM(){};
		void virtual mousemove(){};
		bool visible;
	protected:
		coord pos;
		coord size;
		bool isSelected;
		
};

