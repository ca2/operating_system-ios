//
//  windowing.h
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2026-05-12 06:06
//  <3ThomasBorregaardSørensen!!
//
//
// Created by camilo on 2024-12-05 17:05 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "acme/windowing/windowing.h"
#include "acme/_operating_system.h"
#include "ui_window.h"


namespace uikit
{



   class CLASS_DECL_ACME windowing :
      virtual public ::acme::windowing::windowing
   {
   public:

      
      ::map < ui_window_t, ::pointer < ::uikit::ui_window > > m_windowmap;


      windowing();
      ~windowing() override;

      ::acme::windowing::window *
      acme_windowing_window(const ::operating_system::window &operatingsystemwindow) override;
   
      void add_window(::acme::windowing::window * pacmewindowingwindow) override;

      void each_window(const ::function < void(::acme::windowing::window * pacmewindowingwindow) > & function) override;

      ::operating_system::window operating_system_window(const ::wparam &wparam) override;

      ::operating_system::window operating_system_window(const ::lparam &lparam) override;


   };


} // namespace uikit


//CLASS_DECL_ACME HWND get_task_main_hwnd(::task *ptask);
//CLASS_DECL_ACME HWND get_main_hwnd();


