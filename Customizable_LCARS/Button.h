#pragma once
#include "Element.h"
#include "RoundedRectangle.h"

using namespace std;

namespace lcars {
	/*
	 * The LCARS Button is the most basic form of input and can only have a vertical and horizontal span of one
	 */
	class Button : public Element {
	public:
		void render(sf::RenderWindow &window);
		void * callback;
		string * text;
		bool * active;
	};
}