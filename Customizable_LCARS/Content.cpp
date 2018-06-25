#include "stdafx.h"
#include "Content.h"

namespace lcars {
	Content::Content()
	{
	}


	Content::~Content()
	{
	}
	void Content::render(sf::RenderWindow & window)
	{
		for (Element * element : childs) {
			element->render(window);
		}
	}
}