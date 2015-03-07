#ifndef INFOELEMENT_H
#define INFOELEMENT_H
#include "TextElement.h"
#include "HBoxElement.h"
#include "ButtonElement.h"
namespace spider {
enum MessageType {
    Info, Warning, Error, Message
};
class InfoElement : public HBoxElement
{


    protected:
        MessageType type;
        HBoxElement *hbox;
        TextElement *textElement;
        ButtonElement *btnElement;

    public:
        virtual string getType() {
            return "info";
        }
        MessageType getMessageType() {
            return this->type;
        }
        void hide();
        void show(MessageType type, char *text);
        void setMessageType(MessageType type);
        InfoElement(Element *parent);
        virtual ~InfoElement();
        void show();
    private:
};
}
#endif // INFOELEMENT_H
