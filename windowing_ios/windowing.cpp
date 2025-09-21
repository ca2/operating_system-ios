//
//  windowing.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-21 02:00 <3ThomasBS_!!
//  From windowing_macos on 2022-05-11 02:19 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "windowing.h"
#include "window.h"
#include "text_editor_interface.h"
#include "host_interaction.h"
#include "aura/windowing/display.h"
#include "message_box.h"


char * ns_aura_application_delegate_class();
//bool macos_get_cursor_position(INT_POINT * ppointCursor);

void ns_main_send(dispatch_block_t block);
void ns_main_post(dispatch_block_t block);


//void * ns_get_key_window();


namespace windowing_ios
{


   windowing::windowing()
   {
      
      //m_pWindowing4 = this;
      
   }


   windowing::~windowing()
   {
   
   }


   void windowing::initialize(::particle * pparticle)
   {
   
      //auto estatus =
      
      ::windowing::windowing::initialize(pparticle);
      
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      estatus =
      
      //øconstruct(m_pdisplay);
      

      øconstruct_new(m_ptexteditorinterface);

      
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
      
      //m_pdisplay->m_pwindowing = this;
         
      //return estatus;
      
   }


void windowing::initialize_windowing()
{
    
    ::uikit::acme::windowing::windowing::initialize_windowing();
    
}


   ::windowing::text_editor_interface * windowing::get_text_editor_interface()
   {
       
       if(!m_pwindowKeyboardFocus)
       {
           
           return nullptr;
           
       }
       
       if(m_ptexteditorinterface)
       {
           
           m_ptexteditorinterface->m_pwindow = m_pwindowKeyboardFocus;
           
       }
       
       return m_ptexteditorinterface;

   }

void windowing::clear_active_window(::thread *, ::windowing::window *)
{

   

}
   void windowing::defer_initialize_host_window(const ::int_rectangle* lpcrect)
   {
      ::sandbox_windowing::windowing::defer_initialize_host_window(lpcrect);
//      if(::is_set(m_pwindowApplicationHost))
//      {
//         
//         return;
//         
//      }
//      
//      øconstruct(m_phostinteraction);
//      
//      m_phostinteraction->create_host();
//      
//      m_phostinteraction->display();
//      
//      m_phostinteraction->set_need_layout();
//      
//      m_phostinteraction->set_need_redraw();
//      
//      m_phostinteraction->post_redraw();
//      
//      m_pwindowApplicationHost = m_phostinteraction->window();

   }


   ::acme::windowing::window * windowing::get_application_host_window()
   {
      return ::sandbox_windowing::windowing::get_application_host_window();
      //return m_pwindowApplicationHost;

   }


//   ::windowing::window *windowing::new_window(::user::interaction_impl *pimpl)
//   {
//
//      auto pwindow = øcreate < ::windowing::window >();
//      
//      pwindow->create_window(pimpl);
//
//      return pwindow;
//
//   }


   void windowing::os_menu_item_enable(void * pitem, bool bEnable)
   {
    
      //::os_menu_item_enable(pitem, bEnable);
      
   }


   void windowing::os_menu_item_check(void * pitem, bool bCheck)
   {

      //::os_menu_item_check(pitem, bCheck);
      
   }


   void windowing::defer_create_main_menu(const string_array & straMenuParent, const string_array & straMenuName, const string_array & straMenuId)
   {
   //
   //      auto pmenushared =
   //         create_menu_shared(
   //
   //                            straMenuParent,
   //                            straMenuName,
   //                            straMenuId
   //
   //                            );
   //
   //      ns_create_main_menu(pmenushared);
   //
      //return success;
      
   }


   ::pointer < ::windowing::cursor > windowing::get_cursor(enum_cursor ecursor)
   {
   
      return nullptr;
      
   }

//
//   void windowing::windowing_post(const ::procedure & procedure)
//   {
//      
//      auto routineLocal = procedure;
//
//      ns_main_post(^
//                    {
//         
//         routineLocal();
//         
//      });
//      
//      //return success;
//
//   }
//


   ::acme::windowing::window * windowing::window(oswindow oswindow)
   {

      return oswindow;

   }


   ::windowing::display * windowing::display()
   {
      
      if(!m_pdisplay)
      {
         
         m_pdisplay = acme_display();
         
      }

      return m_pdisplay;

   }


void windowing::windowing_application_main_loop() 
{
 
    ::uikit::acme::windowing::windowing::windowing_application_main_loop();
    
}


void windowing::windowing_post_quit()
{
    
    ::uikit::acme::windowing::windowing::windowing_post_quit();

    
}



//   ::windowing::window * windowing::get_active_window(::thread * pthread)
//   {
//      
//      return nullptr;
//      
//   }


//   void windowing::release_mouse_capture()
//   {
//
//      auto pwindowCapture = m_pwindowCapture;
//
//      m_pwindowCapture.release();
//
//      if(pwindowCapture)
//      {
//
//         pwindowCapture->m_puserinteractionimpl->m_puserinteraction->m_pinteractionimpl->m_puserinteractionMouseCapture.release();
//
//      }
//
//      //return ::success;
//
//   }


//   bool windowing::post_ui_message(const MESSAGE &message)
//   {
//
//      oswindow oswindow = message.oswindow;
//
//      ASSERT(oswindow != nullptr);
//
//      auto pimpl = oswindow->m_pimpl;
//
//      if(::is_null(pimpl))
//      {
//
//         return false;
//
//      }
//
//      auto pinteraction = pimpl->m_puserinteraction;
//
//      if(::is_null(pinteraction))
//      {
//
//         return false;
//
//      }
//
//      ::thread *pthread = nullptr;
//
//      if (::is_set(pinteraction))
//      {
//
//         pthread = pinteraction->m_pthreadUserInteraction;
//
//      }
//
//      if (::is_null(pthread))
//      {
//
//         return false;
//
//      }
//
//      class ::message_queue *pmq = pthread->m_pmq;
//
//      if (pmq == nullptr)
//      {
//
//         if (message.m_id == e_message_quit)
//         {
//
//            return false;
//
//         }
//
//         pmq = pthread->get_message_queue();
//
//      }
//
//      if (pmq == nullptr)
//      {
//
//         return false;
//
//      }
//
//      synchronous_lock ml(pmq->mutex());
//
//      if (message.m_id == e_message_quit)
//      {
//
//         output_debug_string("e_message_quit thread");
//
//      }
//
//      if (message.m_id == e_message_left_button_down)
//      {
//
//         output_debug_string("post_ui_message::e_message_left_button_down\n");
//
//      }
//      else if (message.m_id == e_message_left_button_up)
//      {
//
//         output_debug_string("post_ui_message::e_message_left_button_up\n");
//
//      }
//
//      pmq->m_messagea.add(message);
//
//      pmq->m_eventNewMessage.set_event();
//
//      return true;
//
//   }


//   ::windowing::window * windowing::get_keyboard_focus(::thread *)
//   {
//
////      void * pnswindow = ns_get_key_window();
////
////      if(::is_null(pnswindow))
////      {
////
////         return nullptr;
////
////      }
////
////      auto pwindowFocus = m_nsmap[pnswindow];
////
////      return pwindowFocus;
//
//      return nullptr;
//
//   }


   void windowing::_defer_dock_application(int_bool bDock)
   {

//      if (bDock)
//      {
//   
//         //if (!nsapp_activation_policy_is_regular())
//         {
//   
//            nsapp_activation_policy_regular();
//            
//            ns_main_post(^()
//                          {
//
//            ProcessSerialNumber psn = { 0, kCurrentProcess };
//            
//            TransformProcessType(&psn, kProcessTransformToForegiosApplication);
//               
//            });
//         }
//   
//      }
//      else
//      {
//   
//         //if (!nsapp_activation_policy_is_accessory())
//         {
//   
//            nsapp_activation_policy_accessory();
//            
//            ns_main_post(^()
//                          {
//            //hide icon on Dock
//            ProcessSerialNumber psn = { 0, kCurrentProcess };
//            TransformProcessType(&psn, kProcessTransformToUIElementApplication);
//               
//            });
//   
//         }
//   
//      }

   }


//   void windowing::clear_keyboard_focus(::windowing::window* pwindowGainingFocusIfAny)
//   {
//
//      if (!m_pwindowKeyboardFocus)
//      {
//
//         return;
//
//      }
//
//      auto puserinteractionimpl = m_pwindowKeyboardFocus->m_puserinteractionimpl;
//
//      if (puserinteractionimpl)
//      {
//
//         if (puserinteractionimpl->m_puserinteractionKeyboardFocus)
//         {
//
//            puserinteractionimpl->m_puserinteractionKeyboardGainingFocusIfAny = pwindowGainingFocusIfAny;
//
//            //puserinteractionimpl->m_puserinteractionKeyboardFocus->post_message(e_message_kill_focus);
//
//         }
//
//         auto puserinteraction = puserinteractionimpl->m_puserinteraction;
//
//         if (puserinteraction)
//         {
//
//            puserinteraction->post_message(e_message_kill_focus);
//
//         }
//
//         //if (puserinteractionimpl->m_puserinteractionKeyboardFocus)
//         //{
//
//         //   puserinteractionimpl->m_puserinteractionKeyboardGainingFocusIfAny = pwindowGainingFocusIfAny;
//
//         //   puserinteractionimpl->m_puserinteractionKeyboardFocus->post_message(e_message_kill_focus);
//
//         //}
//
//         puserinteractionimpl->m_puserinteractionKeyboardFocus.release();
//
//      }
//
//      m_pwindowKeyboardFocus.release();
//
//      //auto estatus =
//      //
//      //m_pdisplay->release_mouse_capture();
//
//      //      if(!estatus)
//      //      {
//      //
//      //         return estatus;
//      //
//      //      }
//      //
//      //      return estatus;
//
//   }
   

void windowing::_user_send(const ::procedure & procedure)
{

   __block auto p = procedure;

   ns_main_send(^{
      
      p();
      
   });
}


   void windowing::_user_post(const ::procedure & procedure)
{
      
      __block auto p = procedure;

      ns_main_post(^{
         
         p();
         
      });

}


bool windowing::defer_realize(         ::pointer < ::reified < ::message_box > > & preifiedMessageBox, ::message_box * pmessagebox)
{
   
   return ::uikit::acme::windowing::windowing::defer_realize(preifiedMessageBox,pmessagebox);
//
  // preifiedMessageBox = øallocate ::windowing_ios::message_box;
   
   //preifiedMessageBox->on_realize(pmessagebox);
   
   //return true;
   
}


::string windowing::_ns_application_delegate_class()
{
    
    return ::string_from_strdup(ns_aura_application_delegate_class());
    
}


} // namespace windowing_ios



