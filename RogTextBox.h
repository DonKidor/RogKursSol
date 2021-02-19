#pragma once
#include "rog.h"

class RogTextBox : public PaintBox {
	private:
		int counter;
		std::string text;
		void paint() override;
		void updated(allContr cTab) override;
		int maxCharSize;
	public:
		RogTextBox();
		void setCharSize(int charSize);
		int textColor;
};
