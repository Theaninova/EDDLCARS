#pragma once
#include "SFML/Graphics.hpp"
#include "RoundedRectangle.h"
#include "Element.h"

namespace lcars {
	class Swept : public Element
	{
	public:
		Swept();
		~Swept();

		int orientation; // 0 is from bottom to right, 1 top to right, 2 left to top, 3 left to bottom

		float output_width;
		float output_height;

		void render(sf::RenderWindow &window);

		/*
		* 0 bottom : top left corner, 1 right : top left corner, 2 top : bottom left corner, 3 left : top right corner
		*/
		sf::Vector2f getAttachmentPoint(int point);
	};
}