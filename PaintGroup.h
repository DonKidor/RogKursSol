#pragma once


#include "rog.h"

class PaintGroup : public PaintObject {
	using PaintObject::PaintObject;
	public:
		void add(PaintObject* p);
		bool updatePb(allContr cTab,bool canLayer) override;
		void paint(sf::RenderWindow &w) override;
		void setVisible(bool v) override;
		void setScene(Scene *s) override;
		void setPos(coord npos) override;
	private:
		void virtual updated(allContr cTab) {};
		std::vector<PaintObject*> groupObj;
		bool checkBound(coord c) override {return false;};
};
