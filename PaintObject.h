#pragma once


#include "postcodes.h"
#include "Scene.h"

class Scene;

class PaintObject {
	public:
		int tag;
		coord pos;
		coord size;
		~PaintObject();
		PaintObject();
		PaintObject(Scene* s);
		void setScene(Scene *s);
		bool updatePb(allContr cTab,bool canLayer);
		void virtual paint() = 0;
		void setSelected(bool f) { isSelected=f;};
		void setVisible(bool v);
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
		bool isSelected;
		
};

