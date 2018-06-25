#include "stdafx.h"
#include "Swept.h"
#include "StaticValues.h"

namespace lcars {
	Swept::Swept()
	{
	}


	Swept::~Swept()
	{
	}

	void Swept::render(sf::RenderWindow & window)
	{
		RoundedRectangle button;

		button.cornerRound[0] = false;
		button.cornerRound[1] = false;
		button.cornerRound[2] = false;
		button.cornerRound[3] = false;

		if (orientation == 0) button.cornerRound[2] = true;
		if (orientation == 1) button.cornerRound[1] = true;
		if (orientation == 2) button.cornerRound[0] = true;
		if (orientation == 3) button.cornerRound[3] = true;

		sf::Vector2f absSize;
		absSize.x = (size[0] - padding) * defaultSpan[0] * renderScale;
		absSize.y = (size[1] - padding) * defaultSpan[1] * renderScale;
		button.size = absSize;

		if ((output_height * defaultSpan[1]) > (output_width * defaultSpan[0]))
			button.cornerRadius = ((output_width * defaultSpan[0]) + (1 * defaultSpan[1])) * renderScale;
		else
			button.cornerRadius = ((output_height * defaultSpan[1]) + (1 * defaultSpan[1])) * renderScale;

		sf::Vector2f absPos = getAbsPos();
		absPos.x = (absPos.x + padding / 2) * defaultSpan[0] * renderScale;
		absPos.y = (absPos.y + padding / 2) * defaultSpan[1] * renderScale;
		button.setPosition(absPos);

		button.setFillColor(sf::Color::Green);

		button.apply();
		window.draw(button);

		//Making the inverse curve by Overlaying a part of the extension
		RoundedRectangle overlay;

		overlay.cornerRound[0] = false;
		overlay.cornerRound[1] = false;
		overlay.cornerRound[2] = false;
		overlay.cornerRound[3] = false;

		if (orientation == 0) overlay.cornerRound[2] = true;
		if (orientation == 1) overlay.cornerRound[1] = true;
		if (orientation == 2) overlay.cornerRound[0] = true;
		if (orientation == 3) overlay.cornerRound[3] = true;

		absSize.x = (size[0] - output_width) * defaultSpan[0] * renderScale;
		absSize.y = (size[1] - output_height) * defaultSpan[1] * renderScale;
		overlay.size = absSize;

		if (orientation != 2 && orientation != 3)
			absPos.x += (output_width - padding) * defaultSpan[0] * renderScale;
		if (orientation != 1 && orientation != 2)
			absPos.y += (output_height - padding) * defaultSpan[1] * renderScale;
		overlay.setPosition(absPos);

		overlay.cornerRadius = 1 * defaultSpan[1] * renderScale;

		overlay.setFillColor(sf::Color::Black);

		//overlay.setOutlineThickness(2);

		overlay.apply();
		window.draw(overlay);
	}

	sf::Vector2f Swept::getAttachmentPoint(int point)
	{
		sf::Vector2f myAbsPos(pos[0], pos[1]);

		if (relativeElement != nullptr)
			myAbsPos = relativeElement->getAttachmentPoint(relativeArrangement);

		switch (point) {
		case 0:
			if (orientation == 2 || orientation == 3)
				myAbsPos.x += size[0] - output_width;

			myAbsPos.y += size[1];
			break;
		case 1:
			if (orientation == 1 || orientation == 2)
				myAbsPos.y += size[1] - output_height;

			myAbsPos.x += size[0];
			break;
		case 2:
			if (orientation == 2 || orientation == 3)
				myAbsPos.x += size[0] - output_width;

			break;
		case 3:
			if (orientation == 1 || orientation == 2)
				myAbsPos.y += size[1] - output_height;

			break;
		}

		return myAbsPos;
	}
}