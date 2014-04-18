#include "libspider.h"

namespace spider {

    int htmlToColor(string str) {
        string str2 = str.substr(1, str.length() -1);
        stringstream c(str2);
        unsigned int value = 0;
        c >> hex >> value;
        return value;
    }


}



