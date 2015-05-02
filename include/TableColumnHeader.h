#ifndef TABLECOLUMNHEADER_H
#define TABLECOLUMNHEADER_H
#include "TableCell.h"

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
