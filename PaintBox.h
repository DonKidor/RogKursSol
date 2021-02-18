#pragma once

#include "rog.h"

class PaintBox : public PaintObject{
	using PaintObject::PaintObject;
	public:
		int baseColor;
		void paint() override;
	private:
		bool checkBound(coord c) override;
};
