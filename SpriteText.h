#pragma once

#include "rog.h"

class SpriteText : public PaintBox {
	public:
		SpriteText(int length);
		~SpriteText();
		void setValue(int v);
		int getValue() { return value;};
		void paint(sf::RenderWindow &w) override;
		int depth;
	private:
		coord numSize;
		int value;
		RogSprite **nums;
		int numCount;
};
