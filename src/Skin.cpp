#include "Skin.h"
namespace spider {
Skin::Skin()
{
    //ctor
}
slice::slice(Image *image, int x1, int y1, int x2, int y2, int leftBorder, int topBorder, int rightBorder, int bottomBorder) {
    this->image = image;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->leftBorder = leftBorder;
    this->topBorder = topBorder;
    this->rightBorder = rightBorder;
    this->bottomBorder = bottomBorder;
}
void Skin::drawImageSlice(string selector, GraphicsContext *g, int left, int top, int width, int height) {
    if(this->slices->find(selector) != this->slices->end()) {
        slice *slice = (*this->slices)[selector];
        g->drawImagePart(slice->image, left, top, width, height, slice->x1, slice->y1, slice->x2, slice->y2);
    }
}
Skin::Skin(const string& bitmap, GraphicsContext *g) {
    this->colors = new std::map<string, pixel *>;
    this->images = new std::map<string, Image *>;
    this->slices = new std::map<string, slice *>;
    cout << bitmap << "\r\n";
    Image *image = new Image(bitmap);
    cout << "Sizeof pixels: " << sizeof(image->pixels) << "\r\n";
    this->image = image;
    cout << "Sizeof pixels: " << sizeof(image->pixels) << "\r\n";
    this->colors->insert(pair<string, pixel *>("body.background.color", this->image->getPixelPtr(0, 0)));

    (*this->colors)["body.foreground.color"] = this->image->getPixelPtr(1, 0);
    (*this->colors)["::selected.background.color"] = this->image->getPixelPtr(7, 0);
    (*this->colors)["::selected.foreground.color"] = this->image->getPixelPtr(8, 0);
    (*this->slices)["#header.background.image"] = new slice(image, 214, 0, 27, 56, 1, 0, 0, 0);
    (*this->slices)["tab.background.image::active"] = new slice(image, 0, 11, 32, 23, 1, 1, 1, 1);
    (*this->slices)["tabbar.background.image"] = new slice(image, 97, 1, 1, 22, 0, 0, 0, 0);
    (*this->slices)["button.background.image"] = new slice(image, 128, 1, 71, 19, 3, 13, 13, 3);
    (*this->slices)["table::columnheader.background.image"] = new slice(image, 200, 63, 18, 18, 0, 0, 0, 0);
    (*this->colors)["table::nth-child(2n).background.color"] = this->image->getPixelPtr(22, 0);
    (*this->colors)["treeitem::selected.background.color"] = this->image->getPixelPtr(6, 0);
    (*this->colors)["treeitem::selected.foreground.color"] = this->image->getPixelPtr(7, 0);
    (*this->colors)["treeview.foreground.color"] = this->image->getPixelPtr(1, 0);
    (*this->colors)["treeitem::focus.foreground.color"] = this->image->getPixelPtr(2, 0);
    (*this->colors)["treeview.background.color"] = this->image->getPixelPtr(3, 0);
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
