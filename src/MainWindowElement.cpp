#include "MainWindowElement.h"
#include "StartView.h"
#include "InputElement.h"
#include "InputEventArgs.h"
#include "SplitterElement.h"
namespace spider {
    MainWindowElement::MainWindowElement()
    {

    }
    int treeview_itemselected(SPType *sender, EventArgs *e) {
        TreeViewElement *treeView = (TreeViewElement *)sender;
        MainWindowElement *mainWindow = (MainWindowElement *)treeView->getMainWindowElement();
        TreeViewEventArgs *args = (TreeViewEventArgs *)e;
        TreeItem *selectedItem = args->getItem();
        Uri *uri = selectedItem->getUri();
        char *uri2 = uri->getUri();
        string uri3 (uri2);
        mainWindow->getViewStack()->navigate(uri3);
        return 0;
    }
    MainWindowElement::MainWindowElement(Element *parent) : VBoxElement(parent)
    {
        this->setWindowElement(parent);

    }
    void MainWindowElement::showMessage(MessageType msgType, char *msg) {
        this->infoElement->show(msgType, msg);
    }
    int search_entered(SPType *sender, EventArgs *e) {
        InputEventArgs *ie = (InputEventArgs *)e;
        Element * elm = (Element *)sender;
        MainWindowElement *mainWindow = (MainWindowElement *)elm->getMainWindowElement();
        string query = ie->getText();
        if (query.find("spoyler:") < 1) {
            query = "spoyler:search:" + query;
        }
        ViewStackElement * viewStack = mainWindow->getViewStack();
        viewStack->navigate(ie->getText());

        return 0;
    }
    void MainWindowElement::layout() {
        this->setMainWindowElement(this);
        this->set("bgcolor", "#373737");
        spider::HBoxElement *header = new spider::HBoxElement(this);
        header->set("bgcolor", "#767676");
        header->set("height", "55");
        header->getPadding()->top = 3;
        header->getPadding()->left = 3;
        header->getPadding()->bottom = 3;
        header->getPadding()->right =  3;
        this->appendChild(header);

        // add search element
        InputElement *searchElement = new InputElement(header);
        header->appendChild(searchElement);
        searchElement->set("width", "120");
        searchElement->setName("searchBox");
        searchElement->set("bgcolor", "#777777");
        searchElement->addEventListener("enter", &search_entered);
        // Add the info element
        this->infoElement = new spider::InfoElement(this);
        this->infoElement->set("height", "28");
        this->appendChild(this->infoElement);
        this->infoElement->hide();


        // Add header children

        spider::HBoxElement *body = new spider::HBoxElement(this);
        body->set("bgcolor", "#474747");
        body->set("flex", "1");
        body->set("height", "100");
        this->appendChild(body);



            // Inside body
        spider::VBoxElement *sidebar = new spider::VBoxElement(body);
        sidebar->set("width", "220");
        sidebar->set("bgcolor", "#474747");
        body->appendChild(sidebar);

        body->appendChild(new SplitterElement(body));

        // Add TreeView
        this->treeView = new TreeViewElement(sidebar);
        treeView->set("bgcolor", "#575757");
        treeView->set("fgcolor", "#dddddd");
        treeView->set("flex", "1");
        treeView->set("height", "920");
        treeView->set("width", "220");
        sidebar->appendChild(treeView);
        treeView->setWindowElement(this->getWindowElement());
        treeView->setMainWindowElement(this);
        // Add sample elements
        TreeItem *item = new TreeItem(new Uri("spoyler:internal:start"));

        item->setSelected(false);
        TreeItem *item2 = new TreeItem(new Uri("spoyler:internal:history"));

        item2->setSelected(false);
        treeView->addEventListener("itemselected", treeview_itemselected);
        treeView->addItem(item);
        treeView->addItem(item2);

        // Add viewstack





        this->viewStack = new spider::ViewStackElement(body);
        viewStack->set("bgcolor", "#373737");
        body->appendChild(viewStack);
        viewStack->set("flex", "1");
        viewStack->setWindowElement(this->getWindowElement());
        viewStack->appendChild(new spider::views::StartView(this));
        spider::HBoxElement *footer = new spider::HBoxElement(this);
        footer->set("bgcolor", "#444444");
        footer->set("height", "86");
        this->appendChild(footer);
        // Add header buttons


        this->pack();
    }
    ViewStackElement *MainWindowElement::getViewStack() {
        return this->viewStack;
    }
    MainWindowElement::~MainWindowElement()
    {
        //dtor
    }
}
