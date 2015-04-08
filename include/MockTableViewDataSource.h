#ifndef MOCKTABLEVIEWDATASOURCE_H
#define MOCKTABLEVIEWDATASOURCE_H
#include "TableViewDataSource.h"
namespace spider {
class MockTableViewDataSource : public TableViewDataSource
{
    public:
        MockTableViewDataSource();
        virtual ~MockTableViewDataSource();
        virtual int getColumnCount();
        virtual int getRowCount();
        virtual string getUriForCell (int column, int row);
        virtual string getTextForCell (int column, int row);
        virtual string getTextForColumn (int column);
        virtual string getRowUri(int index);
        virtual bool isRowActive(int index);
        virtual bool isCellActive (int index);
        virtual void *getDataForCell(int index);
        virtual bool compareTableCells(int column, TableViewCell *t1, TableViewCell *t2);
    protected:
    private:
};
}

#endif // MOCKTABLEVIEWDATASOURCE_H
