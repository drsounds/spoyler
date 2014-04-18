#include "ArtistOverviewView.h"
#include "HBoxElement.h"
namespace spider {
ArtistOverviewView::ArtistOverviewView(Element *parent)
 : ViewElement(parent)
{
    //ctor
    HBoxElement *header = new HBoxElement(this);
    header->set("height", "128");



}

ArtistOverviewView::~ArtistOverviewView()
{
    //dtor
}
}
