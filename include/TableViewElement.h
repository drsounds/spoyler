#ifndef TABLEVIEWELEMENT_H
#define TABLEVIEWELEMENT_H
#include "Element.h"
#include "TableViewDataSource.h"
namespace spider {
class TableViewElement : public Element
{
    public:
        TableViewDataSource *dataSource;
        TableViewElement();
        TableViewElement(Element *parent, TableViewDataSource *dataSource);
        virtual ~TableViewElement();
        virtual string getType() {
            return "TableView";
        }
        virtual void draw(int x, int y, GraphicsContext *g);
    protected:
    private:
};
}
#endif // TABLEVIEWELEMENT_H
