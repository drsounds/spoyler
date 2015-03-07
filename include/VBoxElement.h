#ifndef VBOXELEMENT_H
#define VBOXELEMENT_H
#include "BoxElement.h"
namespace spider {
    class VBoxElement : public BoxElement {

	public:
	    VBoxElement(Element *parent) : BoxElement(parent) {
		}
		VBoxElement();
        virtual string getType() {
            return "vbox";
        }
		void pack();
	};
}
#endif // VBOXELEMENT_H
