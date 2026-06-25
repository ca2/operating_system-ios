//
// Created by camilo on 31/01/2022 15:37 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "window.h"
#include "windowing.h"
#include "acme_window_bridge.h"
#include "acme/nano/graphics/context.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "acme/platform/application.h"
#include "acme/platform/node.h"
#include "acme/user/micro/elemental.h"
#include "acme/user/user/mouse.h"
#include "acme/windowing/windowing.h"
#include "acme_window_bridge.h"
#include <CoreGraphics/CoreGraphics.h>

void ns_main_post(dispatch_block_t block);

bool ns_app_is_running();

void ns_app_run();

void ns_app_stop();

CLASS_DECL_ACME void ns_get_main_screen_size(int & cx, int & cy);

void screen_coordinates_aware_copy(CGRect & rect, const ::i32_rectangle &rectangle);

void screen_coordinates_aware_copy(CGPoint & cgpoint, const ::i32_point & point);

void screen_coordinates_aware_copy(::i32_point & point, const CGPoint & cgpoint);

//void macos_defer_initialize_nano_callbacks();
namespace uikit
{


   namespace acme
   {


      namespace windowing
   {
      
      
      window::window()
      {
         
         m_bIsActiveCached = false;
         //macos_defer_initialize_nano_callbacks();
         
      }
      
      
      window::~window()
      {
         
         //delete_drawing_objects();
         
         m_pnanographicscontext.release();
         
      }
      
      
#ifdef _DEBUG
      
      
      ::i64 window::increment_reference_count()
      {
         
         return ::acme::windowing::window::increment_reference_count();
         
      }
      
      
      ::i64 window::decrement_reference_count()
      {
         
         return ::acme::windowing::window::decrement_reference_count();
         
      }
      
      
      ::i64 window::release()
      {
         
         return ::acme::windowing::window::release();
         
      }
      
      
#endif
      
      
      void window::on_initialize_particle()
      {
         
         ::acme::windowing::window::on_initialize_particle();
         
      }
      
      
      //   void window::on_char(int iChar)
      //   {
      //
      //      m_pinterface->on_char(iChar);
      //
      //   }
      
      
      void window::_draw_background(CGContextRef cgcontextref)
      {
         
         {
            
            //nano()->graphics();
            
            constructø(m_pnanographicscontext);
            
            m_pnanographicscontext->attach(cgcontextref, m_sizeWindow, 0);
            
            ::pointer < ::micro::elemental > pelemental;
            
            pelemental = m_pacmeuserinteraction;
            
            if (pelemental)
            {
               
               pelemental->draw_background(m_pnanographicscontext);
               
            }
            
         }
         //m_pinterface->draw(pnanodevice);
         
      }

      void window::_draw_foreground(CGContextRef cgcontextref)
      {
         
         {
            
            //nano()->graphics();
            
            constructø(m_pnanographicscontext);
            
            m_pnanographicscontext->attach(cgcontextref, m_sizeWindow, 0);
            
            ::pointer < ::micro::elemental > pelemental;
            
            pelemental = m_pacmeuserinteraction;
            
            if (pelemental)
            {
               
               pelemental->draw_foreground(m_pnanographicscontext);
               
            }
            
         }
         //m_pinterface->draw(pnanodevice);
         
      }

      
      bool window::is_active_window()
      {
         
         //return m_pacmewindowbridge->is_active();
         return true;
         
      }
      
      
      //   void window::delete_drawing_objects()
      //   {
      //
      //      m_pinterface->delete_drawing_objects();
      //
      //   }
      
      
      //   bool window::get_dark_mode()
      //   {
      //
      //      return system()->dark_mode();
      //
      //   }
      
      
      //   void window::create_drawing_objects()
      //   {
      //
      //      m_pinterface->create_drawing_objects();
      //
      //   }
      
      
      //   void window::update_drawing_objects()
      //   {
      //
      //      m_pinterface->update_drawing_objects();
      //
      //   }
      
      
      void window::create_window()
      {
         
         main_send([this]()
                   {
            
            _create_window();
            
         });
         
      }
      
      
      ::particle * window::get_acme_window_bridge()
      {
         
         if(!m_pacmewindowbridge)
         {
            
            m_pacmewindowbridge = allocateø acme_window_bridge();
            
         }
         
         return m_pacmewindowbridge;
         
      }
      
      
      void window::_create_window()
      {
         
         //acme_window_bridging();
         
         CGRect cgrect;
         
         auto rectangle = m_pacmeuserinteraction->get_rectangle();
         
         screen_coordinates_aware_copy(cgrect, rectangle);
         
         ::cast < ::uikit::acme_window_bridge> pacmewindowbridge = get_acme_window_bridge();
         pacmewindowbridge->m_papplekitacmewindowingwindow = this;
         pacmewindowbridge->m_puikitacmewindowingwindow = this;

         m_pacmewindowbridge->attach_ns_acme_window(cgrect);
         
         if(!system()->acme_windowing()->get_application_host_window())
         {
            
            ::cast < ::uikit::acme::windowing::windowing > pwindowing = system()->acme_windowing();
            
            pwindowing->m_pwindowApplicationHost = this;
         }
         
         //nano_window_on_create();
         
         //create_drawing_objects();
         
         ///on_create();
         
      }
      
      
      void window::handle(::topic * ptopic, ::handler_context * phandlercontext)
      {
         
         if (ptopic->m_atomMatterId == id_set_application_dark_mode)
         {
            
            //update_drawing_objects();
            //m_pimplementation->handle(ptopic, pcontext);
            redraw();
            
         }
         
      }
      
      
      //   void window::on_left_button_down(::user::mouse * pmouse)
      //   {
      //
      //      m_pacmeuserinteraction->on_left_button_down(pmouse);
      //
      //   }
      //
      //
      //   void window::on_left_button_up(::user::mouse * pmouse)
      //   {
      //
      //      m_pacmeuserinteraction->on_left_button_up(pmouse);
      //
      //   }
      //
      //
      //   void window::on_right_button_down(::user::mouse * pmouse)
      //   {
      //
      //      m_pacmeuserinteraction->on_right_button_down(pmouse);
      //
      //   }
      //
      //
      //   void window::on_right_button_up(::user::mouse * pmouse)
      //   {
      //
      //      m_pacmeuserinteraction->on_right_button_up(pmouse);
      //
      //   }
      //
      //
      //   void window::on_mouse_move(::user::mouse * pmouse)
      //   {
      //
      //      m_pacmeuserinteraction->on_mouse_move(pmouse);
      //
      //   }
      //
      //
      //   ::payload window::get_result()
      //   {
      //
      //      return m_pacmeuserinteraction->get_result();
      //
      //   }
      //
      //
      //   ::nano::user::child * window::hit_test(::user::mouse * pmouse, ::user::e_zorder ezorder)
      //   {
      //
      //      return m_pacmeuserinteraction->hit_test(pmouse, ezorder);
      //
      //   }
      
      
      void window::show_window(::user_interface::enum_show_window eshowwindow)
      {
         
         if(eshowwindow == user_interface::e_show_window_hide)
         {
            
            m_pacmewindowbridge->ns_hide();

         }
         else
         {
            
            set_active_window();
            
            m_pacmewindowbridge->ns_show();
            
         }
         
      }
      
      
      void window::set_active_window()
      {
         
         //m_pacmewindowbridge->set
         
      }
      
      
      void window::main_post(const ::procedure & procedure)
      {
         
         system()->acme_windowing()->main_post(procedure);
         
      }
      
      
      void window::_update_window()
      {
         
         if(!m_pacmewindowbridge)
         {
            
            return;
            
         }
         
         m_pacmewindowbridge->redraw();
         
      }
      
      
      bool window::message_loop_step()
      {
         
         return false;
         
      }
      
      
      //   void window::message_loop()
      //   {
      //
      // ///     while(aaa_message_loop_step())
      //    //  {
      //
      //      //}
      //
      //      ns_main_post(^()
      //                    {
      //
      //         m_pacmewindowbridge->_run_modal_loop();
      //
      //      });
      //
      //
      //   }
      
      
      void window::redraw()
      {
         
         _update_window();
         
      }
      
      
      void window::destroy_window()
      {
         
         m_pacmewindowbridge->close();
         
         nano_window_on_destroy();
         
      }
      
      
      //
      //   void window::on_click(const ::payload & payload, ::user::mouse * pmouse)
      //   {
      //
      //      m_pinterface->on_click(payload, pmouse);
      //
      //   }
      //
      //
      //   void window::on_right_click(const ::payload & payload, ::user::mouse * pmouse)
      //   {
      //
      //      m_pinterface->on_right_click(payload, pmouse);
      //
      //   }
      
      
      void window::set_position_unlocked(const ::i32_point & point)
      {
         
         m_pacmewindowbridge->set_position(point.x, point.y);
         
      }
      
      
      void window::set_mouse_capture()
      {
         
      }
      
      
      void window::release_mouse_capture()
      {
         
      }
      
      
      ::i32_rectangle window::get_window_rectangle_unlocked()
      {
         
         auto cgrect = m_pacmewindowbridge->get_frame();
         ::i32_rectangle r;
         copy(r, cgrect);
         return r;
         
      }
      
      //
      //   void window::get_window_rectangle(::i32_rectangle & rectangle)
      //   {
      //
      //   }
      
      
      ::payload window::wait_for_dialog_response(const class ::time & timeTimeout)
      {
         
         m_pacmewindowbridge->_run_modal_loop();
         
         ::pointer < ::micro::elemental > pelemental;
         
         pelemental = m_pacmeuserinteraction;
         
         if (pelemental)
         {
            
            return pelemental->get_dialog_response();
            
         }
         
         return {};
         
      }
      
      
      //   ::i32_size window::get_main_screen_size()
      //   {
      //
      //      int cx = 800;
      //
      //      int cy = 600;
      //
      //      ns_get_main_screen_size(cx, cy);
      //
      //      return { cx, cy };
      //
      //   }
      
      
      ::payload window::do_synchronously()
      {
         
         //      if(ns_app_is_running())
         //      {
         //
         //         return ::nano::user::window_implementation::do_synchronously();
         //
         //      }
         //
         //      atom atomResult;
         //
         //      m_pinterface->m_psequencer->then([ &atomResult ](auto psequence)
         //      {
         //
         //         atomResult = psequence->m_payloadResult;
         //
         //         ns_app_stop();
         //
         //      });
         //
         //      ns_app_run();
         //
         //      //   auto pmessagebox = pparticle->create_newø < ::nano::user::message_box >();
         //      //
         //      //   atom idResult;
         //      //
         //      //   manual_reset_happening event;
         //      //
         //      //   pmessagebox->display(pszMessage, pszTitle, emessagebox, pszDetails);
         //      //
         //      //   pmessagebox->m_functionClose = [&idResult, &event](window * pwindow)
         //      //   {
         //      //
         //      //      idResult = pwindow->m_atomResult;
         //      //
         //      //      event.set_happening();
         //      //
         //      //   };
         //      //
         //      //   if(is_single_main_user_thread() && is_main_thread())
         //      //   {
         //      //
         //      //      pmessagebox->_run_modal_loop();
         //      //
         //      //   }
         //      //   else
         //      //   {
         //      //      event.wait();
         //      //
         //      //   }
         //      //
         //      //   //auto idResult = pmessagebox->get_result();
         //      //
         //      //   return idResult;
         //
         //      return atomResult;
         return {};
         
         
      }
      
      
      void window::ios_window_become_main()
      {
         
         application()->application_menu_update();
         
      }
      
      
      void window::ios_window_resign_main()
      {
         
         
      }
      
      
      void window::ios_window_become_key()
      {
         
         m_bIsActiveCached = true;
         //application()->application_menu_update();
         
      }
      
      

      
      void window::ios_window_resign_key()
      {
         m_bIsActiveCached = false;
         
      }
      
      
      void window::ios_window_on_show()
      {
         
         
      }


      void window::ios_window_on_hide()
      {
         
         //application()->application_menu_update();
         
      }
      
      } //namespace windowing


   } //namespace acme


} // namespace uikit



