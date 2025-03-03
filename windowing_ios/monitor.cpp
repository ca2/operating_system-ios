//
//  monitor.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 27/05/21 19:48 BRT <3ThomasBS_!!
//
#include "framework.h"
#include "monitor.h"


#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>


void ns_main_post(dispatch_block_t block);

void ns_main_send(dispatch_block_t block);

void ns_monitor_cgrect(int i, CGRect * p);
void ns_workspace_cgrect(int i, CGRect * p);


namespace windowing_ios
{


   monitor::monitor()
   {

      //m_pMonitor2 = this;
   
   }


   monitor::~monitor()
   {
      

   }


   ::int_rectangle monitor::monitor_rectangle()
   {
      
      CGRect rectMonitor;
      
      ns_monitor_cgrect((int) m_iIndex, &rectMonitor);
      
      ::int_rectangle rectangle;
       
      copy(rectangle, rectMonitor);
      
      return rectangle;
      
   }


   ::int_rectangle monitor::workspace_rectangle()
   {
      __block CGRect rectWorkspace;

      ns_main_send(^()
                   {
         
         ns_workspace_cgrect((int) m_iIndex, &rectWorkspace);
         
         
      });
       
       ::int_rectangle rectangle;
      copy(rectangle, rectWorkspace);
      
      return rectangle;

      
   }


} // namespace windowing_ios





void ns_main_monitor_cgrect(CGRect * p);



//INT_RECTANGLE get_main_screen_rectangle()
//{
//
//   INT_RECTANGLE rectangle{};
//   
//   CGRect r;
//   
//   ns_main_monitor_cgrect(&r);
//   
//   screen_coordinates_aware_copy(rectangle, r);
//
//   return rectangle;
//   
//   //return true;
//   
//}
