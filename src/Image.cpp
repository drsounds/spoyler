#include "Image.h"
namespace spider {
Image::Image()
{
    //ctor
}
Image::Image(unsigned int width, unsigned int height) {
    this->pixels = new pixel[width * height];
}
Image *Image::sliceImage(unsigned int x, unsigned int y, unsigned int width, unsigned int height, int topBorder, int leftBorder, int rightBorder, int bottomBorder) {
    unsigned int startPos = x + (y * width * height);
    unsigned int length = width + (height * width);

    Image *image = new Image(width, height);
    for (int i = 0, x = 0; x < startPos + length; i++, x++) {
        pixel *pixel = image->pixels[i];
        pixel->r = this->pixels[startPos + i].r;
        pixel->g = this->pixels[startPos + i].g;
        pixel->b = this->pixels[startPos + i].b;
        pixel->a = this->pixels[startPos + i].a;

    }
    image->leftBorder = leftBorder;
    image->topBorder = topBorder;
    image->rightBorder = rightBorder;
    image->bottomBorder = bottomBorder;
    return image;
}
pixel *Image::getPixel(unsigned int x, unsigned int y) {
    unsigned int pos = x + (this->width * y);
    pixel *pixel = this->pixels[pos];
    return pixel;
}
Image::~Image()
{
    //dtor
}
}
