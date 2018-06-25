#include "stdafx.h"
#include "Element.h"

namespace lcars {
	Element::Element()
	{
	}


	Element::~Element()
	{
	}

	sf::Vector2f Element::getAbsPos() {
		if (relativeElement == nullptr) {
			return sf::Vector2f(pos[0], pos[1]);
		}

		sf::Vector2f myRelPos = relativeElement->getAttachmentPoint(relativeArrangement);

		switch (relativeArrangement) {
		case 0: //Do nothing
			break;
		case 1: //Do nothing
			break;
		case 2:
			myRelPos.y += -size[1];
			break;
		case 3:
			myRelPos.x += -size[0];
			break;
		}

		return myRelPos;
	}

	sf::Vector2f Element::getAttachmentPoint(int point)
	{
		sf::Vector2f myAbsPos(pos[0], pos[1]);

		if (relativeElement != nullptr)
			myAbsPos = relativeElement->getAttachmentPoint(relativeArrangement);

		switch (point) {
		case 0:
			myAbsPos.y += size[1];
			break;
		case 1:
			myAbsPos.x += size[0];
			break;
		case 2: /*Do nothing*/ break;
		case 3: /*Do nothing*/ break;
		}

		return myAbsPos;
	}
}