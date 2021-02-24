#pragma once

#include "rog.h"

class PaintGroup;

class RogInventory : public RogSprite{
	public:
		RogInventory();
		~RogInventory();
		void paint(sf::RenderWindow &w) override;
		int hits,golds,attack,defense;
		void setScene(Scene *s) override;
		void setPos(coord npos) override;
	private:
		void updated(allContr cTab) override;
		RogItem *invItems[2][3];
		
		PaintGroup *items;
		
		void doRightPos(PaintObject *t,coord off);
		coord hpOffset;
		SpriteText *hp;
		coord goldOffset;
		SpriteText *gold;
		coord attOffset;
		SpriteText *att;
		coord defOffset;
		SpriteText *def;
		coord itemsOffset;
};
