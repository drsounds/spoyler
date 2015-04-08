#include "TableViewElement.h"
namespace spider {
    TableViewElement::TableViewElement()
    {
        //ctor
    }
    TableViewElement::TableViewElement(Element *parent, TableViewDataSource *dataSource)
    {
        //ctor
        this->dataSource = dataSource;
    }
    TableViewElement::~TableViewElement()
    {
        //dtor
    }
    void TableViewElement::draw(int x, int y, GraphicsContext *g) {
        Element::draw(x, y, g); // Super draw
        rectangle *absoluteBounds = this->absoluteBounds;
        TableViewDataSource *dataSource = this->dataSource;

        // Draw table data here


        int columnY = y;
        if (columnY < 30) {
            // If columnY is below zero, set it to the position at top
            columnY = ((Element *)this->parent)->absoluteBounds->y;
        }
        // Draw column headers
        g->skin->drawImageSlice("tableview::columnheader.background.image", g, x, columnY, this->absoluteBounds->width, 18);

        int columnWidth = absoluteBounds->width / dataSource->getColumnCount();
        int left = 0;
        int padding = 10;
        for (int i = 0; i < dataSource->getColumnCount(); i++) {
            string text = dataSource->getTextForColumn(i);
            char *str = (char *)text.c_str();
            g->drawString(str, new FontStyle("MS Sans Serif", 8, 1, false, false), new Color(0, 0, 0, 255), x + left, columnY + 1, columnWidth, 18);
            left += columnWidth;
        }

    }
}
