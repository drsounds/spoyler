#include "HeaderElement.h"
namespace spider {
HeaderElement::HeaderElement(Element *parent)
 : HBoxElement(parent)
{
    this->getPadding()->top = 20;
    this->getPadding()->left = 20;

    // Insert image
    this->image = new ImageElement(this);
    this->image->set("width", "128");
    this->image->set("height", "128");
    this->image->set("flex", "0");
    this->appendChild(image);

    this->title = new TitleElement(this);
    title->set("flex", "1");
    title->setTitle("Title");
    title->setEntity("Object");
    title->set("height", "100%");
    title->set("width", "100%");
    this->appendChild(title);


}
HeaderElement::HeaderElement()
{
    this->getPadding()->top = 20;
    this->getPadding()->left = 20;
    this->title = new TitleElement(this);
    title->set("flex", "1");
    title->setTitle("Title");
    title->setEntity("Object");
    title->set("height", "100%");
    this->appendChild(title);


}

HeaderElement::~HeaderElement()
{
    //dtor
}
}
