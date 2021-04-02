#include "TableCell.h"
#ifndef TABLECOLUMNHEADER_H
#define TABLECOLUMNHEADER_H

namespace spider {
class TableCell;
class TableColumnHeader : public TableCell {
    public:
        TableColumnHeader(TableElement *tableElement);
        virtual ~TableColumnHeader();
    protected:
    private:
};
}

#endif // TABLECOLUMNHEADER_H
