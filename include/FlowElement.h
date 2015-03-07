#ifndef FLOWELEMENT_H
#define FLOWELEMENT_H
#include "Element.h"
namespace spider {
class FlowElement : public Element
{
    public:
        FlowElement();
        FlowElement(Element *parent);
        virtual ~FlowElement();
        void pack();
        virtual string getType() {
            return "flow";
        }
    protected:
    private:
};
}
#endif // FLOWELEMENT_H
