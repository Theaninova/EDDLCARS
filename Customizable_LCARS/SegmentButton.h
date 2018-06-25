#pragma once
#include "Button.h"

namespace lcars {
	class SegmentButton : public Button
	{
	public:
		SegmentButton();
		~SegmentButton();

		void render(sf::RenderWindow &window);
	};
}