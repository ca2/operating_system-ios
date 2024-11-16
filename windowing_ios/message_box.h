// Created by camilo on 2022-05-08 18:26 <3ThomasBorregaardSørensen!!(All around what Thomas Likes 25!!)
// Adapted to ios by camilo on 2022-05-30 09:01 <3ThomasBS!!
#pragma once


#include "acme/user/user/message_box.h"


namespace windowing_ios
{


   class CLASS_DECL_AURA message_box :
      virtual public ::acme::user::message_box
   {
   public:

      void * m_pUIAlertController;
//      string                  m_strMessage;
//      string                  m_strTitle;
//      e_message_box           m_emessagebox;
//      string                  m_strDetails;

      //void do_asynchronously() override;
//      void do_conversation(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox, const ::string & strDetails) override;
//
//      ::string get_conversation_message() override;
//      ::string get_conversation_title() override;
//      ::e_message_box get_conversation_flags() override;
//      ::string get_conversation_details() override;
      void on_realize(::message_box * pmessagebox) override;


      void add_button(const ::scoped_string & scopedstrText, enum_dialog_result edialogresult, char chLetter) override;
      
      
      void run() override;
      
      


   };


} // namespace windowing_android



