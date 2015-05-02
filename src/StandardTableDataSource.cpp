#include "StandardTableDataSource.h"
#include <string>
#include <sstream>
using namespace std;
namespace spider {
StandardTableDataSource::StandardTableDataSource()
{
    //ctor
    this->rows = new vector<TableRow *>;
    this->columnHeaders = vector<TableColumnHeader *>;

}
int StandardTableDataSource::getColumnCount() {
    return this->columnHeaders->size();
}

int StandardTableDataSource::getRowCount() {
    return this->rows->size();
}
StandardTableDataSource::~StandardTableDataSource() {

}
string StandardTableDataSource::getUriForCell (int column, int row) {
    return "spoyler:internal:debug";
}
string StandardTableDataSource::getTextForCell (int column, int row) {
    string t ("Row ");
    t.append(to_string<int>(row));
    t.append(" ");
    t.append(" at column ");
    t.append(to_string<int>(column));
    return t;
}    //dtor
string StandardTableDataSource::getTextForColumn (int column) {
    string t = "Column ";
    t.append(to_string<int>(column));
    return t;
}
string StandardTableDataSource::getRowUri(int index) {
    return "spoyler:internal:debug";
}

bool StandardTableDataSource::isRowActive(int index) {
    if (index == 1) {
        return true;
    }
}

bool StandardTableDataSource::isCellActive (int index) {
    return false;
}

void *StandardTableDataSource::getDataForCell(int index) {
    return NULL;
}

bool StandardTableDataSource::compareTableCells(int column, TableCell *t1, TableCell *t2) {
    return false;
}
}
