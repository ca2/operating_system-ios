//
//  host_interaction.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 11/05/22.
//  21:33
// for acme_windowing_ui_kit on 2024-11-26 10:29
// by camilo <3ThomasBorregaardSorensen
//
#pragma once


#include "acme/windowing/sandbox/host_interaction.h"

namespace uikit
{


   namespace acme
{
   
   
   namespace windowing
   {
   
   
   class host_interaction :
   virtual public ::acme::sandbox_windowing::host_interaction
   {
   public:
      
      

      host_interaction();
      ~host_interaction() override;
      
      
      
      
   };
   
   }
   
   }

} // namespace uikit



