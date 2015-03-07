#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include "Color.h"
using namespace std;
struct pixel {
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};



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
            Image(unsigned int width, unsigned int height);
            Image();
            virtual ~Image();
            unsigned int width;
            unsigned int height;
            int leftBorder;
            int topBorder;
            int bottomBorder;
            int rightBorder;
            pixel *pixels;
            Image *sliceImage(unsigned int x,unsigned int y, unsigned int width, unsigned int height, int left, int top, int bottom, int right);
            pixel *getPixel( unsigned int x, unsigned int y);
            void *handle; // OS Specific handle, created opon first load

        protected:
        private:
    };
}

#endif // IMAGE_H
