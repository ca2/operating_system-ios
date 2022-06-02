//
//  windowing.hpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-21 01:59 <3ThomasBS_!!
//
#pragma once


namespace windowing_ios
{


    class CLASS_DECL_WINDOWING_MACOS windowing :
      virtual public ::windowing::windowing
   {
   public:
      
      
      __pointer(::windowing::display)           m_pdisplay;
      
      __pointer(class window)                   m_pwindowActive;
      
      __pointer(class window)                   m_pwindowCapture;
      
      __pointer(class window)                   m_pwindowApplicationHost;
      
      __pointer(host_interaction)               m_phostinteraction;
      
      map < void *, __pointer(class window) >   m_nsmap;

     
      __pointer(text_editor_interface) m_ptexteditorinterface;

      
      windowing();
      ~windowing() override;
      
      
      void initialize(::object * pobject) override;
      
      
      ::windowing::text_editor_interface * get_text_editor_interface() override;

      
      void defer_initialize_host_window(const RECTANGLE_I32* lpcrect) override;
     
      ::windowing::window * get_application_host_window() override;
      
      ::windowing::window * new_window(::user::interaction_impl *pimpl) override;

      __pointer(::windowing::cursor) get_cursor(enum_cursor ecursor) override;
      
      void windowing_post(const ::procedure & procedure) override;
      
      ::windowing::window * window(oswindow oswindow) override;

      ::windowing::display * display() override;
      
      ::windowing::window * get_active_window(::thread * pthread) override;

      //virtual bool post_ui_message(::message::base * pbase);
      
      void release_mouse_capture() override;
      
      ::windowing::window * get_keyboard_focus(::thread *) override;

      
      void get_cursor_position(POINT_I32 * ppoint) override;
      
      void _defer_dock_application(int_bool bDock);
      
      
      void clear_keyboard_focus(::windowing::window* pwindowGainingFocusIfAny) override;
      
   };
      

} // namespace windowing_ios




