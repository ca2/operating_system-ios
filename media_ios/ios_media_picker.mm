//
//  ios_media_picker.mm
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 01:37 <3ThomasBorregaardSorensen!!
//

#include "ios_media_picker.h"
#include "windowing_ios/ios/ios_window.h"
#include "windowing_ios/ios/iosWindow.h"
#include "iosMediaPickerViewController.h"


void ns_main_post(dispatch_block_t block);


ios_media_picker::ios_media_picker()
{
 
   m_pioscontroller = [[iosMediaPickerViewController alloc] initWithMediaPicker: this];
   
}


void ios_media_picker::ios_media_picker_pick_media(const char * pszMediaType, ios_window * pioswindow)
{
   
   ns_main_post(^{
      
      
      auto pnsioswindow = (iosWindow *) (__bridge ns_acme_window *) pioswindow->m_pnsacmewindow;
      
      [ m_pioscontroller pickMedia : pszMediaType window : pnsioswindow ];
      
   });
   
   
}
