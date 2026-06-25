//
//  ui_image.mm
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 12/05/26.
//
#include <UIKit/UIKit.h>
#include "_mm.h"

void ui_image_release(ui_image_t & uiimage)
{
 
   if(uiimage.is_null())
   {
      
      return;
      
   }
   
   // Transfers ownership to ARC. ARC will release 'pns' when this function exits.
   UIImage * image = (__bridge_transfer UIImage *)uiimage.m_p;
   
   uiimage.clear();
   
}



cg_image_t ui_image_get_cg_image(ui_image_t uiimage)
{
   UIImage * image = (__bridge UIImage *)uiimage.m_p;
 
   CGImageRef cgImage = image.CGImage;

   return {(::uptr) cgImage};
}
