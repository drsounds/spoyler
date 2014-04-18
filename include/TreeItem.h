#ifndef TREEITEM_H
#define TREEITEM_H
#include "Uri.h"
#include "SPType.h"
namespace spider {
    class TreeItem : SPType {
    protected:
        bool highlighted;
		char *title;
		char *subtitle;
		Uri *uri;
		bool selected;
	public:
	    bool isHighlighted() {
            return this->highlighted;
	    }
	    void setHighlighted(bool value) {
            this->highlighted = value;
	    }
	    bool isSelected() {
            return this->selected;
	    }
	    void setSelected(bool selected) {
            this->selected = selected;
	    }
		TreeItem(Uri *uri);
		char *text() {
			return this->title;
		}
		void setText(char *text) {
            this->title = text;
		}
		Uri *getUri() {
            return this->uri;
		}
		~TreeItem();

	};
}
#endif // TREEITEM_H
