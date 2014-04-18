#include "Image.h"
namespace spider {
Image::Image(string *uri)
{
    //ctor
    this->uri;
}
void Image::download() {
    string uri = *this->uri;
    if (this->uri->find("http") == 0) {
        // Download image async

    }
    if (this->uri->find("res") == 0) {
    }
}

void Image::downloadImageAsync() {

    this->worker = new boost::thread (&Image::download, this);
}

Image::~Image()
{
    delete this->uri;
    //dtor
}
}
