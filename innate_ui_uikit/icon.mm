//
//  icon.mm
//  innate_ui_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-09-20 18:50
//
//
//
#include "framework.h"
#import <UIKit/UIKit.h>
#include "icon.h"


namespace innate_ui_uikit
{



void icon::__create_icon()
{
   
   auto buffer = m_memory.data();
   auto size = m_memory.size();
   
   NSData *imageData = [[NSData alloc] initWithBytes:buffer length:size];
   
   // Create NSImage from NSData
   UIImage *image = [[UIImage alloc] initWithData:imageData];
   
   m_pUIImage = (__bridge_retained void *) image;
   
}


void icon::__icon_release()
{
 
   UIImage * puiimage = (__bridge_transfer UIImage *) m_pUIImage;
   
   m_pUIImage = nullptr;
   
   puiimage = nil;
   
}

} // namespace innate_ui_uikit




