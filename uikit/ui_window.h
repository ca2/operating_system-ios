//
//  ui_window.h
//  uikit
//
//  From early core_graphics/ns_bitmap.h by
//  Camilo Sasuke Thomas Borregaard Sørensen on 2026-05-12 04:52 <3ThomasBorregaardSørensen!!
//
//
#pragma once


#include "operating_system-apple/acme_windowing_kit/window.h"
#include "acme/operating_system/ios/window.h"


namespace uikit
{




   class CLASS_DECL_UIKIT ui_window :
      virtual public ::apple_kit::acme::windowing::window
   {
   public:
      
      ui_window_t m_uiwindow;
      
      ::operating_system::ios_window m_ioswindow;
      
      
      ui_window();
      ~ui_window();
      
      
      //virtual ::i32 get_size();
      
      
      
   };

} // namespace uikit



