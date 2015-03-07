#ifndef COLOR_H
#define COLOR_H
#include "SPType.h"
#include <string>
namespace spider {
class Color : public SPType {
private:
    short r;
    short g;
    short b;
    short a;
public:
    string getType() {
        return "Color";
    }
    short getR();
    short getG();
    short getB();
    short getA();
    void setR(short r);
    void setG(short g);
    void setB(short b);
    void setA(short a);
    Color(short r, short g, short b, short a);
    Color(const string& html);
    string toHTMLColor();
};
}
#endif // COLOR_H
