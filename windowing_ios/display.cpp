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
   
      m_pDisplay2 = this;
   
   }


   display::~display()
   {
      

   }


   ::count display::get_monitor_count()
   {
    
      return ns_monitor_count();
      
   }



   ::point_i32 display::_get_mouse_cursor_position()
   {

      return m_pointCursor2;

   }
   

} // namespace windowing_ios


