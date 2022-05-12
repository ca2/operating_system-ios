//  From windowing_android by camilo on 2022-05-11 23:05 <3ThomasBorregaardSorensen!(ThomasLikesNumber5!!)
#pragma once


#include "aura/graphics/graphics/_graphics.h"


namespace windowing_ios
{


   class CLASS_DECL_AURA buffer :
      virtual public ::graphics::double_buffer
   {
   public:


      buffer();
      ~buffer() override;

      ::draw2d::graphics* on_begin_draw() override;

      bool update_buffer(const ::size_i32 & size, int iStride = -1) override;
      void destroy_buffer() override;

      bool update_screen(::image * pimage) override;

      //virtual ::draw2d::graphics * on_begin_draw();

   };


} // namespace windowing_ios



