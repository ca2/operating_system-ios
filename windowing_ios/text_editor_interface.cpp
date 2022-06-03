//
//  text_editor_interface.cpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/06/22. 21:45
//
#include "framework.h"


namespace windowing_ios
{


   text_editor_interface::text_editor_interface()
   {
      
      
   }


   text_editor_interface::~text_editor_interface()
   {


   }


   void text_editor_interface::set_input_method_manager_selection(strsize iStart, strsize iEnd)
   {

   }


   void text_editor_interface::set_input_method_manager_candidate_position(strsize iStart, strsize iEnd)
   {

   }


   void text_editor_interface::synchronize_input_method_manager_with_selection_end()
   {


   }


   void text_editor_interface::set_editor_selection(strsize iStart, strsize iEnd)
   {


   }


   void text_editor_interface::set_editor_text(const ::string& strText)
   {


   }


   void text_editor_interface::show_software_keyboard()
   {
       
       auto pwindow = m_pwindow;
       
       if(pwindow)
       {
           
           auto puserinteractionimpl = pwindow->m_puserinteractionimpl;
           
           if(puserinteractionimpl)
           {
               
               auto puserinteraction = puserinteractionimpl->m_puserinteractionKeyboardFocus;
               
               if(puserinteraction)
               {
                   
                   auto rectangle = puserinteraction->get_window_rect();
                   string strText;
                   
                   puserinteraction->_001GetText(strText);
                   
                   strsize iSelBeg = 0;
                   
                   strsize iSelEnd = 0;
                   
                   puserinteraction->_001GetSel(iSelBeg,iSelEnd);
                   
                   pwindow->ios_window_edit_on_set_focus(rectangle.left, rectangle.top, rectangle.right,
                                                         rectangle.bottom,
                          strText,       iSelBeg,
                                                         iSelEnd);
//
               }
               
           }
           
           
       }

//       m_pwindow->m_puserinteractionimpl->m_puserinteractionKeyboardFocus;
       

   }


   void text_editor_interface::hide_software_keyboard()
   {


   }


} // namespace windowing_ios



