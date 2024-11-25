//
//  display.cpp
//  windowing_ios
//
//  Created by Camilo Sasuke on 27/05/21 19:43 BRT <3ThomasBS_!!
//  From windowing_macos by camilo on 2022-05-11 16:10 <3ThomasBorregaardSorensen!
//
#include "framework.h"
#include "display.h"


int ns_monitor_count();


namespace windowing_ios
{


   display::display()
   {
   
      //m_pDisplay2 = this;
   
   }


   display::~display()
   {
      

   }


   ::collection::count display::get_monitor_count()
   {
    
      return ns_monitor_count();
      
   }



   ::int_point display::_get_mouse_cursor_position()
   {

      return m_pointCursor2;

   }
   

   bool display::get_zoomed_window_site(::collection::index iWorkspace, ::int_rectangle & rectangle)
   {

      return get_monitor_rectangle(iWorkspace, rectangle);
      
   }


int display::get_zoomed_title_bar_height()
{
   
   ::int_rectangle r1;
   get_monitor_rectangle(0, r1);
   
   ::int_rectangle r2;
   get_workspace_rectangle(0, r2);
 
   return ::abs(r2.top() - r1.top());
   
}
::int_size display::get_main_screen_size()
{
    
    return ::uikit::acme::windowing::display::get_main_screen_size();
    
}


} // namespace windowing_ios


