#pragma once

#include "rog.h"


class RogButton : public RogLabel {
	using RogLabel::RogLabel;
	public:
		int hgColor;
		void paint() override;
		void setDefault() override;
	private:
		void mousemove() override;
		bool hgLight;
		void updated(allContr cTab) override;
};
