#include "TableElement.h"
namespace spider {
    TableElement::TableElement()
    {
        //ctor
    }
    void TableElement::scroll(int scrollX, int scrollY, int x, int y) {
        Element::scroll(scrollX, scrollY, x, y);
    }
    TableElement::TableElement(Element *parent, TableDataSource *dataSource)
    {
        //ctor
        this->dataSource = dataSource;
        this->columns = new vector<TableColumnHeader *>;
        this->rows = new vector<TableRow *>;
    }
    TableElement::~TableElement()
    {
        //dtor
    }
    string TableElement::getType() {
        return "table";
    }
    void TableElement::draw(int x, int y, GraphicsContext *g) {
        spider_position pos;
        std::vector<Node *> *children = this->getChildNodes();
        x += this->getX() ;
        y += this->getY();
        if (this->absoluteBounds == NULL)
        this->absoluteBounds = new rectangle;

        this->absoluteBounds->x = x + this->getMargins()->left;
        this->absoluteBounds->y = y + this->getMargins()->bottom;
        this->absoluteBounds->width = this->getWidth() - this->getMargins()->left + this->getMargins()->right;
        this->absoluteBounds->height = this->getHeight() - this->getMargins()->top + this->getMargins()->bottom;

        int width =  this->getWidth();
        int height = this->getHeight();

        rectangle rect2;
        rect2.x = 0;
        rect2.y = 0;
        rect2.width = width;
        rect2.height = height;

        y = y + 1;
        TableDataSource *dataSource = this->dataSource;
        rectangle *absoluteBounds = this->absoluteBounds;

        // Draw table data here
        width = ((Element *)this)->getWidth();
        if (width < 1) {
            width = ((Element *)this->parent->parent)->getWidth();
        }
        int columnY = y;

        rectangle clipRect;
        clipRect.x = x;
        clipRect.y = y;
        clipRect.width = width;
        clipRect.height = ((Element *)this->parent->parent)->getHeight();
 int left = 0;
        int padding = 10;
        int columnWidth = width / dataSource->getColumnCount();
        int top = columnY + 18;
        // Draw rows
        for (int i = 0; i < 100; i++) {
            if (i % 2 != 1) {
                g->fillRectangle(x, top, width, 18, g->skin->getColor("table::nth-child(2n).background.color", ""));

            }
            top += 18;
        }
        int columnYY = columnY;

        top = columnY + 18;
        for (int i = 0; i < dataSource->getRowCount(); i++) {
            for (int j = 0; j < dataSource->getColumnCount(); j++) {
                string text = dataSource->getTextForCell(j, i);
                left = x + (j * columnWidth) + padding;
                g->drawString((char *)text.c_str(), new FontStyle("Tahoma", 13, 1, false, false), new Color(255, 255, 255, 255), left, top + 2, columnWidth, 18);
            }
            top += 18;
        }

        // Draw column headers
        if (columnY < 60) {
            // If columnY is below zero, set it to the position at top
            columnY = ((Element *)this->parent)->absoluteBounds->y + 1;
        }
        g->skin->drawImageSlice("table::columnheader.background.image", g, x, columnY, width, 18);

        left =0;
        for (int i = 0; i < dataSource->getColumnCount(); i++) {
            string text = dataSource->getTextForColumn(i);
            char *str = (char *)text.c_str();
            g->drawString(str, new FontStyle("Tahoma", 13, 1, true, false), new Color(200, 200, 200, 255), x + padding + left, columnY + 2, columnWidth, 18);
            g->drawString(str, new FontStyle("Tahoma", 13, 1, true, false), new Color(0, 0, 0, 255), x + padding + left, columnY + 1, columnWidth, 18);
            left += columnWidth;
        }
        columnY = columnYY;


    }
}
