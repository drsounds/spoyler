#include "VBoxElement.h"
namespace spider {
    VBoxElement::VBoxElement()
    {
    }



    void spider::VBoxElement::pack() {
        int width = this->getWidth();
        int flexes = 0;
        int statics = 0;
        int topheight = 0;
        int bottomheight = 0;
        int side = -1;
        // First calculate count of flex
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {

            Element *child = static_cast<Element *>(*it);
            if (!child->isVisible())
                continue;
            if(child->hasAttribute("flex")) {
                flexes++;
                side = 0;
            } else {
                if(side == 0)
                    side+=1;
                if(side > 1)
                    side = 1;
                statics++;
                if(side < 1)
                    topheight += child->getHeight();
                else if(side > 0)
                    bottomheight += child->getHeight();
            }
        }

        int flexHeight = flexes > 0 ?  (this->getHeight() - topheight - bottomheight) / flexes : 0;
        float flex = 1;
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
             if (!child->isVisible())
                continue;
            if(child->hasAttribute("flex")) {
        //		child->setWidth((flex / flexes) * flexWidth);
            //	flex = (int)child->getAttribute("flex");
                child->setHeight((1 / flexes) * flexHeight);
            } else {
                statics++;
            }
        }

        // Now assign elements
        int top = 0;
        int bottom = 0;
        side = -1;
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            if (!child->isVisible())
                continue;
            if(child->hasAttribute("flex")) {

                side = 0;
            } else {
                if(side == 0)
                    side = 1;
            }
            if (side < 0)
            {
                child->setY(top);
            }
            else if (side == 0) {
                child->setY(topheight + (((1 / flexes) * (flexHeight - 1)))*0 + child->getMargins()->top + this->getPadding()->top);

                child->setHeight(flexHeight);
            } else if(side > 0)
                child->setY(topheight + flexHeight + bottom + child->getPadding()->top + child->getMargins()->top);


            child->setWidth(this->getWidth() - (child->getMargins()->bottom * 2 + this->getPadding()->bottom * 2));
            switch(side) {
                case -1:
                    top += child->getHeight() ;
                    break;
                case 0:
                    top += child->getHeight();
                    break;
                case 2:
                    bottom += child->getHeight();
                    break;
                default:
                    top += child->getHeight();
            }
        }



        // Pack child elements
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            if (!child->isVisible())
                continue;
            child->pack();
        }

    };
}

