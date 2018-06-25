#pragma once
#include "SFML/Graphics.hpp"
#include "stdafx.h"

class RoundedRectangle : public sf::Shape
{
public:
	RoundedRectangle();
	~RoundedRectangle();

	void apply();

	float cornerRadius;

	bool cornerRound[4]; //starts at the bottom right side and then goes on counter-clockwise

	sf::Vector2f size;

	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(size_t index) const;
private:
	int qPointCount = 8; //Make the number even
};