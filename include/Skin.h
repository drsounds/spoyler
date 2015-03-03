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
    protected:
    private:
};
}
#endif // SKIN_H
