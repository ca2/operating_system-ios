// created by Camilo 2021-02-04 00:58 BRT CamiloSasuke<3ThomasBorregaardSoerensen
//  From windowing_macos on 2022-05-11 02:13 <3ThomasBorregaardSorensen!!
#pragma once


#include "aura/windowing/keyboard.h"


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_MACOS keyboard :
      virtual public ::windowing::keyboard
   {
   public:


      keyboard();
      ~keyboard() override;
      
      
      //::user::enum_key wparam_to_userkey(wparam wparam) override;


   };


} // namespace windowing_ios



