#ifndef ARTISTOVERVIEWVIEW_H
#define ARTISTOVERVIEWVIEW_H
#include "ViewElement.h"
#include "ImageElement.h"
#include "TextElement.h"
namespace spider {
class ArtistOverviewView : public ViewElement
{
    public:
        ArtistOverviewView(Element *parent);
        virtual ~ArtistOverviewView();
    protected:
    private:
};
}
#endif // ARTISTOVERVIEWVIEW_H
