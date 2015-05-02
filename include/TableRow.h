#ifndef TABLEROW_H
#define TABLEROW_H
#include "TableElement.h"
#include <vector>
using namespace std;
namespace spider {
class TableRow
{
    public:
        bool isSelected;
        string uri;
        string title;
        TableRow(TableElement *tableView);
        TableElement *tableElement;
        virtual ~TableRow();
        std::vector<TableRow *> *children;
    protected:
    private:
};
}

#endif // TABLEROW_H
