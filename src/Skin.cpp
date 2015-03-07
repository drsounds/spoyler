#include "Skin.h"
namespace spider {
Skin::Skin()
{
    //ctor
}
Skin::Skin(const string& bitmap, GraphicsContext *g) {
    this->colors = new std::map<string, pixel *>;
    this->images = new std::map<string, Image *>;

    Image *image = g->loadImage(bitmap);
    this->image = image;

    this->colors["body.background.color"] = this->image->getPixel(0, 0);
    this->colors["body.foreground.color"] = this->image->getPixel(1, 0);
    this->colors["::selected.background.color"] = this->image->getPixel(7, 0);
    this->colors["::selected.foreground.color"] = this->image->getPixel(8, 0);
    this->images["tab.background.image::active"] = this->image->sliceImage(0, 1, 32, 23, 1, 1, 1, 1);
    this->images["tabbar.background.image"] = this->image->sliceImage(101, 0, 20, 23, 0, 0, 0, 0);
    this->images["button.background.image"] = this->image->sliceImage(128, 1, 71, 19, 3, 13, 13, 3);
    this->images["button.background.image::active"] = this->image->sliceImage(128, 21, 71, 19, 3, 13, 13, 3);
    this->images["header.background.image"] = this->image->sliceImage(214, 0, 27, 56, 1, 1, 1, 1);
}
bool Skin::hasColor(string selector) {
    if(std::find(this->colors.begin(), this->colors.end(), selector) != this->colors.end()) {
        return true;
    }
    return false;
}

bool Skin::hasImage(string selector) {
    if(std::find(this->images.begin(), this->images.end(), selector) != this->images.end()) {
        return true;
    }
    return false;
}
pixel *Skin::getColor(string selector, string def) {
    if (!this->hasColor(selector)) {
        return def;
    }
    return this->colors[selector];
}
Image *getImage(string selector, string def) {
    if (!this->hasImage(selector)) {
        return def;
    }
    return this->images[selector];
}
Skin::~Skin()
{
    //dtor
}
}
