#include "ImageLibrary.h"
namespace spider {
image *ImageLibrary::get(string uri) {
    return static_cast<image *>((*this->mImages)[uri]);
}
void ImageLibrary::set(string uri, image *image) {
    (*this->mImages)[uri] = image;
}
ImageLibrary::ImageLibrary()
{
    //ctor
}


ImageLibrary::~ImageLibrary()
{
    //dtor
}
}
