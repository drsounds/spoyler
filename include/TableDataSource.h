#ifndef TABLEVIEWDATASOURCE_H
#define TABLEVIEWDATASOURCE_H
#include <TableCell.h>
#include <TableColumn.h>
#include <vector>
namespace spider {
class TableDataSource
{
    public:

        TableDataSource();
        virtual ~TableDataSource();
        virtual int getColumnCount() { }
        virtual int getRowCount() { }
        virtual string getUriForCell (int column, int row) {  }
        virtual string getTextForCell (int column, int row) {  }
        virtual string getTextForColumn (int column) {}
        virtual string getRowUri(int index) {}
        virtual bool isRowActive(int index) {}
        virtual bool isCellActive (int index) {}
        virtual void *getDataForCell(int index) {}
        virtual bool compareTableCells(int column, TableCell *t1, TableCell *t2) { }

        virtual vector<int> getSelectedIndexes() {}
        virtual bool isIndexSelected (int index) { return false; }
        virtual void addIndexesToSelection(int index) {}
        virtual void removeIndexesFromSelection (int index) {}

    protected:
    private:
};
}
#endif // TABLEVIEWDATASOURCE_H
