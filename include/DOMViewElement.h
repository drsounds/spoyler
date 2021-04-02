#include "Element.h"

namespace spider {
    class DOMViewElement : public Element {
    private:
    public:
        int parseDepth;
        DOMViewElement () {

        }
        DOMViewElement(Element *parent);

        void loadXML(char *buffer);
    };
    char *getAttribute(const char *attribute, const char **attributes, const char *defValue);

    void startElement(void *data, const char *el, const char **attr);
    void endElement(void *data, const char *el);
}
