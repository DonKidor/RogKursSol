#pragma once
#include "rog.h"


class RogLabel : public PaintBox {
	public:
		RogLabel(std::string text);
		std::string text;
		int textColor;
		void paint() override;
		void setText(std::string text) {
			this->text=text;
		};
		void setDefault() override;
};
