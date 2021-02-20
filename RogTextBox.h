#pragma once
#include "rog.h"

class RogTextBox : public PaintBox {
	private:
		int counter;
		std::string text;
		void paint(sf::RenderWindow &w) override;
		void updated(allContr cTab) override;
		int maxCharSize;
		sf::Text textShape;
		sf::Font font;
	public:
		int charSize;
		RogTextBox(sf::Font font);
		void setCharSize(int charSize);
		sf::Color textColor;
		void setDefault() override;
};
