#ifndef H_SPIDER_WINDOW_ELEMENT
#define H_SPIDER_WINDOW_ELEMENT
#include "VBoxElement.h"
#include "ImageLibrary.h"
namespace spider {

	class WindowElement : public VBoxElement {
protected:
//        ImageLibrary *mImages;
public:
  /*      ImageLibrary *images() {
            return this->mImages;
        }*/
		void draw(spider::GraphicsContext *gs);
		WindowElement();
		virtual spider::GraphicsContext *createGraphics();
		virtual void invalidateRegion(rectangle rect) {}
        virtual string getType() {
            return "window";
        }
	};

};

#endif
