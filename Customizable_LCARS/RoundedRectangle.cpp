#include "stdafx.h"
#include "RoundedRectangle.h"
#include <vector>

using namespace std;

RoundedRectangle::RoundedRectangle()
{
}


RoundedRectangle::~RoundedRectangle()
{
}

void RoundedRectangle::apply()
{
	update();
}

size_t RoundedRectangle::getPointCount() const
{
	return 4 * qPointCount;
}

bool check(int index, int qPointCount, bool round, int checkTime) {
	if (!round && (index >= qPointCount * checkTime && index < qPointCount * (checkTime + 1))) {
		return true;
	}
	else {
		return false;
	}
}

sf::Vector2f RoundedRectangle::getPoint(size_t index) const
{
	if (check((int) index, qPointCount, cornerRound[0], 0)) { return sf::Vector2f(size.x, size.y); }
	if (check((int) index, qPointCount, cornerRound[1], 1)) { return sf::Vector2f(0, size.y); }
	if (check((int) index, qPointCount, cornerRound[2], 2)) { return sf::Vector2f(0, 0); }
	if (check((int) index, qPointCount, cornerRound[3], 3)) { return sf::Vector2f(size.x, 0); }

	const float pi = 3.141592654f;

	int center = (int) index / qPointCount;

	float alpha = (index - center) * ((pi / 2) / (qPointCount - 1));

	sf::Vector2f out;

	out.x = cos(alpha) * cornerRadius;
	out.y = sin(alpha) * cornerRadius;

	switch (center) {
	case 0: out.x += size.x - cornerRadius; out.y += size.y - cornerRadius; break;
	case 1: out.x += cornerRadius;          out.y += size.y - cornerRadius; break;
	case 2: out.x += cornerRadius;          out.y += cornerRadius; break;
	case 3: out.x += size.x - cornerRadius; out.y += cornerRadius; break;
	}

	return out;
}