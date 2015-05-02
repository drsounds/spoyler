#include "MockTableDataSource.h"
#include <string>
#include <sstream>
using namespace std;
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
namespace spider {


vector<int> MockTableDataSource::getSelectedIndexes() {
    vector<int> indexes;
    for (vector<int>::iterator it = this->selectedIndexes->begin(); i != this->selectedIndexes->end(); ++it) {
        int index = **it;
        indexes.push_back(index);
    }
    return indexes;
}
bool MockTableDataSource::isIndexSelected (int index) {
    return (std::find(this->selectedIndexes->begin(), this->selectedIndexes->end(), index) != this->selectedIndexes->end());

}
void MockTableDataSource::addIndexToSelection(int index) {
    this->selectedIndexes->push_back(indexes);
}
void MockTableDataSource::removeIndexFromSelection (int index) {
}

MockTableDataSource::MockTableDataSource()
{
    //ctor
}
int MockTableDataSource::getColumnCount() {
    return 3;
}

int MockTableDataSource::getRowCount() {
    return 3;
}
MockTableDataSource::~MockTableDataSource() {

}
string MockTableDataSource::getUriForCell (int column, int row) {
    return "spoyler:internal:debug";
}
string MockTableDataSource::getTextForCell (int column, int row) {
    string t ("Row ");
    t.append(to_string<int>(row));
    t.append(" ");
    t.append(" at column ");
    t.append(to_string<int>(column));
    return t;
}    //dtor
string MockTableDataSource::getTextForColumn (int column) {
    string t = "Column ";
    t.append(to_string<int>(column));
    return t;
}
string MockTableDataSource::getRowUri(int index) {
    return "spoyler:internal:debug";
}

bool MockTableDataSource::isRowActive(int index) {
    if (index == 1) {
        return true;
    }
}

bool MockTableDataSource::isCellActive (int index) {
    return false;
}

void *MockTableDataSource::getDataForCell(int index) {
    return NULL;
}

bool MockTableDataSource::compareTableCells(int column, TableCell *t1, TableCell *t2) {
    return false;
}
}
