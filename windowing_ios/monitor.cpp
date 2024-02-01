//
//  monitor.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 27/05/21 19:48 BRT <3ThomasBS_!!
//
#include "framework.h"
#include "monitor.h"


void ns_main_async(dispatch_block_t block);

void ns_main_sync(dispatch_block_t block);

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


   ::rectangle_i32 monitor::monitor_rectangle()
   {
      
      CGRect rectMonitor;
      
      ns_monitor_cgrect((int) m_iIndex, &rectMonitor);
      
      ::rectangle_i32 rectangle;
       
      copy(rectangle, rectMonitor);
      
      return rectangle;
      
   }


   ::rectangle_i32 monitor::workspace_rectangle()
   {
      __block CGRect rectWorkspace;

      ns_main_sync(^()
                   {
         
         ns_workspace_cgrect((int) m_iIndex, &rectWorkspace);
         
         
      });
       
       ::rectangle_i32 rectangle;
      copy(rectangle, rectWorkspace);
      
      return rectangle;

      
   }


} // namespace windowing_ios





void ns_main_monitor_cgrect(CGRect * p);



//RECTANGLE_I32 get_main_screen_rectangle()
//{
//
//   RECTANGLE_I32 rectangle{};
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
