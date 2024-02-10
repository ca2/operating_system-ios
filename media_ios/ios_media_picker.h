//
//  ios_media_picker.h
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 01:08 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "acme/_.h"


#ifdef __OBJETIVE_CPP__
@interface iosAudioPickerViewController;
#endif


struct platform_media_item_t;


class ios_media_picker
{
public:
   
#ifdef __OBJETIVE_CPP__
   iosMediaPickerViewController * m_pioscontroller;
#else
   void * m_pIosController;
#endif
   
   virtual void ios_window_pick_media(const char * pszMediaType);
   virtual void ios_window_did_pick_platform_media_item(platform_media_item_t * papplemedia) = 0;
   
   
};
