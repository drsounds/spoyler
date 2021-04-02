#include "libspider.h"
#include "Color.h"
#include <string>
#include <stdio.h>
using namespace std;
/*!
 * From http://www.dreamincode.net/forums/topic/58058-converting-rgb-to-hex/
 **/
string RGBToHex(int rNum, int gNum, int bNum) {
	string result;
    result.append("#");
	char r[255];
//	snprintf(r, 255, "%.2X", rNum);
	result.append(r );

	char g[255];
	//snprintf(g, 255, "%.2X", gNum);
	result.append(g );

	char b[255];
	//snprintf(b, 255, "%.2X", bNum);
	result.append(b );

	return result;
}



namespace spider {
/**
Colors
**/
short Color::getR() {
	return this->r;
}
short Color::getG(){
	return this->g;
}
short Color::getB(){
	return this->b;
}
short Color::getA() {
	return this->a;
}
string Color::toHTMLColor() {
    return RGBToHex(this->r, this->g, this->b);
}
void Color::setR(short r) {
	this->r = r;
}
void  Color::setG(short g) {
	this->g = g;
}
void  Color::setB(short b){
	this->b = b;
}
void  Color::setA(short a){
	this->a = a;
}
Color::Color(short r, short g, short b, short a){
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color::Color(const string& html) {
	// TODO Fix this later
	int color = htmlToColor(html);

	short r, g, b;
	if(html.length() > 6 + 1) {
		r = color >> 16 + 8 & 0xff;
		g = color >> 16 & 0xff;
		b = color >> 8 & 0xff;
	} else {
		r = color >> 16 & 0xff;
		g = color >> 8 & 0xff;
		b = color >> 0 & 0xff;
	}
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
};
