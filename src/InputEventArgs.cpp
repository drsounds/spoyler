#include "InputEventArgs.h"
namespace spider {
InputEventArgs::InputEventArgs(string text)
    : EventArgs()
{
    //ctor
    this->text = text;
}

InputEventArgs::~InputEventArgs()
{
    //dtor
}
}
