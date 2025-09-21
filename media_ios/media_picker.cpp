//
//  media_picker.cpp
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 10/02/24.
//
#include "framework.h"
#include "media_picker.h"
#include "aqua/multimedia/media_item_picker_callback.h"
#include "media_apple/media_item.h"
#include "windowing_ios/window.h"

namespace media_ios
{

void media_picker::set_windowing_window(::windowing::window * pwindow)
{
   
   m_pioswindow = pwindow;
   
}


void media_picker::pick_media(const char * pszMediaType)
{
   
   ios_media_picker_pick_media(pszMediaType, m_pioswindow);
   
}


void media_picker::ios_media_picker_did_pick_platform_media_item(platform_media_item_t * pplatformmediaitem)
{
   
   
   auto papplemediaitem = øallocate ::media_apple::media_item();
   
   papplemediaitem->initialize(this);
   
   papplemediaitem->attach(pplatformmediaitem);
   
   m_ppickercallback->did_pick_media_item(papplemediaitem);
   
}


} // namespace media_ios




