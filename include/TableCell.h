#include "TableRow.h"
#ifndef TABLECELL_H
#define TABLECELL_H
namespace spider {
class TableRow;
class TableElement;
class TableCell
{
    public:
        TableCell(TableRow *tableRow);
        virtual ~TableCell();
        string uri;
        string title;
        TableRow *tableRow;
        TableElement *tableElement;
    protected:
    private:
};
}

#endif // TABLECELL_H
