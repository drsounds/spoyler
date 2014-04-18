#ifndef H_LIBSPIDER
#define H_LIBSPIDER
#include <map>
#include <string>
#include <vector>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#define DEBUG
#define CONTROL_INPUT 1
#include "SPType.h"
#include "EventArgs.h"
using namespace std;

namespace spider {


    typedef struct margin {
        int left;
        int top;
        int bottom;
        int right;
    };
    int htmlToColor(string str);
	typedef struct spider_position {
		int x;
		int y;
	};
	typedef struct  {
		int width;
		int height;
		int x;
		int y;
		int z;
	} s_size, rectangle;

	typedef int(*s_event)(SPType *, EventArgs *);
}
#endif
