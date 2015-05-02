#ifndef TABLECELL_H
#define TABLECELL_H
#include "TableRow.h"
namespace spider {
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
