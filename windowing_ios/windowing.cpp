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


//bool macos_get_cursor_position(POINT_I32 * ppointCursor);


void ns_main_async(dispatch_block_t block);


//void * ns_get_key_window();


namespace windowing_ios
{


   windowing::windowing()
   {
      
      m_pWindowing4 = this;
      
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
      
      __construct(m_pdisplay);
      

      __construct_new(m_ptexteditorinterface);

      
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
      
      m_pdisplay->m_pwindowing = this;
         
      //return estatus;
      
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


   void windowing::defer_initialize_host_window(const RECTANGLE_I32* lpcrect)
   {
      
      if(::is_set(m_pwindowApplicationHost))
      {
         
         return;
         
      }
      
      __construct(m_phostinteraction);
      
      m_phostinteraction->create_host();
      
      m_phostinteraction->display();
      
//      m_phostinteraction->set_need_layout();
//      
//      m_phostinteraction->set_need_redraw();
//      
//      m_phostinteraction->post_redraw();
      
      m_pwindowApplicationHost = m_phostinteraction->window();

   }


   ::windowing::window * windowing::get_application_host_window()
   {

      return m_pwindowApplicationHost;

   }


   ::windowing::window *windowing::new_window(::user::interaction_impl *pimpl)
   {

      auto pwindow = __create < ::windowing::window >();
      
      pwindow->create_window(pimpl);

      return pwindow;

   }


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
//      ns_main_async(^
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

   ::windowing::window * windowing::window(oswindow oswindow)
   {

      return oswindow;

   }


   ::windowing::display * windowing::display()
   {

      return m_pdisplay;

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
//            ns_main_async(^()
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
//            ns_main_async(^()
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


} // namespace windowing_ios



