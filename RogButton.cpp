#include "rog.h"
#include "RogButton.h"


void RogButton::paint(sf::RenderWindow &w) {
	sf::Color t=baseColor;
	if(hgLight)
		baseColor=hgColor;
	RogLabel::paint(w);
	baseColor=t;
}

void RogButton::mousemove() {
	hgLight=true;
}

void RogButton::updated(allContr cTab) {
	hgLight=false;
}

void RogButton::setDefault() {
	RogLabel::setDefault();
	hgColor=sf::Color::Green;
}
