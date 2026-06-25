//
//  ui_image.cpp
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2026-05-12 04:23
//  <3ThomasBorregaardSørensen!!
//
#include "framework.h"
#include "ui_image.h"
#include "acme/prototype/geometry2d/size.h"
#include "_mm.h"

namespace uikit
{

   ui_image::ui_image()
   {
   
      //m_pNS = nullptr;
      
   }


   ui_image::~ui_image()
   {
   
      ui_image_release(m_uiimage);
   
   }


   ::i32_size ui_image::get_size()
   {
   
      auto cgimage = ui_image_get_cg_image(m_uiimage);
      
      auto cgsize = cg_image_get_size(cgimage);
      
      return {cgsize.w, cgsize.h};
      
   }


} // namespace uikit


