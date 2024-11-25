#include "framework.h"
#include "display.h"
#include "window.h"
#include "windowing.h"


IMPLEMENT_FACTORY(acme_windowing_appkit)
{

   pfactory->add_factory_item < ::uikit::acme::windowing::windowing, ::acme::windowing::windowing >();
   pfactory->add_factory_item < ::uikit::acme::windowing::window, ::acme::windowing::window >();
   pfactory->add_factory_item < ::uikit::acme::windowing::display, ::acme::windowing::display >();

}


