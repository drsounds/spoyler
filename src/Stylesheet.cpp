#include "Stylesheet.h"
namespace spider {

Selector::Selector()
 : Node() {
 }
Selector::~Selector() {

}

Stylesheet::Stylesheet()

{

    try
    {
        // send your JSON above to the parser below, but populate ss first


        boost::property_tree::read_json("../../skin.json", *pt);

    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    this->selectors = new map<string, string>;

    //ctor
}

string Stylesheet::get(string entity, string prop) {
    boost::property_tree::ptree tree = this->pt->get_child((char *)entity.c_str());
    string val = tree.get_child((char *)prop.c_str()).get_value<std::string>();
    return val;
}

Stylesheet::~Stylesheet()
{
    //dtor
}
}
