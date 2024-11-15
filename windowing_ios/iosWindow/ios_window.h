//
//  ios_window.h
//  os
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//

#pragma once

#ifdef __OBJC__
//#include "acme/user/user/_const_key.h"
#import <UIKit/UIKit.h>
#endif

#ifdef __OBJC__
@class iosWindow;
typedef UIWindow * ui_window_ptr;
#include <UIKit/UIKit.h>
#else
typedef void * ui_window_ptr;
#include <CoreGraphics/CoreGraphics.h>
#endif

class ios_window
{
public:


bool m_bDirty;
   
#ifdef __OBJC__
   iosWindow * m_pioswindow;
#else
   void * m_pioswindow;
#endif
   ui_window_ptr m_puiwindow;
  
   bool m_bCanBecomeFirstResponder;
   double m_dStatusBarFrameHeight;
   
  
   virtual void ios_window_draw(CGContextRef cgc, CGSize sizeWindow) = 0;
   virtual void ios_window_mouse_down(int iGesture, double x, double y) = 0;
   virtual void ios_window_mouse_up(int iGesture, double x, double y) = 0;
   virtual void ios_window_mouse_moved(int iGesture, double x, double y) = 0;
   virtual void ios_window_mouse_dragged(int iGesture, double x, double y) = 0;
   virtual bool ios_window_key_down(::user::enum_key ekey) = 0;
   virtual bool ios_window_key_up(::user::enum_key ekey) = 0;
   virtual bool ios_window_on_text(const char * pszText, long iSel, long iEnd) = 0;
   virtual bool ios_window_on_sel_text(long iBeg, long iEnd) = 0;
   
   //virtual int ios_window_get_x() = 0;
   //virtual int ios_window_get_y() = 0;
   //virtual long ios_window_edit_hit_test(int x, int y) = 0;
   virtual bool ios_window_edit_caret_rect(CGRect * prectangle, long iSel) = 0;
   
   virtual void ios_window_resized(int cx, int cy) = 0;
   virtual void ios_window_moved(CGPoint int_point) = 0;

   virtual void ios_window_did_become_key() = 0;

   virtual void ios_window_on_activate() = 0;
   virtual void ios_window_on_deactivate() = 0;
   
   virtual void ios_window_on_show() = 0;
   virtual void ios_window_on_hide() = 0;
   
   virtual bool ios_window_become_first_responder() = 0;
   virtual void ios_window_text_view_did_begin_editing() = 0;
   
   virtual void ios_window_pick_browse(char ** ppszUTType, const ::function < void(const ::file::path & path) > & callback);
   virtual void ios_window_did_pick_document_at_url(const char * pszUrl) = 0;
   virtual void ios_window_did_pick_document_at_urls(const char ** pszaUrl, long lCount) = 0;

   virtual void ios_window_pick_browse_for_saving_user_controller(void * pUserController);
   double _get_status_bar_frame_height();

   
   virtual void ios_window_invalidate();
   virtual void ios_window_show();
   virtual void ios_window_hide();
   virtual void ios_window_redraw();
   //virtual void ios_window_redraw_sync();
   
   virtual void ios_window_get_frame(CGRect * prect);
   
   virtual bool ios_window_has_keyboard_focus() = 0;
   virtual void ios_window_show_keyboard(bool bShow = true);
   
   virtual void ios_window_set_title(const char * pszTitle);
   virtual void ios_window_get_title(char * pszTitle, long iSize);

   
   virtual void ios_window_set_sel(long iBeg, long iEnd);
   virtual void ios_window_get_sel(long & iBeg, long & iEnd);

   virtual void ios_window_edit_on_set_focus(int l, int t, int r, int b, const char * pszText, long iSelBeg, long iSelEnd);
   virtual void ios_window_edit_on_kill_focus();

   virtual void ios_window_set_text(const char * pszText);
   virtual void ios_window_get_text(char * pszText, long iSize);
   virtual long ios_window_get_text_length();

   

   virtual void ios_window_destroy();
   
   
   
   
   
};

#ifdef __OBJC__
UIWindow * new_ios_window(ios_window * pwindow, CGRect int_rectangle, unsigned int uStyle);
#endif
