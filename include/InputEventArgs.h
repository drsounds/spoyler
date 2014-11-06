#ifndef INPUTEVENTARGS_H
#define INPUTEVENTARGS_H
#include "EventArgs.h"
namespace spider {
class InputEventArgs : public EventArgs
{
    public:
        InputEventArgs(string text);
        string getText() {
            return this->text;
        }
        virtual ~InputEventArgs();
    protected:
        string text;
    private:
};
}
#endif // INPUTEVENTARGS_H
