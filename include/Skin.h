#ifndef SKIN_H
#define SKIN_H
#include <map>
#include "Image.h"
#include "Color.h"
#include "GraphicsContext.h"
using namespace std;
namespace spider {
class GraphicsContext;
class slice {
public:
    Image *image;
    int x1;
    int y1;
    int x2;
    int y2;
    int leftBorder;
    int topBorder;
    int rightBorder;
    int bottomBorder;
    slice(Image *image, int x1, int x2, int y1, int y2, int leftBorder, int topBorder, int rightBorder, int bottomBorder);
};
class Skin
{
    public:
        map<string, Image *> *images;
        map<string, pixel *> *colors;
        map<string, slice *> *slices;
        Image *image;
        Skin();
        Skin(const string& bitmap, GraphicsContext *g);
        virtual ~Skin();
        void drawImageSlice(string selector, GraphicsContext *g, int left, int top, int width, int height);
        bool hasColor(string selector);
        bool hasImage(string selector);
        Color *getColor(string selector, string def);
        Image *getImage(string selector, string def);

    protected:
    private:
};
}
#endif // SKIN_H
