#ifndef BOXELEMENT_H
#define BOXELEMENT_H
#include "Element.h"
namespace spider {
	class BoxElement : public Element {

	public:
	    BoxElement(Element *parent);
		BoxElement();
		~BoxElement();
		void pack();
		virtual string gettype() {
            return "box";
		}

	};
}
#endif // BOXELEMENT_H
