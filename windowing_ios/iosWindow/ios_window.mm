//
//  ios_window.cpp
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#import "_mm.h"
#import "iosWindow/iosWindowApp.h"


//#import "acme/operating_system/apple/DDInvocationGrabber.h"
//#import "acme/operating_system/apple/NSObject+DDExtensions.h"


#ifdef AURA_LANGUAGE

#error "AURA_LANGUAGE?!?!?!!!???"

#endif


#ifndef __MM

#error "MM?!?!?!!!???"

#endif

UIWindow * new_ios_window(ios_window * pwindow, CGRect rect)
{
   
   __block UIWindow * puiwindow = nullptr;
   
   ns_main_sync(^()
   {
      
      iosWindow * pioswindow = [iosWindow alloc];
       
      pwindow->m_pioswindow = pioswindow;
       
      pwindow->m_pioswindow->m_pwindow = pwindow;
      
      if([pwindow->m_pioswindow initWithFrame:[[UIScreen mainScreen] bounds]])
      {
      
         puiwindow = pioswindow;
         
      }
      
   });
   
   return puiwindow;

}


void ios_window::ios_window_show()
{
   
//   [[m_proun dd_invokeOnMainThread] showWindow : m_pioswindow];
   
}


void ios_window::ios_window_redraw()
{
   
   ns_main_async(^{
      
      [m_pioswindow->m_controller->childContentView setNeedsDisplay];
      
      [m_pioswindow setNeedsDisplay];
      
   });
   
}


void ios_window::ios_window_redraw_sync()
{
   
   ns_main_async(^{
      
      [m_pioswindow->m_controller->childContentView setNeedsDisplay];

      [m_pioswindow setNeedsDisplay];
      
   });
   
}


void ios_window::ios_window_invalidate()
{
   
   ns_main_async(^{
      
      [m_pioswindow->m_controller->childContentView setNeedsDisplay];

      [m_pioswindow setNeedsDisplay];
      
   });

}


void ios_window::ios_window_show_keyboard(bool bShow)
{
   
   ns_main_async(^
   {

      if(bShow)
      {
         
         m_pioswindow->m_pwindow->m_bCanBecomeFirstResponder = true;
    
         [m_pioswindow->m_controller->childContentView becomeFirstResponder];
      
      }
      else
      {
         
         m_pioswindow->m_pwindow->m_bCanBecomeFirstResponder = false;
      
         if(m_pioswindow->m_controller->childContentView.isFirstResponder)
         {
      
            [m_pioswindow->m_controller->childContentView resignFirstResponder];
         
         }
      
      }
      
   });
   
}



//
//  ios_window.cpp
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
//#import "macos_mm.h"





void ios_window::ios_window_set_title(const char * pszTitle)
{
   
   NSString * str = [NSString stringWithUTF8String:pszTitle];
   
   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:FALSE] setTitle: str];

   
}


void ios_window::ios_window_get_title(char * pszTitle, long iSize)
{
   
   NSString * str = [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:FALSE] title];

   strncpy(pszTitle, [str UTF8String], iSize);
   
}


void ios_window::ios_window_set_sel(long iBeg, long iEnd)
{
   
   // UITextView --> UIView
//   UITextView * pimpact = m_pioswindow->m_controller->childContentView;
//
//   UITextPosition * beg = [pimpact beginningOfDocument];
//
//   UITextPosition * selbeg = [pimpact endOfDocument];
//
//   UITextPosition * selend = selbeg;
//
//   long iLen = (long) strlen([[pimpact text] UTF8String]);
//
//   if(iBeg >= 0 && iBeg < iLen)
//   {
//
//      selbeg = [pimpact positionFromPosition: beg offset: iBeg];
//
//   }
//
//   if(iEnd >= 0 && iEnd < iLen)
//   {
//
//      selend = [pimpact positionFromPosition: beg offset: iEnd];
//
//   }
//
//   UITextRange * sel = [pimpact textRangeFromPosition: selbeg toPosition: selend];
//
//   [pimpact setSelectedTextRange: sel];
   
}


void ios_window::ios_window_get_sel(long & iBeg, long & iEnd)
{
   
   // UITextView --> UIView
//   UITextView * pimpact = m_pioswindow->m_controller->childContentView;
//
//   UITextPosition * beg = [pimpact beginningOfDocument];
//
//   UITextPosition * selbeg = [[pimpact selectedTextRange] start];
//
//   UITextPosition * selend = [[pimpact selectedTextRange] start];
//
//   iBeg = [pimpact offsetFromPosition: beg toPosition: selbeg];
//
//   iEnd = [pimpact offsetFromPosition: beg toPosition: selend];
   
}


void ios_window::ios_window_set_text(const char * pszText)
{
   
   NSString * text = [[NSString alloc] initWithUTF8String:pszText];
   
   // UITextView --> UIView
   //[m_pioswindow->m_controller->childContentView setText: text];
   
}

void ios_window::ios_window_get_text(char * pszText, long iSize)
{
   
   // UITextView --> UIView
//   strncpy(pszText, [[m_pioswindow->m_controller->childContentView text] UTF8String], iSize);
   
}


long ios_window::ios_window_get_text_length()
{
   
//   return strlen([[m_pioswindow->m_controller->childContentView text] UTF8String]);
   
   return 0;
   
}


void ios_window::ios_window_edit_on_set_focus(int l, int t, int r, int b, const char * pszText, long iSelBeg, long iSelEnd)
{
   
   CGRect rect;
   
   rect.origin.x = l;
   rect.origin.y = t;
   rect.size.width = r - l;
   rect.size.height = b - t;
 

   NSString * strText = [ NSString stringWithUTF8String: pszText ];

   [ m_pioswindow->m_controller onEditSetFocus: rect withText: strText withSelBeg: iSelBeg withSelEnd: iSelEnd];
   
}


void ios_window::ios_window_edit_on_kill_focus()
{
   
   [ m_pioswindow->m_controller onEditKillFocus ];
   
}






void ios_window::ios_window_destroy()
{
   
   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] close];
   
}


//void ios_window::ios_window_show()
//{
//   
////   [[m_pioswindow->m_controller dd_invokeOnMainThreadAndWaitUntilDone:TRUE] showWindow : m_pioswindow];
//   
//}


void ios_window::ios_window_hide()
{
   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] orderOut : m_pioswindow];
   
}

//void ios_window::ios_window_order_front()
//{
//   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] orderFront : m_pioswindow];
//   
//}
//
//
//void ios_window::ios_window_make_key_window()
//{
//   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeKeyWindow];
//   
//}


//void ios_window::ios_window_make_key_window_and_order_front()
//{
//   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeKeyAndOrderFront: m_pioswindow];
//   
//}
//
//
//void ios_window::ios_window_make_main_window()
//{
//   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeMainWindow];
//   
//}
//
//
//void ios_window::ios_window_redraw()
//{
//   
//   [[m_pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] display ];
//   
//}
//
//
//void ios_window::ios_window_invalidate()
//{
//   
//   //   [[m_pioswindow->m_controller dd_invokeOnMainThread] setViewsNeedDisplay : TRUE];
//   
//}

