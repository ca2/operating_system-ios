#include "framework.h"
//#include "interaction_impl.h"
//#include "node.h"
//#include "aura/platform/message_queue.h"
//#include "acme/constant/activate.h"
//#include "acme/constant/button_state.h"
//#include "acme/constant/message.h"
//#include "aura/graphics/draw2d/graphics.h"
//#include "aura/graphics/graphics/graphics.h"
////#include "aura/user/user/interaction_impl.h"
//#include "aura/windowing/windowing.h"
//#include "aura/windowing/window.h"
//#include "aura/user/user/box.h"
//
//
//#define WHEEL_DELTA 120
//
//
//void deactivate_window(oswindow window);
//
////
////struct __CTLCOLOR
////{
////
////   oswindow hWnd;
////   HDC hDC;
////   unsigned int nCtlType;
////
////};
//
//
//// int_bool PeekMessage(MESSAGE * lpMsg, oswindow hWnd, unsigned int wMsgFilterMin, unsigned int wMsgFilterMax, unsigned int wRemoveMsg);
//
//// int_bool GetMessage(MESSAGE * lpMsg, oswindow hWnd, unsigned int wMsgFilterMin, unsigned int wMsgFilterMax);
//
//::user::interaction * g_puserinteractionMouseCapture123 = nullptr;
////#define MESSAGE_WINDOW_PARENT (::oswindow((void *) (iptr) 1))
//
//
//#define TEST 0
//
//
//namespace aura_ios
//{
//
//
//   long long g_iMouseMove = 0;
//
//
//   ::aura::application * g_pappPreTranslateMouseMessage = nullptr;
//
//
//
//   interaction_impl::interaction_impl()
//   {
//      
//      m_pImpl2 = this;
//
//      m_bEnabled = true;
////      set_os_data(nullptr);
//
//   }
//
//
////   void interaction_impl::construct(oswindow hWnd)
////   {
////
////      set_os_data(hWnd);
////
////   }
//
//
////   interaction_impl::interaction_impl(::object * pobject) :
////      ::object(pobject)
////   {
////
////      m_bEnabled = true;
////      set_handle(nullptr);
////
////   }
//
//
//   interaction_impl::~interaction_impl()
//   {
//
//   }
//
//
//
//
//   CLASS_DECL_AURA void hook_window_create(::user::interaction * pWnd);
//
//   CLASS_DECL_AURA bool unhook_window_create();
//
//   void CLASS_DECL_AURA __pre_init_dialog(::user::interaction * pWnd, INT_RECTANGLE * lpRectOld, unsigned int* pdwStyleOld);
//
////   void CLASS_DECL_AURA __post_init_dialog(::user::interaction * pWnd, const INT_RECTANGLE& rectOld, unsigned int dwStyleOld);
////
////   LRESULT CALLBACK __activation_window_procedure(oswindow hWnd, unsigned int nMsg, wparam wparam, lparam lparam);
//////
////
////   ::user::interaction_impl * interaction_impl::from_os_data(void * pdata)
////   {
////
////      return from_handle((oswindow)pdata);
////
////   }
//
////
////   void * interaction_impl::get_os_data() const
////   {
////
////      return ((oswindow &)m_oswindow);
////
////   }
////
////
////   bool interaction_impl::ModifyStyle(oswindow hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
////   {
////
////      if (!::is_window(hWnd))
////         return false;
////
////      DWORD_PTR dw = hWnd->get_window_long_ptr(GWL_STYLE);
////
////      dw &= ~dwRemove;
////
////      dw |= dwAdd;
////
////      hWnd->set_window_long_ptr(GWL_STYLE, dw);
////
////      return true;
////
////   }
////
////
////   bool interaction_impl::ModifyStyleEx(oswindow hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
////   {
////
////      if (!::is_window(hWnd))
////      {
////
////         return false;
////
////      }
////
////      DWORD_PTR dw = hWnd->get_window_long_ptr(GWL_EXSTYLE);
////
////      dw &= ~dwRemove;
////
////      dw |= dwAdd;
////
////      hWnd->set_window_long_ptr(GWL_EXSTYLE, dw);
////
////      return true;
////
////   }
////
////
////   const MESSAGE * PASCAL interaction_impl::GetCurrentMessage()
////   {
////
////      return nullptr;
////
////   }
//
//
////   LRESULT interaction_impl::Default()
////   {
////
////      return 0;
////
////   }
//
//
////   ::user::interaction_impl * interaction_impl::from_handle(oswindow oswindow)
////   {
////
////      if (oswindow == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      return oswindow->m_pimpl;
////
////   }
//
////
////   ::user::interaction_impl * interaction_impl::FromHandlePermanent(oswindow oswindow)
////   {
////
////      if (oswindow == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      return oswindow->m_pimpl;
////
////   }
//
////
////   bool interaction_impl::Attach(oswindow hWndNew)
////   {
////
////      ASSERT(get_oswindow() == nullptr);     // only attach once, detach on destroy
////      //  ASSERT(FromHandlePermanent(hWndNew) == nullptr);
////      // must not already be in permanent ::collection::map
////
////      if (hWndNew == nullptr)
////      {
////
////         return false;
////
////      }
////
////      //single_lock synchronouslock(afxMutexHwnd(), true);
////      //hwnd_map * pMap = afxMapHWND(true); // create ::collection::map if not exist
////      //ASSERT(pMap != nullptr);
////
////      //pMap->set_permanent(set_handle(hWndNew), this);
////      //if(m_puserinteraction == nullptr)
////      {
////         //m_puserinteraction = this;
////      }
////
////      m_oswindow = hWndNew;
////
////      return true;
////
////   }
////
////   oswindow interaction_impl::Detach()
////   {
////      oswindow hWnd = (oswindow)get_handle();
////      if (hWnd != nullptr)
////      {
////         //         single_lock synchronouslock(afxMutexHwnd(), true);
////         //  ;;       hwnd_map * pMap = afxMapHWND(); // don't create if not exist
////         //     if (pMap != nullptr)
////         //      pMap->erase_handle(get_handle());
////         //         set_handle(nullptr);
////         m_oswindow = nullptr;
////      }
////
////      return hWnd;
////   }
//
////   void interaction_impl::pre_subclass_window()
////   {
////      // no default processing
////   }
//
//
////   bool interaction_impl::create_window_ex(::user::interaction * pinteraction, ::pointer < ::user::system > pusersystem, ::user::interaction *  puiParent, id id)
////   {
////
////      if (!native_create_window_ex(pinteraction, cs,
////                                   puiParent == nullptr ? nullptr : puiParent->get_safe_handle(), id))
////      {
////
////         return false;
////
////      }
////
////      return true;
////
////   }
////
//
//   void interaction_impl::update_graphics_resources()
//   {
//      
//      if(m_pgraphicsgraphics.is_null())
//      {
//   
////         auto estatus = __compose(m_pgraphics, __new(::graphics::multiple_buffer));
//  
//         ///auto estatus =
//         ///
//         //__compose(m_pgraphics, __new(::graphics::double_buffer));
//         øconstruct(m_pgraphicsgraphics);
//         
////         if(!estatus)
////         {
////
////            return estatus;
////
////         }
//
//        // estatus =
//         m_pgraphicsgraphics->initialize_graphics_graphics(this);
//      
////         if(!estatus)
////         {
////
////            return estatus;
////
////         }
////
////         return ::success;
////
//      }
//      
//      //return ::success_none;
//      
//   }
//
//
//   void interaction_impl::destroy_impl_only()
//   {
//      
//      //return false;
//      
//   }
//
//
//   void interaction_impl::start_destroying_window()
//   {
//      
//      //if(!
//      ::user::interaction_impl::start_destroying_window();
//      
////      )
////      {
////
////         return false;
////
////      }
////
////      return true;
////
//   }
//
//
//   void interaction_impl::destroy_window()
//   {
//   
//      ::user::interaction_impl::destroy_window();
//   
//   }
//
//
////bool interaction_impl::_is_window() const
////{
////   
////   if(::is_null(m_pwindow))
////   {
////      
////      return false;
////      
////   }
////   
////   return true;
////   
////}
//
////   ::e_status interaction_impl::native_create_host()
////   {
////
////      //if (::is_window(get_handle()))
////      //{
////
////      //   DestroyWindow();
////
////      //}
////
////      //      ASSERT(lpszClassName == nullptr || __is_valid_string(lpszClassName) ||
////      //       __is_valid_atom(lpszClassName));
//////      ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || __is_valid_string(pusersystem->m_createstruct.lpszName));
////
////      // allow modification of several common create parameters
////      //::user::system createstruct;
////      //      pusersystem->m_createstruct.hwndParent = hWndParent;
////      //   pusersystem->m_createstruct.hMenu = hWndParent == nullptr ? nullptr : nIDorHMenu;
////      m_pusersystem->m_createstruct.hMenu = nullptr;
////      //      pusersystem->m_createstruct.hInstance = ::aura::get_system()->m_hInstance;
////      //pusersystem->m_createstruct.lpCreateParams = lpParam;
////
////      if (!m_puserinteraction->pre_create_window(m_pusersystem))
////      {
////
////         return false;
////
////      }
////
////      install_message_routing(m_puserinteraction);
////
////      hook_window_create(m_puserinteraction);
////
////      CGRect int_rectangle;
////
////      INT_RECTANGLE rectParam;
////
//////      rectParam.left = m_pusersystem->m_createstruct.x;
//////      rectParam.top = pusersystem->m_createstruct.y;
//////      rectParam.right = pusersystem->m_createstruct.x + pusersystem->m_createstruct.cx();
//////      rectParam.bottom = pusersystem->m_createstruct.y + pusersystem->m_createstruct.cy();
////
//////      copy(rectangle, rectParam);
//////
//////      if (pusersystem->m_createstruct.hwndParent == MESSAGE_WINDOW_PARENT)
//////      {
//////
//////         return true;
//////
//////      }
//////      else
//////      {
////
////         unsigned uStyle = 0;
////
////         if(m_puserinteraction->m_ewindowflag & ::e_window_flag_miniaturizable)
////         {
////
////#define NSWindowStyleMaskMiniaturizable (1 << 2)
////
////            uStyle |= NSWindowStyleMaskMiniaturizable;
////
////         }
////
////         auto rectangle = m_puserinteraction-> window_rectangle();
////
////         m_oswindow = oswindow_get(new_aura_window(this, rectangle, uStyle));
////
////         m_puserinteraction->layout().window() = ::top_left(rectParam);
////
////         m_puserinteraction->layout().window() = ::int_size(rectParam);
////
////         __refer(m_puserinteraction->m_pthreadUserInteraction, ::get_task());
////
////         //m_puserinteraction->place(rectParam);
////
////
////
////         m_oswindow->set_user_interaction_impl(this);
////
////         oswindow_assign(m_oswindow, this);
////
////      }
////
////      LRESULT lresult = m_puserinteraction->send_message(e_message_create, 0, (LPARAM)&cs);
////
////      bool bOk = true;
////
////      if (!unhook_window_create() || lresult == -1)
////      {
////
////         bOk = false;
////
////         finalize();
////
////         //children_post_quit();
////
////         //children_wait_quit(one_minute());
////
////         PostNcDestroy();        // cleanup if CreateWindowEx fails too soon
////
////         return false;
////
////      }
////
////      if(pusersystem->m_createstruct.style & WS_VISIBLE)
////      {
////
////         m_puserinteraction->display();
////
////         m_puserinteraction->set_need_redraw();
////
////         //m_puserinteraction->post_redraw();
////
////         //;//aura_window_show();
////
////      }
////
////      m_puserinteraction->set_need_layout();
////
////      m_puserinteraction->add_ref(OBJECT_REFERENCE_COUNT_DEBUG_P_NOTE(this, "native_create_window"));
////
////      m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;
////
////      return bOk;
////
////   }
////
////
////   // for child windows
////   bool interaction_impl::pre_create_window(::user::system * pusersystem)
////   {
////      /*      if (pusersystem->m_createstruct.lpszClass == nullptr)
////       {
/////xcore/app/aura/node/macos/macos_interaction_impl.cpp:712:44: No member named 'window_rectangle' in 'user::interaction_impl'       // make sure the default user::interaction class is registered
////       VERIFY(__end_defer_register_class(__WND_REG, &pusersystem->m_createstruct.lpszClass));
////
////       // no WNDCLASS provided - use child user::interaction default
////       ASSERT(pusersystem->m_createstruct.style & WS_CHILD);
////       }*/
////      return true;
////   }
////
//
////   bool interaction_impl::create_window(::user::interaction * pinteraction, const char * lpszClassName,const char * lpszWindowName,unsigned int uStyle, const ::int_rectangle & rectangle,::user::interaction * puiParent,id id, ::create * pcreate)
////   {
////
////      // can't use for desktop or pop-up windows (use CreateEx instead)
////
////      ASSERT(puiParent != nullptr);
////
////      ::user::system createstruct(0, lpszClassName, lpszWindowName, uStyle, rectangle, pcreate);
////
////      pusersystem->m_createstruct.hwndParent = puiParent->get_safe_handle();
////
////      ASSERT((pusersystem->m_createstruct.style & WS_POPUP) == 0);
////
////      return create_window_ex(pinteraction, createstruct, puiParent, id);
////
////   }
//
//
//   // bool interaction_impl::create_message_queue(::user::interaction * pinteraction, const char * pszName)
//   // {
//
//   //    if (is_window(get_handle()))
//   //    {
//
//   //       set_window_text(pszName);
//
//   //    }
//   //    else
//   //    {
//
//   //       ::user::system createstruct(0, nullptr, pszName, WS_CHILD, nullptr);
//
//   //       if (!native_create_window_ex(pinteraction, createstruct, MESSAGE_WINDOW_PARENT, "message_queue"))
//   //       {
//
//   //          return false;
//
//   //       }
//
//   //    }
//
//   //    return true;
//
//   // }
//
//
//   void interaction_impl::install_message_routing(::channel * pchannel)
//   {
//
//      last_install_message_routing(pchannel);
//
//      ::user::interaction_impl::install_message_routing(pchannel);
//
////      if (!m_puserinteraction->m_bMessageWindow)
////      {
//////
//////         USER_MESSAGE_LINK(::user::e_message_paint, pchannel, this, &interaction_impl::_001OnPaint);
//////         USER_MESSAGE_LINK(WM_PRINT, pchannel, this, &interaction_impl::_001OnPrint);
////
////      }
//
//      m_puserinteraction->install_message_routing(pchannel);
//
//      USER_MESSAGE_LINK(::user::e_message_create, pchannel, this, &interaction_impl::on_message_create);
//
//      if (!m_puserinteraction->m_bMessageWindow)
//      {
//
////         USER_MESSAGE_LINK(::user::e_message_set_cursor, pchannel, this, &interaction_impl::_001OnSetCursor);
////         USER_MESSAGE_LINK(::user::e_message_erase_background, pchannel, this,&interaction_impl::_001OnEraseBkgnd);
//         //         USER_MESSAGE_LINK(::user::e_message_nccalcsize, pchannel, this,&interaction_impl::_001OnNcCalcSize);
////         USER_MESSAGE_LINK(::user::e_message_size, pchannel, this, &interaction_impl::_001OnSize);
//         //         USER_MESSAGE_LINK(::user::e_message_window_position_changing, pchannel, this,&interaction_impl::_001OnWindowPosChanging);
//         //         USER_MESSAGE_LINK(::user::e_message_window_position_changed, pchannel, this,&interaction_impl::_001OnWindowPosChanged);
//         //         USER_MESSAGE_LINK(WM_GETMINMAXINFO, pchannel, this,&interaction_impl::_001OnGetMinMaxInfo);
//         //         USER_MESSAGE_LINK(::user::e_message_set_focus, pchannel, this,&interaction_impl::_001OnSetFocus);
//         //         USER_MESSAGE_LINK(::user::e_message_kill_focus, pchannel, this,&interaction_impl::_001OnKillFocus);
//         //USER_MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH, pchannel, this,&interaction_impl::_001OnProdevianSynch);
//      }
//      prio_install_message_routing(pchannel);
//      USER_MESSAGE_LINK(::user::e_message_destroy, pchannel, this, &interaction_impl::_001OnDestroy);
//
//      //      ::user::interaction_impl::install_message_routing(pchannel);
//      //      //m_pbuffer->InstallMessageHandling(pinterface);
//      //      USER_MESSAGE_LINK(::user::e_message_destroy           , pchannel, this, &interaction_impl::_001OnDestroy);
//      //      USER_MESSAGE_LINK(::user::e_message_paint             , pchannel, this, &interaction_impl::_001OnPaint);
//      //      USER_MESSAGE_LINK(WM_PRINT             , pchannel, this, &interaction_impl::_001OnPrint);
//      //      if(m_puserinteraction != nullptr)
//      //      {
//      //         m_puserinteraction->install_message_routing(pchannel);
//      //      }
//      //      USER_MESSAGE_LINK(::user::e_message_create            , pchannel, this, &interaction_impl::on_message_create);
//      //      USER_MESSAGE_LINK(::user::e_message_set_cursor         , pchannel, this, &interaction_impl::_001OnSetCursor);
//      //      USER_MESSAGE_LINK(::user::e_message_erase_background        , pchannel, this, &interaction_impl::_001OnEraseBkgnd);
//      //      USER_MESSAGE_LINK(::user::e_message_reposition              , pchannel, this, &interaction_impl::_001OnMove);
//      //      USER_MESSAGE_LINK(::user::e_message_size              , pchannel, this, &interaction_impl::_001OnSize);
//      USER_MESSAGE_LINK(::user::e_message_show_window, pchannel, this, &interaction_impl::_001OnShowWindow);
//      //      USER_MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH , pchannel, this, &interaction_impl::_001OnProdevianSynch);
//      ////      //USER_MESSAGE_LINK(::user::e_message_timer             , pchannel, this, &interaction_impl::_001OnTimer);
//   }
//
//
//   void interaction_impl::_001OnShowWindow(::message::message * pmessage)
//   {
//
//      __UNREFERENCED_PARAMETER(pmessage);
//
////      do_show_flags();
////
////      clear_show_flags();
//
//   }
//
//
//   void interaction_impl::_001OnMove(::message::message * pmessage)
//   {
//
////      if (m_bDestroyImplOnly)
////      {
////
////         return;
////
////      }
////
////      if (m_puserinteraction->m_eflagLayouting)
////      {
////
////         return;
////
////      }
////
////      ::pointer < ::message::move > pmove(pmessage);
////
////      m_puserinteraction->window_state().m_point = pmove->m_point;
////
////      if (m_puserinteraction->layout().sketch().m_point != pmove->m_point)
////      {
////
////         if (m_puserinteraction->layout().is_moving())
////         {
////
////            output_debug_string("\nWindow is Moving :: _001OnMove");
////
////         }
////
////         m_puserinteraction->move_to(pmove->m_point);
////
////         if (m_puserinteraction->layout().design().display() != e_display_normal)
////         {
////
////            m_puserinteraction->display();
////
////         }
////
////         m_puserinteraction->set_reposition();
////
////         m_puserinteraction->set_need_redraw();
////
////      }
//
//   }
//
//
//   void interaction_impl::_001OnSize(::message::message * pmessage)
//   {
////
////      if (m_bDestroyImplOnly)
////      {
////
////         return;
////
////      }
////
////      if (m_puserinteraction->m_eflagLayouting)
////      {
////
////         return;
////
////      }
////
////      ::pointer < ::message::size > psize(pmessage);
////
////      m_puserinteraction->window_state().m_size = psize->m_size;
////
////      if (m_puserinteraction->layout().sketch().m_size != psize->m_size)
////      {
////
////         m_puserinteraction->set_size(psize->m_size);
////
////         if (m_puserinteraction->layout().design().display() != e_display_normal)
////         {
////
////            m_puserinteraction->display();
////
////         }
////
////         m_puserinteraction->set_need_layout();
////
////         m_puserinteraction->set_need_redraw();
////
////      }
////
//   }
//
//
//   void interaction_impl::_001OnDestroy(::message::message * pmessage)
//   {
//
//      __UNREFERENCED_PARAMETER(pmessage);
//      
//      auto pwindowing = m_pwindowing;
//
//      if(pwindowing->get_active_window(m_puserinteraction->m_pthreadUserInteraction) == m_puserinteraction)
//      {
//
//         pwindowing->clear_active_window(m_puserinteraction->m_pthreadUserInteraction, m_pwindow);
//
//      }
//
//      default_message_handler(pmessage);
//
//      //aura_window_hide();
//
//      //m_ptimerarray.release();
//      
//   }
//
//
//   void interaction_impl::post_non_client_destroy()
//   {
//
//      //Detach();
//
//      //ASSERT(get_handle() == nullptr);
//
//      ::user::interaction_impl::post_non_client_destroy();
//
////      ns_main_post(^()
////      {
////      
////         aura_window_destroy();
////                      
////      });
//
//   }
//
////
////   void interaction_impl::assert_ok() const
////   {
////      
////      if (oswindow() == nullptr)
////      {
////         
////         return; // null (unattached) windows are valid
////         
////      }
////
////      // check for special wnd??? values
////      //      ASSERT(oswindow_TOP == nullptr);       // same as desktop
////      /*      if (get_handle() == oswindow_BOTTOM)
////       {
////       }
////       else if (get_handle() == oswindow_TOPMOST)
////       {
////       }
////       else if (get_handle() == oswindow_NOTOPMOST)
////       {
////       }
////       else
////       {
////       // should be a normal user::interaction
////       ASSERT(::is_window(get_handle()));
////
////       // should also be in the permanent or temporary handle ::collection::map
////       single_lock synchronouslock(afxMutexHwnd(), true);
////       hwnd_map * pMap = afxMapHWND();
////       if(pMap == nullptr) // inside thread not having windows
////       return; // let go
////       ASSERT(pMap != nullptr);
////
////       //         ::ca2::object* p=nullptr;
////       if(pMap)
////       {
////       ASSERT( (p = pMap->lookup_permanent(get_handle())) != nullptr ||
////       (p = pMap->lookup_temporary(get_handle())) != nullptr);
////       }*/
////
////      //ASSERT(dynamic_cast < ::user::interaction *  > (p) == this);   // must be us
////
////      // Note: if either of the above asserts fire and you are
////      // writing a multithreaded application, it is likely that
////      // you have passed a C++ object from one thread to another
////      // and have used that object in a way that was not intended.
////      // (only simple inline wrapper functions should be used)
////      //
////      // In general, user::interaction objects should be passed by oswindow from
////      // one thread to another.  The receiving thread can wrap
////      // the oswindow with a user::interaction object by using ::macos::interaction_impl::from_handle.
////      //
////      // It is dangerous to pass C++ objects from one thread to
////      // another, unless the objects are designed to be used in
////      // such a manner.
////      //      }*/
////      
////   }
////
////
////   void interaction_impl::dump(dump_context & dumpcontext) const
////   {
////      ::object::dump(dumpcontext);
////
//////      dumpcontext << "\nm_hWnd = " << (void *)get_handle();
////
////      /*      if (get_handle() == nullptr || get_handle() == oswindow_BOTTOM ||
////       get_handle() == oswindow_TOPMOST || get_handle() == oswindow_NOTOPMOST)
////       {
////       // not a normal user::interaction - nothing more to dump
////       return;
////       }*/
////
////      /*      if (!::is_window(get_handle()))
////       {
////       // not a valid user::interaction
////       dumpcontext << " (illegal oswindow)";
////       return; // don't do anything more
////       }*/
////
////      ::user::interaction_impl * pWnd = (::user::interaction_impl *) this;
////      if (pWnd != this)
////         dumpcontext << " (Detached or temporary user::interaction)";
////      else
////         dumpcontext << " (permanent user::interaction)";
////
////      // dump out user::interaction specific statistics
////      char szBuf[64];
////      dumpcontext << "\ncaption = \"" << szBuf << "\"";
////
////      //      ::GetClassName(get_handle(), szBuf, _countof(szBuf));
////      //    dumpcontext << "\nclass name = \"" << szBuf << "\"";
////
////      ::int_rectangle rectangle;
////      
////      ((::user::interaction_impl *) this)->m_puserinteraction->window_rectangle(rectangle);
////      
//////      dumpcontext << "\nrect = " << int_rectangle;
////      dumpcontext << "\nparent ::user::interaction * = " << (void *)((::user::interaction_impl *) this)->get_parent();
////
////      //      dumpcontext << "\nstyle = " << (void *)(dword_ptr)::GetWindowLong(get_handle(), GWL_STYLE);
////      //    if (::GetWindowLong(get_handle(), GWL_STYLE) & WS_CHILD)
////      //     dumpcontext << "\nid = " << __get_dialog_control_id(get_handle());
////
////      dumpcontext << "\n";
////   }
//
//
////   bool interaction_impl::DestroyWindow()
////   {
////
////      return ::user::interaction_impl::DestroyWindow();
////
////   }
//
//
////   LRESULT interaction_impl::DefWindowProc(unsigned int nMsg, wparam wparam, lparam lparam)
////   {
////      /*  if (m_pfnSuper != nullptr)
////       return ::CallWindowProc(m_pfnSuper, get_handle(), nMsg, wparam, lparam);
////
////       WNDPROC pfnWndProc;
////       if ((pfnWndProc = *GetSuperWndProcAddr()) == nullptr)
////       return ::DefWindowProc(get_handle(), nMsg, wparam, lparam);
////       else
////       return ::CallWindowProc(pfnWndProc, get_handle(), nMsg, wparam, lparam);*/
////
////      return 0;
////   }
//
//   /*
//    WNDPROC* interaction_impl::GetSuperWndProcAddr()
//    {
//    // Note: it is no longer necessary to override GetSuperWndProcAddr
//    //  for each control class with a different WNDCLASS.
//    //  This implementation now uses instance data, such that the previous
//    //  WNDPROC can be anything.
//
//    return &m_pfnSuper;
//    }
//    */
//   void interaction_impl::pre_translate_message(::message::message * pmessage)
//   {
//      
//      __UNREFERENCED_PARAMETER(pmessage);
//      
//      // no default processing
//      
//   }
//
////
////   void interaction_impl::get_window_text(string & str)
////   {
////
////      char sz[2048];
////
////      __zero(sz);
////
////      //aura_window_get_title(sz, sizeof(sz));
////
////      str = m_strWindowText;
////
////   }
////
//
//
//   void interaction_impl::route_command(::message::command * pcommand, bool bRouteToKeyDescendant)
//   {
//
//      channel::route_command(pcommand, bRouteToKeyDescendant);
//
//      if(pcommand->m_bRet)
//      {
//
//         return;
//
//      }
//
//      //      bool b;
//
//      //if(_iguimessageDispatchCommandMessage(pcommand, b))
//      // return b;
//
////      channel * pcmdtarget = dynamic_cast <channel *> (this);
////      return pcmdtarget->channel::route_command_message(pcommand);
//      
//   }
//
//
//
////   void interaction_impl::on_control_event(::user::control_event * pevent)
////   {
////      UNREFERENCED_PARAMETER(pevent);
////      return false;
////   }
//
//   void interaction_impl::_002OnDraw(::image * pimage)
//   {
//
//      //      ::CallWindowProc(*GetSuperWndProcAddr(), get_handle(), WM_PRINT, (WPARAM)((dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->get_handle()), (LPARAM)(PRF_CHILDREN | PRF_CLIENT));
//
//   }
//
//   
//   void interaction_impl::default_message_handler(::message::message * pmessage)
//   {
//      
////      if (get_handle() == nullptr)
////      {
////
////         return;
////
////      }
////
////      WNDPROC pfnWndProc = *GetSuperWndProcAddr();
////
////      LRESULT lresult = 0;
////
////      if (pfnWndProc == nullptr)
////      {
////
////         lresult = ::DefWindowProcW(m_oswindow, pmessage->m_atom.long_long, pmessage->m_wparam, pmessage->m_lparam);
////
////      }
////      else
////      {
////
////         lresult = ::CallWindowProc(pfnWndProc, m_oswindow, pmessage->m_atom.long_long, pmessage->m_wparam, pmessage->m_lparam);
////
////      }
//      
//      pmessage->m_lresult = 0;
//      
//   }
//
//
//   void interaction_impl::message_handler(::message::message * pmessage)
//{
//      
//       ::user::interaction_impl::message_handler(pmessage);
//      
////      return;
////      
////      bool bKeyMessage = false;
////
////   ::message::key * pkey = nullptr;
////
////   if (m_puserinteraction->pre_message_handler(pkey, bKeyMessage, pmessage))
////   {
////
////      return;
////
////   }
////
////   if(pmessage->m_atom == e_message_timer)
////   {
////
////      //m_pthread->step_timer();
////
////   }
////   else if(pmessage->m_atom == e_message_left_button_down)
////   {
////
////      output_debug_string("linux::interaction_impl::e_message_left_button_down\n");
////
////   }
////   else if(pmessage->m_atom == e_message_left_button_up)
////   {
////
////      output_debug_string("linux::interaction_impl::e_message_left_button_up\n");
////
////   }
////   else if(pmessage->m_atom == e_message_mouse_move)
////   {
////
////      g_iMouseMove++;
////
////      //information("linux::interaction_impl::message_handler e_message_mouse_move");
////      //printf("g_iMouseMove = %d\n", g_iMouseMove);
////
////   }
////   else if(pmessage->m_atom == e_message_paint)
////   {
////
////   }
////   else if(pmessage->m_atom == e_message_left_button_up)
////   {
////
////      information("e_message_left_button_up (0)");
////
////   }
////
////      if (pmessage->m_atom == e_message_size || pmessage->m_atom == e_message_reposition)
////      {
////
////         //         win_update_graqhics();
////
////      }
////
////      if (bKeyMessage)
////      {
////
////         ::pointer < ::message::key > pkey(pmessage);
////         
////         //auto psession = get_session()->m_paurasession;
////         
////         auto pwindowing = m_pwindowing;
////         
////         auto pkeyboard = pwindowing->keyboard();
////
////         pkeyboard->translate_os_key_message(pkey);
////
//////         if(pkey->m_ekey != ::user::e_key_refer_to_text_member)
//////         {
//////
//////            if (pmessage->m_atom == e_message_key_down)
//////            {
//////
//////               try
//////               {
//////
//////                  if(psession->is_key_pressed(pkey->m_ekey))
//////                  {
//////
//////                     return;
//////
//////                  }
//////
//////                  psession->set_key_pressed(pkey->m_ekey, true);
//////
//////               }
//////               catch (...)
//////               {
//////
//////               }
//////
//////            }
//////            else if (pmessage->m_atom == e_message_key_up)
//////            {
//////
//////               try
//////               {
//////
//////                  psession->set_key_pressed(pkey->m_ekey, false);
//////
//////               }
//////               catch (...)
//////               {
//////
//////               }
//////
//////            }
////            
//////         }
////         
////      }
////
////      if (m_puserinteraction != nullptr)
////      {
////
////         if (m_puserinteraction->layout().is_moving())
////         {
////            
////            //information("moving: skip pre translate message");
////            
////         }
////         else if (m_puserinteraction->layout().is_sizing())
////         {
////            
////            //information("sizing: skip pre translate message");
////            
////         }
////         else
////         {
////
////            m_puserinteraction->pre_translate_message(pmessage);
////
////            if (pmessage->m_bRet)
////            {
////               
////               return;
////               
////            }
////
////            pmessage->m_uiMessageFlags |= 1;
////
////         }
////
////      }
////
////      if (pmessage->m_atom == e_message_timer)
////      {
////         //         get_application()->get_application()->step_timer();
////      }
////      else if (pmessage->m_atom == e_message_left_button_down)
////      {
////         //  g_puserinteractionLastLButtonDown = this;
////      }
////      else if (pmessage->m_atom == e_message_size)
////      {
////         m_bUpdateGraphics = true;
////      }
////         /*   else if(pusermessage->m_id == CA2M_BERGEDGE)
////       {
////       if(pusermessage->m_wparam == BERGEDGE_GETAPP)
////       {
////       ::application ** ppapp= (::application **) pusermessage->m_lparam;
////       *ppapp = get_application();
////       pusermessage->m_bRet = true;
////       return;
////       }
////       }*/
////      pmessage->m_lresult = 0;
////
////
//////      if (pusermessage->m_id == e_message_left_button_down ||
//////            pusermessage->m_id == e_message_left_button_up ||
//////            pusermessage->m_id == e_message_middle_button_down ||
//////            pusermessage->m_id == e_message_middle_button_up ||
//////            pusermessage->m_id == e_message_right_button_down ||
//////            pusermessage->m_id == e_message_right_button_up ||
//////            pusermessage->m_id == e_message_right_button_double_click ||
//////            pusermessage->m_id == e_message_left_button_double_click ||
//////            pusermessage->m_id == e_message_mouse_move ||
//////            pusermessage->m_id == e_message_mouse_move ||
//////            pusermessage->m_id == e_message_mouse_wheel)
//////      {
//////
//////         if (pusermessage->m_id == e_message_left_button_down)
//////         {
//////
//////            //output_debug_string("\nWM_LBUTTONDOWN");
//////
//////         }
//////         else if(pusermessage->m_id == e_message_mouse_move)
//////         {
//////
//////            output_debug_string("\nWM_MOUSEMOVE");
//////
//////         }
//////
//////         ::pointer < ::message::mouse > pmouse =  pusermessage;
//////
//////         auto psession = get_session();
//////
//////         // user presence status activity reporting
//////
//////         psession->on_ui_mouse_message(pmouse);
//////
//////
//////         if (get_session() != nullptr)
//////         {
//////
//////            psession->m_pointCursor = pmouse->m_point;
//////
//////         }
//////
//////         if (m_bTranslateMouseMessageCursor)
//////         {
//////
//////            ::int_rectangle rectangle;
//////
//////            if(!pmouse->m_bTranslated)
//////            {
//////
//////               pmouse->m_bTranslated = true;
//////
//////               auto pwindowing = m_pwindowing;
//////
//////               auto pdisplay = pwindowing->display();
//////
//////               if (pdisplay->get_monitor_count() > 0)
//////               {
//////
//////                  pdisplay->get_monitor_rectangle(0, &rectangle);
//////
//////               }
//////               else
//////               {
//////
//////                  if (m_bScreenRelativeMouseMessagePosition)
//////                  {
//////
//////#ifndef __APPLE__
//////
//////                     ::window_rectangle(get_handle(), &rectangle);
//////
//////#endif
//////
//////                  }
//////                  else
//////                  {
//////
//////                     m_puserinteraction->window_rectangle(rectangle);
//////
//////                  }
//////
//////               }
//////
//////               if (rectangle.left >= 0)
//////               {
//////
//////                  pmouse->m_point.x += (int)rectangle.left;
//////
//////               }
//////
//////               if (rectangle.top >= 0)
//////               {
//////
//////                  pmouse->m_point.y += (int)rectangle.top;
//////
//////               }
//////
//////            }
//////
//////         }
//////
//////         if (pusermessage->m_id == e_message_mouse_move)
//////         {
//////
//////            auto pwindowing = m_pwindowing;
//////            // We are at the message handler procedure.
//////            // mouse messages originated from message handler and that are mouse move events should end up with the correct cursor.
//////            // So the procedure starts by setting to the default cursor,
//////            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//////            // handler has set it to another one.
//////            pmouse->m_pcursor = pwindowing->load_default_cursor(e_cursor_arrow);
//////
//////         }
//////
//////         //_008OnMouse(pmouse);
//////
//////         return;
//////
//////      }
////      if(pmessage->m_atom == e_message_left_button_down ||
////                 pmessage->m_atom == e_message_left_button_up ||
////                 pmessage->m_atom == e_message_middle_button_down ||
////                 pmessage->m_atom == e_message_middle_button_up ||
////                 pmessage->m_atom == e_message_right_button_down ||
////                 pmessage->m_atom == e_message_right_button_up ||
////                 pmessage->m_atom == e_message_mouse_move ||
////                 pmessage->m_atom == e_message_mouse_move)
////     //         pmessage->m_atom == e_message_mouse_wheel)
////           {
////
////              if(::is_set(m_puserinteraction) && !m_puserinteraction->m_bUserElementOk)
////              {
////
////                 return;
////
////              }
////
////              ::pointer < ::message::mouse > pmouse = pmessage;
////
////              auto psession = get_session();
////
////              if(psession != nullptr)
////              {
////
////                 psession->on_ui_mouse_message(pmouse);
////
////                 psession->m_pointCursor = pmouse->m_point;
////
////              }
////
////     //         if(m_puserinteraction != nullptr && m_puserinteraction->get_session()  != nullptr && m_puserinteraction->get_session() != get_session())
////     //         {
////     //
////     //            auto psystem = m_psystem;
////     //
////     //            auto psession = psystem->node();
////     //
////     //            psession->m_pointCursor = pmouse->m_point;
////     //
////     //         }
////
//////              if(m_bTranslateMouseMessageCursor && !pmouse->m_bTranslated)
//////              {
//////                 pmouse->m_bTranslated = true;
//////                 ::int_rectangle rectWindow;
//////     //            if(m_bScreenRelativeMouseMessagePosition)
//////     //            {
//////     //
//////     //               INFO("Screen Relative Mouse Message Position");
//////     //
//////     //               ::int_rectangle rectWindow32;
//////     //
//////     //               ::window_rectangle((oswindow) get_handle(), &rectWindow32);
//////     //
//////     //               ::copy(rectWindow, rectWindow32);
//////     //
//////     //            }
//////     //            else
//////                 {
//////                    m_puserinteraction->window_rectangle(rectWindow);
//////                 }
//////
//////                 auto puser = psession->user();
//////
//////                 auto pwindowing = puser->windowing();
//////
//////                 auto pdisplay = pwindowing->display();
//////
//////                 if(pdisplay->get_monitor_count() > 0)
//////                 {
//////
//////                    ::int_rectangle rcMonitor;
//////
//////                    pdisplay->get_monitor_rectangle(0, &rcMonitor);
//////
//////                    if(rectWindow.left >= rcMonitor.left)
//////                    {
//////
//////                       pmouse->m_point.x += (int) rectWindow.left;
//////
//////                    }
//////
//////                    if(rectWindow.top >= rcMonitor.top)
//////                    {
//////
//////                       pmouse->m_point.y += (int) rectWindow.top;
//////
//////                    }
//////
//////                 }
//////                 else
//////                 {
//////
//////                    if(rectWindow.left >= 0)
//////                    {
//////
//////                       pmouse->m_point.x += (int) rectWindow.left;
//////
//////                    }
//////
//////                    if(rectWindow.top >= 0)
//////                    {
//////
//////                       pmouse->m_point.y += (int) rectWindow.top;
//////
//////                    }
//////
//////                 }
//////
//////              }
////
////              auto puser = psession->user();
////
////              auto pwindowing = puser->windowing();
////
////              pwindowing->set(pmouse, get_oswindow(), m_pwindow, pmouse->m_atom, pmouse->m_wparam, pmouse->m_lparam);
////
////              if(pmessage->m_atom == e_message_mouse_move)
////              {
////
////                 // We are at the message handler routine.
////                 // mouse messages originated from message handler and that are mouse move events should end up with the correct cursor.
////                 // So the routine starts by setting to the default cursor,
////                 // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
////                 // handler has set it to another one.
////
////                 m_puserinteraction->m_pinteractionimpl->_on_mouse_move_step(pmouse->m_point);
////
////              }
////
////              //_008OnMouse(pmouse);
////
////              ::user::interaction * puserinteractionMouse = nullptr;
////
////              if(m_puserinteractionMouseCapture)
////              {
////
////                 if(g_puserinteractionMouseCapture123 == nullptr)
////                 {
////
////                    g_puserinteractionMouseCapture123 = m_puserinteractionMouseCapture;
////
////                 }
////                 else if(g_puserinteractionMouseCapture123 != m_puserinteractionMouseCapture)
////                 {
////
////                    output_debug_string("different capture (1)");
////
////                 }
////
////                 puserinteractionMouse = m_puserinteractionMouseCapture;
////
////              }
////
////              if(g_puserinteractionMouseCapture123 != nullptr)
////              {
////
////                 if(g_puserinteractionMouseCapture123 != puserinteractionMouse)
////                 {
////
////                    output_debug_string("different capture (2)");
////
////                 }
////
////              }
////              else
////              {
////
////
////
////              }
////
////
////              if(!puserinteractionMouse)
////              {
////                 
////                 if(pmouse->m_atom == e_message_left_button_down)
////                 {
////
////                    puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
////                    
////                 }
////                 else
////                 {
////
////                    puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
////
////                 }
////               
////              }
////
////              if(puserinteractionMouse)
////              {
////                 
////                 string strType2 = __type_name(puserinteractionMouse);
////                 
////                 //::output_debug_string("\nmouse: "+ strType2);
////                 
////              }
////              //}
////              
////
////              if(pmouse->m_atom == e_message_left_button_down)
////              {
////
////                 ::output_debug_string("left_button_down");
////
////              }
////              else if(pmouse->m_atom == e_message_left_button_up)
////              {
////
////                 ::output_debug_string("left_button_up");
////
////              }
////
////              string strUserInteractionType(__type_name(puserinteractionMouse));
////
////              if(pmouse->m_atom == e_message_mouse_move)
////              {
////
////                 static int s_iMotionNotify = 0;
////
////                 s_iMotionNotify++;
////
////                 if (strUserInteractionType.contains_ci("button"))
////                 {
////
////                    //output_debug_string("mouse_move::userinteraction=button");
////
////                 }
////                 else
////                 {
////
////                    puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
////
////                 }
////
////              }
////
////              if(puserinteractionMouse)
////              {
////
////                 do
////                 {
////
////                    puserinteractionMouse->route_message(pmouse);
////
////                    if(pmouse->m_bRet)
////                    {
////
////                       break;
////
////                    }
////
////                    puserinteractionMouse = puserinteractionMouse->get_parent();
////
////                 }while(puserinteractionMouse != nullptr);
////
////              }
////
////              return;
////              
////           }
////      else if (bKeyMessage)
////      {
////
////         //auto psession = get_session();
////         
////         auto pwindowing = m_pwindowing;
////
////         ::pointer < ::user::interaction > puiFocus = m_puserinteractionKeyboardFocus;
////
////         if (puiFocus)
////         {
////
////            puiFocus->send(pkey);
////
////            if (pmessage->m_bRet)
////            {
////
////               return;
////
////            }
////
////         }
////         else
////         {
////
////            m_puserinteraction->_000OnKey(pkey);
////
////            if (pmessage->m_bRet)
////            {
////
////               return;
////
////            }
////
////         }
////
////         default_message_handler(pmessage);
////
////         return;
////
////      }
////
//////      if (pmessage->m_atom == e_message_event)
//////      {
//////
//////         if (m_puserinteraction != nullptr)
//////         {
//////
//////            m_puserinteraction->on_control_event((::user::control_event *) pmessage->m_lparam.m_lparam);
//////
//////         }
//////         else
//////         {
//////
////////            on_control_event((::user::control_event *) pmessage->m_lparam.m_lparam);
//////
//////         }
//////
//////         return;
//////
//////      }
////
////      //(this->*m_pfnDispatchWindowProc)(pmessage);
////
////      m_puserinteraction->route_message(pmessage);
////
////      if (pmessage->m_bRet)
////      {
////
////         return;
////
////      }
////
////      default_message_handler(pmessage);
//
//   }
//
//
////   bool interaction_impl::IsTopParentActive()
////   {
////
////      ASSERT(get_handle() != nullptr);
////
////      ASSERT_VALID(this);
////
////      ::user::interaction *pWndTopLevel = EnsureTopLevel();
////
////      return interaction_impl::GetForegroundWindow() == pWndTopLevel->GetLastActivePopup();
////
////   }
////
////
////   void interaction_impl::ActivateTopParent()
////   {
////      // special activate logic for floating toolbars and palettes
//////      ::user::interaction * pActiveWnd = GetForegroundWindow();
////      //      if (pActiveWnd == nullptr || !(MAC_WINDOW(pActiveWnd)->get_handle() == get_handle() || ::IsChild(MAC_WINDOW(pActiveWnd)->get_handle(), get_handle())))
////      {
////         // clicking on floating frame when it does not have
////         // focus itself -- activate the toplevel frame instead.
////         EnsureTopLevel()->SetForegroundWindow();
////      }
////   }
//
//
//   /*
//
//   ::pointer < ::user::frame_window > interaction_impl::top_level_frame()
//   {
//      if (get_handle() == nullptr) // no oswindow attached
//         return nullptr;
//
//      ASSERT_VALID(this);
//
//      ::user::frame_window* pFrameWnd = nullptr;
//      if(m_puserinteraction != nullptr)
//         pFrameWnd = dynamic_cast < ::user::frame_window * > (m_puserinteraction);
//      if (pFrameWnd == nullptr || !pFrameWnd->is_frame_window())
//         pFrameWnd = get_parent_frame();
//
//      if (pFrameWnd != nullptr)
//      {
//         ::user::frame_window* pTemp;
//         while ((pTemp = pFrameWnd->get_parent_frame()) != nullptr)
//            pFrameWnd = pTemp;
//      }
//      return pFrameWnd;
//   }
//
//
//    */
//
//
//
//
////   int interaction_impl::message_box(const char * lpszText, const char * lpszCaption, unsigned int nType)
////   {
////
////      string strCaption;
////
////      if (lpszCaption == nullptr)
////         lpszCaption = papplication->m_strAppName;
////      else
////         lpszCaption = strCaption;
////
////      int nResult = ::message_box_synchronous((oswindow)get_handle(), lpszText, lpszCaption, nType);
////
////      return nResult;
////
////   }
//
//
////   ::user::interaction *  PASCAL interaction_impl::
//
////   int interaction_impl::SetScrollPos(int nBar, int nPos, bool bRedraw)
////   {
////      //      return ::SetScrollPos(get_handle(), nBar, nPos, bRedraw);
////      return 0;
////   }
////
////   int interaction_impl::GetScrollPos(int nBar) const
////   {
////      //return ::GetScrollPos(get_handle(), nBar);
////      return 0;
////   }
////
////   void interaction_impl::SetScrollRange(int nBar, int nMinPos, int nMaxPos, bool bRedraw)
////   {
////      //::SetScrollRange(get_handle(), nBar, nMinPos, nMaxPos, bRedraw);
////   }
////
////   void interaction_impl::GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const
////   {
////      //::GetScrollRange(get_handle(), nBar, lpMinPos, lpMaxPos);
////   }
//
////   // Turn on/off non-control scrollbars
////   //   for WS_?SCROLL scrollbars - show/hide them
////   //   for control scrollbar - enable/disable them
////   void interaction_impl::EnableScrollBarCtrl(int nBar, bool bEnable)
////   {
////      // WS_?SCROLL scrollbar - show or hide
////      ShowScrollBar(nBar, bEnable);
////   }
////
////   /*
////    bool interaction_impl::SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, bool bRedraw)
////    {
////    ASSERT(lpScrollInfo != nullptr);
////
////    oswindow hWnd = get_handle();
////    lpScrollInfo->cbSize = sizeof(*lpScrollInfo);
////    ::SetScrollInfo(hWnd, nBar, lpScrollInfo, bRedraw);
////    return true;
////    }
////
////    bool interaction_impl::GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, unsigned int nMask)
////    {
////    UNREFERENCED_PARAMETER(nMask);
////    ASSERT(lpScrollInfo != nullptr);
////
////    oswindow hWnd = get_handle();
////    return ::GetScrollInfo(hWnd, nBar, lpScrollInfo) != false;
////    }
////    */
////
////
////   int interaction_impl::GetScrollLimit(int nBar)
////   {
////
////      int nMin = 0, nMax = 0;
////
////      GetScrollRange(nBar, &nMin, &nMax);
////
////      return nMax;
////
////   }
////
////
////   void interaction_impl::ScrollWindow(int xAmount, int yAmount,
////                                       const INT_RECTANGLE * lpRect, const INT_RECTANGLE * lpClipRect)
////   {
////
////   }
////
////
////   void interaction_impl::CalcWindowRect(INT_RECTANGLE * lpClientRect, unsigned int nAdjustType)
////   {
////
////   }
////
////
////   bool interaction_impl::HandleFloatingSysCommand(unsigned int nID, lparam lparam)
////   {
////      /*      ::user::interaction* pParent = GetTopLevelParent();
////       switch (nID & 0xfff0)
////       {
////       case SC_PREVWINDOW:
////       case SC_NEXTWINDOW:
////       if (LOWORD(lparam) == VK_F6 && pParent != nullptr)
////       {
////       pParent->SetFocus();
////       return true;
////       }
////       break;
////
////       case SC_CLOSE:
////       case SC_KEYMENU:
////       // Check lparam.  If it is 0L, then the ::account::user may have done
////       // an Alt+Tab, so just ignore it.  This breaks the ability to
////       // just press the Alt-key and have the first menu selected,
////       // but this is minor compared to what happens in the Alt+Tab
////       // case.
////       if ((nID & 0xfff0) == SC_CLOSE || lparam != 0L)
////       {
////       if (pParent != nullptr)
////       {
////       // Sending the above WM_SYSCOMMAND may destroy the cast,
////       // so we have to be careful about restoring activation
////       // and focus after sending it.
////       oswindow hWndSave = get_handle();
////       oswindow hWndFocus = ::GetFocus();
////       pParent->SetActiveWindow();
////       pParent->send_message(WM_SYSCOMMAND, nID, lparam);
////
////       // be very careful here...
////       if (::is_window(hWndSave))
////       ::set_active_window(hWndSave);
////       if (::is_window(hWndFocus))
////       ::SetFocus(hWndFocus);
////       }
////       }
////       return true;
////       }
////       return false;*/
////      return false;
////   }
//
////   void interaction_impl::WalkPreTranslateTree(::user::interaction *  puiStop, ::message::message * pmessage)
////   {
////      ASSERT(puiStop == nullptr || puiStop->is_window());
////      ASSERT(pmessage != nullptr);
////
////      ::pointer < ::user::message > pusermessage(pmessage);
////      // walk from the target user::interaction up to the hWndStop user::interaction checking
////      //  if any user::interaction wants to translate this message
////
////      for (::pointer < ::user::interaction > pinteraction = pusermessage->m_puserinteraction; pinteraction != nullptr; pinteraction->get_parent())
////      {
////
////         pinteraction->pre_translate_message(pmessage);
////
////         if (pmessage->m_bRet)
////            return; // trapped by target user::interaction (eg: accelerators)
////
////         // got to hWndStop user::interaction without interest
////         if (pinteraction == puiStop)
////            break;
////
////      }
////      // no special processing
////   }
//
//
////   bool interaction_impl::SendChildNotifyLastMsg(LRESULT* pResult)
////   {
////
////      return false;
////
////   }
////
////   bool PASCAL interaction_impl::ReflectLastMsg(oswindow hWndChild, LRESULT* pResult)
////   {
////      // get the ::collection::map, and if no ::collection::map, then this message does not need reflection
////      /*      single_lock synchronouslock(afxMutexHwnd(), true);
////       hwnd_map * pMap = afxMapHWND();
////       if (pMap == nullptr)
////       return false;
////
////       // check if in permanent ::collection::map, if it is reflect it (could be OLE control)
////       ::user::interaction * pWnd = dynamic_cast < ::user::interaction * > (pMap->lookup_permanent(hWndChild)); */
////      ::user::interaction * pWnd = dynamic_cast <::user::interaction *> (FromHandlePermanent(hWndChild));
////      ASSERT(pWnd == nullptr || pWnd->get_handle() == hWndChild);
////      if (pWnd == nullptr)
////      {
////         return false;
////      }
////
////      // only OLE controls and permanent windows will get reflected msgs
////      ASSERT(pWnd != nullptr);
////      throw ::exception(todo);;
////      //return pWnd->SendChildNotifyLastMsg(pResult);
////
////      return false;
////   }
//
////   bool interaction_impl::OnChildNotify(unsigned int uMsg, wparam wparam, lparam lparam, LRESULT* pResult)
////   {
////
////      return ReflectChildNotify(uMsg, wparam, lparam, pResult);
////   }
//
////   bool interaction_impl::ReflectChildNotify(unsigned int uMsg, wparam wparam, lparam lparam, LRESULT* pResult)
////   {
////      UNREFERENCED_PARAMETER(wparam);
////      // Note: reflected messages are m_puserinteraction->send directly to interaction_impl::OnWndMsg
////      //  and interaction_impl::_001OnCommand for speed and because these messages are not
////      //  routed by normal _001OnCommand routing (they are only dispatched)
////
////      switch (uMsg)
////      {
////      // normal messages (just wparam, lparam through OnWndMsg)
////      case e_message_hscroll:
////      case e_message_vscroll:
////      case WM_PARENTNOTIFY:
////      case WM_DRAWITEM:
////      case e_message_measure_item:
////      case WM_DELETEITEM:
////      case WM_VKEYTOITEM:
////      case WM_CHARTOITEM:
////      case WM_COMPAREITEM:
////         // reflect the message through the message ::collection::map as WM_REFLECT_BASE+uMsg
////         //return interaction_impl::OnWndMsg(WM_REFLECT_BASE+uMsg, wparam, lparam, pResult);
////         return false;
////
////      // special case for e_message_command
////      case e_message_command:
////      {
////         // reflect the message through the message ::collection::map as OCM_COMMAND
////         /* xxx         int nCode = HIWORD(wparam);
////          if (interaction_impl::_001OnCommand(0, MAKELONG(nCode, WM_REFLECT_BASE+e_message_command), nullptr, nullptr))
////          {
////          if (pResult != nullptr)
////          *pResult = 1;
////          return true;
////          } */
////      }
////      break;
////
////      // special case for WM_NOTIFY
////      /*      case WM_NOTIFY:
////       {
////       // reflect the message through the message ::collection::map as OCM_NOTIFY
////       NMHDR* pNMHDR = (NMHDR*)lparam;
////       //            int nCode = pNMHDR->code;
////       //            __NOTIFY notify;
////       //          notify.pResult = pResult;
////       //        notify.pNMHDR = pNMHDR;
////       // xxxx         return interaction_impl::_001OnCommand(0, MAKELONG(nCode, WM_REFLECT_BASE+WM_NOTIFY), &notify, nullptr);
////       }
////
////       // other special cases (WM_CTLCOLOR family)*/
////      default:
////         if (uMsg >= WM_CTLCOLORMSGBOX && uMsg <= WM_CTLCOLORSTATIC)
////         {
////            // fill in special struct for compatiblity with 16-bit WM_CTLCOLOR
////            /*__CTLCOLOR ctl;
////             ctl.hDC = (HDC)wparam;
////             ctl.nCtlType = uMsg - WM_CTLCOLORMSGBOX;
////             //ASSERT(ctl.nCtlType >= CTLCOLOR_MSGBOX);
////             ASSERT(ctl.nCtlType <= CTLCOLOR_STATIC);
////
////             // reflect the message through the message ::collection::map as OCM_CTLCOLOR
////             bool bResult = interaction_impl::OnWndMsg(WM_REFLECT_BASE+WM_CTLCOLOR, 0, (LPARAM)&ctl, pResult);
////             if ((HBRUSH)*pResult == nullptr)
////             bResult = false;
////             return bResult;*/
////            return false;
////         }
////         break;
////      }
////
////      return false;   // let the parent handle it
////   }
//
////   void interaction_impl::OnParentNotify(const ::id & id, lparam lparam)
////   {
////      if ((LOWORD(message) == e_message_create || LOWORD(message) == e_message_destroy))
////      {
////         if (ReflectLastMsg((oswindow)lparam))
////            return;     // eat it
////      }
////      // not handled - do default
////      Default();
////   }
//
////   void interaction_impl::OnSetFocus(::user::interaction *)
////   {
////      bool bHandled;
////
////      bHandled = false;
////      if (!bHandled)
////      {
////         Default();
////      }
////   }
////
////
////   LRESULT interaction_impl::OnActivateTopLevel(wparam wparam, LPARAM)
////   {
////
////      return 0;
////
////   }
////
////   void interaction_impl::OnSysColorChange()
////   {
////      throw ::exception(error_not_implemented);;
////
////      /*      application* pApp = ::aura::get_system();
////       if (pApp != nullptr && pApp->GetMainWnd() == this)
////       {
////       // recolor global brushes used by control bars
////       afxData.UpdateSysColors();
////       }
////
////       // forward this message to all other child windows
////       if (!(GetStyle() & WS_CHILD))
////       send_message_to_descendants(WM_SYSCOLORCHANGE, 0, 0L, true, true);
////
////       Default();*/
////   }
////
////   bool gen_GotScrollLines;
////
////   void interaction_impl::OnSettingChange(unsigned int uFlags, const char * lpszSection)
////   {
////      //      UNUSED_ALWAYS(uFlags);
////      //    UNUSED_ALWAYS(lpszSection);
////
////      // force refresh of settings that we cache
////      gen_GotScrollLines = false;
////
////
////      interaction_impl::OnDisplayChange(0, 0);    // to update system metrics, etc.
////   }
//
//   /*   void interaction_impl::OnDevModeChange(__in char * lpDeviceName)
//    {
//    UNREFERENCED_PARAMETER(lpDeviceName);
//    throw ::exception(error_not_implemented);;
//    application* pApp = ::aura::get_system();
//    if (pApp != nullptr && pApp->GetMainWnd() == this)
//    pApp->DevModeChange(lpDeviceName);
//
//    // forward this message to all other child windows
//    if (!(GetStyle() & WS_CHILD))
//    {
//    const MESSAGE* pMsg = GetCurrentMessage();
//    send_message_to_descendants(pMsg->message, pMsg->wparam, pMsg->lparam,
//    true, true);
//    }*/
//   //}
//
//
//   //
//   //   bool interaction_impl::OnHelpInfo(HELPINFO* /*pHelpInfo*/)
//   //   {
//   //      if (!(GetStyle() & WS_CHILD))
//   //      {
//   //         ::user::interaction* pMainWnd = ::aura::get_system()->GetMainWnd();
//   //         if (pMainWnd != nullptr &&
//   //            GetKeyState(VK_SHIFT) >= 0 &&
//   //            GetKeyState(VK_CONTROL) >= 0 &&
//   //            GetKeyState(VK_MENU) >= 0)
//   //         {
//   //            //            pMainWnd->SendMessage(e_message_command, ID_HELP);
//   //            return true;
//   //         }
//   //      }
//   //      return Default() != 0;
//   //   }
//   //
////   LRESULT interaction_impl::OnDisplayChange(WPARAM, LPARAM)
////   {
////      if (!(GetStyle() & WS_CHILD))
////      {
////         const MESSAGE* pMsg = GetCurrentMessage();
////         send_message_to_descendants(pMsg->message, pMsg->wParam, pMsg->lParam, true, true);
////      }
////
////      return Default();
////   }
//
////   LRESULT interaction_impl::OnDragList(WPARAM, lparam lparam)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //
////      //      LPDRAGLISTINFO lpInfo = (LPDRAGLISTINFO)lparam;
////      //      ASSERT(lpInfo != nullptr);
////      //
////      //      LRESULT lResult;
////      //      if (ReflectLastMsg(lpInfo->hWnd, &lResult))
////      //         return (int)lResult;    // eat it
////      //
////      //      // not handled - do default
////      //      return (int)Default();
////   }
//
//
//   void interaction_impl::_thread_prodevian()
//   {
//
////      unsigned int tickStart;
////
////      bool bUpdateScreen = false;
////
////      while (::task_get_run())
////      {
////
////         try
////         {
////auto tickStart = ::millis::now();
////
////            if(m_puserinteraction == nullptr)
////            {
////
////               break;
////
////            }
////
////            if(m_oswindow != nullptr)
////            {
////
////               m_oswindow->m_bNsWindowRect = false;
////
////            }
////
////            if (!m_puserinteraction->m_bLockWindowUpdate)
////            {
////
////               bool bUpdateBuffer = m_puserinteraction->m_bProDevian || m_puserinteraction->_001UpdateVisual();
////
////               if(bUpdateBuffer)
////               {
////
////               }
////               else if(m_puserinteraction->is_window_visible())
////               {
////
////                  bUpdateBuffer = m_puserinteraction->has_pending_graphical_update();
////
////               }
////
////               if(bUpdateBuffer)
////               {
////
////                  _001UpdateBuffer();
////
////                  if(m_puserinteraction == nullptr)
////                  {
////
////                     break;
////
////                  }
////
////                  m_puserinteraction->on_after_graphical_update();
////
////                  bUpdateScreen = true;
////
////               }
////
////            }
////
////            if(bUpdateScreen)
////            {
////
////               unsigned long long now = get_nanos();
////
////               unsigned long long delta1 = now - m_uiLastUpdateBeg;
////
////               long long delta2 = (long long) m_uiLastUpdateBeg - (long long) m_uiLastUpdateEnd;
////
////               unsigned long long frameNanos = 1000000000LL / get_config_fps();
////
////               if(delta1 < frameNanos || (delta2 > 0 && delta2 < 10000000000LL))
////               {
////
////                  output_debug_string("opt_out set need redraw");
////
////               }
////               else
////               {
////
////                  bUpdateScreen = false;
////
////                  _001UpdateScreen();
////
////               }
////
////            }
////
////            unsigned int dwSpan = tickStart.elapsed();
////
////            if (dwSpan < 50)
////            {
////
////               sleep(50 - dwSpan);
////
////            }
////
////         }
////         catch(...)
////         {
////
////            break;
////
////         }
////
////      }
////
////      output_debug_string("m_pthreadDraw has finished!");
////
//   }
//
//
//   void interaction_impl::on_message_create(::message::message * pmessage)
//   {
//
//      __UNREFERENCED_PARAMETER(pmessage);
//
//      default_message_handler(pmessage);
//
//      if (m_puserinteraction->is_message_only_window())
//      {
//
//         information("good : opt out!");
//
//      }
//      else
//      {
//
//      }
//
////      if(::is_null(g_pappPreTranslateMouseMessage))
////      {
////
////         g_pappPreTranslateMouseMessage = ::aura::get_system()->payload("pre_translate_mouse_message").cast < ::aura::application >();
////
////      }
//      
//      m_puserbox = m_puserinteraction;
//
//   }
//
//
//   void interaction_impl::release_graphics_resources()
//   {
//
//      ::release(m_pgraphicsgraphics);
//
//   }
//
//
////   void interaction_impl::_001OnTimer(::timer * ptimer)
////   {
////
////      ::user::interaction_impl::_001OnTimer(ptimer);;
////
//////      if (ptimer->m_uEvent == 2049)
////      //    {
//////
////      //       set_need_redraw();
//////
////      //    }
////
////   }
//
//
//   /*
//
//
//      void interaction_impl::OnHScroll(unsigned int, unsigned int, CScrollBar* pScrollBar)
//      {
//         UNREFERENCED_PARAMETER(pScrollBar);
//         Default();
//      }
//
//      void interaction_impl::OnVScroll(unsigned int, unsigned int, CScrollBar* pScrollBar)
//      {
//         UNREFERENCED_PARAMETER(pScrollBar);
//         Default();
//      }
//      */
////   bool CALLBACK interaction_impl::GetAppsEnumWindowsProc(oswindow hwnd, lparam lparam)
////   {
////      user::oswindow_array * phwnda = (user::oswindow_array *) lparam;
////      phwnda->add(hwnd);
////      return true;
////   }
////
////   void interaction_impl::get_app_wnda(user::oswindow_array & wnda)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      EnumWindows(GetAppsEnumWindowsProc, (LPARAM) &wnda);
////   }
//
//   /*   void interaction_impl::_001OnDeferPaintLayeredWindowBackground(::image * pimage)
//    {
//    _001DeferPaintLayeredWindowBackground(pgraphics);
//    }*/
//
////
////   class print_window :
////      virtual ::object
////   {
////   public:
////
////
////
////      manual_reset_happening m_happening;
////      oswindow m_hwnd;
////      HDC m_hdc;
////
////      print_window(::object * pobject, oswindow hwnd, HDC hdc, unsigned int tickTimeout) :
////         ::object(pobject)
////
////      {
////         m_happening.reset_happening();
////         m_hwnd = hwnd;
////         m_hdc = hdc;
////         //begin_thread(pobject, &print_window::s_print_window, (LPVOID) this, ::priority_normal);
////         //if (m_happening.wait(millis(tickTimeout)).timeout())
////         //{
////         // information("print_window::time_out");
////         // }
////      }
////   };
////
//
////   void interaction_impl::_001DeferPaintLayeredWindowBackground(HDC hdc)
////   {
////
////      //::int_rectangle rectClient;
////
////      //client_rectangle(rectClient);
////
////
////      //pgraphics->FillSolidRect(rectClient, 0x00000000);
////
////      //return;
////
////      //auto rectUpdate = window_rectangle();
////
////      //      SetViewportOrgEx(hdc, 0, 0, nullptr);
////
////      //::int_rectangle rectPaint;
////
////      //rectPaint = rectUpdate;
////
////      //_001ScreenToClient(rectPaint);
////
////      //user::oswindow_array wndaApp;
////
////
////
////   }
//
//
//   void interaction_impl::_001OnProdevianSynch(::message::message * pmessage)
//   {
//      
//      __UNREFERENCED_PARAMETER(pmessage);
//      
//      //      ::aura::get_system()->get_event(get_application()->get_application())->set_happening();
//      //    ::aura::get_system()->get_event(::aura::get_system()->get_twf())->wait(millis(8400));
//   }
//
//   void interaction_impl::_001OnPaint(::message::message * pmessage)
//   {
//
//      //lock lock(m_puserinteraction, 2000);
//
//      throw ::exception(error_not_implemented);;
//
//   }
//
//
//   void interaction_impl::_001OnPrint(::message::message * pmessage)
//   {
//      throw ::exception(error_not_implemented);;
//      //      ::pointer < ::user::message > pusermessage(pmessage);
//      //
//      //      if(pusermessage->m_wparam == nullptr)
//      //         return;
//      //
//      //      ::draw2d::graphics_pointer graphics(this);
//      //      WIN_DC(graphics.m_p)->Attach((HDC) pusermessage->m_wparam);
//      //      ::int_rectangle rectx;
//      //      ::draw2d::bitmap * pbitmap = &pgraphics->GetCurrentBitmap();
//      //      ::GetCurrentObject((HDC) pusermessage->m_wparam, OBJ_BITMAP);
//      //      //      unsigned int dw = ::get_last_error();
//      //      ::int_size size = pbitmap->get_size();
//      //      rectx.left = 0;
//      //      rectx.top = 0;
//      //      rectx.right = size.cx();
//      //      rectx.bottom = size.cy();
//      //      try
//      //      {
//      //         ::int_rectangle rectWindow;
//      //         window_rectangle(rectWindow);
//      //
//      //         ::image_pointer pimage(this);
//      //         if(!pimage = create_image(rectWindow.bottom_right()))
//      //            return;
//      //
//      //         ::draw2d::graphics_pointer & pgraphics = pimage->get_graphics();
//      //
//      //         if(pgraphics->get_handle() == nullptr)
//      //            return;
//      //
//      //         ::int_rectangle rectPaint;
//      //         ::int_rectangle rectUpdate;
//      //         rectUpdate = rectWindow;
//      //         rectPaint = rectWindow;
//      //         rectPaint.offset(-rectPaint.top_left());
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SelectClipRgn(nullptr);
//      //         if(m_puserinteraction != nullptr && m_puserinteraction != this)
//      //         {
//      //            m_puserinteraction->_001OnDeferPaintLayeredWindowBackground(pgraphics);
//      //         }
//      //         else
//      //         {
//      //            _001OnDeferPaintLayeredWindowBackground(pgraphics);
//      //         }
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SelectClipRgn(nullptr);
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SetViewportOrg(::int_point());
//      //         _000OnDraw(pgraphics);
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SetViewportOrg(::int_point());
//      //         //(dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->FillSolidRect(rectUpdate.left, rectUpdate.top, 100, 100, 255);
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SelectClipRgn(nullptr);
//      //         (dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->SetViewportOrg(::int_point());
//      //
//      //         pgraphics->SelectClipRgn( nullptr);
//      //         pgraphics->BitBlt(rectPaint.left, rectPaint.top,
//      //            rectPaint.width(), rectPaint.height(),
//      //            pgraphics, rectUpdate.left, rectUpdate.top,
//      //            SRCCOPY);
//      //
//      //         pgraphics->text_out(0, 0, "Te Amo Carlinhos!!", 11);
//      //      }
//      //      catch(...)
//      //      {
//      //      }
//      //      pgraphics->FillSolidRect(rectx, rgb(255, 255, 255));
//      //      WIN_DC(graphics.m_p)->Detach();
//      //      pmessage->m_bRet = true;
//      //      pusermessage->set_lresult(0);
//   }
//
//
////   void interaction_impl::OnEnterIdle(unsigned int /*nWhy*/, ::user::interaction * /*pWho*/)
////   {
////      // In some OLE inplace active scenarios, OLE will m_puserinteraction->send a
////      // message instead of sending it.  This causes so many WM_ENTERIDLE
////      // messages to be sent that tasks running in the background stop
////      // running.  By dispatching the pending WM_ENTERIDLE messages
////      // when the first one is received, we trick oswindows into thinking
////      // that only one was really sent and dispatched.
////      {
////         //         MESSAGE msg;
////         throw ::exception(error_not_implemented);;
////         //while (PeekMessage(&msg, nullptr, WM_ENTERIDLE, WM_ENTERIDLE, PM_REMOVE))
////         //while (PeekMessage(&msg, ::caNULL, WM_ENTERIDLE, WM_ENTERIDLE, true))
////         // DispatchMessage(&msg);
////      }
////
////      //Default();
////   }
//
////   HBRUSH interaction_impl::OnCtlColor(::draw2d::graphics_pointer & pgraphics, ::user::interaction * pWnd, unsigned int)
////   {
//////      ASSERT(pWnd != nullptr && pWnd->get_handle() != nullptr);
//////      LRESULT lResult;
//////      if (pWnd->SendChildNotifyLastMsg(&lResult))
//////         return (HBRUSH)lResult;     // eat it
//////      return (HBRUSH)Default();
////      throw ::exception(todo);;
////      return nullptr;
////   }
//
//   // implementation of OnCtlColor for default gray backgrounds
//   //   (works for any user::interaction containing controls)
//   //  return value of false means caller must call DefWindowProc's default
//   //  true means that 'hbrGray' will be used and the appropriate text
//   //    ('clrText') and background colors are set.
////   bool PASCAL interaction_impl::GrayCtlColor(HDC hDC, oswindow hWnd, unsigned int nCtlColor,
////         HBRUSH hbrGray, color32_t clrText)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      if (hDC == nullptr)
////      //      {
////      //         // sometimes Win32 passes a nullptr hDC in the WM_CTLCOLOR message.
////      //         //         information(::ca2::trace::category_AppMsg, 0, "Warning: hDC is nullptr in interaction_impl::GrayCtlColor; WM_CTLCOLOR not processed.\n");
////      //         return false;
////      //      }
////      //
////      //      if (hbrGray == nullptr ||
////      //         nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_MSGBOX ||
////      //         nCtlColor == CTLCOLOR_SCROLLBAR)
////      //      {
////      //         return false;
////      //      }
////      //
////      //      if (nCtlColor == CTLCOLOR_LISTBOX)
////      //      {
////      //         // only handle requests to draw the space between edit and drop button
////      //         //  in a drop-down combo (not a drop-down list)
////      //         if (!__is_combo_box_control(hWnd, (unsigned int)CBS_DROPDOWN))
////      //            return false;
////      //      }
////      //
////      //      // set background color and return handle to brush
////      //      LOGBRUSH logbrush;
////      //      VERIFY(::GetObject(hbrGray, sizeof(LOGBRUSH), (LPVOID)&logbrush));
////      //      ::SetBkColor(hDC, logbrush.lbColor);
////      //      if (clrText == (color32_t)-1)
////      //         clrText = ::GetSysColor(COLOR_WINDOWTEXT);  // normal text
////      //      ::SetTextColor(hDC, clrText);
////      //      return true;
////   }
//
//
//
//   /////////////////////////////////////////////////////////////////////////////
//   // Centering dialog support (works for any non-child user::interaction)
//
////   void interaction_impl::CenterWindow(::user::interaction *  pAlternateOwner)
////   {
////      throw ::exception(error_not_implemented);;
////   }
//
////   bool interaction_impl::CheckAutoCenter()
////   {
////      return true;
////   }
//
//   /////////////////////////////////////////////////////////////////////////////
//   // Dialog initialization support
//
////   bool interaction_impl::ExecuteDlgInit(const char * lpszResourceName)
////   {
////      // find resource handle
////      LPVOID lpResource = nullptr;
////      HGLOBAL hResource = nullptr;
////      if (lpszResourceName != nullptr)
////      {
////         //         HINSTANCE hInst = ::ca2::FindResourceHandle(lpszResourceName, RT_DLGINIT);
////         //       HRSRC hDlgInit = ::FindResource(hInst, lpszResourceName, RT_DLGINIT);
////         /*     if (hDlgInit != nullptr)
////          {
////          // load it
////          hResource = LoadResource(hInst, hDlgInit);
////          if (hResource == nullptr)
////          return false;
////          // lock it
////          lpResource = LockResource(hResource);
////          ASSERT(lpResource != nullptr);
////          }*/
////      }
////
////      // execute it
////      bool bResult = ExecuteDlgInit(lpResource);
////
////      // cleanup
////      if (lpResource != nullptr && hResource != nullptr)
////      {
////         throw ::exception(error_not_implemented);;
////         //         UnlockResource(hResource);
////      }
////      return bResult;
////   }
////
////   bool interaction_impl::ExecuteDlgInit(LPVOID lpResource)
////   {
////      throw ::exception(error_not_implemented);;
////   }
////
////   void interaction_impl::UpdateDialogControls(channel* pTarget, bool bDisableIfNoHndler)
////   {
////      UNREFERENCED_PARAMETER(pTarget);
////      UNREFERENCED_PARAMETER(bDisableIfNoHndler);
////      ::message::command state(this);
////      user::interaction wndTemp;       // very temporary user::interaction just for CmdUI update
////
////      // walk all the kids - assume the IDs are for buttons
////      /* xxx   for (oswindow hWndChild = ::GetTopWindow(get_handle()); hWndChild != nullptr;
////       hWndChild = ::GetNextWindow(hWndChild, GW_HWNDNEXT))
////       {
////       // m_puserinteraction->send to buttons
////       wndTemp.set_handle(hWndChild); // quick and dirty attach
////       state.m_nID = __get_dialog_control_id(hWndChild);
////       state.m_pOther = &wndTemp;
////
////       // check for reflect handlers in the child user::interaction
////       ::user::interaction * pWnd = ::macos::interaction_impl::FromHandlePermanent(hWndChild);
////       if (pWnd != nullptr)
////       {
////       // call it directly to disable any routing
////       if (MAC_WINDOW(pWnd)->interaction_impl::_001OnCommand(0, MAKELONG(0xffff,
////       e_message_command+WM_REFLECT_BASE), &state, nullptr))
////       continue;
////       }
////
////       // check for handlers in the parent user::interaction
////       if (interaction_impl::_001OnCommand((unsigned int)state.m_nID, CN_UPDATE_::message::command, &state, nullptr))
////       continue;
////
////       // determine whether to disable when no handler exists
////       bool bDisableTemp = bDisableIfNoHndler;
////       if (bDisableTemp)
////       {
////       if ((wndTemp.SendMessage(WM_GETDLGCODE) & DLGC_BUTTON) == 0)
////       {
////       // non-button controls don't get automagically disabled
////       bDisableTemp = false;
////       }
////       else
////       {
////       // only certain button controls get automagically disabled
////       unsigned int nStyle = (unsigned int)(wndTemp.GetStyle() & 0x0F);
////       if (nStyle == (unsigned int)BS_AUTOCHECKBOX ||
////       nStyle == (unsigned int)BS_AUTO3STATE ||
////       nStyle == (unsigned int)BS_GROUPBOX ||
////       nStyle == (unsigned int)BS_AUTORADIOBUTTON)
////       {
////       bDisableTemp = false;
////       }
////       }
////       }
////       // check for handlers in the target (owner)
////       state.DoUpdate(pTarget, bDisableTemp);
////       }
////       wndTemp.set_handle(nullptr);      // quick and dirty detach */
////   }
//
//
////   bool interaction_impl::IsFrameWnd()
////   {
////      return false;
////   }
//
////   bool interaction_impl::SubclassWindow(oswindow hWnd)
////   {
////      if (!Attach(hWnd))
////         return false;
////
////      // allow any other subclassing to occur
////      pre_subclass_window();
////
////      throw ::exception(error_not_implemented);;
////   }
////
////   oswindow interaction_impl::UnsubclassWindow()
////   {
////      ASSERT(::is_window(get_handle()));
////
////      throw ::exception(error_not_implemented);;
////      //      // set WNDPROC back to original value
////      //      WNDPROC* lplpfn = GetSuperWndProcAddr();
////      //      SetWindowLongPtr(get_handle(), GWLP_WNDPROC, (iptr)*lplpfn);
////      //      *lplpfn = nullptr;
////      //
////      //      // and Detach the oswindow from the user::interaction object
////      //      return Detach();
////   }
//
////
////   bool interaction_impl::IsChild(::user::interaction *  pWnd)
////   {
////      ASSERT(::is_window(get_handle()));
////      if (pWnd->get_handle() == nullptr)
////      {
////         return ::user::interaction_impl::is_child(pWnd);
////      }
////      else
////      {
////         //         return ::IsChild(get_handle(), MAC_WINDOW(pWnd)->get_handle()) != false;
////         return false;
////      }
////   }
////
////
////   bool interaction_impl::_is_window() const
////   {
////
////      return ::is_window(m_oswindow) != false;
////
////   }
//
//
////   ::user::interaction * interaction_impl::get_wnd() const
////   {
////
////      return m_puserinteraction;
////
////   }
//
//
////   void interaction_impl::MoveWindow(int x, int y, int nWidth, int nHeight, bool bRepaint)
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      set_window_position(zorder_none, x, y, nWidth, nHeight, bRepaint ? SWP_SHOWWINDOW : 0);
////
////   }
//
//
////   double_point interaction_impl::client_screen_top_left()
////   {
////
////      ::huge_int_rectangle rectWindow;
////
////      if (!m_puserinteraction->window_rectangle(rectWindow))
////      {
////
////         return point(0.0, 0.0);
////
////      }
////
////      return rectWindow.top_left();
////
////   }
//
//
////   bool interaction_impl::window_rectangle(RECTANGLE_I64 * lprect)
////   {
////
////      return ::user::interaction_impl::window_rectangle(lprect);
////
////   }
////
////
////   bool interaction_impl::client_rectangle(RECTANGLE_I64 * lprect)
////   {
////
////      if (!::is_window(get_handle()))
////      {
////
////         return false;
////
////      }
////
////      ::int_rectangle rect32;
////
////      if (!::client_rectangle(get_handle(), rect32))
////      {
////
////         return false;
////
////      }
////
////      ::copy(lprect, rect32);
////
////      return true;
////
////   }
////
////
////   id interaction_impl::SetDlgCtrlId(id id)
////   {
////
////      return m_puserinteraction->SetDlgCtrlId((id));
////
////   }
////
////
////   id interaction_impl::GetDlgCtrlId()
////   {
////
////      return m_puserinteraction->GetDlgCtrlId();
////
////   }
//
//
////   void interaction_impl::window_impl_maximize()()
////   {
////
////      ::user::interaction_impl::_001WindowMaximize();
////
////   }
////
////
////   void interaction_impl::_001WindowRestore()
////   {
////
////      m_puserinteraction->m_edisplay = user::e_display_normal;
////
////      if (m_puserinteraction != nullptr)
////      {
////
////         m_puserinteraction->m_edisplay = user::e_display_normal;
////
////      }
////
////   }
//
//
//   void interaction_impl::show_task(bool bShow)
//   {
//
//      if(bShow)
//      {
//
//         node()->defer_dock_application(true);
//
//         m_puserinteraction->set_need_layout();
//
//         m_puserinteraction->set_need_redraw();
//
//      }
//      else
//      {
//
//         node()->defer_dock_application(false);
//
//      }
//
//   }
//
//
////   bool interaction_impl::ShowWindow(int nCmdShow)
////   {
////
////      return ::user::interaction_impl::ShowWindow(nCmdShow);
////
//////      if (!::is_window(get_handle()))
//////      {
//////
//////         return false;
//////
//////      }
//////
//////      if(nCmdShow <= SW_HIDE)
//////      {
//////
//////         aura_window_hide();
//////
//////
//////      }
//////      else
//////      {
//////
//////         ::show_window(get_handle(), nCmdShow);
//////
//////         //m_puserinteraction->send_message(e_message_show_window, ::IsWindowVisible(get_handle()));
//////
//////      }
//////
//////      //deferred_on_change_visibility();
//////
//////      return m_puserinteraction->is_window_visible();
////
////   }
//
//
//   bool interaction_impl::window_impl_is_iconic()
//   {
//
////      if(!::is_window(get_handle()))
////      {
////         return false;
////      }
//
//      return m_puserinteraction->layout().is_iconic();
//
//   }
//
//
////   ::user::interaction * interaction_impl::get_parent() const
////   {
////
////      return nullptr;
////
////   }
////
////
////   int interaction_impl::GetWindowLong(int nIndex)
////   {
////
////      return get_window_long(nIndex);
////
////   }
////
////
////   int interaction_impl::SetWindowLong(int nIndex, int lValue)
////   {
////
////      return set_window_long(nIndex, lValue);
////
////   }
////
////
////   unsigned int interaction_impl::GetStyle() const
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      return get_window_long(GWL_STYLE);
////
////   }
////
////
////   unsigned int interaction_impl::GetExStyle() const
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      return get_window_long(GWL_EXSTYLE);
////
////   }
////
//
////   bool interaction_impl::ModifyStyle(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      return ModifyStyle(get_handle(), dwRemove, dwAdd, nFlags);
////
////   }
////
////
////   bool interaction_impl::ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      return ModifyStyleEx(get_handle(), dwRemove, dwAdd, nFlags);
////
////   }
//
//
////   ::user::interaction *  interaction_impl::SetOwner(::user::interaction *  pOwnerWnd)
////   {
////
////      return nullptr;
////
////   }
//
////
////   lresult interaction_impl::send_message(const ::id & id, wparam wparam, lparam lparam)
////   {
////
////      return ::user::interaction_impl::send_message(message, wparam, lparam);
////
////   }
////
////
////   bool interaction_impl::post_message(const ::id & id, wparam wparam, lparam lparam)
////   {
////
////      if (m_puserinteraction->m_pthreadUserInteraction == nullptr)
////      {
////
////         return false;
////
////      }
////
////      auto pmq = m_puserinteraction->m_pthreadUserInteraction->get_message_queue();
////
////      return pmq->post_message(m_oswindow, message, wparam, lparam);
////
////      //return ::post_message((oswindow) m_oswindow, message, wparam, lparam);
////
////   }
//
//
////   bool interaction_impl::DragDetect(const ::int_point & point) const
////   {
////
////      throw ::exception(error_not_implemented);;
////
////      return true;
////
////   }
//
//
////   void interaction_impl::set_window_text(const ::string & lpszString)
////   {
////
////      m_strWindowText = lpszString;
////
////      //aura_window_set_title(m_strWindowText);
////
////   }
//
////
////   void interaction_impl::DragAcceptFiles(bool bAccept)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
//
////   void interaction_impl::MoveWindow(const INT_RECTANGLE * lpRect, bool bRepaint)
////   {
////
////      MoveWindow(lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top, bRepaint);
////
////   }
////
////
////   unsigned int interaction_impl::ArrangeIconicWindows()
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
////
////   int interaction_impl::SetWindowRgn(HRGN hRgn, bool bRedraw)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   int interaction_impl::GetWindowRgn(HRGN hRgn)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   void interaction_impl::bring_to_top(::e_display edisplay)
////   {
////
////      ::user::interaction_impl::bring_to_top(edisplay);
////
//////      return;
//////
//////      if (nCmdShow > SW_HIDE && nCmdShow != SW_MINIMIZE)
//////      {
//////
//////         BringWindowToTop();
//////
//////         //aura_window_show();
//////
//////      }
////
////   }
//
//
////   bool interaction_impl::BringWindowToTop()
////   {
////
////      bool b = ::BringWindowToTop(get_handle()) != false;
////
////      return b;
////
////   }
//
//
////   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, INT_POINT * lpPoint, unsigned int nCount)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, INT_RECTANGLE * lpRect)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   ::draw2d::graphics * interaction_impl::GetDC()
////   {
////
////      return nullptr;
////
////   }
////
////
////   ::draw2d::graphics * interaction_impl::GetWindowDC()
////   {
////
////      return nullptr;
////
////   }
////
////
////   bool interaction_impl::ReleaseDC(::draw2d::graphics_pointer & pgraphics)
////   {
////
////      if (pgraphics == nullptr)
////      {
////
////         return false;
////
////      }
////
////      return true;
////
////   }
//
//
////   void interaction_impl::UpdateWindow()
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   void interaction_impl::SetRedraw(bool bRedraw)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   bool interaction_impl::GetUpdateRect(INT_RECTANGLE * lpRect, bool bErase)
////   {
////
////      throw ::exception(error_not_implemented);
////
////   }
////
////
////   int interaction_impl::GetUpdateRgn(::draw2d::region* pRgn, bool bErase)
////   {
////
////      throw ::exception(error_not_implemented);
////
////   }
////
////
////   void interaction_impl::Invalidate(bool bErase)
////   {\
////
////      m_bNeedsUpdate = true;
////
////   }
////
////
////   void interaction_impl::InvalidateRect(const ::int_rectangle & rectangle, bool bErase)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::InvalidateRgn(::draw2d::region* pRgn, bool bErase)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::ValidateRect(const ::int_rectangle & rectangle)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::ValidateRgn(::draw2d::region* pRgn)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   bool interaction_impl::window_impl_is_visible()
////   {
////
////      if (!::is_window(get_handle()))
////      {
////
////         return false;
////
////      }
////
//////      if (m_puserinteraction != nullptr)
//////      {
//////
//////         if (!m_puserinteraction->is_this_visible())
//////         {
//////
//////            return false;
//////
//////         }
//////
//////         if (m_puserinteraction->get_parent() != nullptr && !m_puserinteraction->get_parent()->is_window_visible())
//////         {
//////
//////            return false;
//////
//////         }
//////
//////      }
////
////      if (!::IsWindowVisible(get_handle()))
////      {
////
////         return false;
////
////      }
////
////      return true;
////
////   }
//
//
////   void interaction_impl::ShowOwnedPopups(bool bShow)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   void interaction_impl::send_message_to_descendants(const ::id & id, wparam wparam, lparam lparam, bool bDeep, bool bOnlyPerm)
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      // walk through oswindows to avoid creating temporary user::interaction objects
////      // unless we need to call this function recursively
////      user::interaction * pinteraction = m_puserinteraction->top_child();
////
////      while (pinteraction != nullptr)
////      {
////
////         try
////         {
////
////            pinteraction->send_message(message, wparam, lparam);
////
////         }
////         catch (...)
////         {
////
////         }
////
////         if (bDeep)
////         {
////
////            // m_puserinteraction->send to child windows after parent
////
////            try
////            {
////
////               pinteraction->send_message_to_descendants(message, wparam, lparam, bDeep, bOnlyPerm);
////
////            }
////            catch (...)
////            {
////
////            }
////
////         }
////
////         try
////         {
////
////            pinteraction = pinteraction->under_sibling();
////
////         }
////         catch (...)
////         {
////
////            break;
////
////         }
////
////      }
////
////   }
//
//
//
////   ::draw2d::graphics * interaction_impl::GetDCEx(::draw2d::region* prgnClip, unsigned int flags)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   bool interaction_impl::LockWindowUpdate()
////   {
////
////      throw ::exception(error_not_implemented);
////
////   }
////
////
////   void interaction_impl::UnlockWindowUpdate()
////   {
////
////      throw ::exception(error_not_implemented);
////
////   }
////
//
//   void interaction_impl::on_show_window()
//   {
//
//      ::user::interaction_impl::on_show_window();
//
////      if(show_window_is_visible(m_puserinteraction->m_iShowWindowRequest))
////      {
////
////         aura_window_show();
////
////      }
////      else if(show_window_is_visible(m_puserinteraction->m_iShowWindowRequest))
////      {
////
////         aura_window_hide();
////
////      }
//
//   }
//
//
//   void interaction_impl::on_zorder()
//   {
//
////      if (m_bZ)
////      {
////
////         ::set_window_position(m_oswindow, (oswindow) m_iZ,
////                        0,
////                        0,
////                        0,
////                        0,
////                        SWP_NOSIZE
////                        | SWP_NOMOVE
////                        | (m_bZ ? 0 : SWP_NOZORDER)
////                        | SWP_NOREDRAW
////                        | SWP_NOCOPYBITS
////                        | SWP_NOACTIVATE
////                        | SWP_NOOWNERZORDER
////                        | SWP_NOSENDCHANGING
////                        | SWP_DEFERERASE);
////
////         m_bZ = false;
////
////      }
//
//      //::user::interaction_impl::on_reposition();
//
//   }
//
//
//   void interaction_impl::on_reposition()
//   {
//
////      if (m_rectLastOsPlacement.top_left() != m_puserinteraction.m_rectParentClientRequest.top_left())
////      {
////
////         ::set_window_position(m_oswindow, (oswindow) m_iZ,
////                        (int) m_puserinteraction->m_rectParentClientRequest.left,
////                        (int) m_puserinteraction->m_rectParentClientRequest.top,
////                        0,
////                        0,
////                        SWP_NOSIZE
////                        | (m_bZ ? 0 : SWP_NOZORDER)
////                        | SWP_NOREDRAW
////                        | SWP_NOCOPYBITS
////                        | SWP_NOACTIVATE
////                        | SWP_NOOWNERZORDER
////                        | SWP_NOSENDCHANGING
////                        | SWP_DEFERERASE);
////
////         m_rectLastOsPlacement.move_to(m_puserinteraction.m_rectParentClientRequest.top_left());
////
////      }
//
//      //::user::interaction_impl::on_reposition();
//
//   }
//
//
//   void interaction_impl::on_layout(::draw2d::graphics_pointer & pgraphics)
//   {
//
////      if (m_rectLastOsPlacement != m_puserinteraction.m_rectParentClientRequest)
////      {
////
////         ::set_window_position(m_oswindow, (oswindow) m_iZ,
////                        (int) m_puserinteraction->m_rectParentClientRequest.left,
////                        (int) m_puserinteraction->m_rectParentClientRequest.top,
////                        (int) m_puserinteraction->m_rectParentClientRequest.width(),
////                        (int) m_puserinteraction->m_rectParentClientRequest.height(),
////                        (m_bZ ? 0 : SWP_NOZORDER)
////                        | SWP_NOREDRAW
////                        | SWP_NOCOPYBITS
////                        | SWP_NOACTIVATE
////                        | SWP_NOOWNERZORDER
////                        | SWP_NOSENDCHANGING
////                        | SWP_DEFERERASE);
////
////         m_puserinteraction->m_rectParentClient = m_puserinteraction.m_rectParentClientRequest;
////
////         m_rectLastOsPlacement = m_puserinteraction.m_rectParentClientRequest;
////
////      }
//
//      //::user::interaction_impl::on_layout(pgraphics);
//
//   }
//
//
////   void interaction_impl::_001UpdateScreen()
////   {
////
////
////
////      if (m_puserinteraction->is_window_visible())
////      {
////
////         //aura_window_redraw();
////
////      }
////
////   }
//
//
////   bool interaction_impl::DrawAnimatedRects(int idAni, const INT_RECTANGLE *lprcFrom, const INT_RECTANGLE * lprcTo)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
//
//
////   bool interaction_impl::DrawCaption(::draw2d::graphics_pointer & pgraphics, const ::int_rectangle & rectangle, unsigned int uFlags)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////      return false;
////
////   }
//
//
////   bool interaction_impl::SetTimer(uptr uEvent, unsigned int nElapse, PFN_TIMER pfnTimer)
////   {
////
////      return ::user::interaction_impl::SetTimer(uEvent, nElapse, pfnTimer);
////
////   }
////
////
////   bool interaction_impl::KillTimer(uptr uEvent)
////   {
////
////      return ::user::interaction_impl::KillTimer(uEvent);
////
////   }
//
//
//   bool interaction_impl::IsWindowEnabled()
//   {
//
//      return true;
//
//   }
//
//
////   bool interaction_impl::enable_window(bool bEnable)
////   {
////
////      m_bEnabled = bEnable;
////
////      return true;
////
////   }
//
//
////   ::user::interaction *  interaction_impl::GetActiveWindow()
////   {
////
////      ::user::interaction_impl * pimpl = ::macos::interaction_impl::from_handle(::get_active_window());
////
////      if(pimpl == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      try
////      {
////
////         return pimpl->m_puserinteraction;
////
////      }
////      catch(...)
////      {
////
////      }
////
////      return nullptr;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::SetActiveWindow()
////   {
////
////      ::user::interaction_impl * pimpl = ::macos::interaction_impl::from_handle(::set_active_window(get_handle()));
////
////      if(pimpl == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      return pimpl->m_puserinteraction;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::GetFocus()
////   {
////
////      ::user::interaction_impl * pimpl = ::macos::interaction_impl::from_handle(::get_focus());
////
////      if(pimpl == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      return pimpl->m_puserinteraction;
////
////   }
////
////
////   bool  interaction_impl::SetFocus()
////   {
////
////      ::user::interaction_impl * pimpl = ::macos::interaction_impl::from_handle(::set_focus(get_handle()));
////
////      if(pimpl == nullptr)
////      {
////
////         return nullptr;
////
////      }
////
////      return pimpl->m_puserinteraction;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::get_desktop_window()
////   {
////
////      return nullptr;
////
////   }
////
////
////   // Helper for radio buttons
////   int interaction_impl::GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton)
////   {
////
////      for (int nID = nIDFirstButton; nID <= nIDLastButton; nID++)
////      {
////
////         if (IsDlgButtonChecked(nID))
////         {
////
////            return nID; // id that matched
////
////         }
////
////      }
////
////      return 0; // invalid ID
////
////   }
////
////
////   void interaction_impl::CheckDlgButton(int nIDButton, unsigned int nCheck)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::CheckRadioButton(int nIDFirstButton, int nIDLastButton, int nIDCheckButton)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   int interaction_impl::DlgDirList(char * lpPathSpec, int nIDListBox, int nIDStaticPath, unsigned int nFileType)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   int interaction_impl::DlgDirListComboBox(char * lpPathSpec, int nIDComboBox, int nIDStaticPath, unsigned int nFileType)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   bool interaction_impl::DlgDirSelect(char * lpString, int nSize, int nIDListBox)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   bool interaction_impl::DlgDirSelectComboBox(char * lpString, int nSize, int nIDComboBox)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   ::user::interaction * interaction_impl::GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious) const
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   ::user::interaction * interaction_impl::GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious) const
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   unsigned int interaction_impl::IsDlgButtonChecked(int nIDButton) const
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   LPARAM interaction_impl::SendDlgItemMessage(int nID, const ::id & id, wparam wparam, lparam lparam)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::SetDlgItemInt(int nID, unsigned int nValue, bool bSigned)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::SetDlgItemText(int nID, const char * lpszString)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   int interaction_impl::ScrollWindowEx(int greekdeltax, int greekdeltay, const INT_RECTANGLE * lpRectScroll, const INT_RECTANGLE * lpRectClip, ::draw2d::region* prgnUpdate, INT_RECTANGLE * lpRectUpdate, unsigned int flags)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::ShowScrollBar(unsigned int nBar, bool bShow)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::ChildWindowFromPoint(const ::int_point & point)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::ChildWindowFromPoint(const ::int_point & point, unsigned int nFlags)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
//
//
//
////   ::user::interaction *  interaction_impl::GetNextWindow(unsigned int nFlag)
////   {
////
////      return nullptr;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::GetTopWindow()
////   {
////
////      if (m_puserinteraction->m_uiptraChild.is_there_no_interaction())
////      {
////
////         return nullptr;
////
////      }
////
////      return m_puserinteraction->m_uiptraChild.interaction_at(0);
////
////   }
////
////
////   ::user::interaction *  interaction_impl::GetWindow(unsigned int nCmd)
////   {
////
////      ASSERT(::is_window(get_handle()));
////
////      return nullptr;
////
////   }
////
////
////   ::user::interaction *  interaction_impl::GetLastActivePopup()
////   {
////
////      throw ::exception(todo);;
////
////   }
////
////
////   ::user::interaction * interaction_impl::SetParent(::user::interaction * pWndNewParent)
////   {
////
//////      ::user::interaction_impl * pimpl = ::macos::interaction_impl::from_handle(::SetParent(get_handle(), (oswindow)pWndNewParent->get_handle()));
//////
//////      if(pimpl == nullptr)
//////      {
//////
//////         return nullptr;
//////
//////      }
//////
//////      return pimpl->m_puserinteraction;
////
////      return ::user::interaction_impl::SetParent(pWndNewParent);
////
////   }
////
////
////   ::user::interaction * PASCAL interaction_impl::oswindowFromPoint(INT_POINT int_point)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   bool interaction_impl::FlashWindow(bool bInvert)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::FlashWindow(get_handle(), bInvert) != false;
////
////   }
////
////   bool interaction_impl::ChangeClipboardChain(oswindow hWndNext)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::ChangeClipboardChain(get_handle(), hWndNext) != false;
////
////   }
////
////   oswindow interaction_impl::SetClipboardViewer()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::SetClipboardViewer(get_handle());
////
////   }
////
////   bool interaction_impl::OpenClipboard()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::OpenClipboard(get_handle()) != false;
////
////   }
////
////   ::user::interaction * PASCAL interaction_impl::GetOpenClipboardWindow()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      return ::macos::interaction_impl::from_handle(::GetOpenClipboardWindow());
////
////   }
////
////   ::user::interaction * PASCAL interaction_impl::GetClipboardOwner()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      return ::macos::interaction_impl::from_handle(::GetClipboardOwner());
////
////   }
////
////   ::user::interaction * PASCAL interaction_impl::GetClipboardViewer()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      return ::macos::interaction_impl::from_handle(::GetClipboardViewer());
////
////   }
////
////
////
////   int_point PASCAL interaction_impl::GetCaretPos()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ::int_point point;
////      //      ::GetCaretPos((INT_POINT *)&point); return point;
////
////   }
////
////   void PASCAL interaction_impl::SetCaretPos(INT_POINT int_point)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ::SetCaretPos(point.x, point.y);
////
////   }
////
////   void interaction_impl::HideCaret()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ::HideCaret(get_handle());
////
////   }
////
////   void interaction_impl::ShowCaret()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //    ::ShowCaret(get_handle());
////
////   }
////
////   bool interaction_impl::SetForegroundWindow()
////   {
////
////      bool b = ::SetForegroundWindow(get_handle()) != false;
////
////      //      aura_window_show();
////
////      return b;
////
////   }
////
////   ::user::interaction * PASCAL interaction_impl::GetForegroundWindow()
////   {
////
////      return nullptr;
////      // return ::macos::interaction_impl::from_handle(::GetForegroundWindow());
////
////   }
//
////   bool interaction_impl::SendNotifyMessage(const ::id & id, wparam wparam, lparam lparam)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      return ::SendNotifyMessage(get_handle(), message, wparam, lparam) != false;
////
////   }
//
//
////   void interaction_impl::Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      const_cast < user::interaction * > (this)->send_message(WM_PRINT, (WPARAM)(dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->get_handle(), dwFlags);
////
////   }
////
////   void interaction_impl::PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      const_cast < user::interaction * > (this)->send_message(WM_PRINTCLIENT, (WPARAM)(dynamic_cast<::draw2d_quartz2d::graphics * >(pgraphics))->get_handle(), dwFlags);
////
////   }
//
////   bool interaction_impl::SetWindowContextHelpId(unsigned int dwContextHelpId)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::SetWindowContextHelpId(get_handle(), dwContextHelpId) != false;
////
////   }
////
////   unsigned int interaction_impl::GetWindowContextHelpId() const
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::GetWindowContextHelpId(get_handle());
////
////   }
//
//
//   // Default message ::collection::map implementations
////   void interaction_impl::OnActivateApp(bool, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnActivate(unsigned int, ::user::interaction *, bool)
////   {
////      Default();
////   }
////   void interaction_impl::OnCancelMode()
////   {
////      Default();
////   }
////   void interaction_impl::OnChildActivate()
////   {
////      Default();
////   }
////   void interaction_impl::OnClose()
////   {
////      Default();
////   }
////   void interaction_impl::OnContextMenu(::user::interaction *, int_point)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnCopyData(::user::interaction *, COPYDATASTRUCT*)
////   {
////
////      return Default() != false;
////
////   }
//
////   void interaction_impl::OnEnable(bool)
////   {
////      Default();
////   }
////   void interaction_impl::OnEndSession(bool)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnEraseBkgnd(::draw2d::graphics *)
////   {
////
////      return Default() != false;
////
////   }
////
////   void interaction_impl::OnGetMinMaxInfo(MINMAXINFO*)
////   {
////      Default();
////   }
////   void interaction_impl::OnIconEraseBkgnd(::draw2d::graphics *)
////   {
////      Default();
////   }
////   void interaction_impl::OnKillFocus(::user::interaction *)
////   {
////      Default();
////   }
////   LRESULT interaction_impl::OnMenuChar(unsigned int, unsigned int, ::user::menu*)
////   {
////      return Default();
////   }
////   void interaction_impl::OnMenuSelect(unsigned int, unsigned int, HMENU)
////   {
////      Default();
////   }
////   void interaction_impl::OnMove(int, int)
////   {
////      Default();
////   }
////   HCURSOR interaction_impl::OnQueryDragIcon()
////   {
////      return (HCURSOR)Default();
////   }
////
////   bool interaction_impl::OnQueryEndSession()
////   {
////
////      return Default() != false;
////
////   }
////
////   bool interaction_impl::OnQueryNewPalette()
////   {
////
////      return Default() != false;
////
////   }
////
////   bool interaction_impl::OnQueryOpen()
////   {
////
////      return Default() != false;
////
////   }
////
////   void interaction_impl::_001OnSetCursor(::message::message * pmessage)
////   {
////      ::pointer < ::user::message > pusermessage(pmessage);
////      if (psession->get_cursor() != nullptr
////            && psession->get_cursor()->m_ecursor != cursor_system)
////      {
////
////         throw ::exception(error_not_implemented);;
////         //         ::SetCursor(nullptr);
////      }
////      pusermessage->set_lresult(1);
////      pusermessage->m_bRet = true;
////      //(bool)Default();
////   }
////   void interaction_impl::OnShowWindow(bool, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnSize(unsigned int, int, int)
////   {
////      Default();
////   }
////   void interaction_impl::OnTCard(unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnWindowPosChanging(WINDOWPOS*)
////   {
////      Default();
////   }
////   void interaction_impl::OnWindowPosChanged(WINDOWPOS*)
////   {
////      Default();
////   }
////   void interaction_impl::OnDropFiles(HDROP)
////   {
////      Default();
////   }
////   void interaction_impl::OnPaletteIsChanging(::user::interaction *)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnNcActivate(bool)
////   {
////
////      return Default() != false;
////
////   }
////
////   void interaction_impl::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnNcCreate(::user::system *)
////   {
////
////      return Default() != false;
////
////   }
////
////   LRESULT interaction_impl::OnNcHitTest(point)
////   {
////      return Default();
////   }
////   void interaction_impl::OnNcLButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcLButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcLButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcMButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcMButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcMButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcMouseMove(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcPaint()
////   {
////      Default();
////   }
////   void interaction_impl::OnNcRButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcRButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnNcRButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnSysChar(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnSysCommand(unsigned int, LPARAM)
////   {
////      Default();
////   }
////   void interaction_impl::OnSysDeadChar(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnSysKeyDown(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnSysKeyUp(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnCompacting(unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnFontChange()
////   {
////      Default();
////   }
////   void interaction_impl::OnPaletteChanged(::user::interaction *)
////   {
////      Default();
////   }
////   void interaction_impl::OnSpoolerStatus(unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnTimeChange()
////   {
////      Default();
////   }
////   void interaction_impl::OnChar(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnDeadChar(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnKeyDown(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnKeyUp(unsigned int, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnLButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnLButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnLButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnMButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnMButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnMButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   int interaction_impl::OnMouseActivate(::user::interaction *, unsigned int, unsigned int)
////   {
////      return (int)Default();
////   }
////   void interaction_impl::OnMouseMove(unsigned int, int_point)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnMouseWheel(unsigned int, short, int_point)
////   {
////
////      return Default() != false;
////
////   }
//
////   LRESULT interaction_impl::OnRegisteredMouseWheel(WPARAM, LPARAM)
////   {
////      return Default();
////   }
////   void interaction_impl::OnRButtonDblClk(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnRButtonDown(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnRButtonUp(unsigned int, int_point)
////   {
////      Default();
////   }
////   void interaction_impl::OnTimer(uptr)
////   {
////      Default();
////   }
////   void interaction_impl::OnInitMenu(::user::menu*)
////   {
////      Default();
////   }
////   void interaction_impl::OnInitMenuPopup(::user::menu*, unsigned int, bool)
////   {
////      Default();
////   }
////   void interaction_impl::OnAskCbFormatName(unsigned int nMaxCount, char * pszName)
////   {
////      //      (nMaxCount);
////      if (nMaxCount > 0)
////      {
////         /* defwindow proc should do this for us, but to be safe, we'll do it here too */
////         pszName[0] = '\0';
////      }
////      Default();
////   }
////   void interaction_impl::OnChangeCbChain(oswindow, oswindow)
////   {
////      Default();
////   }
////   void interaction_impl::OnDestroyClipboard()
////   {
////      Default();
////   }
////   void interaction_impl::OnDrawClipboard()
////   {
////      Default();
////   }
////   void interaction_impl::OnHScrollClipboard(::user::interaction *, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnPaintClipboard(::user::interaction *, HGLOBAL)
////   {
////      Default();
////   }
////   void interaction_impl::OnRenderAllFormats()
////   {
////      Default();
////   }
////   void interaction_impl::OnRenderFormat(unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnSizeClipboard(::user::interaction *, HGLOBAL)
////   {
////      Default();
////   }
////   void interaction_impl::OnVScrollClipboard(::user::interaction *, unsigned int, unsigned int)
////   {
////      Default();
////   }
////   unsigned int interaction_impl::OnGetDlgCode()
////   {
////      return (unsigned int)Default();
////   }
////   void interaction_impl::OnMDIActivate(bool, ::user::interaction *, ::user::interaction *)
////   {
////      Default();
////   }
////   void interaction_impl::OnEnterMenuLoop(bool)
////   {
////      Default();
////   }
////   void interaction_impl::OnExitMenuLoop(bool)
////   {
////      Default();
////   }
//   // Win4 support
//   //   void interaction_impl::OnStyleChanged(int, LPSTYLESTRUCT)
//   //   { Default(); }
//   //   void interaction_impl::OnStyleChanging(int, LPSTYLESTRUCT)
//   //   { Default(); }
////   void interaction_impl::OnSizing(unsigned int, INT_RECTANGLE *)
////   {
////      Default();
////   }
////   void interaction_impl::OnMoving(unsigned int, INT_RECTANGLE *)
////   {
////      Default();
////   }
////   void interaction_impl::OnCaptureChanged(::user::interaction *)
////   {
////      Default();
////   }
////
////   bool interaction_impl::OnDeviceChange(unsigned int, uptr)
////   {
////
////      return Default() != false;
////
////   }
////
////   void interaction_impl::OnWinIniChange(const char *)
////   {
////      Default();
////   }
////   void interaction_impl::OnChangeUIState(unsigned int, unsigned int)
////   {
////      Default();
////   }
////   void interaction_impl::OnUpdateUIState(unsigned int, unsigned int)
////   {
////      Default();
////   }
////
////   unsigned int interaction_impl::OnQueryUIState()
////   {
////
////      return (unsigned int)Default();
////
////   }
//
//   // user::interaction dialog data support
//   //    void interaction_impl::DoDataExchange(CDataExchange*)
//   //   { } // default does nothing
//
//   // user::interaction modality support
//
////   void interaction_impl::BeginModalState()
////   {
////
////      throw ::exception(todo);;
////
////      //::EnableWindow(get_handle(), false);
////
////   }
////
////   void interaction_impl::EndModalState()
////   {
////
////      throw ::exception(todo);;
////
////      //::EnableWindow(get_handle(), true);
////
////   }
////
//   // frame_window
//   /*    void frame_window::DelayUpdateFrameTitle()
//    { m_nIdleFlags |= idleTitle; }
//    void frame_window::DelayRecalcLayout(bool bNotify)
//    { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
//    bool frame_window::InModalState() const
//    { return m_cModalStack != 0; }
//    void frame_window::set_title(const char * lpszTitle)
//    { m_strTitle = lpszTitle; }
//    string frame_window::get_title() const
//    { return m_strTitle; }
//    */
//
//
//
////   void interaction_impl::CloseWindow()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      ::CloseWindow(get_handle());
////
////   }
////
////   bool interaction_impl::OpenIcon()
////   {
////
////      throw ::exception(error_not_implemented);;
////      //      ASSERT(::is_window(get_handle()));
////      //      return ::OpenIcon(get_handle()) != false;
////
////   }
//
//
////   oswindow PASCAL interaction_impl::GetSafeOwner_(oswindow hParent, oswindow* pWndTop)
////   {
////
////      return nullptr;
////
////   }
////
////
////   LRESULT CALLBACK __cbt_filter_hook(int code, wparam wparam, lparam lparam)
////   {
////
////      throw ::exception(error_not_implemented);;
////
////   }
////
////
////   void interaction_impl::_001OnEraseBkgnd(::message::message * pmessage)
////   {
////
////      ::pointer < ::message::erase_bkgnd > perasebkgnd(pmessage);
////
////      perasebkgnd->m_bRet = true;
////
////      perasebkgnd->set_result(true);
////
////   }
////
////
////   void interaction_impl::_001BaseWndInterfaceMap()
////   {
////
////      ::aura::get_system()->window_map().set(get_handle(), this);
////
////   }
//
//
////   void interaction_impl::_001OnTriggerMouseInside()
////   {
////
////      //throw ::exception(error_not_implemented);;
////      //      m_bMouseHover = true;
////      //      TRACKMOUSEEVENT tme = { sizeof(tme) };
////      //      tme.dwFlags = TME_LEAVE;
////      //      tme.hwndTrack = get_handle();
////      //      TrackMouseEvent(&tme);
////
////   }
//
//#ifdef EXTRALOG
//
//   ::int_rectangle rectLast;
//
//   ::int_size sizeLast;
//
//#endif
//
//
////
////   CLASS_DECL_AURA void hook_window_create(::user::interaction * pinteraction)
////   {
////
////      UNREFERENCED_PARAMETER(pinteraction);
////
////   }
////
////
////   CLASS_DECL_AURA bool unhook_window_create()
////   {
////
////      return true;
////
////   }
////
//
////   void CLASS_DECL_AURA
////   __handle_activate(::user::interaction * pWnd, WPARAM nState, ::user::interaction * pWndOther)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //   ASSERT(pWnd != nullptr);
////      //
////      //   // m_puserinteraction->send WM_ACTIVATETOPLEVEL when top-level parents change
////      //   if (!(MAC_WINDOW(pWnd)->GetStyle() & WS_CHILD))
////      //   {
////      //      ::user::interaction * pTopLevel= MAC_WINDOW(pWnd)->GetTopLevelParent();
////      //      if (pTopLevel && (pWndOther == nullptr || !::is_window(MAC_WINDOW(pWndOther)->get_handle()) || pTopLevel != MAC_WINDOW(pWndOther)->GetTopLevelParent()))
////      //      {
////      //         // lparam points to user::interaction getting the e_message_activate message and
////      //         //  hWndOther from the e_message_activate.
////      //         oswindow hWnd2[2];
////      //         hWnd2[0] = MAC_WINDOW(pWnd)->get_handle();
////      //         if(pWndOther == nullptr || MAC_WINDOW(pWndOther) == nullptr)
////      //         {
////      //            hWnd2[1] = nullptr;
////      //         }
////      //         else
////      //         {
////      //            hWnd2[1] = MAC_WINDOW(pWndOther)->get_handle();
////      //         }
////      //         // m_puserinteraction->send it...
////      //         pTopLevel->send_message(WM_ACTIVATETOPLEVEL, nState, (LPARAM)&hWnd2[0]);
////      //      }
////      //   }
////   }
////
////   bool CLASS_DECL_AURA
////   __handle_set_cursor(::user::interaction * pWnd, unsigned int nHitTest, unsigned int nMsg)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //   if (nHitTest == HTERROR &&
////      //      (nMsg == e_message_left_button_down || nMsg == e_message_middle_button_down ||
////      //      nMsg == e_message_right_button_down))
////      //   {
////      //      // activate the last active user::interaction if not active
////      //      ::user::interaction * pLastActive = MAC_WINDOW(pWnd)->GetTopLevelParent();
////      //      if (pLastActive != nullptr)
////      //         pLastActive = pLastActive->GetLastActivePopup();
////      //      if (pLastActive != nullptr &&
////      //         pLastActive != ::macos::interaction_impl::GetForegroundWindow() &&
////      //         pLastActive->IsWindowEnabled())
////      //      {
////      //         pLastActive->SetForegroundWindow();
////      //         return true;
////      //      }
////      //   }
////      //   return false;
////   }
//
//
//
//
//
////   LRESULT CALLBACK
////   __activation_window_procedure(oswindow hWnd, unsigned int nMsg, wparam wparam, lparam lparam)
////   {
////
////      throw ::exception(error_not_implemented);;
////      //   WNDPROC oldWndProc = (WNDPROC)::GetProp(hWnd, gen_OldWndProc);
////      //   ASSERT(oldWndProc != nullptr);
////      //
////      //   LRESULT lResult = 0;
////      //   try
////      //   {
////      //      bool bCallDefault = true;
////      //      switch (nMsg)
////      //      {
////      //      case WM_INITDIALOG:
////      //         {
////      //            unsigned int uStyle;
////      //            ::int_rectangle rectOld;
////      //            ::user::interaction * pWnd = ::macos::interaction_impl::from_handle(hWnd);
////      //            __pre_init_dialog(pWnd, &rectOld, &uStyle);
////      //            bCallDefault = false;
////      //            lResult = CallWindowProc(oldWndProc, hWnd, nMsg, wparam, lparam);
////      //            __post_init_dialog(pWnd, rectOld, uStyle);
////      //         }
////      //         break;
////      //
////      //      case e_message_activate:
////      //         __handle_activate(::macos::interaction_impl::from_handle(hWnd), wparam,
////      //            ::macos::interaction_impl::from_handle((oswindow)lparam));
////      //         break;
////      //
////      //      case e_message_set_cursor:
////      //         bCallDefault = !__handle_set_cursor(::macos::interaction_impl::from_handle(hWnd),
////      //            (short)LOWORD(lparam), HIWORD(lparam));
////      //         break;
////      //
////      //      case e_message_ncdestroy:
////      //         SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<iptr>(oldWndProc));
////      //         RemoveProp(hWnd, gen_OldWndProc);
////      //         GlobalDeleteAtom(GlobalFindAtom(gen_OldWndProc));
////      //         break;
////      //      }
////      //
////      //      // call original wndproc for default handling
////      //      if (bCallDefault)
////      //         lResult = CallWindowProc(oldWndProc, hWnd, nMsg, wparam, lparam);
////      //   }
////      //   catch(::exception::aura * pe)
////      //   {
////      //      // handle exception
////      //      MESSAGE msg;
////      //      msg.hwnd = hWnd;
////      //      msg.message = nMsg;
////      //      msg.wparam = wparam;
////      //      msg.lparam = lparam;
////      //
////      //      //lResult = __process_window_procedure_exception(pe, &msg);
////      //      //      information(::ca2::trace::category_AppMsg, 0, "Warning: Uncaught exception in __activation_window_procedure (returning %ld).\n",
////      //      //       lResult);
////      //      ::exception_pointer esp(pe);
////      //   }
////      //
////      //
////      //   return lResult;
////   }
//
//
//   void interaction_impl::offset_viewport_org(INT_RECTANGLE * lprectScreen)
//   {
//
//   }
//
//
//   void interaction_impl::set_origin(::draw2d::graphics_pointer & pgraphics)
//   {
//
//      // graphics will be already set its view port to the user::interaction for linux - cairo with xlib
//
//      pgraphics->set_origin(::int_point());
//
//   }
//
//
//   void interaction_impl::_001WindowMinimize()
//   {
////
////      if(get_handle() == nullptr)
////      {
////
////         return;
////
////      }
//
//      //aura_window_iconified();
//
//      //get_handle()->iconify();
//      
//      
//
//   }
//
//
////   bool interaction_impl::has_focus()
////   {
////
////      return ::get_focus() == get_handle();
////
////   }
//
//
////   bool interaction_impl::is_active()
////   {
////
////      return ::get_active_window() == get_handle();
////
////   }
//
//
////   void interaction_impl::ns_main_post(dispatch_block_t block)
////   {
////
////      ::ns_main_post(block);
////
////   }
//
//
////   bool interaction_impl::ShowWindow(int iShow)
////   {
////
////      if(iShow == SW_HIDE)
////      {
////
////         aura_window_hide();
////
////      }
////      else if(iShow == SW_MINIMIZE)
////      {
////
////         aura_window_miniaturize();
////
////      }
////      else if(iShow == SW_SHOWNOACTIVATE)
////      {
////
////         aura_window_order_front();
////
////      }
////   else
////   {
////
////      defer_dock_application(true);
////
////           nsapp_activate_ignoring_other_apps(1);
////
////           aura_window_show();
////   }
////
////   }
//
//   void interaction_impl::window_show_change_visibility()
//   {
//
////      auto edisplay = m_puserinteraction->layout().design().display();
////
////      if(!::is_visible(edisplay))
////      {
////
////         aura_window_hide();
////
////      }
////      else if(edisplay == e_display_iconic)
////      {
////
////         aura_window_miniaturize();
////
////      }
////      else if(m_puserinteraction->layout().design().activation() & e_activation_no_activate)
////      {
////
////         aura_window_order_front();
////
////      }
////      else
////      {
////
////         defer_dock_application(true);
////
////         nsapp_activate_ignoring_other_apps(1);
////
////         aura_window_show();
////
////      }
//
//      //return 1;
//
//   }
//
//   
//
////void interaction_impl::native_create_host()
////{
////
////   auto pwindowMain = m_psystem->m_paurasystem->m_pwindowMain;
////
////   if (pwindowMain && !pwindowMain->m_puserinteractionimpl)
////   {
////
////      m_pwindow = m_psystem->m_paurasystem->m_pwindowMain;
////
////      m_pwindow->m_puserinteractionimpl = this;
////
////      m_puserinteraction->m_pinteractionimpl = this;
////
////   }
////   else
////   {
////
////      //auto estatus =
////
////      øconstruct(m_pwindow);
////
////      //if (!estatus)
////      //{
////
////      //   return estatus;
////
////      //}
////
////      if (!m_psystem->m_paurasystem->m_pwindowMain)
////      {
////
////         m_psystem->m_paurasystem->m_pwindowMain = m_pwindow;
////
////      }
////
////   }
////
////   //auto estatus =
////
////   m_pwindow->create_window(this);
////
////   //if (!estatus)
////   //{
////
////   //   return estatus;
////
////   //}
////
////   //return true;
////
////}
//
//   void interaction_impl::on_destroy()
//   {
//      
//      ::user::interaction_impl::on_destroy();
//      
////      ::user::interaction_impl::set_destroying();
//
//      //::aura_window::m_bDestroying = true;
//      
//      //return ::success;
//
//   }
//
//
//   void interaction_impl::show_software_keyboard(::user::element * pelement)
//   {
//   
//   
//   }
//
//
//   void interaction_impl::hide_software_keyboard(::user::element * pelement)
//   {
//      
//      
//   }
//
//
//} // namespace aura_ios
//
//
//
