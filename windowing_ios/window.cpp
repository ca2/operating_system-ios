//
//  ios_window.cpp
//  aura
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2013-09-17.
//  From windowing_macos on 2022-05-11 02:15 <3ThomasBorregaardSorensen!!
//
//

#include "framework.h"
#include "window.h"
#include "window_impl.h"
#include "windowing.h"
#include "acme/constant/message.h"
#include "acme/constant/user.h"
#include "acme/filesystem/filesystem/file_system_options.h"
#include "acme/user/micro/elemental.h"
#include "aqua/multimedia/media_item_picker.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aura/graphics/graphics/graphics.h"
#include "aura/graphics/image/drawing.h"
#include "aura/graphics/image/image.h"
#include "aura/graphics/image/source.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/prototype/collection/string_array.h"
#include "acme/prototype/collection/str_array.h"
#include "aqua/multimedia/media_item_picker_callback.h"
#include "aqua/platform/application.h"
#include "aura/platform/session.h"
#include "aura/user/user/interaction_graphics_thread.h"
#include "aura/user/user/interaction_thread.h"
//#include "aura/user/user/interaction_impl.h"
#include "aura/user/user/user.h"
#include "acme/constant/user_key.h"
#include "acme/operating_system/_.h"
#include "acme/parallelization/message_queue.h"
#include "aura/message/user.h"
#include <CoreGraphics/CoreGraphics.h>

string_array string_array_from_strdup_count(const char ** pszaUrl, long lCount);


void ns_main_post(dispatch_block_t block);

void ns_set_cursor(void * pNSCursor);
void * ns_get_cursor();

double get_status_bar_frame_height();

#define WHEEL_DELTA 120
//#define EXTRALOG
//void * new_ios_window(ios_window * papexwindow, CGRect rect, unsigned int uStyle);


void ns_main_post(dispatch_block_t block);


void ns_main_send(dispatch_block_t block);

namespace windowing_ios
{


   window::window()
   {
      
      //m_pWindow4 = this;
      //m_pioswindowing = nullptr;
      m_pNSCursorLast = nullptr;
      m_pwindowCapture = nullptr;
      
   }


   window::~window()
   {
      
      
   }


#ifdef _DEBUG


long long window::increment_reference_count()
{
    
    return ::uikit::acme::windowing::window::increment_reference_count();
    
}


long long window::decrement_reference_count()
{
    return ::uikit::acme::windowing::window::decrement_reference_count();
}


long long window::release()
{
    return ::uikit::acme::windowing::window::release();
}


#endif

void window::on_initialize_particle()
{

    ::sandbox_windowing::window::on_initialize_particle();
    
    ::uikit::acme::windowing::window::on_initialize_particle();
    
}


   void window::on_message_create(::message::message * pmessage)
   {
      
      
      
   }


   void window::on_message_destroy(::message::message * pmessage)
   {
      
      ns_main_send(^{
         
         
         ::ios_window::ios_window_hide();
         
         ::ios_window::ios_window_destroy();
         
         
      });
      
      
   }


   void window::install_message_routing(channel * pchannel)
   {

      ::windowing::window::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &window::on_message_create);

      //auto puserinteraction = user_interaction();

//      auto pimpl = m_puserinteractionimpl.m_p;
//
//      if (!puserinteraction->m_bMessageWindow)
//      {
//
//         //MESSAGE_LINK(e_message_redraw, pchannel, pimpl, &::user::interaction_impl::_001OnRedraw);
//         //MESSAGE_LINK(e_message_apply_visual, pchannel, pimpl, &::user::interaction_impl::_001OnApplyVisual);
//
//
//         //#ifndef LINUX
//         //MESSAGE_LINK(e_message_reposition, pchannel, this, &window::_001OnMove);
//         //MESSAGE_LINK(e_message_size, pchannel, this, &window::_001OnSize);
//         //#endif
//
//
//         //MESSAGE_LINK(e_message_show_window, pchannel, this, &window::_001OnShowWindow);
//         //MESSAGE_LINK(e_message_kill_focus, pchannel, this, &window::_001OnKillFocus);
//         //MESSAGE_LINK(e_message_set_focus, pchannel, this, &window::_001OnSetFocus);
//         //MESSAGE_LINK(e_message_set_cursor, pchannel, this, &window::_001OnSetCursor);
//
//      }

      //MESSAGE_LINK(e_message_destroy_window, pchannel, pimpl, &::user::interaction_impl::_001OnDestroyWindow);

   //   MESSAGE_LINK(WM_ACTIVATE, pchannel, this, &window::_001OnActivate);
     // MESSAGE_LINK(WM_DWMNCRENDERINGCHANGED, pchannel, this, &window::_001OnDwmNcRenderingChanged);

      //pimpl->install_message_routing(pchannel);


      MESSAGE_LINK(e_message_destroy, pchannel, this, &window::on_message_destroy);

      //MESSAGE_LINK(e_message_create, pchannel, pimpl, &::user::interaction_impl::_001OnPrioCreate);

   }


   void window::create_window()
   {

      //if (::is_window(get_handle()))
      //{

      //   DestroyWindow();

      //}

      //      ASSERT(lpszClassName == nullptr || __is_valid_string(lpszClassName) ||
      //       __is_valid_atom(lpszClassName));
   //      ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || __is_valid_string(pusersystem->m_createstruct.lpszName));

      // allow modification of several common create parameters
      //::user::system createstruct;
      //      pusersystem->m_createstruct.hwndParent = hWndParent;
      //   pusersystem->m_createstruct.hMenu = hWndParent == nullptr ? nullptr : nIDorHMenu;

      auto puserinteraction = user_interaction();

      auto pusersystem = puserinteraction->m_pusersystem;

      //pusersystem->m_createstruct.hMenu = nullptr;
      //      pusersystem->m_createstruct.hInstance = ::aura::get_system()->m_hInstance;
      //pusersystem->m_createstruct.lpCreateParams = lpParam;

      if (!puserinteraction->pre_create_window(pusersystem))
      {

         //return false;
         
         throw ::exception(error_failed);

      }


      //hook_window_create(puserinteraction);

      //CGRect int_rectangle;

      //INT_RECTANGLE rectParam;

   //      rectParam.left = m_pusersystem->m_createstruct.x;
   //      rectParam.top = pusersystem->m_createstruct.y;
   //      rectParam.right = pusersystem->m_createstruct.x + pusersystem->m_createstruct.cx();
   //      rectParam.bottom = pusersystem->m_createstruct.y + pusersystem->m_createstruct.cy();

   //      copy(rectangle, rectParam);
   //
   //      if (pusersystem->m_createstruct.hwndParent == MESSAGE_WINDOW_PARENT)
   //      {
   //
   //         return true;
   //
   //      }
   //      else
   //      {

      
      install_message_routing(puserinteraction);

       _create_window();
       
         //puserinteraction->place(rectParam);

      //auto ptask = ::get_task();
      
      //puserinteraction->m_pthreadUserInteraction = ptask;
         
         //puserinteraction->place(rectParam);



         //oswindow_assign(m_oswindow, this);

      //}

      auto lresult = puserinteraction->send_message(e_message_create); //
      //, 0, //(lparam)&cs);

      bool bOk = true;

      //if (!unhook_window_create() || lresult == -1)
      if (lresult == -1)
      {

         bOk = false;

         set_finish();

         //children_post_quit();

         //children_wait_quit(one_minute());

         //PostNcDestroy();        // cleanup if CreateWindowEx fails too soon

         //return false;
         
         throw ::exception(::error_failed);

      }

      //if(pusersystem->m_createstruct.style & WS_VISIBLE)
      //if(pusersystem->m_.style & WS_VISIBLE)
      if(puserinteraction->const_layout().design().is_screen_visible())
      {

         puserinteraction->display();

         puserinteraction->set_need_redraw();

         puserinteraction->post_redraw();

         //;//ios_window_show();

      }

      puserinteraction->set_need_layout();

      puserinteraction->increment_reference_count();

      puserinteraction->m_ewindowflag |= e_window_flag_window_created;

      puserinteraction->post_message(e_message_pos_create);

      //return bOk;

   }
void window::acme_window_bridging()
{
   m_pacmewindowbridge = this;
}

void window::_create_window()
{
//    
//    unsigned uStyle = 0;
//
//    if(puserinteraction->m_ewindowflag & ::e_window_flag_miniaturizable)
//    {
//
//#define NSWindowStyleMaskMiniaturizable (1 << 2)
//
//       uStyle |= NSWindowStyleMaskMiniaturizable;
//
//    }
//
//
//    //__todo?
//    //windowing()->copy(cgrect, rectangle);
//    //or
//    //display()->copy(cgrect, rectangle);
//    //because rectangle origin is top-left
//    //and because cgrect origin is bottom-left and,
//    //the origin of screen is at bottom.
//
// //m_puserinteractionimpl = pimpl;
// 
//  //auto psession = m_pcontext->m_pacmesession->m_paurasession;
//
// //auto puser = psession->user();
//
////      auto pwindowing = (::windowing_ios::windowing *) puser->windowing()->m_pWindowing4;
//
// //m_pioswindowing = dynamic_cast < class ::windowing_ios::windowing * >(m_pwindowing.m_p);
//
////      m_pwindowing = pwindowing;
//
////      pimpl->m_pwindowing = pwindowing;
////
////      pimpl->m_pwindow = this;
////
////      pimpl->puserinteraction->m_pwindow = this;
// 
// //set_oswindow(this);
//
//
//    auto rectangle = puserinteraction-> window_rectangle();
//
//    CGRect cgrect;
//
//    copy(cgrect, rectangle);
//
//    
//    auto pNSWindow = new_ios_window(this, cgrect, uStyle);
//
//    set_os_data(pNSWindow);

   ::uikit::acme::windowing::window::_create_window();
 //ios_windowing()->m_nsmap[m_pnsacmewindow] = this;
 

}

   ::windowing_ios::windowing * window::ios_windowing()
   {
      
      auto pwindowing = ::windowing::window::windowing();
      
      auto pwindowingHere = dynamic_cast < class ::windowing_ios::windowing * >(pwindowing);
      
      return pwindowingHere;
      
   }


//   ::windowing_ios::windowing * window::ios_windowing()
//   {
//      
//      ::cast < ::windowing_ios::windowing > pioswindowing = system()->windowing();
//   
//      if(!pioswindowing)
//      {
//         
//         return nullptr;
//         
//      }
//      
//      return pioswindowing;
//      
//   }


   double window::get_top_margin()
   {
      
      return _get_status_bar_frame_height();
      
   }





   //// for child windows
   //bool interaction_impl::pre_create_window(::user::system * pusersystem)
   //{
   //   /*      if (pusersystem->m_createstruct.lpszClass == nullptr)
   //    {
   ///xcore/app/aura/node/macos/ios_interaction_impl.cpp:712:44: No member named 'window_rectangle' in 'user::interaction_impl'       // make sure the default user::interaction class is registered
   //    VERIFY(__end_defer_register_class(__WND_REG, &pusersystem->m_createstruct.lpszClass));
   //
   //    // no WNDCLASS provided - use child user::interaction default
   //    ASSERT(pusersystem->m_createstruct.style & WS_CHILD);
   //    }*/
   //   return true;
   //}

//   void window::ios_window_add_ref()
//   {
//
//      increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_P_NOTE(this, "ios_window_add_ref"));
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      puserinteraction->increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_P_NOTE(this, "ios_window_add_ref"));
//
//   }
//
//
//   void window::ios_window_dec_ref()
//   {
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      puserinteraction->decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_P_NOTE(this, "ios_window_dec_ref"));
//
//      decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_P_NOTE(this, "ios_window_dec_ref"));
//
//   }


//   void window::set_keyboard_focus()
//   {
//      
//      auto pwindowing = windowing();
//
//      if (!pwindowing)
//      {
//
//         throw ::exception(error_wrong_state);
//
//      }
//
//      if (pwindowing->m_pwindowKeyboardFocus && pwindowing->m_pwindowKeyboardFocus != this)
//      {
//
//         pwindowing->clear_keyboard_focus(this);
//
//      }
//
//      pwindowing->m_pwindowKeyboardFocus = this;
//
//      auto puserinteractionimpl = m_puserinteractionimpl;
//
//      if (puserinteractionimpl)
//      {
//
//         puserinteractionimpl->on_final_set_keyboard_focus();
////         auto puserinteraction = puserinteractionimpl->m_puserinteraction;
////
////         if (puserinteraction)
////         {
////
////            puserinteraction->post_message(e_message_set_focus);
////
////         }
//
//      }
//
//      //if (Window() == 0)
//      //{
//
//      //   throw ::exception(error_failed);
//
//      //}
//
//      //windowing_output_debug_string("\noswindow_data::SetFocus 1");
//
//      //display_lock displaylock(x11_display()->Display());
//
//      //if (!is_window())
//      //{
//
//      //   windowing_output_debug_string("\noswindow_data::SetFocus 1.1");
//
//      //   throw ::exception(error_failed);
//
//      //}
//
//      //if (!XSetInputFocus(Display(), Window(), RevertToNone, CurrentTime))
//      //{
//
//      //   windowing_output_debug_string("\noswindow_data::SetFocus 1.3");
//
//      //   throw ::exception(error_failed);
//
//      //}
//
//      //windowing_output_debug_string("\noswindow_data::SetFocus 2");
//
//      ////return ::success;
//
//
//
//
//
//   }


   void window::show_window()
   {
   
      main_send([this]()
                {
         
         ios_window_show();
         
      });
      
   }


   void window::hide_window()
   {
      
      main_send([this]()
                {
         
         ios_window_hide();
         
      });
      
   }

   void window::set_active_window()
   {

      //ios_window_make_key_window_and_order_front();
      
      auto pioswindowing = ios_windowing();
      
      pioswindowing->m_pwindowActive = this;

      //return ::success;

   }


   void window::set_tool_window(bool bSet)
   {
      
      auto pioswindowing = ios_windowing();
      
      pioswindowing->_defer_dock_application(!bSet);

      //return ::success;
      
   }


   void window::set_foreground_window(::user::activation_token * puseractivationtoken)
   {
      
      //ios_window_order_front();
      
      //return ::success;
      
   }


   bool window::is_active_window()
   {

//      return ios_window_is_key_window();
      
      return true;

   }

   
   bool window::has_keyboard_focus()
   {
      
      auto pioswindowing = ios_windowing();

      if (!pioswindowing)
      {

         return false;

      }

      auto pwindowKeyboardFocus = pioswindowing->m_pwindowKeyboardFocus;

      if (::is_null(pwindowKeyboardFocus))
      {

         return false;

      }

      //auto pimplFocus = pwindowFocus->m_puserinteractionimpl;

      //if (::is_null(pimplFocus))
      //{

      //   return false;

      //}

      //auto pinteractionFocus = pimplFocus->m_puserinteraction;

      //if (::is_null(pinteractionFocus))
      //{

      //   return false;

      //}

      //if (!(pinteractionFocus->m_ewindowflag & ::e_window_flag_focus))
      //{

      //   return false;

      //}

      bool bHasKeyboardFocus = pwindowKeyboardFocus == this;

      if (!bHasKeyboardFocus)
      {

         return false;

      }

      return true;

   }


   bool window::ios_window_has_keyboard_focus()
   {
   
      bool bHasKeyboardFocus = has_keyboard_focus();
      
      return bHasKeyboardFocus;
   
   }



//   void window::window_show()
//   {
//      
//      //ios_window_show();
//      
//      ::windowing::window::window_show();
//      
//   }


   bool window::_configure_window_unlocked(const class ::zorder& zorder, const ::user::activation& activation, bool bNoZorder, ::e_display edisplay)
   {

      //windowing_output_debug_string("\n::windowing_macos::window::show_window 1");
      
      if(edisplay == e_display_iconic)
      {
       
         //ios_window_miniaturize();
         
      }
      else if(windowing()->is_screen_visible(edisplay))
      {
         
         ios_window_show();
       
         //ios_window_make_key_window_and_order_front();
         
         //ios_window_make_main_window();
         
         //nsapp_activate_ignoring_other_apps(1);
         
      }
//      else if(edisplay == e_display_restored)
//      {
//         
//         ios_window_show();
//       
//         //ios_window_make_key_window_and_order_front();
//         
//         //ios_window_make_main_window();
//         
//         //nsapp_activate_ignoring_other_apps(1);
//         
//      }
      //else if(edisplay == e_display_none || edisplay == e_display_hide)
      else
      {
         
         //ios_window_resign_key();
         ios_window_hide();
         
      }

      //return ::success;
       
       return true;

   }


   void window::set_mouse_cursor(::windowing::cursor * pcursor)
   {

      if (::is_null(pcursor))
      {

         throw ::exception(error_bad_argument);
         //return error_failed;

      }

//      auto pcursorMacos = dynamic_cast < class cursor * >(pcursor);
//
//      if (::is_null(pcursorMacos))
//      {
//
//         //return error_failed;
//
//         throw ::exception(::error_null_pointer);
//
//      }
//
//      if(::is_null(pcursorMacos->m_pNSCursor)
//         && (::is_ok(pcursorMacos->m_pimage)
//             || pcursor->m_ecursor != e_cursor_none))
//      {
//
//         pcursorMacos->_create_os_cursor();
//
//      }
//
//      void * pNSCursor = pcursorMacos->m_pNSCursor;
//
//      if (ns_get_cursor() == pNSCursor)
//      {
//
//         //return true;
//
//         return;
//
//      }
//
//      m_pwindowing->windowing_post(__routine([this, pNSCursor]()
//                                          {
//
////                                             synchronous_lock sl(user_mutex());
//
//                                             windowing_output_debug_string("\n::SetCursor 1");
////
////                                             display_lock displaylock(x11_display()->Display());;
//
//         ns_set_cursor(pNSCursor);
//
//
////                                             XDefineCursor(Display(), Window(), pcursorx11->m_cursor);
//
////                                             m_cursorLast = pcursorx11->m_cursor;
//
//                                          }));
//
//      //return true;

   }


//   ::int_point window::get_mouse_cursor_position()
//   {
//      
//      return m_pointMouseCursor;
//      
//   }
   

   bool window::_strict_set_window_position_unlocked(int x, int y, int cx, int cy, bool bNoMove, bool bNoSize)
   {
//
//      ns_main_post(^(){
//         CGRect r;
//
//         ios_window_get_frame(&r);
//
//         if(!(nFlags & SWP_NOMOVE))
//         {
//            r.origin.x = x;
//            r.origin.y = y;
//         }
//         if(!(nFlags & SWP_NOSIZE))
//         {
//
//            r.size.width = cx;
//
//            r.size.height = cy;
//
//         }
//
//
//         ios_window_set_frame(r);
//
//         if(nFlags & SWP_SHOWWINDOW)
//         {
//
//            ios_window_defer_show();
//
//         }
//
//
//      }
//
//                    );

      return true;

   }

//
//   void window::set_mouse_capture()
//   {
//
//      auto pwindowing = (class windowing *) windowing()->m_pWindowing2;
//      
//      if(!pwindowing)
//      {
//         
//         return;
//         
//         //return ::error_failed;
//         
//      }
//      
//      pwindowing->m_pwindowCapture = this;
//
//      //return ::success;
//
//   }


   void window::window_update_screen()
   {
      
      ::sandbox_windowing::window::window_update_screen();
      
      configure_window_unlocked();
      
      //__update_graphics_buffer();
      
      ios_window_redraw();
      
   }



   void window::ios_window_draw(CGContextRef cgc, CGSize sizeWindowParam)
   {
      
#ifdef EXTRALOG

      output_debug_string("ios_window_draw start\n");
      
#endif

      ::int_size sizeWindow(sizeWindowParam.width, sizeWindowParam.height);

      #ifdef EXTRALOG

      //static int s_iLastExact = -1;

      string str;

      string strFormat;

      strFormat.format("|-> window int_size %d, %d\n", sizeWindow.cx(), sizeWindow.cy());

      printf("%s", strFormat.c_str());
      
//      string strSize;
//
//      if(sizeLast != sizeWindow)
//      {
//
//         sizeLast = sizeWindow;
//
//         strSize = strFormat;
//
//      }
//
//      str += strFormat;
//
//      int_rectangle rect1 = puserinteraction->window_rectangle();
//
//      if(rect1.size() != rectLast.size())
//      {
//
//         rectLast = rect1;
//
//         // xxxlog output_debug_string("different window int_rectangle int_size (1)");
//
//      }

   #endif

      auto tickNow = ::time::now();

      auto tickEllapsed = tickNow - m_timeLastDeviceDraw;

      if(tickEllapsed < 12_ms)
      {

         // xxxlog
         //output_debug_string("\n\nwarning: ios_window_draw more than 80FPS!!! Ellapsed: " + str::from(tickEllapsed) + "ms.\n\n");

      }

      m_timeLastDeviceDraw = tickNow;

      ::windowing::device_draw_life_time devicedrawlifetime(this);

      critical_section_lock slDisplay(this->cs_display());

       ::pointer < ::graphics::graphics > pbuffer = m_pgraphicsgraphics;

      if(!pbuffer)
      {

         return;

      }
      
      auto puserinteraction = user_interaction();
      
      if(!puserinteraction)
      {
      
         return;

      }
      
      auto g = __øcreate < ::draw2d::graphics >();

      g->attach(cgc);
      
      //auto rectClient = puserinteraction->client_rectangle();

      g->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      _synchronous_lock slGraphics(pbuffer->synchronization());
       
       auto pbufferitem = pbuffer->get_screen_item();
      
      _synchronous_lock sl1(pbufferitem->synchronization());

       auto & pimageBuffer2 = pbufferitem->m_pimage2;

      if (!pimageBuffer2)
      {

         output_debug_string("NOT DRAWING? <<---- search and bp here !imageBuffer2 ");

         return;

      }
      
      slGraphics.unlock();

   #ifdef EXTRALOG

//      if(strSize.has_character())
//      {
//
//         s_iLastExact = -1;
//
//      }
//
//      if(s_iLastExact > 0)
//      {
//
//
//         if(s_iLastExact % 10 == 0)
//         {
//
//            str = "\n.";
//
//         }
//         else
//         {
//
//            str = ".";
//
//         }
//
//         strFormat.Format("%d", iAge);
//
//         str += strFormat;
//
//         output_debug_string(str);
//         
//      }
//      else
//      {
//
//         INFO(str);
//
//      }
//
   #endif

      ::int_size sizeMin = pimageBuffer2->size().minimum(sizeWindow);
      
      if(::is_ok(pimageBuffer2))
      {
         
         //output_debug_string("imageBuffer2 ok size : " + __string(imageBuffer2->size()) + "\n");
         
      }
      else
      {

         output_debug_string("imageBuffer2 nok\n");
         
         return;
         
      }
      
      ::image::image_source imagesource(pimageBuffer2);
      
      ::image::image_drawing_options imagedrawingoptions(sizeMin);
      
      if(sizeMin.is_empty())
      {
         
         output_debug_string("sizeMin is empty\n");
         
      }
      else
      {

         //output_debug_string("sizeMin is " + __string(sizeMin) + "\n");
         
      }

      ::image::image_drawing imagedrawing(imagedrawingoptions, imagesource);

      g->draw(imagedrawing);
      
      //output_debug_string("ios_window_draw end\n");
      
      m_bPendingRedraw = false;
      
      m_timeLastRedraw.Now();

   }


//   bool window::ios_window_key_down(unsigned int uiKeyCode)
//   {
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      if(puserinteraction == nullptr)
//      {
//
//         return false;
//
//      }
//
//      auto pkey  = __create_new < ::message::key >();
//
//      pkey->m_id = e_message_key_down;
//
//      pkey->m_strText = pszUtf8;
//
//      pkey->m_nChar = uiKeyCode;
//
//      puserinteraction->send(pkey);
//
//      return true;
//
//   }
//
//
//   bool window::ios_window_key_up(unsigned int uiKeyCode)
//   {
//
//      ::pointer < ::user::message > spbase;
//
//      auto pkey  = __new(::message::key);
//
//      pkey->m_id = e_message_key_up;
//
//      pkey->m_nChar = uiKeyCode;
//
//      spbase = pkey;
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      if(puserinteraction == nullptr)
//      {
//
//         return false;
//
//      }
//
//      puserinteraction->send(spbase);
//
//      return spbase->m_bRet;
//
//   }

//   bool window::ios_window_key_down(unsigned int virtualKey, unsigned int scanCode, const char * pszUtf8)
bool window::ios_window_key_down(::user::enum_key ekey)
   {
      
      {         auto pkey  = __create_new < ::message::key >();

         pkey->m_atom = e_message_key_down;
         pkey->m_ekey = ekey;
         //pkey->set(get_oswindow(), this, e_message_key_down, virtualKey, (lparam)(scanCode << 16));
         
         post_message(pkey);
         
      }
      
//      if(::is_set(pszUtf8) && ansi_len(pszUtf8) > 0)
//      {
//
//         auto pkey = __create_new < ::message::key >();
//
//         pkey->set(get_oswindow(), this, e_message_text_composition, 0, 0);
//
//         pkey->m_strText = pszUtf8;
//
//         post_message(pkey);
//
//      }
//

//      if(::is_set(pszUtf8))
//      {
//
//
//
//         string * pstringText = new string(pszUtf8);
//
//         auto lparam = (::lparam) (iptr) (string *) (pstringText);
//
//         printf("ios_window_key_down e_message_text_composition\n");
//
//         auto puserinteraction = m_pimpl->m_puserinteraction;
//
//         puserinteraction->post_message(e_message_text_composition, 0, lparam);
//
//      }
//

      return true;

   }


   //bool window::ios_window_key_up(unsigned int vk, unsigned int scan)
bool window::ios_window_key_up(::user::enum_key ekey)
   {

      auto puserinteraction = user_interaction();

      if(puserinteraction == nullptr)
      {

         return false;

      }

      auto pkey  = __create_new <::message::key >();

//      pkey->set(get_oswindow(), this, e_message_key_up, vk, (::lparam)(scan << 16));
   pkey->m_atom = e_message_key_up;
   pkey->m_ekey = ekey;
      puserinteraction->send_message(pkey);

      return true;

   }


   character_count utf8_len_from_unicode_len_from_utf8_string(const char * pszText, character_count iUnicodeLen)
   {
      
      auto p = pszText;
      
      for(character_count i = 0; i < iUnicodeLen; i++)
      {
       
         unicode_increment(p);
         
      }

      return p - pszText;

   }


   bool window::ios_window_on_text(const char * pszText, long iUnicodeBeg, long iUnicodeEnd)
   {
      
      auto pinteraction = m_puserinteractionKeyboardFocus;
      
      if(pinteraction)
      {
         
         character_count iBeg = utf8_len_from_unicode_len_from_utf8_string(pszText, iUnicodeBeg);
         
         character_count iEnd = utf8_len_from_unicode_len_from_utf8_string(pszText, iUnicodeEnd);
         
         pinteraction->set_text_and_selection(pszText, iBeg, iEnd, ::e_source_user);

      }
      
      return true;
      
   }


   bool window::ios_window_on_sel_text(long iBeg, long iEnd)
   {
      
      return false;
      
   }


//   long window::ios_window_edit_hit_test(int x, int y)
//   {
//
////      auto pinteraction = m_puserinteractionKeyboardFocus;
////
////      if(pinteraction)
////      {
////
////         ::pointer < ::user::plain_edit > pedit = pinteraction;
////
////         if(pedit)
////         {
////
////            pedit->hit_te
////         pinteraction->_001SetText(pszText, ::e_source_user);
////
////         pinteraction->_001SetSel(iSel, iEnd, ::e_source_user);
////
////         }
////
////      }
//
//      return -1;
//
//   }


   bool window::ios_window_edit_caret_rect(CGRect * prectangle, long iSel)
   {
      
      return false;
      
   }


   void window::on_left_button_down(double xHost, double yHost, double xAbsolute, double yAbsolute)
   {
      
      m_pointMouseCursor.x() = xHost;
      
      m_pointMouseCursor.y() = yHost;

      if (!this->is_active_window())
      {

         try
         {

            auto pmouseactivate = __create_new < ::message::mouse_activate >();

             pmouseactivate->m_pwindow =this;
             pmouseactivate->m_oswindow = this;
             pmouseactivate->m_atom = ::e_message_mouse_activate;

            send_message(pmouseactivate);

            if (pmouseactivate->m_lresult == e_mouse_activate || pmouseactivate->m_lresult == e_mouse_activate_no_activate_and_eat)
            {

               auto pactivate = __create_new < ::message::activate >();
                pactivate->m_pwindow =this;
                pactivate->m_oswindow = this;
                pactivate->m_atom = ::e_message_activate;
                pactivate->m_wparam = ::make_unsigned_int(e_activate_click_active, 0);
                pactivate->m_eactivate = e_activate_click_active;

               post_message(pactivate);

            }

         }
         catch (...)
         {

         }

      }

      {

         auto pmouse = __create_new < ::message::mouse > ();

         ::atom id;
         
         id = e_message_left_button_down;

         auto psession = session();

         try
         {

            psession->set_key_pressed(::user::e_key_left_button, true);

         }
         catch (...)
         {

         }
         
         pmouse->m_pwindow = this;
         pmouse->m_oswindow = this;
         pmouse->m_atom = e_message_left_button_down;
         pmouse->m_lparam =::make_unsigned_int(xHost, yHost);
         pmouse->m_pointHost.x() = xHost;
         pmouse->m_pointHost.y() = yHost;
         pmouse->m_pointAbsolute.x() = xAbsolute;
         pmouse->m_pointAbsolute.y() = yAbsolute;
         
         ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;
         
         if(pelemental)
         {
            
            pelemental->fore_on_left_button_down(pmouse);
            
            if(pmouse->m_bRet)
            {
             
               return;
               
            }
            
         }

         user_interaction()->send_message(pmouse);
         
         if(pmouse->m_bRet)
         {
            
            return;
            
         }
         
         if(pelemental)
         {
            
            pelemental->back_on_left_button_down(pmouse);
            
            if(pmouse->m_bRet)
            {
             
               return;
               
            }
            
         }

      }

   }


   void window::on_right_button_down(double xHost, double yHost, double xAbsolute, double yAbsolute)
{
   
   m_pointMouseCursor.x() = xHost;
   
   m_pointMouseCursor.y() = yHost;

   if (!this->is_active_window())
   {

      try
      {

         auto pmouseactivate = __create_new < ::message::mouse_activate >();

          pmouseactivate->m_pwindow =this;
          pmouseactivate->m_oswindow = this;
          pmouseactivate->m_atom = ::e_message_mouse_activate;

         send_message(pmouseactivate);

         if (pmouseactivate->m_lresult == e_mouse_activate || pmouseactivate->m_lresult == e_mouse_activate_no_activate_and_eat)
         {

            auto pactivate = __create_new < ::message::activate >();
             pactivate->m_pwindow =this;
             pactivate->m_oswindow = this;
             pactivate->m_atom = ::e_message_activate;
             pactivate->m_wparam = ::make_unsigned_int(e_activate_click_active, 0);
             pactivate->m_eactivate = e_activate_click_active;

            post_message(pactivate);

         }

      }
      catch (...)
      {

      }

   }

   {

      auto pmouse = __create_new < ::message::mouse > ();

      auto psession = session();

      try
      {

         psession->set_key_pressed(::user::e_key_right_button, true);

      }
      catch (...)
      {

      }
      
      pmouse->m_pwindow = this;
      pmouse->m_oswindow = this;
      pmouse->m_atom = e_message_right_button_down;
      pmouse->m_lparam =::make_unsigned_int(xHost, yHost);
      pmouse->m_pointHost.x() = xHost;
      pmouse->m_pointHost.y() = yHost;
      pmouse->m_pointAbsolute.x() = xAbsolute;
      pmouse->m_pointAbsolute.y() = yAbsolute;
      
      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;
      
      if(pelemental)
      {
         
         pelemental->fore_on_right_button_down(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }

      user_interaction()->send_message(pmouse);
      
      if(pmouse->m_bRet)
      {
         
         return;
         
      }
      
      if(pelemental)
      {
         
         pelemental->back_on_right_button_down(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }

   }

}


   void window::on_left_button_up(double xHost, double yHost, double xAbsolute, double yAbsolute)
   {
      
      m_pointMouseCursor.x() = xHost;
      
      m_pointMouseCursor.y() = yHost;
      
      auto pmouse = __create_new < ::message::mouse >();

      
      auto psession = session();

      try
      {

         psession->set_key_pressed(::user::e_key_left_button, false);

      }
      catch (...)
      {

      }
      
      pmouse->m_pwindow = this;
      pmouse->m_oswindow = this;
      pmouse->m_atom = e_message_left_button_up;
      pmouse->m_lparam =::make_unsigned_int(xHost, yHost);
      pmouse->m_pointHost.x() = xHost;
      pmouse->m_pointHost.y() = yHost;
      pmouse->m_pointAbsolute.x() = xAbsolute;
      pmouse->m_pointAbsolute.y() = yAbsolute;
      
      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;
      
      if(pelemental)
      {
         
         pelemental->fore_on_left_button_up(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }

      user_interaction()->send_message(pmouse);
      
      if(pmouse->m_bRet)
      {
         
         return;
         
      }
      
      if(pelemental)
      {
         
         pelemental->back_on_left_button_up(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }
   }


void window::on_right_button_up(double xHost, double yHost, double xAbsolute, double yAbsolute)
{
   
   m_pointMouseCursor.x() = xHost;
   
   m_pointMouseCursor.y() = yHost;
   
   auto pmouse = __create_new < ::message::mouse >();

   
   auto psession = session();

   try
   {

      psession->set_key_pressed(::user::e_key_right_button, false);

   }
   catch (...)
   {

   }
   
   pmouse->m_pwindow = this;
   pmouse->m_oswindow = this;
   pmouse->m_atom = e_message_right_button_up;
   pmouse->m_lparam =::make_unsigned_int(xHost, yHost);
   pmouse->m_pointHost.x() = xHost;
   pmouse->m_pointHost.y() = yHost;
   pmouse->m_pointAbsolute.x() = xAbsolute;
   pmouse->m_pointAbsolute.y() = yAbsolute;
   
   ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;
   
   if(pelemental)
   {
      
      pelemental->fore_on_right_button_up(pmouse);
      
      if(pmouse->m_bRet)
      {
       
         return;
         
      }
      
   }

   user_interaction()->send_message(pmouse);
   
   if(pmouse->m_bRet)
   {
      
      return;
      
   }
   
   if(pelemental)
   {
      
      pelemental->back_on_right_button_up(pmouse);
      
      if(pmouse->m_bRet)
      {
       
         return;
         
      }
      
   }
}


//   bool window::ios_window_double_click(double x, double y)
//   {
//
//      auto pmouse = __create_new < ::message::mouse >();
//
//      ::atom id;
//
//      if (iButton == 1)
//      {
//
//         id = e_message_right_button_double_click;
//
//      }
//      else
//      {
//
//         id = e_message_left_button_double_click;
//
//      }
//
//      pmouse->set(this, this, id, (wparam) 0, __MAKE_LPARAM(x, y));
//
//      post_message(pmouse);
//
//   }
//

   void window::on_mouse_move(double xHost, double yHost, double xAbsolute, double yAbsolute)
   {
      
//      if(is_destroying())
//      {
//
//         return;
//
//      }
      
      m_pointMouseCursor.x() = xHost;
      
      m_pointMouseCursor.y() = yHost;
      
      bool bOk = true;

      auto puserinteraction = user_interaction();

      if(!puserinteraction)
      {

         return;

      }
      
      if(m_mouserepositionthrottling.m_timeMouseMove.elapsed() < m_mouserepositionthrottling.m_timeMouseMoveIgnore)
      {
         
         //printf("mouse_move_ignored %f, %f\n", x, y);

         bOk = false;

      }

      if(bOk)
      {

//            printf("mouse_move_\"accepted\" %f, %f\n", x, y);

         m_mouserepositionthrottling.m_timeMouseMove.Now();

         m_mouserepositionthrottling.m_pointMouseMove.x() = xHost;

         m_mouserepositionthrottling.m_pointMouseMove.y() = yHost;

//            if(false)
//            {
//
//               if(pinteraction->m_millisMouseMovePeriod > 0)
//               {
//
//                  ::int_size sizeDistance((pinteraction->m_pointMouseMoveSkip.x - pinteraction->m_pointMouseMove.x),
//                     (pinteraction->m_pointMouseMoveSkip.y - pinteraction->m_pointMouseMove.y));
//
//                  if(!pinteraction->m_millisMouseMoveSkip.timeout(pinteraction->m_millisMouseMovePeriod)
//                     && sizeDistance.cx() * sizeDistance.cx() + sizeDistance.cy() * sizeDistance.cy() < pinteraction->m_iMouseMoveSkipSquareDistance)
//                  {
//
//                     pinteraction->m_iMouseMoveSkipCount++;
//
//                     pinteraction->m_bMouseMovePending = true;
//
//                     if(pinteraction->m_iMouseMoveSkipCount == 2)
//                     {
//
//                        //output_debug_string("\nmmv>skip 2!");
//
//                     }
//                     else if(pinteraction->m_iMouseMoveSkipCount == 5)
//                     {
//
//                        //output_debug_string("\nmmv>Skip 5!!!");
//
//                     }
//                     else if(pinteraction->m_iMouseMoveSkipCount == 10)
//                     {
//
//                        //output_debug_string("\nmmv>SKIP 10 !!!!!!!!!");
//
//                     }
//
//                     return true;
//
//                  }
//
//                  pinteraction->m_iMouseMoveSkipCount = 0;
//
//                  pinteraction->m_pointMouseMoveSkip = pinteraction->m_pointMouseMove;
//
//               }
//
//            }

      }

      if(!bOk)
      {

         return;

      }
      
      ::atom id = e_message_mouse_move;
      
      //wparam wparam = ::make_u32(0, 0);
      
      lparam lparam(xHost, yHost);
      
//      if(ulAppleMouseButton & 1)
//      {
//
//         wparam |= ::user::e_button_state_left;
//
//      }
//
//      if(ulAppleMouseButton & 2)
//      {
//
//         wparam |= ::user::e_button_state_right;
//
//      }
      
      auto pmouse = __create_new < ::message::mouse >();
      
       pmouse->m_pwindow = this;
       pmouse->m_oswindow = this;
       pmouse->m_atom = e_message_mouse_move;
      pmouse->m_lparam =::make_unsigned_int(xHost, yHost);
      pmouse->m_pointHost.x() = xHost;
      pmouse->m_pointHost.y() = yHost;
      pmouse->m_pointAbsolute.x() = xAbsolute;
      pmouse->m_pointAbsolute.y() = yAbsolute;
      
      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;
      
      if(pelemental)
      {
         
         pelemental->fore_on_mouse_move(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }

      user_interaction()->send_message(pmouse);
      
      if(pmouse->m_bRet)
      {
         
         return;
         
      }
      
      if(pelemental)
      {
         
         pelemental->back_on_mouse_move(pmouse);
         
         if(pmouse->m_bRet)
         {
          
            return;
            
         }
         
      }
   }


   void window::ios_window_mouse_dragged(int iGesture, double x, double y)
   {
      
      ::atom id = e_message_mouse_move;

      //wparam wparam = 0;

      lparam lparam(x, y);

//      if(ulAppleMouseButton & 1)
//      {
//
//         wparam |= ::user::e_button_state_left;
//
//      }
//
//      if(ulAppleMouseButton & 2)
//      {
//
//         wparam |= ::user::e_button_state_right;
//
//      }

      auto pmouse = __create_new < ::message::mouse >();
      
      //pmouse->set(this, this, id, wparam, lparam);
       pmouse->m_pwindow = this;
       pmouse->m_oswindow = this;
       pmouse->m_atom = id;
       pmouse->m_lparam =::make_unsigned_int(x, y);
       pmouse->m_pointHost.x() = x;
       pmouse->m_pointHost.y() = y;
      pmouse->m_pointAbsolute = pmouse->m_pointHost;

      post_message(pmouse);

   }


//   void window::ios_window_mouse_wheel(double deltaY, double x, double y)
//   {
//
//      id id = e_message_mouse_wheel;
//
//      short delta = deltaY * WHEEL_DELTA / 3.0;
//
//      wparam wparam = delta << 16;
//
//      lparam lparam = __MAKE_LPARAM(x, y);
//
//      auto pwheel  = __create_new < ::message::mouse_wheel > ();
//
//      pwheel->set(this, this, id, wparam, lparam);
//
//      post_message(pwheel);
//
//   }


   void window::ios_window_resized(int cx, int cy)
   {
      
//      {
//
//         id id = e_message_reposition;
//
//         wparam wparam = 0;
//
//         lparam lparam = __MAKE_LPARAM(rectangle.origin.x, rectangle.origin.y);
//
//         auto pmove  = __create_new < ::message::move > ();
//
//         pmove->set(this, this, id, wparam, lparam);
//
//         post_message(pmove);
//
//      }
      
//      {
//
//         ::atom id = e_message_reposition;
//
//         wparam wparam = 0;
//
//         lparam lparam = __MAKE_LPARAM(0, 0);
//
//         auto pmove  = __create_new < ::message::move > ();
//
//         pmove->set(this, this, id, wparam, lparam);
//
//         post_message(pmove);
//
//      }
//
//      {
//
//         ::atom id = e_message_size;
//
//         wparam wparam = 0;
//
//         lparam lparam = __MAKE_LPARAM(cx, cy);
//
//         auto psize  = __create_new < ::message::size > ();
//
//         psize->set(this, this, id, wparam, lparam);
//
//         post_message(psize);
//
//      }
      
      auto puserinteraction = user_interaction();
      
      puserinteraction->place(::int_rectangle_dimension(0, 0, cx, cy));
                                                        
      puserinteraction->set_need_redraw();
      
      puserinteraction->post_redraw();

      //return;

   //      if(puserinteraction == nullptr)
   //      {
   //
   //         return;
   //
   //      }
   //
   //      //
   //      if(puserinteraction->window_state().m_point != rectangle.origin)
   //      {
   //
   //         puserinteraction->window_state().m_point = rectangle.origin;
   //
   //         information("window::ios_window_resized effective position is different from requested position");
   //
   //         puserinteraction->post_message(e_message_reposition, 0, puserinteraction->window_state().m_point.lparam());
   //
   //      }
   //
   //      if(puserinteraction->m_sizeRequest != rectangle.int_size)
   //      {
   //
   //         puserinteraction->m_sizeRequest = rectangle.int_size;
   //
   //         information("window::ios_window_resized effective position is different from requested position");
   //
   //         puserinteraction->post_message(e_message_size, 0, puserinteraction->m_sizeRequest.lparam());
   //
   //      }
   //
   //      puserinteraction->m_point = rectangle.origin;
   //
   //      puserinteraction->m_size = rectangle.int_size;
   //
   ////      ::int_size sz;
   ////
   ////      long_long_point pt(rectangle.origin.x, rectangle.origin.y);
   ////
   ////      bool bMove = false;
   ////
   ////      {
   ////
   ////         synchronous_lock synchronouslock(puserinteraction->mutex());
   ////
   ////         if (pt != puserinteraction->m_rectParentClient.top_left())
   ////         {
   ////
   ////            bMove = true;
   ////
   ////         }
   ////
   ////         puserinteraction->m_rectParentClient.move_to(point);
   ////
   ////         puserinteraction->set_size(rectangle.int_size);
   ////
   ////         sz = puserinteraction->m_rectParentClient.size();
   ////
   ////      }
   ////
   ////      if(puserinteraction == nullptr)
   ////      {
   ////
   ////         return;
   ////
   ////      }
   ////
   ////      puserinteraction->post_message(e_message_size, 0, sz.lparam());
   ////
   ////      if (bMove)
   ////      {
   ////
   ////         puserinteraction->post_message(e_message_reposition, 0, pt.lparam());
   ////
   ////      }

   //      if (puserinteraction->m_eflagLayouting)
   //      {
   //
   //         //pmessage->m_bRet = true;
   //
   //         return;
   //
   //      }
   //
   //      ::int_rectangle rectSize;
   //
   //      copy(rectSize, rectangle);
   //
   //      if(puserinteraction->window_state().int_rectangle() != rectSize)
   //      {
   //
   //         puserinteraction->window_state().m_point = rectSize.origin();
   //
   //         puserinteraction->window_state().m_size = rectSize.size();
   //
   //      }
   //
   //
   //      if (puserinteraction->layout().sketch().int_rectangle() != rectSize)
   //      {
   //
   //         puserinteraction->place(rectSize);
   //
   //         if (puserinteraction->layout().design().display() != e_display_normal)
   //         {
   //
   //            puserinteraction->display();
   //
   //         }
   //
   //         puserinteraction->set_need_layout();
   //
   //         puserinteraction->set_need_redraw();
   //
   //      }

   }


   void window::ios_window_moved(CGPoint point)
   {
      
      if(m_bEatMoveEvent)
      {
         
         m_bEatMoveEvent = false;
         
         return;
         
      }

      {
      
         ::atom id = e_message_reposition;
         
         //wparam wparam = 0;
         
         lparam lparam(point.x, point.y);
      
         auto preposition  = __create_new < ::message::reposition > ();
      
          preposition->m_pwindow = this;
          preposition->m_oswindow = this;
          preposition->m_atom = id;
          preposition->m_lparam =::make_unsigned_int(point.x, point.y);
          preposition->m_point.x() = point.x;
          preposition->m_point.y() = point.y;

         post_message(preposition);
         
      }
   //      if(puserinteraction == nullptr)
   //      {
   //
   //         return;
   //
   //      }
   //
   //
   //      ::int_point pointMove;
   //
   //      copy(pointMove, point);
   //
   //      if (puserinteraction->m_eflagLayouting)
   //      {
   //
   //         //pmessage->m_bRet = true;
   //
   //         return;
   //
   //      }
   //
   //      ///::pointer < ::message::move > pmove(pmessage);
   //
   //      if (puserinteraction->layout().sketch().m_point != pointMove)
   //      {
   //
   //         puserinteraction->move_to(pointMove);
   //
   //         if (puserinteraction->layout().design().display() != e_display_normal)
   //         {
   //
   //            puserinteraction->display();
   //
   //         }
   //
   //         puserinteraction->set_reposition();
   //
   //         puserinteraction->set_need_redraw();
   //
   //      }
   //
   //
   ////      if(puserinteraction->m_pointRequest != int_point)
   ////      {
   ////
   ////         puserinteraction->m_pointRequest = point;
   ////
   ////         information("window::ios_window_resized effective position is different from requested position");
   ////
   ////      }
   ////
   ////      puserinteraction->m_point = point;

   }


   void window::ios_window_did_become_key()
   {

//      if(is_destroying())
//      {
//
//         return;
//
//      }

      m_timeLastExposureAddUp.Now();

   }


   void window::ios_window_on_activate()
   {

      if(is_destroying())
      {

         return;

      }

      //this->set_active_window();

      auto puserinteraction = user_interaction();

      if(::is_null(puserinteraction))
      {

         return;

      }

//      puserinteraction->set_need_redraw();
      puserinteraction->send_message(e_message_activate, 1);

   }


   void window::ios_window_on_deactivate()
   {

      if(is_destroying())
      {

         //return;

         output_debug_string("destroying");

      }

      auto pwindowing = ios_windowing();

      auto puserinteraction = user_interaction();

      auto pwindowActive = pwindowing->get_active_window(m_puserthread);

      if(::is_null(pwindowActive))
      {

         return;

      }

      if(pwindowActive != this)
      {

         return;

      }

      pwindowing->clear_active_window(m_puserthread, this);

      //::deactivate_window(get_handle());

   //      if(puserinteraction == nullptr)
   //      {
   //
   //         return;
   //
   //      }

      puserinteraction->send_message(e_message_activate, 0);

//      if(!is_destroying())
//      {
//
//         puserinteraction->set_need_redraw();
//
//      }

   }


bool window::ios_window_become_first_responder()
{
   
   return true;
   
}


void window::ios_window_text_view_did_begin_editing()
{

   on_final_set_keyboard_focus();

}


//   void * window::ios_window_get_mouse_cursor()
//   {
//
//      auto pimpl = m_pimpl;
//
//      if(::is_null(pimpl))
//      {
//
//         return nullptr;
//
//      }
//
//      auto puserinteraction = pimpl->m_puserinteraction;
//
//      if(::is_null(puserinteraction))
//      {
//
//         return nullptr;
//
//      }
//
//      auto pcursor = puserinteraction->get_mouse_cursor();
//
//      if(::is_null(pcursor))
//      {
//
//         return nullptr;
//
//      }
//
//      auto poscursor = pcursor->get_os_data();
//
//      if(::is_null(poscursor))
//      {
//
//         return nullptr;
//
//      }
//
//      return poscursor;
//
//   }
//
   
//   void window::profiling_on_start_draw_rectangle()
//   {
//
//      auto pimpl = m_pimpl;
//
//      if(::is_null(pimpl))
//      {
//
//         return;
//
//      }
//
//      auto pimpl2 = pimpl->m_pImpl2;
//
//      if(::is_null(pimpl2))
//      {
//
//         return;
//
//      }
//
//      auto pprodevian = pimpl2->m_pgraphicsthread;
//
//      if(::is_null(pprodevian))
//      {
//
//         return;
//
//      }
//
//      pprodevian->profiling_on_before_update_screen();
//
//   }
//
//
//   void window::profiling_on_end_draw_rectangle()
//   {
//
//      auto pimpl = m_pimpl;
//
//      if(::is_null(pimpl))
//      {
//
//         return;
//
//      }
//
//      auto pimpl2 = pimpl->m_pImpl2;
//
//      if(::is_null(pimpl2))
//      {
//
//         return;
//
//      }
//
//      auto pprodevian = pimpl2->m_pgraphicsthread;
//
//      if(::is_null(pprodevian))
//      {
//
//         return;
//
//      }
//
//      pprodevian->profiling_on_after_update_screen();
//
//   }


//   void window::ios_window_iconified()
//   {
//
//      if(is_destroying())
//      {
//
//         return;
//
//      }
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      if(::is_null(puserinteraction))
//      {
//
//         return;
//
//      }
//
//      if(m_pimpl->m_puserbox != nullptr)
//      {
//
//         m_pimpl->m_puserbox->m_windowdisplayandlayout.m_edisplayPrevious = m_pimpl->m_puserbox->m_windowdisplayandlayout.m_edisplay;
//
//      }
//
//      puserinteraction->layout().window() = ::e_display_iconic;
//
//   }


//   void window::ios_window_deiconified()
//   {
//
//      if(is_destroying())
//      {
//
//         return;
//
//      }
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      if(puserinteraction == nullptr)
//      {
//
//         return;
//
//      }
//
//      if(m_pimpl->m_puserbox)
//      {
//
//         if(m_pimpl->m_puserbox->m_windowdisplayandlayout.m_edisplayPrevious == ::e_display_iconic)
//         {
//
//            m_pimpl->m_puserbox->m_windowdisplayandlayout.m_edisplayPrevious = ::e_display_normal;
//
//         }
//
//         puserinteraction->_001OnDeiconify(m_pimpl->m_puserbox->m_windowdisplayandlayout.m_edisplayPrevious);
//
//      }
//
//   }
//

   void window::ios_window_on_show()
   {

      if(is_destroying())
      {
         
         return;
         
      }
      
      auto puserinteraction = user_interaction();

      if(puserinteraction == nullptr)
      {

         return;

      }

      m_timeLastExposureAddUp.Now();

      puserinteraction->send_message(e_message_show_window, 1);

      //puserinteraction->user_interaction_update_visibility_cache(true);

   //      if(!(puserinteraction->m_ewindowflag & window_flag_miniaturizable))
   //      {
   //
   //         if(puserinteraction->layout().sketch().display() == e_display_iconic)
   //         {
   //
   //            puserinteraction->m_windowState3
   //
   //         }
   //
   //      }

      puserinteraction->set_need_layout();

      puserinteraction->set_need_redraw();

      puserinteraction->post_redraw();

   }


   void window::ios_window_on_hide()
   {

   //      if(is_destroying())
   //      {
   //
   //         return;
   //
   //      }
      
      information("macos::window::ios_window_on_hide");

      auto puserinteraction = user_interaction();

      if(::is_null(puserinteraction))
      {

         warning("macos::window::ios_window_on_hide (2) puserinteraction == nullptr");

         return;

      }
      
//      if(puserinteraction->is_destroying())
//      {
//         
//         return;
//         
//      }
      
      if(puserinteraction->const_layout().window().is_screen_visible())
      {

         puserinteraction->hide();

      }
      
      puserinteraction->message_call(e_message_show_window, 0);

   }


//   void window::ios_window_on_miniaturize()
//   {
//
//      if(is_destroying())
//      {
//
//         return;
//
//      }
//
//      auto puserinteraction = m_pimpl->m_puserinteraction;
//
//      if(::is_null(puserinteraction))
//      {
//
//         return;
//
//      }
//
//      //puserinteraction->message_call(e_message_show_window, 0);
//
//      //puserinteraction->user_interaction_update_visibility_cache(false);
//
//   }

   void window::frame_toggle_restore(::user::activation_token * puseractivationtoken)
{
      
      ns_main_post(^()
                     {
         
         auto puserinteraction = user_interaction();

      if(puserinteraction->get_parent() == nullptr && puserinteraction->get_owner() == nullptr)
      {

         if(!puserinteraction->is_window_visible()
            || (!(puserinteraction->m_ewindowflag & e_window_flag_miniaturizable)
                && !puserinteraction->is_window_screen_visible()))
         {

            puserinteraction->display_previous_restore();

         }
         else if(puserinteraction->_001GetTopLeftWeightedOccludedOpaqueRate()  > 0.025)
         {

            puserinteraction->order(::e_zorder_top);

            puserinteraction->display(e_display_default, { ::user::e_activation_set_foreground, nullptr});

         }
         else if(m_timeLastExposureAddUp.elapsed() < 300_ms)
         {

            information("Ignored minituarize request (by toggle intent) because of recent full exposure.");

         }
         else
         {

            puserinteraction->display(e_display_iconic, {::user::e_activation_no_activate, nullptr});

         }

         puserinteraction->set_need_redraw();

         puserinteraction->post_redraw();

      }

      });

      //return ::success;
      
   }


   void window::non_top_most_upper_window_rects(::int_rectangle_array & recta)
   {
      
      
//      recta = cg_get_window_rect_list_intersect_above(ns_get_window_id(m_pnswindow));
      
      
   }


   void window::post_message(::message::message * pmessage)
   {

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

      auto puserinteraction = user_interaction();

      if(::is_null(puserinteraction))
      {

         return;

      }
      
      puserinteraction->post_message(pmessage);

      //::thread * pthread = nullptr;

//      if (::is_set(puserinteraction))
//      {
//
//         pthread = puserinteraction->m_pthreadUserInteraction;
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
//      class ::message_queue * pmq = pthread->m_pmq;
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

      //return true;

   }


//   void window::get_cursor_position(INT_POINT * ppoint)
//   {
//   
//      //macos_get_cursor_position(ppoint);
//   
//   }


   lresult window::send_message(::message::message * pmessage)
   {

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

      auto puserinteraction = user_interaction();

      if(::is_null(puserinteraction))
      {

         return 0;

      }
      
      auto lresult = puserinteraction->send_message(pmessage);

      //::thread * pthread = nullptr;

   //      if (::is_set(puserinteraction))
   //      {
   //
   //         pthread = puserinteraction->m_pthreadUserInteraction;
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
   //      class ::message_queue * pmq = pthread->m_pmq;
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

      return lresult;

   }


   void window::destroy_window()
   {

//      ::pointer < ::user::primitive_impl > pimplThis = m_puserinteractionimpl;
      
      auto puserinteraction = user_interaction();

      try
      {

         puserinteraction->send_message(e_message_destroy);

      }
      catch (...)
      {

      }

      try
      {

         puserinteraction->send_message(e_message_non_client_destroy);

      }
      catch (...)
      {

      }

      //return ::success;

   }


   void window::bring_to_front()
   {

      //ios_window_order_front();

      //return ::success;

   }

void window::pick_browse(const ::function < void(const ::file::path & ) > & callback)
{
   
   auto ppszUTType = strdupa_from_stringa(application()->m_pfilesystemoptions->m_straUTType);
   
   ios_window_pick_browse(ppszUTType, callback);
   
}


void window::pick_media(const char * pszMediaType)
{
   
   auto pfactory = system()->factory("media", "ios");
   
   ns_main_send(^{

      __øconstruct(m_pmediaitempicker, pfactory);
      
      m_pmediaitempicker->m_ppickercallback = application();
      
      m_pmediaitempicker->set_windowing_window(this);
      
      m_pmediaitempicker->pick_media(pszMediaType);

   });
      
}


//
//::pointer < ::windowing_ios::window > pioswindow = pwindow;
//
//pioswindow->ios_window_get_ui_view_controller());

void window::ios_window_did_pick_document_at_url(const char * pszUrl)
{
   
   application()->did_pick_document_at_url(pszUrl);
   
}


void window::ios_window_did_pick_document_at_urls(const char ** pszaUrl, long lCount)
{
   
   auto straUrl = string_array_from_strdup_count(pszaUrl, lCount);
   
   application()->did_pick_document_at_urls(straUrl);
   
}


void window::on_prompt_write_file(::user::controller *pusercontroller)
{
   void * pUserController = pusercontroller;
   
   ios_window_pick_browse_for_saving_user_controller(pUserController);
 

}


   void window::_main_send(const ::procedure & procedure)
   {
      
      auto pwindowing = windowing();

      pwindowing->_main_send(procedure);

   }


   void window::_main_post(const ::procedure & procedure)
   {

      auto pwindowing = windowing();

      pwindowing->_main_post(procedure);

   }


   ::oswindow window::oswindow() const
   {

      return as_non_const(this);

   }


} // namespace windowing_ios



