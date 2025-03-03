//
//  monitor.m
//  windowing_macos
//
//  Created by Camilo Sasuke on 27/05/21 20:48 BRT <3ThomasBS_!!
//
#include "framework.h"


double get_status_bar_frame_height();


int ns_monitor_count()
{
   
   auto screenArray = [UIScreen screens];

   auto count = [screenArray count];

   return (int) count;
   
}


void ns_screen_translate(CGRect * prect)
{
   
   CGRect rectMainMonitor;

   ns_main_monitor_cgrect(&rectMainMonitor);
   
   auto nsBottom = prect->origin.y + prect->size.height;
   
   auto top = rectMainMonitor.origin.y + rectMainMonitor.size.height;

   prect->origin.y = top - nsBottom;

}


void ns_monitor_cgrect(int i, CGRect * prect)
{

   auto screenArray = [UIScreen screens];

   auto pscreen = [screenArray objectAtIndex:i];
   
   *prect = [pscreen bounds];
   
   ns_screen_translate(prect);
   
}


void ns_workspace_cgrect(int i, CGRect * prect)
{

   auto screenArray = [UIScreen screens];

   auto pscreen = [screenArray objectAtIndex:i];
   
   *prect = [pscreen bounds];
   
   prect->size.height -= get_status_bar_frame_height();
   
   
   ns_screen_translate(prect);
   
}


void ns_main_monitor_cgrect(CGRect * prect)
{

   auto pscreen = [UIScreen mainScreen];

   *prect = [pscreen bounds];
   
}



