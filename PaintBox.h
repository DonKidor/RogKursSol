#pragma once

#include "rog.h"

class PaintBox : public PaintObject{
	public:
		PaintBox();
		sf::Color baseColor;
		void paint(sf::RenderWindow &w) override;
		void setDefault() override;
	private:
		bool checkBound(coord c) override;
		sf::RectangleShape rect;
};
