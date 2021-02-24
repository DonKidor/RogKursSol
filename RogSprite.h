#pragma once

#include "rog.h"

class RogSprite : public PaintBox {
	public:
		RogSprite(sf::Texture tex);
		void paint(sf::RenderWindow &w) override;
		void setDefault() override;
		void setTexture(sf::Texture tex);
		void setScale(coord c);
		coord getScale() { return scale;};
		void setSize(coord c) override { throw;};
		
		void setTexOffset(coord pos, coord size);
		
	private:
		sf::RectangleShape rect;
		sf::Texture tex;
	protected:
		coord texUV;
		coord texSize;
		coord scale;
};
