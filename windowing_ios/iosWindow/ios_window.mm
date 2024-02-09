//
//  ios_window.cpp
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#import "_mm.h"
#import "iosWindow/iosWindowApp.h"


void ns_workspace_cgrect(int i, CGRect * prect);


//#import "acme/operating_system/apple/DDInvocationGrabber.h"
//#import "acme/operating_system/apple/NSObject+DDExtensions.h"


#ifdef AURA_LANGUAGE

#error "AURA_LANGUAGE?!?!?!!!???"

#endif


#ifndef __OBJECTIVE_CPP__

#error "MM?!?!?!!!???"

#endif

UIWindow * new_ios_window(ios_window * pwindow, CGRect rect, unsigned int uStyle)
{
   
   __block UIWindow * puiwindow = nullptr;
   
   ns_main_sync(^()
   {
      
      iosWindow * pioswindow = [iosWindow alloc];
      
      iosWindowApp * papp = (iosWindowApp *) [[UIApplication sharedApplication] delegate];

      if(!papp.ioswindow)
      {
         
         papp.ioswindow = pioswindow;
         
      }
       
      pwindow->m_pioswindow = pioswindow;
       
      pwindow->m_pioswindow->m_pwindow = pwindow;
      
      //CGRect rectWorkspace;
      
      //ns_workspace_cgrect(0, &rectWorkspace);
      
      auto bounds = [[UIScreen mainScreen] bounds];
      
      //if([pwindow->m_pioswindow initWithFrame: rectWorkspace ] )
      if([pwindow->m_pioswindow initWithFrame: bounds ] )
      {
      
         puiwindow = pioswindow;
         
      }
      
   });
   
   return puiwindow;

}


void ios_window::ios_window_show()
{
   
   ns_main_async(^{
      
      [m_pioswindow makeKeyAndVisible];
      
   });
}


void ios_window::ios_window_redraw()
{
   
//   dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW,
//                                           (int64_t)(0.050 * NSEC_PER_SEC));
//   dispatch_after(popTime, dispatch_get_main_queue(), ^(void) {
//      //[m_pioswindow->m_controller->m_iosframeview setNeedsDisplay];
//      [m_pioswindow setNeedsDisplay];
//   });
   ns_main_async(^{

      
//      [CATransaction begin];
//      [m_pioswindow->m_controller->m_iosframeview.layer displayIfNeeded];
//      [CATransaction flush];
//      [CATransaction commit];

      [m_pioswindow->m_controller->m_iosframeview setNeedsDisplay];

      //printf("%s", "Called iosframe setNeedsDisplay\n");
      //[m_pioswindow setNeedsDisplay];

   });
   
}


//void ios_window::ios_window_redraw_sync()
//{
//
//   ns_main_async(^{
//
//      [m_pioswindow->m_controller->m_iosframeview setNeedsDisplay];
//
//      [m_pioswindow setNeedsDisplay];
//
//   });
//
//}


void ios_window::ios_window_invalidate()
{
   
   ns_main_async(^{
      
      [m_pioswindow->m_controller->m_iosframeview setNeedsDisplay];

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
    
         [m_pioswindow->m_controller->m_iosframeview becomeFirstResponder];
      
      }
      else
      {
         
         m_pioswindow->m_pwindow->m_bCanBecomeFirstResponder = false;
      
         if(m_pioswindow->m_controller->m_iosframeview.isFirstResponder)
         {
      
            [m_pioswindow->m_controller->m_iosframeview resignFirstResponder];
         
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
   
   auto ioseditview = m_pioswindow->m_controller->m_ioseditview;

   UITextPosition * beg = [ ioseditview beginningOfDocument ];

   UITextPosition * selbeg = beg;

   UITextPosition * selend = beg;

   if(iBeg >= 0)
   {

      selbeg = [ ioseditview positionFromPosition: beg offset: iBeg ];

   }

   if(iEnd >= 0)
   {

      selend = [ ioseditview positionFromPosition: beg offset: iEnd ];

   }

   UITextRange * sel = [ ioseditview textRangeFromPosition: selbeg toPosition: selend ];

   [ ioseditview setSelectedTextRange: sel];
   
}


void ios_window::ios_window_get_sel(long & iBeg, long & iEnd)
{
   
   // UITextView --> UIView
   auto ioseditview = m_pioswindow->m_controller->m_ioseditview;

   UITextPosition * beg = [ioseditview beginningOfDocument];

   UITextPosition * selbeg = [[ioseditview selectedTextRange] start];

   UITextPosition * selend = [[ioseditview selectedTextRange] start];

   iBeg = [ioseditview offsetFromPosition: beg toPosition: selbeg];

   iEnd = [ioseditview offsetFromPosition: beg toPosition: selend];
   
}


void ios_window::ios_window_set_text(const char * pszText)
{
   
   NSString * text = [ [ NSString alloc] initWithUTF8String: pszText];
   
   [m_pioswindow->m_controller->m_ioseditview setContentText: text];
   
}

void ios_window::ios_window_get_text(char * pszText, long iSize)
{
   
   
   if(!m_pioswindow ||
      !m_pioswindow->m_controller ||
      !m_pioswindow->m_controller->m_ioseditview)
   {
      
      return;
      
   }
   
   NSString * str = [ m_pioswindow->m_controller->m_ioseditview getContentText ];

   strncpy(pszText, [ str UTF8String], iSize);
   
}


long ios_window::ios_window_get_text_length()
{
   
   if(!m_pioswindow ||
      !m_pioswindow->m_controller ||
      !m_pioswindow->m_controller->m_ioseditview)
   {
      
      return 0;
      
   }
   
   NSString * str = [ m_pioswindow->m_controller->m_ioseditview getContentText ];

   return strlen([ str UTF8String ]);
   
}


void ios_window::ios_window_edit_on_set_focus(int l, int t, int r, int b, const char * pszText, long iSelBeg, long iSelEnd)
{
   
   CGRect rect;
   
   rect.origin.x = l;
   rect.origin.y = t;
   rect.size.width = r - l;
   rect.size.height = b - t;
 
//#define SHENNANIGAN
//   
//#ifdef SHENNANIGAN
//   if(rect.size.height > 50)
//   {
//      rect.size.height = 50;
//      
//   }
//#endif


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


void ios_window::ios_window_pick_browse()
{

   [ m_pioswindow pickBrowse ];
   
}


void ios_window::ios_window_pick_browse_for_saving_user_controller(void *pUserController)
{
   
   [ m_pioswindow pickBrowseForSavingUserController : pUserController ];
   
}


void ios_window::ios_window_get_frame(CGRect * prect)
{
   
   ns_main_sync(^{
      *prect = [m_pioswindow frame];
   });
   
}


double ios_window::_get_status_bar_frame_height()
{
 
   return m_dStatusBarFrameHeight;
   
}




