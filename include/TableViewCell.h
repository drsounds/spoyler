#ifndef TABLEVIEWCELL_H
#define TABLEVIEWCELL_H
#include <string>
using namespace std;
namespace spider {
class TableViewCell
{
    public:
        TableViewCell();
        virtual ~TableViewCell();
    protected:
        string text;
        string uri;

    private:
};
}
#endif // TABLEVIEWCELL_H
