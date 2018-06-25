#include "stdafx.h"
#include "Segment.h"
#include "SegmentButton.h"

namespace lcars {
	Segment::Segment()
	{
		topSwept.relativeElement = relativeElement;
		topSwept.pos[0] = pos[0];
		topSwept.pos[1] = pos[0];
		//Size is being determined while rendering
		topSwept.relativeArrangement = relativeArrangement;
		topSwept.orientation = 0;
		topSwept.output_height = outlineHeight;
		topSwept.output_width = outlineWidth;
	}

	Segment::~Segment()
	{
	}

	void Segment::addPriorityTwoElement(int id, string * text, void * callback, bool * active)
	{
		SegmentButton button;
		button.text = text;
		button.callback = callback;
		button.active = active;

		button.pos[0] = 0;
		button.pos[1] = 0;
		button.size[0] = 0.5;
		button.size[1] = outlineHeight;
		button.relativeArrangement = 1;

		if (elements[1].size() == 0)
			button.relativeElement = &topSwept;
		else
			button.relativeElement = &elements[1][elements[1].size() - 1];
	}
}