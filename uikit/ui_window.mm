//
//  ui_window.mm
//  uikit
//
//  From early core_graphics/ns_bitmap.mm by
//  Camilo Sasuke Thomas Borregaard Sørensen on 2026-05-12 04:53 <3ThomasBorregaardSørensen!!
//
#include <UIKit/UIKit.h>
#include "_mm.h"

void ui_window_release(ui_window_t & uiwindow)
{
 
   if(uiwindow.is_null())
   {
      
      return;
      
   }
   
   UIWindow * window = (__bridge_transfer UIWindow *)uiwindow.m_p;
   
   uiwindow.clear();
      
}
