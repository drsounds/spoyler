#ifndef TABLEVIEWELEMENT_H
#define TABLEVIEWELEMENT_H
#include "Element.h"
#include "TableDataSource.h"
namespace spider {
class TableElement : public Element
{
    public:
        TableDataSource *dataSource;
        TableElement();
        TableElement(Element *parent, TableDataSource *dataSource);
        virtual ~TableElement();
        virtual string getType();
        virtual void draw(int x, int y, GraphicsContext *g);
    protected:
    private:
};
}
#endif // TABLEVIEWELEMENT_H
