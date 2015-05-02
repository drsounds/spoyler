#include "TableCell.h"
namespace spider {
TableCell::TableCell(TableCell *tableCell)
{
    this->tableCell = tableCell;
    this->tableElement = tableCell->tableRow->tableElement;
    //ctor
}

TableCell::~TableCell()
{
    //dtor
}
}
