#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "libspider.h"
#include "SPType.h"
#include "Observer.h"
#include <list>
#include "EventArgs.h"
using namespace std;
namespace spider {
    class Observable
    {
        public:
            Observable();
            void notify(string event, SPType *sender, EventArgs *data);
            void addEventListener(string event, s_event e);
            virtual ~Observable();
        protected:
            list<Observer *> *observers;
        private:
    };
}

#endif // OBSERVABLE_H
