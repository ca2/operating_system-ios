//
//  ui_window.cpp
//  uikit
//
//  UIKit window wrapper.
//
#include "framework.h"
#include "ui_window.h"
#include "_mm.h"


namespace uikit
{

   ui_window::ui_window()
   {
   
      //m_pNS = nullptr;
      
   }


   ui_window::~ui_window()
   {
   
      ui_window_release(m_uiwindow);
   
   }


} // namespace uikit

