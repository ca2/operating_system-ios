// Created by camilo on 2022-05-08 18:27 <3ThomasBorregaardS�rensen!!(All around what Thomas Likes 25!!)
// Adapted to ios by camilo on 2022-05-30 09:01 <3ThomasBS!!
#include "framework.h"
#include "message_box.h"


int ui_MessageBoxA(const char * pszMessageParam, const char * pszHeaderParam,  unsigned int uType, const char * pszDetails, ::function < void (enum_dialog_result) > function);


CLASS_DECL_ACME class ::system * get_system();

namespace windowing_ios
{


   void message_box::do_message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox, const ::string & strDetails)
   {


      m_strMessage = strMessage;

      m_strTitle = strTitle;
      
      m_strDetails = strDetails;

      m_emessagebox = emessagebox;
       
      ui_MessageBoxA(m_strMessage, m_strTitle, (unsigned int) m_emessagebox,
                     m_strDetails,
                                     [this](enum_dialog_result eresult)
                                     {
           
           m_atomResult = eresult;
           
           m_psequence->on_sequence();
           
       });

   }


   ::string message_box::get_message_box_message()
   {

      return m_strMessage;

   }


   ::string message_box::get_message_box_title()
   {

      return m_strTitle;
      
   }


   ::e_message_box message_box::get_message_box_flags()
   {

      return m_emessagebox;

   }


   ::string message_box::get_message_box_details()
   {

      return m_strDetails;

   }

__pointer(::conversation) node::create_new_message_box_conversation()
   {

      return __new(class message_box());

   }



} // namespace windowing_android



