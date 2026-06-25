//
//  uikit.cpp
//  uikit
//
//  UIKit platform wrapper.
//  <3ThomasBorregaardSørensen!!
//
#include "framework.h"
#include "uikit.h"


static ::uikit::uikit * g_puikit = nullptr;

namespace uikit
{

   uikit::uikit()
   {
      
      if(::system()->has_property("uikit::uikit"))
      {
         
         throw ::exception(error_wrong_state);
         
      }
      
      ::system()->property("uikit::uikit") = this;
      
      
   }


uikit::~uikit()
{
   
   
}



   ::pointer < ui_image > uikit::load_icon(enum_cursor ecursor)
{
      
      return {};
      
   }
   



} // namespace uikit




CLASS_DECL_UIKIT ::uikit::uikit & UIKit()
{
   
   if(!g_puikit)
   {
      
      g_puikit = new ::uikit::uikit();
      
      g_puikit->initialize(::system());
      
   }
   
   return *g_puikit;
   
}



::uikit::ui_window_t as_ui_window_t(const ::operating_system::window & operatingsystemwindow)
{
   
   return {operatingsystemwindow};
   
}
