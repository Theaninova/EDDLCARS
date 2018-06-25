#include "stdafx.h"
#include "SegmentButton.h"
#include "RoundedRectangle.h"
#include "StaticValues.h"

namespace lcars {
	SegmentButton::SegmentButton()
	{
	}


	SegmentButton::~SegmentButton()
	{
	}

	void SegmentButton::render(sf::RenderWindow & window)
	{
		RoundedRectangle button;
		button.cornerRound[0] = false;
		button.cornerRound[1] = false;
		button.cornerRound[2] = false;
		button.cornerRound[3] = false;

		sf::Vector2f absSize;
		absSize.x = (size[0] - padding) * defaultSpan[0] * renderScale;
		absSize.y = (size[1] - padding) * defaultSpan[1] * renderScale;

		button.size = absSize;

		button.cornerRadius = absSize.y / 2;

		sf::Vector2f absPos = getAbsPos();
		absPos.x = (absPos.x + padding / 2) * defaultSpan[0] * renderScale;
		absPos.y = (absPos.y + padding / 2) * defaultSpan[1] * renderScale;

		button.setPosition(absPos);

		button.setFillColor(sf::Color::Red);

		button.apply();

		window.draw(button);
	}
}