#pragma once
#include "SFML\Graphics.hpp"

namespace lcars {
	class Element
	{
	public:
		Element();
		~Element();

		Element * relativeElement;

		float pos[2]; //Position in span
		float size[2];

		void * callback;
		bool * visible;

		int arrangement[2]; //first bool is 1 if the element should be on the right of the other element else it is 2, second is 1 when it is above, 2 when below. They can be 0, when pos should not be changed
		int relativeArrangement; //0 bottom : top left corner, 1 right : top left corner, 2 top : bottom left corner, 3 left : top right corner

		virtual void render(sf::RenderWindow &window) {}

		/*
		* Returns a vector of its absolute position in span
		*/
		sf::Vector2f getAbsPos();

		/*
		* 0 bottom : top left corner, 1 right : top left corner, 2 top : bottom left corner, 3 left : top right corner
		*/
		virtual sf::Vector2f getAttachmentPoint(int point);
	};
}