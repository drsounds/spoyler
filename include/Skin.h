#ifndef SKIN_H
#define SKIN_H
#include <map>
#include "Image.h"
#include "Color.h"
#include "GraphicsContext.h"
using namespace std;
namespace spider {
class GraphicsContext;
class Skin
{
    public:
        map<string, Image *> *images;
        map<string, pixel *> *colors;
        Image *image;
        Skin();
        Skin(const string& bitmap, GraphicsContext *g);
        virtual ~Skin();
        bool hasColor(string selector);
        bool hasImage(string selector);
        Color *getColor(string selector, string def);
        Image *getImage(string selector, string def);

    protected:
    private:
};
}
#endif // SKIN_H
