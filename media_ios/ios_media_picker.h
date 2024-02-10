//
//  ios_media_picker.h
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 01:08 <3ThomasBorregaardSorensen!!
//
#pragma once

#include "acme/_start.h"
#include "acme/_.h"

class ios_window;

#ifdef __OBJECTIVE_CPP__
@class iosMediaPickerViewController;
#endif


struct platform_media_item_t;


class ios_media_picker
{
public:
   
#ifdef __OBJECTIVE_CPP__
   iosMediaPickerViewController * m_pioscontroller;
#else
   void * m_pIosController;
#endif
   
   ios_media_picker();
   
   virtual void ios_media_picker_pick_media(const char * pszMediaType, ios_window * pioswindow);
   virtual void ios_media_picker_did_pick_platform_media_item(platform_media_item_t * pplatformmediaitem) = 0;
   
   
};
