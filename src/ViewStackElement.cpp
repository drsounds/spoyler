#include "ViewStackElement.h"
#include "WhatsNewView.h"
#include <regex>
#include "PlayQueueView.h"
#include "MainWindowElement.h"
#include <vector>
#include <boost/algorithm/string/predicate.hpp>
inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
namespace spider {
    void ViewStackElement::appendChild(Node *child) {

        ViewElement *view = (ViewElement *)child;
        string type = view->getType();
        if (boost::algorithm::ends_with(type, "view")) {

            Node::appendChild(child);
            cout << "valid view: " << type << endl;

            ((Element *)child)->setVisible(false);
        } else {
            exit(0);
        }
    }
    ViewStackElement::ViewStackElement()
    : BoxElement::BoxElement() {
         this->history = new std::stack<string *>;
         this->future = new std::stack<string *>;
    }

    ViewStackElement::ViewStackElement(Element *parent)
     : BoxElement::BoxElement(parent) {
         this->setParent(this);
         this->history = new std::stack<string *>;
         this->future = new std::stack<string *>;
         this->activeView = NULL;
        vector<Node *> *children = this->getChildNodes();
    }
    void ViewStackElement::pack() {
        BoxElement::pack();
         for (std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Node *node = static_cast<Node *>(*it);
            Element *view = (Element *)node;
            string type = view->getType();
            view->setWidth(this->getWidth() - (view->getMargins()->bottom * 2 + this->getPadding()->bottom * 2));
            cout << "View of type: " << type << endl;
            if (view->absoluteBounds != NULL && this->absoluteBounds != NULL) {
                view->absoluteBounds->height = this->absoluteBounds->height;
                view->absoluteBounds->width = this->absoluteBounds->width;
            }
         }
    }
    /**
     * Main navigation handler inside Spotify
     **/
    void ViewStackElement::navigate(string uri) {
        // TODO add navigation handler

        std::stack<string *> *history = this->history;
        ViewStackElement *th = this;



        // Hide all views
        this->pack();
        this->invalidate();
        ViewElement *newView = NULL;
        bool foundView = false;
        for (std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Node *node = static_cast<Node *>(*it);
            ViewElement *view = (ViewElement *)node;
            string type = view->getType();
            std::cout << view->getType() << std::endl;
            if (ends_with(type, "view")) {
                if (view->acceptsUri(uri)) {
                    std::cout << uri << std::endl;
                    std::cout << view->getType() << std::endl;
                    cout << "View " << view->getType() << " shown" << endl;
                    view->setVisible(true);
                    view->navigate(uri);
                    activeView = view;

                } else {
                    cout << "View " << view->getType() << " hidden" << endl;
                    view->setVisible(false);
                }

            } else {
                cout << "Wrong view: " << view->getType() << endl;
            }
            this->invalidate();
        }

       /* if (std::regex_match(uri.c_str(), std::regex("spotify:internal:start"))) {

            // Show What's new view
            view = new views::WhatsNewView((Element *)this);

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:playqueue"))) {

            // Show playqueue view and switch to the queue tab

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:history"))) {

            // Show playqueue view and switch to the history tab

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:config"))) {

            // Show Spotify config page

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:artist:(.*)"))) {

            // Load artist view and navigate to apporiate artist

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:album:(.*)"))) {

            // Load album view and navigate to apporiate artist

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:user:(.*):playvector:(.*)"))) {

            // Load user playvectors view

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:radio"))) {

            // Load radio view

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:config2"))) {

            // Show the extended config2 dialog

        } else {

            // Show error message (The URI could not be found)
            return;
        }
        vector<Node *> *children = this->getChildNodes();
        if (view != NULL) {
            this->appendChild(view);
            view->navigate(uri);
        }*/


    }



}
