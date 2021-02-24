#pragma once

#include "rog.h"

class RogItem : public RogSprite {
	public:
		enum itemType {Consum,Equip};
		RogItem();
		std::string name;
		std::string desc;
		void virtual use() {};
		
};
