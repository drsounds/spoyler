#ifndef SKIN_H
#define SKIN_H
#include <map>
#include "Image.h"
#include "Color.h"
using namespace std;
namespace spider {
class Skin
{
    public:
        map<string, Image *> images;
        map<string, pixel *> colors;
        Image *image;
        Skin();
        Skin(const string& bitmap, GraphicsContext *g);
        virtual ~Skin();
        bool hasColor(string selector);
        bool hasImage(string selector);
        pixel *getColor(string selector, string def);
        Image *getImage(string selector, string def);

    protected:
    private:
};
}
#endif // SKIN_H
