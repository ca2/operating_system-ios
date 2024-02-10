//
//  ios_media_picker.mm
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-10 01:37 <3ThomasBorregaardSorensen!!
//

#include "ios_media_picker.h"


void ios_media_picker::ios_window_pick_media(const char * pszMediaType)
{
   
   [ m_pioscontroller pickMedia : pszMediaType ];
   
}
