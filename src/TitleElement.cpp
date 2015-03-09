#include "TitleElement.h"
namespace spider {
TitleElement::TitleElement()
{
    //ctor
}

TitleElement::~TitleElement()
{

}
void TitleElement::setTitle(const string& title) {

    this->title->setInnerText((char *)title.c_str());
}
string TitleElement::getTitle() {
}

void TitleElement::setEntity(const string& entity) {

    this->title->setInnerText((char *)entity.c_str());
}
string TitleElement::getEntity() {
}
TitleElement::TitleElement(Element *parent)
 : VBoxElement(parent){
    entity = new TextElement(this);
    entity->setInnerText("Object");
    entity->set("height", "180");
    entity->set("fgcolor", "#888888");
    entity->set("size", "15");
    entity->set("width", "100%");
    this->appendChild(entity);

    title = new TextElement(this);
    title->setInnerText("Title");
    title->set("height", "160");
    title->set("fgcolor", "#ffffff");
    title->set("size", "25");
    title->set("width", "100%");
    this->appendChild(title);
}
}
