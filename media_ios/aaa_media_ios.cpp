//
//  media_ios.cpp
//  media_ios::media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 00:15 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "media_ios.h"

//void * new_iosAudioPickerViewController_as_UIViewController();


namespace media_ios
{


media_ios::media_ios()
{
   
   
}


media_ios::~media_ios()
{
   
}

// "iosAudioPickerViewController as UIViewController"
void * media_ios::new_object(const char * psz)
{
   
   if(!strcmp(psz, "iosAudioPickerViewController as UIViewController"))
   {
      
      return new_iosAudioPickerViewController_as_UIViewController();
      
   }
   
   
   throw ::exception(error_no_factory);
   
   return nullptr;
   
}



} // namespace media_ios




