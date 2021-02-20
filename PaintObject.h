#pragma once


#include "postcodes.h"
#include "Scene.h"

class Scene;

class PaintObject {
	public:
		int tag;
		coord size;
		~PaintObject();
		PaintObject();
		PaintObject(Scene* s);
		void virtual setPos(coord npos);
		coord getPos();
		void virtual setScene(Scene *s);
		bool virtual updatePb(allContr cTab,bool canLayer);
		void virtual paint() = 0;
		void setSelected(bool f) { isSelected=f;};
		void virtual setVisible(bool v);
		bool getVisible();
		
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
		bool isSelected;
		
};

