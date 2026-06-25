//
//  ui_image.h
//  core_graphics
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2026-05-12 04:21
//  <3ThomasBorregaardSørensen!!
//
#pragma once


namespace uikit
{


   class CLASS_DECL_UIKIT ui_image :
      virtual public ::particle
   {
   public:
      
      
      ui_image_t m_uiimage;
      
      
      ui_image();
      ~ui_image();
      
      
      virtual ::i32_size get_size();
      
      
      
   };

} // namespace uikit




