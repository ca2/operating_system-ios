//
//  host_interaction.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 11/05/22.
//  21:33
//
#pragma once


#include "aura/windowing/sandbox/host_interaction.h"


namespace windowing_ios
{


   class host_interaction :
      virtual public ::sandbox_windowing::host_interaction
   {
   public:
      

      host_interaction();
      ~host_interaction() override;
      
   
   };


} // namespace windowing_ios



