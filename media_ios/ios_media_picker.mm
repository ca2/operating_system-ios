//
//  ios_media_picker.mm
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 01:37 <3ThomasBorregaardSorensen!!
//

#include "ios_media_picker.h"
#include "windowing_ios/iosWindow/ios_window.h"
#include "iosMediaPickerViewController.h"


void ns_main_async(dispatch_block_t block);


ios_media_picker::ios_media_picker()
{
 
   m_pioscontroller = [[iosMediaPickerViewController alloc] initWithMediaPicker: this];
   
}


void ios_media_picker::ios_media_picker_pick_media(const char * pszMediaType, ios_window * pioswindow)
{
   
   ns_main_async(^{
      [ m_pioscontroller pickMedia : pszMediaType window:pioswindow->m_pioswindow ];
      
   });
   
   
}
