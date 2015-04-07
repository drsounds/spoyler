#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include "Color.h"
#include <vector>
#include <png.h>
using namespace std;
struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

/*! \from http://zarb.org/~gc/html/libpng.html */
void read_png_file(char* file_name);

namespace spider {
    class Color;
    /*!
     * Converts pixel to HTML color
     **/
    string spider_pixel_to_hex(pixel *pixel);

    /*!
     * Converts pixel to Colour
     **/
    Color *spider_pixel_to_colour(pixel *pixel);
    class Image
    {

        public:
            int x, y;
            Image(unsigned int width, unsigned int height);
            Image();
            Image(const string& fileName);
            virtual ~Image();
            unsigned int width;
            unsigned int height;
            int leftBorder;
            int topBorder;
            int bottomBorder;
            int rightBorder;
            int numPixels;
            pixel *pixels;
            Image *sliceImage(unsigned int x,unsigned int y, unsigned int width, unsigned int height, int left, int top, int bottom, int right);
            pixel getPixel( unsigned int x, unsigned int y);
            pixel *getPixelPtr(unsigned int x, unsigned int y);
            void *handle; // OS Specific handle, created opon first load

            // PNG specific stuff

            png_byte color_type;
            png_byte bit_depth;

            png_structp png_ptr;
            png_infop info_ptr;
            int number_of_passes;
            png_bytep *row_pointers;
        protected:
        private:
    };
}

#endif // IMAGE_H
