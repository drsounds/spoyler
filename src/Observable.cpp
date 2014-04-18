#include "Observable.h"
namespace spider {
Observable::Observable()
{
    //ctor
    this->observers = new list<Observer *>;
}

Observable::~Observable()
{
    //dtor
}
void Observable::notify(string evt, SPType *sender, EventArgs *data) {
	for(list<Observer *>::iterator it = this->observers->begin(); it != this->observers->end(); ++it) {
		Observer *observer = static_cast<Observer *>(*it);
		string t = observer->getEvent();
		if(t == (evt)) {
			s_event evt = (observer->getCallback());
			evt(sender, data);
		}
	}
}
void Observable::addEventListener(string evt, s_event callback) {
    Observer *observer = new Observer(evt, callback);


	this->observers->push_back(observer);

}

}
