#pragma once
#include "rog.h"


class RogLabel : public PaintBox {
	public:
		RogLabel(std::string text,sf::Font font);
		std::string text;
		sf::Color textColor;
		void paint(sf::RenderWindow &w) override;
		void setText(std::string text) {
			this->text=text;
		};
		void setDefault() override;
		int charSize;
		bool backVisible;
		void setTextOutline(int thick, sf::Color color);
	private:
		sf::Text textShape;
		sf::Font font;
};
