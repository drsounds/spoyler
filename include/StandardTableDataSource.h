#ifndef STANDARDTABLEDATASOURCE_H
#define STANDARDTABLEDATASOURCE_H
#include <vector>
#include "TableCell.h"
#include "TableRow.h"
using namespace std;
namespace spider {
class StandardTableDataSource : public TableDataSource
{
    public:
        StandardTableDataSource();
        virtual ~StandardTableDataSource();
        virtual ~TableDataSource();
        virtual int getColumnCount();
        virtual int getRowCount();
        virtual string getUriForCell (int column, int row);
        virtual string getTextForCell (int column, int row);
        virtual string getTextForColumn (int column);
        virtual string getRowUri(int index);
        virtual bool isRowActive(int index);
        virtual bool isCellActive (int index);
        virtual void *getDataForCell(int index);
        virtual bool compareTableCells(int column, TableCell *t1, TableCell *t2);
        vector<TableRow *> *rows;
        vector<TableColumnHeader *> *columnHeaders;
    protected:
    private:
};
}

#endif // STANDARDTABLEDATASOURCE_H
