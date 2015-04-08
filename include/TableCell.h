#ifndef TABLEVIEWCELL_H
#define TABLEVIEWCELL_H
#include <string>
using namespace std;
namespace spider {
class TableCell
{
    public:
        TableCell();
        virtual ~TableCell();
    protected:
        string text;
        string uri;

    private:
};
}
#endif // TABLEVIEWCELL_H
