#ifndef TABLEVIEWELEMENT_H
#define TABLEVIEWELEMENT_H
#include "Element.h"
#include <vector>
#include "TableRow.h"
#include "TableColumnHeader.h"
#include "TableDataSource.h"
namespace spider {
class TableElement : public Element
{
    public:
        TableDataSource *dataSource;
        TableElement();
        TableElement(Element *parent, TableDataSource *dataSource);
        vector<TableRow *> *rows;
        vector<TableColumnHeader *> *columns;
        virtual ~TableElement();
        virtual string getType();
        virtual void draw(int x, int y, GraphicsContext *g);
        virtual void scroll(int scrollX, int scrollY, int x, int y);
    protected:
    private:
};
}
#endif // TABLEVIEWELEMENT_H
