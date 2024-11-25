//
//  display.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke on 27/05/21 19:43 BRT <3ThomasBS_!!
//  From windowing_macos on 2022-05-11 02:13 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "acme_windowing_uikit/display.h"
#include "aura/windowing/display.h"


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_IOS display :
      virtual public ::windowing::display,
virtual public ::uikit::acme::windowing::display
   {
   public:
      
   
      display();
      ~display() override;

      
      ::collection::count get_monitor_count() override;
      
      
      ::int_point _get_mouse_cursor_position() override;
   
      
      bool get_zoomed_window_site(::collection::index iWorkspace, ::int_rectangle & rectangle) override;

      int get_zoomed_title_bar_height() override;
      
       ::int_size get_main_screen_size() override;
       
       
   };



} // namespace windowing_ios



