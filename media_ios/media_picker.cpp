//
//  media_picker.cpp
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 10/02/24.
//
#include "framework.h"
#include "media_picker.h"
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


void window::ios_window_did_pick_apple_media(platform_media_item_t * pplatformmediaitem)
{
   
   auto papplemediaitem = node()->m_pauranode->create_media_item_from_platform_media_item(ppl);
   
   papplemediaitem->attach(pmediaitem);
   
   ::pointer < ::aqua::media_item > paquamediaitem = papplemediaitem;
   
   application()->m_paquaapplication->did_pick_media_item(paquamediaitem);
   
}


} // namespace media_ios




