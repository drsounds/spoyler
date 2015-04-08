#include <Windows.h>
#include "Win32WindowElement.h"
#include "Win32GraphicsContext.h"
namespace spider {
    void Win32WindowElement::draw(GraphicsContext *graphics) {
        std::vector<Node *> *elements = this->getChildNodes();
        for (std::vector<Node *>::iterator it = elements->begin(); it != elements->end(); ++it) {
            Node *node = (Node *)*it;
            Element *elm = static_cast<Element *>(node);
            if (elm->isVisible())
                elm->draw(0, 0, graphics);
        }
    }
    void Win32WindowElement::invalidateRegion(rectangle rect) {


        SendMessage(this->hWnd, WM_PAINT, NULL, NULL);

    }
    void Win32WindowElement::navigate(string uri) {
        this->mainWindow->navigate(uri);
    }
    Win32WindowElement::Win32WindowElement() {

    }
    Win32WindowElement::Win32WindowElement(HDC hdc) {
        this->memHDC = hdc;
    }
    GraphicsContext *Win32WindowElement::createGraphics() {
        return new Win32GraphicsContext(this->hWnd, NULL, this);
    }
    void Win32WindowElement::scroll(int x, int y) {
        this->mainWindow->scroll(x, y);
    }
    void Win32WindowElement::scrollTo(int x, int y) {

    }
    void Win32WindowElement::pack() {

        RECT clientRect;
        GetWindowRect(this->getHandle(),&clientRect);
        for (vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *elm = (Element *)static_cast<Node *>(*it);
            elm->setX(0);
            elm->setY(0);
            int width = clientRect.right - clientRect.left;
            int height = clientRect.bottom - clientRect.top;
            elm->setWidth(width);
            elm->setHeight(height);
            elm->pack();
        }
    }
    void Win32WindowElement::scroll(int scrollX, int scrollY, int mouseX, int mouseY) {
        this->mainWindow->scroll(scrollX, scrollY, mouseX, mouseY);
    }
    void sample_click(spider::Element *elm, void *data) {
        MessageBox(((Win32WindowElement *)elm->getWindowNode())->getHandle(), (LPCSTR)"Test",(LPCSTR)L"A", 0);
    }
    void Win32WindowElement::SampleLayout() {
        this->set("bgcolor", "#474747");
        this->setWindowElement(this);
        this->mainWindow = new MainWindowElement(this, new Skin(string("skin.png"), this->createGraphics()));
        this->mainWindow->setWindowElement((WindowElement *)this);
        this->mainWindow->setVisible(true);
        this->mainWindow->layout();
        this->appendChild(mainWindow);
    }
}
/*  This function is called by the Windows function DispatchMessage()  */
