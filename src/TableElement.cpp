#include "TableElement.h"
namespace spider {
    TableElement::TableElement()
    {
        //ctor
    }
    TableElement::TableElement(Element *parent, TableDataSource *dataSource)
    {
        //ctor
        this->dataSource = dataSource;
    }
    TableElement::~TableElement()
    {
        //dtor
    }
    string TableElement::getType() {
        return "table";
    }
    void TableElement::draw(int x, int y, GraphicsContext *g) {
        Element::draw(x, y, g); // Super draw

        y = y + 1;
        rectangle *absoluteBounds = this->absoluteBounds;
        TableDataSource *dataSource = this->dataSource;

        // Draw table data here
        int width = ((Element *)this)->getWidth();
        if (width < 1) {
            width = ((Element *)this->parent->parent)->getWidth();
        }
        int columnY = y;
        if (columnY < 60) {
            // If columnY is below zero, set it to the position at top
            columnY = ((Element *)this->parent)->absoluteBounds->y + 1;
        }
        rectangle clipRect;
        clipRect.x = x;
        clipRect.y = y;
        clipRect.width = width;
        clipRect.height = ((Element *)this->parent->parent)->getHeight();
        g->setClip(clipRect);
        int top = columnY + 18;
        // Draw rows
        for (int i = 0; i < 10; i++) {
            if (i % 2 != 1) {
                g->fillRectangle(x, top, width, 18, g->skin->getColor("table::nth-child(2n).background.color", ""));

            }
            top += 18;
        }
        // Draw column headers
        g->skin->drawImageSlice("table::columnheader.background.image", g, x, columnY, width, 18);

        int columnWidth = width / dataSource->getColumnCount();
        int left = 0;
        int padding = 10;
        for (int i = 0; i < dataSource->getColumnCount(); i++) {
            string text = dataSource->getTextForColumn(i);
            char *str = (char *)text.c_str();
            g->drawString(str, new FontStyle("Tahoma", 13, 1, true, false), new Color(200, 200, 200, 255), x + padding + left, columnY + 2, columnWidth, 18);
            g->drawString(str, new FontStyle("Tahoma", 13, 1, true, false), new Color(0, 0, 0, 255), x + padding + left, columnY + 1, columnWidth, 18);
            left += columnWidth;
        }
        top = columnY + 18;
        for (int i = 0; i < dataSource->getRowCount(); i++) {
            for (int j = 0; j < dataSource->getColumnCount(); j++) {
                string text = dataSource->getTextForCell(j, i);
                left = x + (j * columnWidth) + padding;
                g->drawString((char *)text.c_str(), new FontStyle("Tahoma", 13, 1, false, false), new Color(255, 255, 255, 255), left, top + 2, columnWidth, 18);
            }
            top += 18;
        }



    }
}
