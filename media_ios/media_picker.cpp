//
//  media_picker.cpp
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 10/02/24.
//

#include "media_picker.h"

namespace media_ios
{


void window::pick_media(const char * pszMediaType)
{
   ios_window_pick_media(pszMediaType);
   
   
}


void window::ios_window_did_pick_apple_media(platform_media_item_t * pplatformmediaitem)
{
   
   auto papplemediaitem = node()->m_pauranode->create_media_item_from_platform_media_item(ppl);
   
   papplemediaitem->attach(pmediaitem);
   
   ::pointer < ::aqua::media_item > paquamediaitem = papplemediaitem;
   
   application()->m_paquaapplication->did_pick_media_item(paquamediaitem);
   
}


} // namespace media_ios




