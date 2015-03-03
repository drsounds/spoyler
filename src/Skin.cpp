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
    this->images["tab.background.image::active"] = this->image->sliceImage(0, 1, 32, 23);
    this->images["tabbar.background.image"] = this->image->sliceImage(101, 0, 20, 23);

}
Skin::~Skin()
{
    //dtor
}
}
