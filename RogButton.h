#pragma once

#include "rog.h"


class RogButton : public RogLabel {
	using RogLabel::RogLabel;
	public:
		sf::Color hgColor;
		void paint(sf::RenderWindow &w) override;
		void setDefault() override;
	private:
		void mousemove() override;
		bool hgLight;
		void updated(allContr cTab) override;
};
