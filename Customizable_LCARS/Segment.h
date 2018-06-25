#pragma once
#include "Element.h"
#include "Content.h"
#include "Swept.h"
#include <vector>

using namespace std;

namespace lcars {
	class Segment : public Element
	{
	public:
		Segment();
		~Segment();

		float contentSize[2];

		//There is no "real" outline, but there are buttons and stuff that form the outline
		float outlineHeight;
		float outlineWidth;

		Swept topSwept;
		Swept bottomSwept;

		//Elements with different Priorities
		vector<Element> elements[6];

		void addPriorityOneElement(int id, string * text, void * callback, bool * active);
		void addPriorityTwoElement(int id, string * text, void * callback, bool * active);
		void addPriorityThreeElement(int id, string * text, void * callback, bool * active);
		void addPriorityFourElement(int id, string * text, void * callback, bool * active);
		void addPriorityFiveElement(int id, string * text1, void * callback1, bool * active1, int * twoDigitOut, string * text2, void * callback2, bool * active2);
		void addPrioritySixElement(int id, Segment * element);

		virtual void update() {}

		vector<Content> contentPanes;
	};
}