#include "TableRow.h"
namespace spider {
TableRow::TableRow(TableElement *tableElement)
{
    this->tableElement = tableElement;
    this->children = new vector<TableRow *>;
    //ctor
}

TableRow::~TableRow()
{
    //dtor
}
}
