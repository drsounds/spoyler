#include "Skin.h"
namespace spider {
Skin::Skin()
{
    //ctor
}
Skin::Skin(const string& bitmap, GraphicsContext *g) {
    this->colors = new std::map<string, pixel *>;
    this->images = new std::map<string, Image *>;
    cout << bitmap << "\r\n";
    Image *image = new Image(bitmap);
    cout << "Sizeof pixels: " << sizeof(image->pixels) << "\r\n";
    this->image = image;
    cout << "Sizeof pixels: " << sizeof(image->pixels) << "\r\n";
    this->colors->insert(pair<string, pixel *>("body.background.color", this->image->getPixelPtr(0, 0)));

    (*this->colors)["body.foreground.color"] = this->image->getPixelPtr(1, 0);
    (*this->colors)["::selected.background.color"] = this->image->getPixelPtr(7, 0);
    (*this->colors)["::selected.foreground.color"] = this->image->getPixelPtr(8, 0);
    (*this->images)["header.background.image"] = this->image->sliceImage(214, 0, 27, 56, 1, 0, 0, 0);
    (*this->images)["tab.background.image::active"] = this->image->sliceImage(0, 1, 32, 23, 1, 1, 1, 1);
    (*this->images)["tabbar.background.image"] = this->image->sliceImage(101, 0, 20, 23, 0, 0, 0, 0);
    (*this->images)["button.background.image"] = this->image->sliceImage(128, 1, 71, 19, 3, 13, 13, 3);
  //  (*this->images)["button.background.image::active"] = this->image->sliceImage(128, 21, 71, 19, 3, 13, 13, 3);
}
bool Skin::hasColor(string selector) {
    if(this->colors->find(selector) != this->colors->end()) {
        return true;
    }
    return false;
}

bool Skin::hasImage(string selector) {
    if(this->images->find(selector) != this->images->end()) {
        return true;
    }
    return false;
}
Color *Skin::getColor(string selector, string def) {
    if (!this->hasColor(selector)) {
        return new Color(255, 255, 255, 255);
    }
    return spider_pixel_to_colour((*this->colors)[selector]);
}
Image *Skin::getImage(string selector, string def) {
    if (!this->hasImage(selector)) {
        return NULL;
    }
    return (*this->images)[selector];
}
Skin::~Skin()
{
    //dtor
}
}
