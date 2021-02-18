#pragma once

#include "rog.h"

class RogButton : public PaintBox {
	
	public:
		RogButton(std::string text);
		std::string text;
		int hgColor;
		int textColor;
		void paint() override;
		void setText(std::string text) {
			this->text=text;
		};
	private:
		void mousemove() override;
		bool hgLight;
		void updated(allContr cTab) override;
};
