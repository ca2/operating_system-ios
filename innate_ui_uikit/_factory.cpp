#include "framework.h"
#include "dialog.h"
#include "icon.h"
#include "impact.h"
#include "button.h"
#include "still.h"
#include "innate_ui.h"



IMPLEMENT_FACTORY(innate_ui_uikit)
{

   pfactory->add_factory_item < ::innate_ui_uikit::impact, ::innate_ui::window >();
   pfactory->add_factory_item < ::innate_ui_uikit::dialog, ::innate_ui::dialog >();
   
   
   pfactory->add_factory_item < ::innate_ui_uikit::button, ::innate_ui::button >();
   pfactory->add_factory_item < ::innate_ui_uikit::still, ::innate_ui::still >();


   pfactory->add_factory_item < ::innate_ui_uikit::icon, ::innate_ui::icon >();


   pfactory->add_factory_item < ::innate_ui_uikit::innate_ui, ::innate_ui::innate_ui >();

}



