#include "Segment.h"
#include "Content.h"
#include "SegmentButton.h"
#include "Swept.h"
#include <vector>

using namespace std;

namespace lcars {
	class InputFocusedSegment : public Segment
	{
	public:
		InputFocusedSegment();
		~InputFocusedSegment();

		vector<SegmentButton> buttons;

		Swept topSwept;
		Swept bottomSwept;

		void addButton(void * callback, float width);
		void update();
		void render(sf::RenderWindow &window);
	};
}
