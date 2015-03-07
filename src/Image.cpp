#include "Image.h"
#include <stdio.h>


namespace spider {
Color *spider_pixel_to_colour(pixel *pixel) {
    return new Color(pixel->r, pixel->g, pixel->b, pixel->a);
}
string spider_pixel_to_hex(pixel *pixel) {
	string result;
    result.append("#");
	char r[255];
	snprintf(r, 255, "%.2X", pixel->r);
	result.append(r );

	char g[255];
	snprintf(g, 255, "%.2X", pixel->g);
	result.append(g );

	char b[255];
	snprintf(b, 255, "%.2X", pixel->b);
	result.append(b );

	return result;
}

Image::Image()
{
    //ctor
}
Image::Image(unsigned int width, unsigned int height) {
    this->pixels = new pixel[width * height];
}
Image *Image::sliceImage(unsigned int x, unsigned int y, unsigned int width, unsigned int height, int leftBorder, int topBorder, int bottomBorder, int rightBorder) {
    unsigned int startPos = x + (y * width * height);
    unsigned int length = width + (height * width);

    Image *image = new Image(width, height);
    for (int i = 0, x = 0; x < startPos + length; i++, x++) {
        pixel *pixel = &image->pixels[i];
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
    pixel *pixel = &this->pixels[pos];
    return pixel;
}
Image::~Image()
{
    //dtor
}
}
