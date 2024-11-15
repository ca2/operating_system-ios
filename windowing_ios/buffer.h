//  From windowing_android by camilo on 2022-05-11 23:05 <3ThomasBorregaardSorensen!(ThomasLikesNumber5!!)
#pragma once


#include "aura/graphics/graphics/double_buffer.h"


namespace windowing_ios
{


   class CLASS_DECL_AURA buffer :
      virtual public ::graphics::double_buffer
   {
   public:


      buffer();
      ~buffer() override;
      
      
      virtual ::windowing_ios::window * ios_window();

      //::draw2d::graphics* on_begin_draw() override;
       
      bool _on_begin_draw(::graphics::buffer_item * pbufferitem) override;

//      bool update_buffer(const ::int_size & size, int iStride = -1) override;
      
      bool update_buffer(::graphics::buffer_item * pitem) override;
      void destroy_buffer() override;

      //bool update_screen(::image * pimage) override;
      bool on_update_screen(::graphics::buffer_item * pitem) override;

      //virtual ::draw2d::graphics * on_begin_draw();

   };


} // namespace windowing_ios



