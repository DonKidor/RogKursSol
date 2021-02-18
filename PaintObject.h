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
		void updatePb(allContr cTab);
		void virtual paint() = 0;
		void setSelected(bool f) { isSelected=f;};
	private:
		Scene *atScene;
		bool virtual checkBound(coord c)=0;
		void virtual updated(allContr cTab) {};
		bool settedScene;
		void virtual clickedLBM(){};
		void virtual clickedRBM(){};
		void virtual mousemove(){};
	protected:
		bool isSelected;
		
};

