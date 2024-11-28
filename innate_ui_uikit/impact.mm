//
//  window.mm
//  innate_ui_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-09-20 16:42
//
#include "framework.h"
#import <UIKit/UIKit.h>
#include "impact.h"


namespace innate_ui_uikit
{
   

//   void impact::__øcreate()
//   {
//
//      // m_hwnd = CreateWindowW(_get_class_name(), L"", WS_DLGFRAME | WS_CAPTION | WS_POPUPWINDOW,
//      //         CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, (HINSTANCE) ::platform::get()->m_hinstanceThis,
//      //         nullptr);
//
//      // m_pgtkwidget = gtk_dialog_new_with_buttons("Custom Dialog",
//      //                                              NULL,
//      //                                              GTK_DIALOG_DESTROY_WITH_PARENT,
//      //                                              NULL);
//
//      
//      NSRect frame = NSMakeRect(0, 0, 300, 300);
//            NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
//                                                           styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
//                                                             backing:NSBackingStoreBuffered
//                                                               defer:NO];
//            [window setTitle:@"Custom Dialog"];
//            
//            // Create the label
////            NSTextField *label = [[NSTextField alloc] initWithFrame:NSMakeRect(100, 80, 200, 24)];
////            [label setStringValue:@"This is a custom message"];
////            [label setBezeled:NO];
////            [label setDrawsBackground:NO];
////            [label setEditable:NO];
////            [label setSelectable:NO];
////            [[window contentView] addSubview:label];
//            
//            // Create the button
////            NSButton *button = [[NSButton alloc] initWithFrame:NSMakeRect(110, 20, 80, 24)];
////            [button setTitle:@"OK"];
////            [button setTarget:window]; // Close window when clicked
////            [button setAction:@selector(close)];
////            [[window contentView] addSubview:button];
//            
//            // Add an icon
////            NSImageView *iconView = [[NSImageView alloc] initWithFrame:NSMakeRect(20, 60, 64, 64)];
////            NSImage *icon = [NSImage imageNamed:NSImageNameCaution]; // Change to your preferred icon
////            [iconView setImage:icon];
////            [[window contentView] addSubview:iconView];
//            
//            // Center the window on the screen
//            ///[window center];
//            
//            // Show the window without blocking other UI interactions
//            ///[window makeKeyAndOrderFront:nil];
//            
//            // Ensure the application stays running while the window is open
//            //[NSApp activateIgnoringOtherApps:YES];
//      
//      m_pnsobject = window;
//            
//      //m_pqwidget = new QDialog();
//
//
//      //m_pgtkwidgetFixed = gtk_fixed_new();
//
//      //gtk_window_set_child(GTK_WINDOW(m_pgtkwidget), m_pgtkwidgetFixed);
//      //gtk_widget_set_parent(m_pgtkwidget, nullptr);
//      ///GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(m_pgtkwidget));
//      //m_fixed = gtk_fixed_new();
//      //gtk_box_append(content_area, m_fixed);
//
//   }


void impact::__set_size(int cx, int cy)
{
   
   UIView * puiview = (__bridge UIView *) m_pUIView;
   
   auto frame = [ puiview frame ];
   
   frame.size.width = cx;
   
   frame.size.height= cy;
   
   [ puiview setFrame : frame];
   
}


void impact::__center()
{
   
   UIView * puiview = (__bridge UIView *) m_pUIView;
   
   auto frameBefore = [puiview frame];
   
   auto screen = [[UIScreen mainScreen] bounds];
   
   auto frame = frameBefore;
   
   frame.origin.x = (screen.size.width - frame.size.width)/2;

   frame.origin.y = (screen.size.height - frame.size.height)* 2/5;

   [puiview setFrame:frame];
   
   auto frameAfter = [puiview frame];
   
}


void impact::__show()
{
   
   for(auto & p:m_procedureaLayoutParent)
   {
      
      p();
      
   }
   
   for(auto & p:m_procedureaLayoutChildSize)
   {
   
      p();
      
   }
   
   for(auto & p:m_procedureaLayoutChildPosition)
   {
      
      p();
      
   }

   m_procedureaLayoutParent.clear();
   
   m_procedureaLayoutChildSize.clear();

   m_procedureaLayoutChildPosition.clear();
   
   UIView * puiview = (__bridge UIView *) m_pUIView;
   
   [puiview setHidden:FALSE];
   
}


void impact::__hide()
{
  
   UIView * puiview = (__bridge UIView *) m_pUIView;

   [puiview setHidden:TRUE];
   
}


void impact::__destroy_window()
{
 
   //[puiview close];
   
   UIView * puiview = (__bridge UIView *) m_pUIView;
   
   m_pUIView = nullptr;
   
   puiview = nil;
   
}


void impact::__window_release()
{
   
   UIView * puiview = (__bridge UIView *) m_pUIView;

   m_pUIView = nullptr;
 
   puiview = nil;
   
}

} // namespace innate_ui_uikit
