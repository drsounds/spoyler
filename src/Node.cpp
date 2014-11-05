#include "Node.h"
namespace spider {



    Node::Node() {
        if(this->window == NULL)
            this->window = this;
            this->children = new vector<Node *>();
            this->properties = new map<string, void*>();
            this->attributes = new map<string, string*>();
    }
    Node* Node::getParent() {
        return this->parent;
    }

    void *Node::getAttributeObj(string prop) {

        void *t = (void *)(*this->properties)[prop];
        return t;
    }
    std::vector<Node *> *Node::getChildNodes() {
        return (this->children);
    }
    bool Node::hasAttribute(string attr) {
        map<string, void *>::iterator it = this->properties->find(attr);
        return it != this->properties->end();
    }

    void Node::setParent(Node *elm) {
        this->parent = (elm);
    }
    std::string Node::get(const std::string& title) {
        std::string *val = (*this->attributes)[title];
        return *val;
    }
    void* Node::getObject(const std::string& title) {
        return (*this->properties)[title];
    }


    void Node::set(const std::string& title, std::string *val) {
        int n = 0;
        (*this->getAttributes())[title] = val;
        try {
            n = atoi(val->c_str());



            (*this->attributes)[title] = val;
            (*this->properties)[title] = (void *)n;
        } catch (exception e) {
            (*this->properties)[title] = (void *)val;
        }

        if(val->find("#") == 0) {
            Color *c =new Color(*val);
            (*this->properties)[title] = (void *)c;
        }
    }
     void Node::set(const std::string& title, const std::string value) {
        this->set(title, new std::string(value));
    }

    void Node::appendChild(spider::Node *child) {
        vector<Node *> *nodes = this->children;
        if (nodes == NULL) {
            nodes = new vector<Node *>();
        }
        nodes->push_back(child);
        child->setParent(this);
        child->window = this->getWindowNode();
    }
    Node *getElementById(string *id) {
        return NULL;
    }
    Node *Node::getWindowNode() {
        return this->window;
    }








}
