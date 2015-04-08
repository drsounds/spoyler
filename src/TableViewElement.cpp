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
        int width = this->parent != NULL ? ((Element *)this->parent)->getWidth() : 0;

        int columnY = y;
        if (columnY < 60) {
            // If columnY is below zero, set it to the position at top
            columnY = ((Element *)this->parent)->absoluteBounds->y + 1;
        }
        // Draw column headers
        g->skin->drawImageSlice("tableview::columnheader.background.image", g, x, columnY, width, 18);

        int columnWidth = width / dataSource->getColumnCount();
        int left = 0;
        int padding = 10;
        for (int i = 0; i < dataSource->getColumnCount(); i++) {
            string text = dataSource->getTextForColumn(i);
            char *str = (char *)text.c_str();
            g->drawString(str, new FontStyle("MS Sans Serif", 8, 1, false, false), new Color(200, 200, 200, 255), x + left, columnY + 2, columnWidth, 18);
            g->drawString(str, new FontStyle("MS Sans Serif", 8, 1, false, false), new Color(0, 0, 0, 255), x + left, columnY + 1, columnWidth, 18);
            left += columnWidth;
        }

    }
}
