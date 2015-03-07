#ifndef ARTISTVIEW_H
#define ARTISTVIEW_H
#include "TabbarViewElement.h"
namespace spider {
    class ArtistView : public TabbarViewElement
    {
        public:
            ArtistView(Element *parent);
            virtual ~ArtistView();
            virtual string getType() {
                return "artistview";
            }
        protected:
        private:
    };
}
#endif // ARTISTVIEW_H
