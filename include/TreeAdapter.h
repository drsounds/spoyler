#ifndef TREEADAPTER_H
#define TREEADAPTER_H
#include "libspider.h"
namespace spider {
    template <class T>
	class TreeAdapter {
	public:
		virtual T getItemAt(int pos);
		virtual int count();
	};
}

#endif // TREEADAPTER_H
