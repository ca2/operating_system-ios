//
//  media_ios.h
//  media_ios::media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 00:15 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "media_apple/media_apple.h"


namespace media_ios
{


   class CLASS_DECL_MEDIA_IOS media_ios :
      virtual public ::media_apple::media_apple
   {
   public:
      
      
      media_ios();
      ~media_ios() override;
      
   
      // "iosAudioPickerViewController as UIViewController"
      void * new_object(const char * psz) override;
   
   };
   
   
} // namespace media_ios
   


