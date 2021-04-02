#ifndef MOCKTABLEDATASOURCE_H
#define MOCKTABLEDATASOURCE_H
#include "TableDataSource.h"
#include <vector>
namespace spider {
class MockTableDataSource : public TableDataSource
{
    public:
        vector<int> *selectedIndexes;
        MockTableDataSource();
        virtual ~MockTableDataSource();
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

        virtual vector<int> getSelectedIndexes();
        virtual bool isIndexSelected (int index);
        virtual void addIndexToSelection(int index);
        virtual void removeIndexFromSelection (int index);
    protected:
    private:
};
}
#endif // MOCKTABLEDATASOURCE_H
