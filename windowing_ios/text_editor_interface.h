//
//  text_editor_interface.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/06/22. 21:43
//
#pragma once


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_MACOS text_editor_interface :
      virtual public ::windowing::text_editor_interface
   {
   public:
      
       
       __pointer(::windowing_ios::window) m_pwindow;
      
      text_editor_interface();
      ~text_editor_interface() override;
      
      
      void set_input_method_manager_selection(strsize iStart, strsize iEnd) override;
      void set_input_method_manager_candidate_position(strsize iStart, strsize iEnd) override;
      void synchronize_input_method_manager_with_selection_end() override;


      void set_editor_selection(strsize iStart, strsize iEnd) override;
      void set_editor_text(const ::string & strText) override;
      void show_software_keyboard() override;
      void hide_software_keyboard() override;

      
   };


} // namespace windowing_ios
