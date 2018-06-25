#pragma once
#include "Element.h"
#include <vector>

using namespace std;

namespace lcars {
	class Content : public Element
	{
	public:
		Content();
		~Content();
		
		vector<Element*> childs;

		void render(sf::RenderWindow &window);
	};
}

