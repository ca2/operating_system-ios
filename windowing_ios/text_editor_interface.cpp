//
//  text_editor_interface.cpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/06/22. 21:45
//
#include "framework.h"
#include "window.h"
#include "text_editor_interface.h"
//#include "aura/user/user/interaction_impl.h"


namespace windowing_ios
{


   text_editor_interface::text_editor_interface()
   {
      
      
   }


   text_editor_interface::~text_editor_interface()
   {


   }


   void text_editor_interface::set_input_method_manager_selection(character_count iBeg, character_count iEnd, character_count iCandidateStart, character_count iCandidateEnd)
   {
      

   }


//   void text_editor_interface::set_input_method_manager_candidate_position(character_count iStart, character_count iEnd)
//   {
//
//   }


   void text_editor_interface::synchronize_input_method_manager_with_selection_end()
   {


   }


   void text_editor_interface::set_editor_selection(character_count iBeg, character_count iEnd)
   {

      auto pwindow = m_pwindow;
      
      if(pwindow)
      {
         
         auto len = pwindow->ios_window_get_text_length();
         
         ::string str;
         
         auto psz = str.get_buffer(len);
         
         pwindow->ios_window_get_text(psz, len);
         
         str.release_buffer(len);
////         
////         wstring wstr(str);
         
         auto iUnicodeBeg = ansi_to_wd32_len(str, iBeg);
         
         auto iUnicodeEnd = ansi_to_wd32_len(str, iEnd);
         
         pwindow->ios_window_set_sel(iUnicodeBeg, iUnicodeEnd);
          
      }

   }


   void text_editor_interface::set_editor_text(const ::scoped_string& strText)
   {

      auto pwindow = m_pwindow;
      
      if(pwindow)
      {
         
         pwindow->ios_window_set_text(strText);
          
      }

   }


   void text_editor_interface::show_software_keyboard()
   {
       
       auto pwindow = m_pwindow;
       
       if(pwindow)
       {
           
//           auto puserinteractionimpl = pwindow->m_puserinteractionimpl;
//           
//           if(puserinteractionimpl)
           {
               
               auto puserinteraction = pwindow->m_pacmeuserinteractionKeyboardFocus;
               
               if(puserinteraction)
               {
                   
                   auto rectangle = puserinteraction->get_window_rectangle();
                  
                   string strText;
                   
                   strText = puserinteraction->get_text();
                   
                   character_count iSelBeg = 0;
                   
                   character_count iSelEnd = 0;
                   
                   puserinteraction->get_text_selection(iSelBeg,iSelEnd);
                  
                  auto iUnicodeBeg = ansi_to_wd32_len(strText, iSelBeg);
                  
                  auto iUnicodeEnd = ansi_to_wd32_len(strText, iSelEnd);
                   
                   pwindow->ios_window_edit_on_set_focus(rectangle.left, rectangle.top, rectangle.right,
                                                         rectangle.bottom,
                          strText,       iUnicodeBeg,
                                                         iUnicodeEnd);
//
               }
               
           }
           
           
       }

//       m_pwindow->m_puserinteractionimpl->m_puserinteractionKeyboardFocus;
       

   }


   void text_editor_interface::hide_software_keyboard()
   {
          
       auto pwindow = m_pwindow;
       
       if(pwindow)
       {
           
//           auto puserinteractionimpl = pwindow->m_puserinteractionimpl;
//           
//           if(puserinteractionimpl)
           {
               
               auto puserinteraction = pwindow->m_pacmeuserinteractionKeyboardFocus;
               
               if(!puserinteraction)
               {
                   
                   pwindow->ios_window_edit_on_kill_focus();
//
               }
               
           }
           
           
       }

   //       m_pwindow->m_puserinteractionimpl->m_puserinteractionKeyboardFocus;
          



   }


} // namespace windowing_ios



