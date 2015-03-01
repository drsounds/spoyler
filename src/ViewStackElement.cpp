#include "ViewStackElement.h"
#include "WhatsNewView.h"
#include <regex>
#include "PlayQueueView.h"
#include "MainWindowElement.h"
#include <vector>
namespace spider {
    void ViewStackElement::appendChild(Node *child) {
        Node::appendChild(child);
        ((Element *)child)->setVisible(false);
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
            if (view->acceptsUri(uri)) {
                view->setVisible(true);
                view->navigate(uri);
                activeView = view;
                foundView = true;

            } else {
            }
            this->invalidate();
        }

        if (foundView) {
             for (std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
                Node *node = static_cast<Node *>(*it);
                ViewElement *view = (ViewElement *)node;
                if (view->acceptsUri(uri)) {
                    view->setVisible(true);


                } else {
                    view->hide();
                }
             }

                ((MainWindowElement *)this->mainWindowElement)->hideMessage();
                ((MainWindowElement *)this->mainWindowElement)->invalidate();
        } else {
            ((MainWindowElement *)this->mainWindowElement)->showMessage(Warning, "The uri could not be found");
                ((MainWindowElement *)this->mainWindowElement)->invalidate();
        }
       /* if (std::regex_match(uri.c_str(), std::regex("spoyler:internal:start"))) {

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
