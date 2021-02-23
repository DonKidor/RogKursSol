#pragma once

#include "rog.h"

class RogSprite : public PaintBox {
	public:
		RogSprite(sf::Texture tex);
		void paint(sf::RenderWindow &w) override;
		void setDefault() override;
		void setTexture(sf::Texture tex);
		coord texUV;
		coord texSize;
		
	private:
		sf::RectangleShape rect;
		sf::Texture tex;
};
