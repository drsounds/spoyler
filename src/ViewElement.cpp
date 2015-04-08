#include "ViewElement.h"
#include <string>
using namespace std;
namespace spider {
ViewElement::ViewElement()
 : VBoxElement::VBoxElement()
{

    //ctor
    this->clipView = true;
}
void ViewElement::scroll(int scrollX, int scrollY, int mouseX, int mouseY) {
    if (this->clipView) {
        this->scrollX += x;
        this->scrollY += y;
        this->invalidate();
    }
}
void ViewElement::request(std::string uri) {

}

std::string ViewElement::loadView(std::string view) {
    std::string path = "C:\\Users\\Alecca\\Documents\\Spoyler\\resources\\views\\" + view;
    char *fileName = (char *)path.c_str();
    FILE *fil = fopen(fileName, "rb");
    fseek(fil, 0, SEEK_END);
    size_t fsize = ftell(fil);
    rewind(fil);
    char *buffer = (char *)malloc(sizeof(char) * fsize);
    fread(buffer, sizeof(char), fsize, fil);
    fclose(fil);
    std::string output (buffer);
    delete buffer;
    return output;
}

void ViewElement::pack() {
    VBoxElement::pack();
}

ViewElement::ViewElement(Element *parent)
 : VBoxElement::VBoxElement(parent)
{
    this->clipView = true;
    //ctor
}
void ViewElement::navigate(string uri) {

}
ViewElement::~ViewElement()
{
    //dtor
}
}
