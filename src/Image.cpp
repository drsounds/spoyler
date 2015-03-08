#include "Image.h"
#include <stdio.h>
#include <iostream>
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
void abort_(char *text, int t, png_byte byte) {

}
void abort_(char *text, char *fileName) {

}
void abort_(char *text) {

}
Image::Image(const string& fileName) {
    char *file_name = (char *)fileName.c_str();
    char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(file_name, "rb");
    if (!fp)
            abort_("[read_png_file] File %s could not be opened for reading", file_name);
    fread(header, 1, 8, fp);
    if (png_sig_cmp((png_bytep)header, 0, 8))
            abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


    /* initialize stuff */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr)
            abort_("[read_png_file] png_create_read_struct failed");

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
            abort_("[read_png_file] png_create_info_struct failed");

    if (setjmp(png_jmpbuf(png_ptr)))
            abort_("[read_png_file] Error during init_io");

    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);

    width = png_get_image_width(png_ptr, info_ptr);
    height = png_get_image_height(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    number_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);


    /* read file */
    if (setjmp(png_jmpbuf(png_ptr)))
            abort_("[read_png_file] Error during read_image");

    row_pointers = (png_bytep *) new char[ height];
    for (y=0; y<height; y++)
            row_pointers[y] = (png_byte*) new char [png_get_rowbytes(png_ptr,info_ptr)];
    if (png_ptr == NULL) {

        cout << "PNG pointer null";
    }
    if (row_pointers == NULL) {

        cout << "Row pointers null";
    }
    png_read_image(png_ptr, row_pointers);

    fclose(fp);

    // Process pixels

    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
                abort_("[process_file] input file is PNG_COLOR_TYPE_RGB but must be PNG_COLOR_TYPE_RGBA "
                       "(lacks the alpha channel)");

    if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_RGBA)
            abort_("[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (%d) (is %d)",
                   PNG_COLOR_TYPE_RGBA, png_get_color_type(png_ptr, info_ptr));

    this->pixels = new pixel[width * height];
    int i = 0;
    for (y=0; y<height; y++) {
            png_byte* row = row_pointers[y];
            for (x=0; x<width; x++) {
                png_byte* ptr = &(row[x*4]);
                this->pixels[i].r = ptr[0];
                this->pixels[i].g = ptr[1];
                this->pixels[i].b = ptr[2];
                this->pixels[i].a = ptr[3];

                i++;

            }
    }
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
