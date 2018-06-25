#include "stdafx.h"
#include "InputFocusedSegment.h"

namespace lcars {
	InputFocusedSegment::InputFocusedSegment()
	{
	}

	InputFocusedSegment::~InputFocusedSegment()
	{
	}

	void InputFocusedSegment::addButton(void * callback, float width)
	{
		SegmentButton button;
		button.callback = callback;
		button.pos[0] = 0;
		button.pos[1] = 0;
		button.size[0] = 2;
		button.size[1] = outlineHeight;
		button.relativeArrangement = 1;
		button.relativeElement = &buttons[buttons.size() - 1];

		buttons.push_back(button);
	}

	void InputFocusedSegment::update()
	{
		topSwept.relativeElement = relativeElement;
		topSwept.pos[0] = 0;
		topSwept.pos[1] = 0;
		topSwept.size[0] = 4;
		topSwept.size[1] = 3;
		topSwept.arrangement[0] = 1;
		topSwept.arrangement[1] = 0;
		topSwept.relativeArrangement = 0;
		topSwept.orientation = 3;
		topSwept.output_height = 1;
		topSwept.output_width = 2;
		//elements.push_back(&swept);
	}

	void InputFocusedSegment::render(sf::RenderWindow & window)
	{
		topSwept.render(window);
		bottomSwept.render(window);

		for (SegmentButton &button : buttons) {
			button.render(window);
		}

		contentPanes[0].render(window);
	}
}