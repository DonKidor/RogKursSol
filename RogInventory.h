#pragma once

#include "rog.h"

class RogInventory : public RogSprite {
	public:
		RogInventory();
		~RogInventory();
		void paint(sf::RenderWindow &w) override;
		int hits,golds,attack,defense;
	private:
		void doRightPos(SpriteText *t,coord off,sf::RenderWindow &w);
		coord hpOffset;
		SpriteText *hp;
		coord goldOffset;
		SpriteText *gold;
		coord attOffset;
		SpriteText *att;
		coord defOffset;
		SpriteText *def;
};
