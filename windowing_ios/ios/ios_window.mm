//
//  ios_window.cpp
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#import "_mm.h"
#import "ios/iosApp.h"
#import "ios/iosImpact.h"

void ns_workspace_cgrect(int i, CGRect * prect);


//#import "acme/operating_system/apple/DDInvocationGrabber.h"
//#import "acme/operating_system/apple/NSObject+DDExtensions.h"


#ifdef AURA_LANGUAGE

#error "AURA_LANGUAGE?!?!?!!!???"

#endif


#ifndef __OBJECTIVE_CPP__

#error "MM?!?!?!!!???"

#endif

//UIWindow * new_ios_window(ios_window * pwindow, CGRect rect, unsigned int uStyle)
//{
//   
//   __block UIWindow * puiwindow = nullptr;
//   
//   ns_main_send(^()
//   {
//      
//      iosWindow * pioswindow = [iosWindow alloc];
//      
//      iosApp * papp = (iosApp *) [[UIApplication sharedApplication] delegate];
//
//      if(!papp.m_ioswindow)
//      {
//         
//         papp.m_ioswindow = pioswindow;
//         
//      }
//       
//      pwindow->pioswindow = pioswindow;
//       
//      pwindow->pioswindow->m_pwindow = pwindow;
//      
//      //CGRect rectWorkspace;
//      
//      //ns_workspace_cgrect(0, &rectWorkspace);
//      
//      auto bounds = [[UIScreen mainScreen] bounds];
//      
//      //if([pwindow->pioswindow initWithFrame: rectWorkspace ] )
//      if([pwindow->pioswindow initWithFrame: bounds ] )
//      {
//      
//         puiwindow = pioswindow;
//         
//      }
//      
//   });
//   
//   return puiwindow;
//
//}


void ios_window::ios_window_show()
{
   
   ns_main_post(^{
      
      auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;
      [pioswindow makeKeyAndVisible];
      //iosImpactController * pcontroller = pioswindow->m_pimpactcontroller;
      //[pcontroller presentViewController:pcontroller animated:TRUE completion:nil];
      
   });
}


void ios_window::ios_window_redraw()
{
   
//   dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW,
//                                           (int64_t)(0.050 * NSEC_PER_SEC));
//   dispatch_after(popTime, dispatch_get_main_queue(), ^(void) {
//      //[pioswindow->m_pimpactcontroller->m_pnsacmeimpact setNeedsDisplay];
//      [pioswindow setNeedsDisplay];
//   });
   ns_main_post(^{

      
//      [CATransaction begin];
//      [pioswindow->m_pimpactcontroller->m_pnsacmeimpact.layer displayIfNeeded];
//      [CATransaction flush];
//      [CATransaction commit];
      auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;
      
      
      iosImpact * piosimpact = (iosImpact *) pioswindow->m_pnsacmeimpact;

      [piosimpact setNeedsDisplay];

      //printf("%s", "Called iosframe setNeedsDisplay\n");
      //[pioswindow setNeedsDisplay];

   });
   
}


//void ios_window::ios_window_redraw_sync()
//{
//
//   ns_main_post(^{
//
//      [pioswindow->m_pimpactcontroller->m_pnsacmeimpact setNeedsDisplay];
//
//      [pioswindow setNeedsDisplay];
//
//   });
//
//}


void ios_window::ios_window_invalidate()
{
   
   ns_main_post(^{

      auto pioswindow = (iosWindow *)(__bridge ns_acme_window*) m_pnsacmewindowAppleKit;

      auto piosimpact = (iosImpact *) pioswindow->m_pnsacmeimpact;

      [pioswindow setNeedsDisplay];

      [piosimpact setNeedsDisplay];
      
   });

}


void ios_window::ios_window_show_keyboard(bool bShow)
{
   
   ns_main_post(^
   {
      auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

      if(bShow)
      {
         
         pioswindow->m_pwindow->m_bCanBecomeFirstResponder = true;
    
         [pioswindow->m_pimpactcontroller->m_pnsacmeimpact becomeFirstResponder];
      
      }
      else
      {
         
         pioswindow->m_pwindow->m_bCanBecomeFirstResponder = false;
      
         if(pioswindow->m_pimpactcontroller->m_pnsacmeimpact.isFirstResponder)
         {
      
            [pioswindow->m_pimpactcontroller->m_pnsacmeimpact resignFirstResponder];
         
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
   
//   NSString * str = [NSString stringWithUTF8String:pszTitle];
//   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   ns_main_send(^{
      //[pioswindow setTitle: str];

   });

   
}


void ios_window::ios_window_get_title(char * pszTitle, long iSize)
{
//   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   ns_main_send(^{
      
      //NSString * str = [pioswindow title];
      
      //strncpy(pszTitle, [str UTF8String], iSize);
      
   });

   
}


void ios_window::ios_window_set_sel(long iBeg, long iEnd)
{

   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;
   
   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   auto pioseditimpact = piosimpactcontroller->m_pioseditimpact;

   UITextPosition * beg = [ pioseditimpact beginningOfDocument ];

   UITextPosition * selbeg = beg;

   UITextPosition * selend = beg;

   if(iBeg >= 0)
   {

      selbeg = [ pioseditimpact positionFromPosition: beg offset: iBeg ];

   }

   if(iEnd >= 0)
   {

      selend = [ pioseditimpact positionFromPosition: beg offset: iEnd ];

   }

   UITextRange * sel = [ pioseditimpact textRangeFromPosition: selbeg toPosition: selend ];

   [ pioseditimpact setSelectedTextRange: sel];
   
}


void ios_window::ios_window_get_sel(long & iBeg, long & iEnd)
{
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   // UITextView --> UIView
   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   auto pioseditimpact = piosimpactcontroller->m_pioseditimpact;

   UITextPosition * beg = [pioseditimpact beginningOfDocument];

   UITextPosition * selbeg = [[pioseditimpact selectedTextRange] start];

   UITextPosition * selend = [[pioseditimpact selectedTextRange] start];

   iBeg = [pioseditimpact offsetFromPosition: beg toPosition: selbeg];

   iEnd = [pioseditimpact offsetFromPosition: beg toPosition: selend];
   
}


void ios_window::ios_window_set_text(const char * pszText)
{
   
   NSString * text = [ [ NSString alloc] initWithUTF8String: pszText];
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   auto pioseditimpact = piosimpactcontroller->m_pioseditimpact;

   [pioseditimpact setContentText: text];
   
}

void ios_window::ios_window_get_text(char * pszText, long iSize)
{
   
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   if(!pioswindow)
   {
      
      return;
      
   }
   
   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   if(!piosimpactcontroller)
   {
      
      return;
      
   }
   
   auto pioseditimpact = piosimpactcontroller->m_pioseditimpact;

   if(!pioseditimpact)
   {
    
      return;
      
   }

   NSString * str = [ pioseditimpact getContentText ];

   strncpy(pszText, [ str UTF8String], iSize);
   
}


long ios_window::ios_window_get_text_length()
{
   
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   if(!pioswindow)
   {
      
      return 0;
      
   }
   
   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   if(!piosimpactcontroller)
   {
      
      return 0;
      
   }
   
   auto pioseditimpact = piosimpactcontroller->m_pioseditimpact;

   if(!pioseditimpact)
   {
    
      return 0;
      
   }

   NSString * str = [ pioseditimpact getContentText ];

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
   
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;
   
   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   [ piosimpactcontroller onEditSetFocus: rect withText: strText withSelBeg: iSelBeg withSelEnd: iSelEnd];
   
}


void ios_window::ios_window_edit_on_kill_focus()
{
   
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   auto piosimpactcontroller = (iosImpactController*)pioswindow->m_pimpactcontroller;

   [ piosimpactcontroller onEditKillFocus ];
   
}


void ios_window::ios_window_destroy()
{
   
   //auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   ns_main_send(
                ^()
                {
//                   [pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] close];

                }
                );
   
}


ios_window * ios_window::_ios_window()
{
   
   return this;
   
}



//void ios_window::ios_window_show()
//{
//   
////   [[pioswindow->m_pimpactcontroller dd_invokeOnMainThreadAndWaitUntilDone:TRUE] showWindow : pioswindow];
//   
//}


void ios_window::ios_window_hide()
{
   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] orderOut : pioswindow];
   
}

//void ios_window::ios_window_order_front()
//{
//   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] orderFront : pioswindow];
//   
//}
//
//
//void ios_window::ios_window_make_key_window()
//{
//   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeKeyWindow];
//   
//}


//void ios_window::ios_window_make_key_window_and_order_front()
//{
//   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeKeyAndOrderFront: pioswindow];
//   
//}
//
//
//void ios_window::ios_window_make_main_window()
//{
//   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] makeMainWindow];
//   
//}
//
//
//void ios_window::ios_window_redraw()
//{
//   
//   [[pioswindow dd_invokeOnMainThreadAndWaitUntilDone:TRUE] display ];
//   
//}
//
//
//void ios_window::ios_window_invalidate()
//{
//   
//   //   [[pioswindow->m_pimpactcontroller dd_invokeOnMainThread] setViewsNeedDisplay : TRUE];
//   
//}


void ios_window::ios_window_pick_browse(char ** ppszUTType, const ::function < void(const ::file::path & path) > & callback)
{
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   [ pioswindow pickBrowse : ppszUTType callback : callback];
   
}


void ios_window::ios_window_pick_browse_for_saving_user_controller(void *pUserController)
{
   auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

   [ pioswindow pickBrowseForSavingUserController : pUserController ];
   
}


void ios_window::ios_window_get_frame(CGRect * prect)
{
   
   ns_main_send(^{
      
      auto pioswindow = (iosWindow*)(__bridge ns_acme_window*)m_pnsacmewindowAppleKit;

      *prect = [pioswindow frame];
   });
   
}


double ios_window::_get_status_bar_frame_height()
{
 
   return m_dStatusBarFrameHeight;
   
}




