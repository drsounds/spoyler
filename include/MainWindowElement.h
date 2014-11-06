#ifndef MAINWINDOWELEMENT_H
#define MAINWINDOWELEMENT_H
#include "VBoxElement.h"
#include "HBoxElement.h"
#include "ViewStackElement.h"
#include "ButtonElement.h"
#include "InfoElement.h"
#include "TreeViewElement.h"
namespace spider {
class MainWindowElement : public VBoxElement
{
    private:
        ViewStackElement *viewStack;
        TreeViewElement *treeView;
        InfoElement *infoElement;
    public:
        MainWindowElement();
        MainWindowElement(Element *parent);
        void layout();
        virtual ~MainWindowElement();
        void navigate(string uri);
        ViewStackElement *getViewStack();
        void showMessage(MessageType msgType, char *msg);
};
}
#include "libspider.h"

#endif // MAINWINDOWELEMENT_H
