#ifndef TREEVIEWELEMENT_H
#define TREEVIEWELEMENT_H
#include "Uri.h"
#include "Element.h"
#include "SPType.h"
#include "EventArgs.h"
#include "TreeItem.h"
namespace spider {
    class TreeViewEventArgs : public EventArgs {
    protected:

        TreeItem *item;
    public:
        TreeItem *getItem() {
            return this->item;
        }
        void setItem(TreeItem *item) {
            this->item = item;
        }
    };
    class TreeViewElement : public Element {
	protected:
		vector<TreeItem *> *mItems;
		int itemHeight;
	public:
		TreeViewElement(Element *parent)
            ;

		void draw(int x, int y, GraphicsContext *g);
        vector<TreeItem *> *items() {
            return this->mItems;
        }
		void setItemHeight(int height);
		int getItemHeight();
        void addItem(TreeItem *item);
	};


}
#endif // TREEVIEWELEMENT_H
