#include "Image.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
/*! \from http://zarb.org/~gc/html/libpng.html */
void read_png_file(char* file_name)
{

}

namespace spider {
Color *spider_pixel_to_colour(pixel *pixel) {
        return new Color(pixel->r, pixel->g, pixel->b, pixel->a);
}
string spider_pixel_to_hex(pixel *pixel) {
	string result;
    result.append("#");
	char r[255];
	//snprintf(r, 255, "%.2X", pixel->r);
	result.append(r );

	char g[255];
	//snprintf(g, 255, "%.2X", pixel->g);
	result.append(g );

	char b[255];
	//snprintf(b, 255, "%.2X", pixel->b);
	result.append(b );

	return result;
}

Image::Image()
{
    //ctor
}
void abort_(char *text, int t, void* byte) {
    throw;
}
void abort_(char *text, char *fileName) {
    throw;
}
void abort_(char *text) {
    throw;
}
Image::Image(const string& fileName) {

}
Image::Image(unsigned int width, unsigned int height) {
    this->pixels = new pixel[width * height];
    this->width = width;
    this->height = height;
    this->numPixels = width * height;
    this->handle = NULL;
}
Image *Image::sliceImage(unsigned int x, unsigned int y, unsigned int width, unsigned int height, int leftBorder, int topBorder, int bottomBorder, int rightBorder) {
    unsigned int startPos = x + (y * width);
    cout << "Start pos: " << startPos << "\r\n";
    Image *image = new Image(width, height);
    unsigned int length = width * height;


    for (unsigned int w = 0, h = 0, pos = 0, i = startPos; h < height; pos++, i++, w++) {
        pixel pix = {0};

        pix.r = this->pixels[i].r;
        pix.g = this->pixels[i].g;
        pix.b = this->pixels[i].b;
        pix.a = this->pixels[i].a;
        //cout << "Num pixels: " << image->numPixels << " pos: " << i << "\r\n";
        image->pixels[pos] = pix;
        if (w >= width) {
            h += 1;
            // cout << "Subliminal width: " << this->width - width << endl;
            i += this->width - width;
            w = 0;
            // cout << "W: " << w << "H:" << h << "\r\n";
        }
    }
    image->leftBorder = leftBorder;
    image->topBorder = topBorder;
    image->rightBorder = rightBorder;
    image->bottomBorder = bottomBorder;
    return image;
}
pixel Image::getPixel(unsigned int x, unsigned int y) {
    unsigned int pos = x + (this->width * y);
    pixel pix = this->pixels[pos];
    return pix;
}

pixel *Image::getPixelPtr(unsigned int x, unsigned int y) {
    unsigned int pos = x + (this->width * y);
    pixel *pix = &this->pixels[pos];
    return pix;
}

Image::~Image()
{
    //dtor
}
}
