#include "MockTableViewDataSource.h"
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
MockTableViewDataSource::MockTableViewDataSource()
{
    //ctor
}
int MockTableViewDataSource::getColumnCount() {
    return 3;
}

int MockTableViewDataSource::getRowCount() {
    return 3;
}
MockTableViewDataSource::~MockTableViewDataSource() {

}
string MockTableViewDataSource::getUriForCell (int column, int row) {
    return "spoyler:internal:debug";
}
string MockTableViewDataSource::getTextForCell (int column, int row) {
    string t ("Row ");
    t.append(to_string<int>(row));
    t.append(" ");
    t.append(" at column ");
    t.append(to_string<int>(column));
    return t;
}    //dtor
string MockTableViewDataSource::getTextForColumn (int column) {
    string t = "Column ";
    t.append(to_string<int>(column));
    return t;
}
string MockTableViewDataSource::getRowUri(int index) {
    return "spoyler:internal:debug";
}

bool MockTableViewDataSource::isRowActive(int index) {
    if (index == 1) {
        return true;
    }
}

bool MockTableViewDataSource::isCellActive (int index) {
    return false;
}

void *MockTableViewDataSource::getDataForCell(int index) {
    return NULL;
}

bool MockTableViewDataSource::compareTableCells(int column, TableViewCell *t1, TableViewCell *t2) {
    return false;
}
}
