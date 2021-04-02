#include "Element.h"
#include "TableRow.h"
#include "TableColumnHeader.h"
#include "TableDataSource.h"
#ifndef TABLEVIEWELEMENT_H
#define TABLEVIEWELEMENT_H
#include <vector>
namespace spider {
class TableDataSource;
class Element;
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
