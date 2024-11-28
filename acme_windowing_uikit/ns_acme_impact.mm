//
//  nsview.m
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 02/02/22.
//  09:10
//  Copyright © 2022 Camilo Sasuke Tsumanuma. All rights reserved.
//
//
//  RoundWindowFrameView.m
//  RoundWindow
//
//  Created by Matt Gallagher on 12/12/08.
//  Copyright 2008 Matt Gallagher. All rights reserved.
//
//  Permission is given to use this source code file without charge in any
//  project, commercial or otherwise, entirely at your risk, with the condition
//  that any redistribution (in part or whole) of source code must retain
//  this copyright and permission notice. Attribution in compiled projects is
//  appreciated but not required.
//
#include "framework.h"
#include "acme_window_bridge.h"
#include "ns_acme_window.h"
#include "ns_acme_impact.h"
#include "acme/operating_system/macos/keyboard.h"
#include "acme/operating_system/winpr_input.h"
//#include <Carbon/Carbon.h>


@implementation ns_acme_impact


- (id) initWithFrame: (CGRect) frame andWindow: (ns_acme_window *) pnsacmewindow
{

   self                 = [super initWithFrame:frame];
   
   
   m_pnsacmewindow      = pnsacmewindow;
   
   m_bLShift            = false;
   m_bRShift            = false;
   m_bLControl          = false;
   m_bRControl          = false;
   m_bLAlt              = false;
   m_bRAlt              = false;
   m_bLCommand          = false;
   m_bRCommand          = false;
   
//   if (self)
//   {
//      
//      trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds]
//                                                  options: (NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved | NSTrackingActiveInKeyWindow )
//                                                    owner:self userInfo:nil];
//      [self addTrackingArea:trackingArea];
//      
//   }
   
   return self;
   
}


//- (CGRect) resizeRect
//{
//   
////   const CGFloat resizeBoxSize = 16.0;
//   
//  // const CGFloat contentViewPadding = 5.5;
//   
//   //CGRect contentViewRect = [[self window] contentRectForFrameRect:[[self window] frame]];
//
////   CGRect resizeRect = NSMakeRect(
////      NSMaxX(contentViewRect) + contentViewPadding,
////      NSMinY(contentViewRect) - resizeBoxSize - contentViewPadding,
////      resizeBoxSize,
////      resizeBoxSize);
//   
//    CGRect resizeRect = [[self window] frame];
//
//   return resizeRect;
//   
//}


//- (CGPoint) screenLocationEx: (UIEvent *) event
//{
//    
//    CGPoint point = [ event p
//   
////   CGPoint point = [event locationInWindow];
////   
////   if([event window] != nil)
////   {
////      
////      CGRect rectWindow = [[event window] frame];
////      
////      point.x += rectWindow.origin.x;
////      
////      point.y += rectWindow.origin.y;
////      
////   }
////   
////   point.y = (int) [[NSScreen mainScreen] frame].size.height - point.y;
////
////   return point;
////   
//}


//- (CGPoint) flippedLocationInWindow: (UIEvent *) event
//{
//    
//    CGpoin
//   
////   CGPoint point = [event locationInWindow];
////   
////   if([event window] != nil)
////   {
////      
////      CGRect rectWindow = [[event window] frame];
////      
////      point.y = rectWindow.size.height - point.y - 1;
////      
////   }
////   
////   //point.y = (int) [[NSScreen mainScreen] frame].size.height - point.y;
//
//   return point;
//   
//}



//- (void) mouseUp: (UIEvent *) event
//{
//
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////      
////      return;
////      
////   }
////
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////   
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
//// 
////   p->on_left_button_up(xHost, yHost, xAbsolute, yAbsolute);
//   
//}
//
//
//- (void) mouseMoved: (UIEvent *) event
//{
//
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////      
////      return;
////      
////   }
////   
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////   
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
////
////   p->on_mouse_move(xHost, yHost, xAbsolute, yAbsolute);
////   
////   return;
//   
//}
//
//
//- (void) mouseDragged: (UIEvent *) event
//{
//
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////
////      return;
////      
////   }
////   
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////   
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
////
////   p->on_mouse_move(xHost, yHost, xAbsolute, yAbsolute);
//   
//}
//
//
//- (void) mouseDown: (UIEvent *) event
//{
//   
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////      
////      return;
////      
////   }
////   
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////   
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
////
////   p->on_left_button_down(xHost, yHost, xAbsolute, yAbsolute);
//   
//}
//
//
//- (void) rightMouseUp: (UIEvent *) event
//{
//
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////      
////      return;
////      
////   }
////    
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////   
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
////
////   p->on_right_button_up(xHost, yHost, xAbsolute, yAbsolute);
//   
//}
//
//
//- (void) rightMouseDown: (UIEvent *) event
//{
//   
////   acme_window_bridge * p = m_pacmewindowbridge;
////   
////   if(p == NULL)
////   {
////      
////      return;
////      
////   }
////   
////   CGPoint pointHost = [self flippedLocationInWindow: event];
////   
////   int xHost = pointHost.x;
////   
////   int yHost = pointHost.y;
////
////   CGPoint pointAbsolute = [self screenLocationEx: event];
////
////   int xAbsolute = pointAbsolute.x;
////   
////   int yAbsolute = pointAbsolute.y;
////
////   p->on_right_button_down(xHost, yHost, xAbsolute, yAbsolute);
////   
//}


- (BOOL) isFlipped
{
   
   return YES;
   
}


- (BOOL) isOpaque
{
   
   return NO;
   
}


- (void)addGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
   [super addGestureRecognizer:gestureRecognizer];
   // Check the new gesture recognizer is the same kind as the one we want to implement
   // Note:
   // This works because `UITextTapRecognizer` is a subclass of `UITapGestureRecognizer`
   // and the text view has some `UITextTapRecognizer` added :)
   //   if ([gestureRecognizer isKindOfClass:[UITapGestureRecognizer class]]) {
   //      UITapGestureRecognizer *tgr = (UITapGestureRecognizer *)gestureRecognizer;
   //      if ([tgr numberOfTapsRequired] == 1 &&
   //          [tgr numberOfTouchesRequired] == 1) {
   //         // If found then add self to its targets/actions
   //         [tgr addTarget:self action:@selector(_handleOneFingerTap:)];
   //      }
   //   }
}


- (void)removeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
   // Check the new gesture recognizer is the same kind as the one we want to implement
   // Read above note
   //   if ([gestureRecognizer isKindOfClass:[UITapGestureRecognizer class]]) {
   //      UITapGestureRecognizer *tgr = (UITapGestureRecognizer *)gestureRecognizer;
   //      if ([tgr numberOfTapsRequired] == 1 &&
   //          [tgr numberOfTouchesRequired] == 1) {
   //         // If found then remove self from its targets/actions
   //         [tgr removeTarget:self action:@selector(_handleOneFingerTap:)];
   //      }
   //   }
   [super removeGestureRecognizer:gestureRecognizer];
   
}


- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesBegan:touches withEvent:event];
   
   auto * p = m_pnsacmewindow->m_pacmewindowbridge;
   
   //BOOL allTouchesEnded = ([touches count] == [[event touchesForView:self] count]);
   
   if ([touches count] == 1)
   {
      
      UITouch *touch = [touches anyObject];
      
      if ([touch tapCount] == 1)
      {
         
         CGPoint point = [touch locationInView:self];
         
         int x = point.x;
         
         int y = point.y;
         
         m_pointLastTouchBegan = point;
         
         p->on_left_button_down(x, y, x, y);
         
         //         if(allTouchesEnded)
         //         {
         //
         //            p->ios_window_mouse_up(x, y);
         //
         //         }
         
      }
      
   }
   
}


//- (void) detectPan:(UIPanGestureRecognizer *) uiPanGestureRecognizer
//{
//
//   CGPoint translation = [uiPanGestureRecognizer translationInView:self.superview];
//
//   ios_window * p = m_ioswindow->m_pwindow;
//
//   int x = m_pointLastTouchBegan.x + translation.x;
//
//   int y = m_pointLastTouchBegan.y + translation.y;
//
//   p->ios_window_mouse_dragged(x, y);
//
//}


- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesMoved:touches withEvent:event];
   
   auto * p = m_pnsacmewindow->m_pacmewindowbridge;
   
   if ([touches count] == 1)
   {
      
      UITouch *touch = [touches anyObject];
      
      if ([touch tapCount] == 1)
      {
         
         CGPoint point = [touch locationInView:self];
         
         int x = point.x;
         
         int y = point.y;
         
         m_pointLastTouchBegan = point;
         
          p->on_mouse_move(x, y, x, y);
         
      }
      else
      {
         
         //            twoFingerTapIsPossible = NO;
         
      }
      
   }
   else if([touches count] <= 0)
   {
      
       p->on_left_button_up(m_pointLastTouchBegan.x, m_pointLastTouchBegan.y, m_pointLastTouchBegan.x, m_pointLastTouchBegan.y);
      
   }
   
}

/**
 UIResponder protocol override.
 Our view can become first responder to receive user text input.
 */
- (BOOL)canBecomeFirstResponder
{
    return NO;
}


- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesEnded:touches withEvent:event];
   
   BOOL allTouchesEnded = ([touches count] == [[event touchesForView:self] count]);
   
   auto * p = m_pnsacmewindow->m_pacmewindowbridge;
   
   if ([touches count] == 1 && allTouchesEnded)
   {
      
      UITouch *touch = [touches anyObject];
      
      // --------------------------------------------------------
      //
      //   tap/ClickCount == 0 :
      //   not properly a tap/click,
      //   (but-a/"->"){eco/green-lang): drag.
      //   So, still send mouse up message, at the final location.
      //
      if ([touch tapCount] == 0)
      {
         
         CGPoint point = [touch locationInView:self];
         
         int x = point.x;
         
         int y = point.y;
         
          p->on_left_button_up(x, y, x, y);
         
      }
      else if ([touch tapCount] == 1)
      {
         
         // if touch is a single tap, store its location so we can average it with the second touch location
         
         CGPoint point = [touch locationInView:self];
         
         //CGRect e = [[UIScreen mainScreen] applicationFrame];
         
         //int H = (int) e.size.height;
         
         int x = point.x;
         
         //int y = H - point.y;
         
         int y = point.y;
         
          p->on_left_button_up(x, y, x, y);
         
      }
      else
      {
         
         //            twoFingerTapIsPossible = NO;
         
      }
      
   }
   
   //   CGPoint point = [[self window] convertBaseToScreen:[event locationInWindow]];
   
}


- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesCancelled:touches withEvent:event];
   
   BOOL allTouchesEnded = ([touches count] == [[event touchesForView:self] count]);
   
   auto * p = m_pnsacmewindow->m_pacmewindowbridge;
   
   if ([touches count] == 1 && allTouchesEnded)
   {
      
      UITouch *touch = [touches anyObject];
      
      //if ([touch tapCount] == 1)
      {
         
         // if touch is a single tap, store its location so we can average it with the second touch location
         
         CGPoint point = [touch locationInView:self];
         
         //CGRect e = [[UIScreen mainScreen] applicationFrame];
         
         //int H = (int) e.size.height;
         
         int x = point.x;
         
         //            int y = H - point.y;
         
         int y = point.y;
         
          p->on_left_button_up(x, y,  x, y);
         
      }
      //      else
      //      {
      //
      //         //            twoFingerTapIsPossible = NO;
      //
      //      }
      
   }
   
   //   CGPoint point = [[self window] convertBaseToScreen:[event locationInWindow]];
   
}


//- (void)drawLayer:(CALayer *)layer
//        inContext:(CGContextRef)ctx;
//{
//   if(m_ioswindow == nil)
//      return;
//
//   ios_window * p = m_ioswindow->m_pwindow;
//
//   CGContextRef context = ctx;
//
//   CGContextSaveGState(context);
//
//   CGContextTranslateCTM(context, p->ios_window_get_x(), p->ios_window_get_y());
//
//   p->ios_window_draw(context);
//
//   CGContextRestoreGState(context);
//
//
//}


#define WINDOW_FRAME_PADDING 32

#define REDRAW_HINTING
#undef REDRAW_HINTING
//#define REDRAW_HINTING


- (void) drawRect: (CGRect) rect
{

   auto * p = m_pnsacmewindow->m_pacmewindowbridge;
   
   if(p == NULL)
   {
      
      return;
      
   }

    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextResetClip(context);
    
    CGContextSaveGState(context);
    
//    [ [ UIColor blueColor ] setFill];
   
  // UIRectFill(rect);
    
 //   UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
 //
 //   if(orientation == UIInterfaceOrientationPortrait)
 //   {
 //
 //   }
 //   else
 //   {
 //
 //      //      int w = rect.size.width;
 //      //
 //      //      rect.size.width = rect.size.height;
 //      //
 //      //      rect.size.height = w;
 //
 //   }
    
    //int cx = rect.size.width;
    
    //int cy = rect.size.height;
    
    //if(m_pacmewindowbridge != nil)
    {
       
        //auto * p = m_pacmewindowbridge;
       
 //      if(orientation == UIInterfaceOrientationPortrait)
 //      {
 //
 //      }
 //      else
 //      {
 //
 //         //CGContextTranslateCTM(context, cx / 2, cy / 2);
 //         //CGContextRotateCTM(context, M_PI / 2.0);
 //         //CGContextTranslateCTM(context, -cy / 2, -cx / 2);
 //
 //      }
//       {
// 
//             CGContextSetBlendMode(context, kCGBlendModeCopy);
// 
//             CGContextSetRGBFillColor(context, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 155 / 255.0f);
// 
//             auto rectArtifact2 = rect;
// 
//             rectArtifact2.size.width /= 4;
// //
// //            rectArtifact2.size.height /= 4;
// //
// //            //rectArtifact2.origin.x = rect.size.width - rectArtifact2.size.width;
// //
// //            //rectArtifact2.origin.y = rect.size.height - rectArtifact2.size.height;
// 
//          rectArtifact2.origin.x = 0;
//          rectArtifact2.origin.y = 0;
// 
//             CGContextFillRect(context, rectArtifact2);
// //
//          }
 //      //UIRectFill(rect);
       
       //if(0)
       {
       
 //      int x = p->ios_window_get_x();
 //
 //      int y = p->ios_window_get_y();
 //
 //      CGContextTranslateCTM(context, x, y);
       
           p->_on_draw_background(context, rect.size);
          p->_on_draw_foreground(context, rect.size);
       }

    }
    
    CGContextRestoreGState(context);
    
//
//   CGContextRef cgc = (CGContextRef) [[UIGraphicsContext currentContext] graphicsPort];
//
//#ifdef REDRAW_HINTING
//   
//   {
//      
//      CGContextSetBlendMode(cgc, kCGBlendModeCopy);
//      
//      CGContextSetRGBFillColor(cgc, 255 / 255.0f, 200 / 255.0f, 0 / 255.0f, 155 / 255.0f);
//      
//      auto rectArtifact1 = rect;
//      
//      rectArtifact1.size.width /= 4;
//      
//      rectArtifact1.size.height /= 4;
//      
//      CGContextFillRect(cgc, rectArtifact1);
//      
//   }
//   
//#endif
//   
//   auto rectFrame = [self frame];
//   
//   p->_on_draw_frame(cgc, rectFrame.size);
//   
//#ifdef REDRAW_HINTING
//   
//   {
//   
//      CGContextSetBlendMode(cgc, kCGBlendModeCopy);
//
//      CGContextSetRGBFillColor(cgc, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 155 / 255.0f);
//      
//      auto rectArtifact2 = rect;
//      
//      rectArtifact2.size.width /= 4;
//      
//      rectArtifact2.size.height /= 4;
//      
//      rectArtifact2.origin.x = rect.size.width - rectArtifact2.size.width;
//      
//      rectArtifact2.origin.y = rect.size.height - rectArtifact2.size.height;
//
//      CGContextFillRect(cgc, rectArtifact2);
//      
//   }
//   
//#endif
//   
}


- (BOOL)acceptsFirstResponder
{

   return TRUE;

}


- (BOOL) acceptsFirstMouse:(UIEvent *)theEvent
{
   
//   if(![NSApp isActive])
//   {
//      
//   }
   
//   if(![m_pacmewindowbridge isKeyWindow])
//   {
//      
//      [m_pacmewindowbridge makeKeyWindow];
//      
//   }
   
   return YES;
   
}


- (BOOL) mouseDownCanMoveWindow
{

   return NO;

}

#define DO_FLAG(m_f, p, now, key) \
if(m_f) \
{ \
if(!now) \
{ \
p->macos_window_key_up(key); \
m_f = false; \
} \
} \
else \
{ \
if(now) \
{ \
p->macos_window_key_down(key); \
m_f = true; \
} \
}

//
//- (void)keyDown:(UIEvent *)event
//{
//
//   acme_window_bridge * p = m_pacmewindowbridge;
//     
//   if(p == NULL)
//   {
//      
//      return;
//      
//   }
//   
//   if(event.isARepeat)
//   {
//      
//      return;
//      
//   }
//   
//   DWORD keyCode;
//   
//   DWORD keyFlags = 0;
//   
//   DWORD vkcode;
//   
//   DWORD scancode;
//   
//   keyCode = [event keyCode];
//   
//   vkcode = keyCode;
//      
//   scancode = GetVirtualScanCodeFromVirtualKeyCode(vkcode, 4);
//
//   keyFlags |= (scancode & KBDEXT) ? KBDEXT : 0;
//   
//   char * pszUtf8 = nullptr;
//   
//   if(!apple_is_action_key(keyCode) && !(kbdModFlags &(NSControlKeyMask | NSCommandKeyMask|NSAlternateKeyMask)))
//   {
//   
//      if([[event characters] length ] > 0)
//      {
//      
//         pszUtf8 = strdup([[event characters] UTF8String]);
//      
//      }
//      else if(keyCode == kVK_Space)
//      {
//       
//         pszUtf8=strdup(" ");
//         
//      }
//      
//   }
//   else if(keyCode == kVK_Tab)
//   {
//    
//      pszUtf8 = strdup("\t");
//      
//   }
//   else if(keyCode == kVK_Return)
//   {
//    
//      pszUtf8 = strdup("\r");
//      
//   }
//   
//   if(pszUtf8)
//   {
//
//      int iUni = *pszUtf8;
//      
//      p->on_char(iUni);
//      
//      free(pszUtf8);
//      
//   }
//   
//}
//
//
//- (void)keyUp:(UIEvent *)event
//{
//   
//   DWORD keyCode;
//   
//   DWORD keyFlags = 0;
//   
//   DWORD vkcode;
//   
//   DWORD scancode;
//   
//   NSString * characters;
//   
//   acme_window_bridge * p = m_pacmewindowbridge;
//   
//   if(p == NULL)
//   {
//      
//      return;
//      
//   }
//   
//   keyCode = [event keyCode];
//   
//   characters = [event charactersIgnoringModifiers];
//
//   vkcode = keyCode;
//
//   scancode = GetVirtualScanCodeFromVirtualKeyCode(vkcode, 4);
//
//   keyFlags |= (scancode & KBDEXT) ? KBDEXT : 0;
//   
//}
//
//
//- (void)flagsChanged:(UIEvent *)event
//{
//
//   acme_window_bridge * p = m_pacmewindowbridge;
//   
//   if(p == NULL)
//   {
//      
//      printf("flags_changed(0)\n");
//      
//      [super flagsChanged:event];
//      
//      return;
//      
//   }
//   
//   int key;
//   
//   DWORD keyFlags = 0;
//   
//   DWORD vkcode;
//   
//   DWORD scancode;
//   
//   DWORD modFlags;
//   
//   key = [event keyCode] + 8;
//   
//   modFlags = [event modifierFlags] & NSDeviceIndependentModifierFlagsMask;
//   
//   vkcode = GetVirtualKeyCodeFromKeycode(key, KEYCODE_TYPE_APPLE);
//   
//   scancode = GetVirtualScanCodeFromVirtualKeyCode(vkcode, 4);
//   
//   keyFlags |= (scancode & KBDEXT) ? KBDEXT : 0;
//   
//   scancode &= 0xFF;
//   
//   vkcode &= 0xFF;
//   
//#if 0
//   
//   if (modFlags & NSAlphaShiftKeyMask)
//      printf("NSAlphaShiftKeyMask");
//   
//   if (modFlags & NSShiftKeyMask)
//      printf("NSShiftKeyMask");
//   
//   if (modFlags & NSControlKeyMask)
//      printf("NSControlKeyMask");
//   
//   if (modFlags & NSAlternateKeyMask)
//      printf("NSAlternateKeyMask");
//   
//   if (modFlags & NSCommandKeyMask)
//      printf("NSCommandKeyMask");
//   
//   if (modFlags & NSNumericPadKeyMask)
//      printf("NSNumericPadKeyMask");
//   
//   if (modFlags & NSHelpKeyMask)
//      printf("NSHelpKeyMask");
//   
//#endif
//   
//   kbdModFlags = modFlags;
//
//}
//

//- (void)viewWillMoveToWindow:(UIWindow *)newWindow
//{
//   
//   NSTrackingArea *const trackingArea = [[NSTrackingArea alloc] initWithRect:NSZeroRect options:(NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved | NSTrackingActiveAlways | NSTrackingInVisibleRect) owner:self userInfo:nil];
//   
//   [self addTrackingArea:trackingArea];
//   
//   [self.window invalidateCursorRectsForView:self];
//   
//}


//- (void)mouseEntered:(UIEvent *)theEvent
//{
//
//   [super mouseEntered:theEvent];
//
//}
//
//
//- (void)mouseExited:(UIEvent *)theEvent
//{
//
//   [super mouseExited:theEvent];
//
//}


@end


//unsigned int event_num_pad_key_code(UIEvent * event)
//{
//
//   NSString * arrow = [event charactersIgnoringModifiers];
//   
//   if([arrow length] == 1)
//   {
//      
//      unichar key = [arrow characterAtIndex:0];
//      
//      if(key == NSLeftArrowFunctionKey)
//      {
//         
//         return VK_LEFT; //::user::key_left;
//         
//      }
//      else if(key == NSRightArrowFunctionKey)
//      {
//         
//         return VK_RIGHT; //::user::key_right;
//         
//      }
//      else if(key == NSUpArrowFunctionKey)
//      {
//         
//         return VK_UP; // ::user::key_up;
//         
//      }
//      else if(key == NSDownArrowFunctionKey)
//      {
//         
//         return VK_DOWN; // ::user::key_down;
//         
//      }
//      else if(key >= L'0' && key <= L'9')
//      {
//         
//         //return 3000 + key - L'0';
//         
//         return 0;
//         
//      }
//      
//   }
//   
//   return 0;
//
//}
//
//
//unsigned int event_key_code(UIEvent * event)
//{
//
//   unsigned int uiModifierFlags = (unsigned int) [event modifierFlags];
//
//   if(uiModifierFlags & NSNumericPadKeyMask)
//   {
//
//      return event_num_pad_key_code(event);
//   
//   }
//   
//   unsigned int uiKeyCode = [event keyCode];
// 
//   return uiKeyCode;
//   
//}
//
//
//
