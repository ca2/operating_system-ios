//
//  text_editor_interface.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/06/22. 21:43
//
#pragma once


#include "aura/windowing/text_editor_interface.h"


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_IOS text_editor_interface :
      virtual public ::windowing::text_editor_interface
   {
   public:
      
       
       ::pointer < ::windowing_ios::window > m_pwindow;
      
      text_editor_interface();
      ~text_editor_interface() override;
      
      
      void set_input_method_manager_selection(character_count iSelBeg, character_count iSelEnd, character_count iCandidateBeg, character_count iCandidateEnd) override;
//      void set_input_method_manager_candidate_position(character_count iStart, character_count iEnd) override;
      void synchronize_input_method_manager_with_selection_end() override;


      void set_editor_selection(character_count iStart, character_count iEnd) override;
      void set_editor_text(const ::string & strText) override;
      void show_software_keyboard() override;
      void hide_software_keyboard() override;

      
   };


} // namespace windowing_ios
