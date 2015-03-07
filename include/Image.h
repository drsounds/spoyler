#ifndef IMAGE_H
#define IMAGE_H
struct pixel {
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};

namespace spider {

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
            Image *sliceImage(unsigned int x,unsigned int y, unsigned int width, unsigned int height, int topLeft, int top, int topRight, int right, int bottomRight, int bottom, int bottomLeft);
            pixel *getPixel( unsigned int x, unsigned int y);
            void *handle; // OS Specific handle, created opon first load
        protected:
        private:
    };
}

#endif // IMAGE_H
