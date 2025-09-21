//
//  still.mm
//  innate_ui_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-09-20 16:29
//
#include "framework.h"
#import <UIKit/UIKit.h>
#include "icon.h"
#include "impact.h"
#include "still.h"

//
//
//@interface XYZTextField: NSTextField
//
//- (BOOL) isFlipped;
//
//@end
//
//@implementation XYZTextField
//
//- (BOOL) isFlipped
//{
//    return YES;
//}
//
//@end


//#include <QDialog>

//#include "innate_ui.h"
//#include "acme/platform/platform.h"
//#include "acme/platform/system.h"
//#include "acme/platform/application.h"
//#include "acme/parallelization/manual_reset_happening.h"


namespace innate_ui_uikit
{
   


//   dialog::dialog()
//   {
//
//      //m_ptFixed = nullptr;
//
//   }
//
//
//   dialog::~dialog()
//   {
//
//   }


   // void dialog::_get_class(WNDCLASSEXW & wcex)
   // {
   //
   //    wcex.style = CS_HREDRAW | CS_VREDRAW;
   //    wcex.lpfnWndProc = WndProc;
   //    wcex.cbClsExtra = 0;
   //    wcex.cbWndExtra = 0;
   //    wcex.hInstance = (HINSTANCE) ::platform::get()->m_hinstanceThis;
   //    //wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
   //    wcex.hIcon = nullptr;
   //    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
   //    wcex.hbrBackground = ::GetSysColorBrush(COLOR_3DFACE);
   //    //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
   //    wcex.lpszMenuName = nullptr;
   //    //wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
   //    wcex.hIconSm = nullptr;
   //
   // }

   void still::__create_still()
   {

      //øcreate();
      // m_hwnd = CreateWindowW(_get_class_name(), L"", WS_DLGFRAME | WS_CAPTION | WS_POPUPWINDOW,
      //         CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, (HINSTANCE) ::platform::get()->m_hinstanceThis,
      //         nullptr);

      // m_pgtkwidget = gtk_dialog_new_with_buttons("Custom Dialog",
      //                                              NULL,
      //                                              GTK_DIALOG_DESTROY_WITH_PARENT,
      //                                              NULL);

      
//      NSRect frame = NSMakeRect(0, 0, 300, 150);
//            NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
//                                                           styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
//                                                             backing:NSBackingStoreBuffered
//                                                               defer:NO];
//            [window setTitle:@"Custom Dialog"];
//
//            // Create the label
//            NSTextField *label = [[NSTextField alloc] initWithFrame:NSMakeRect(100, 80, 200, 24)];
//            [label setStringValue:@"This is a custom message"];
//            [label setBezeled:NO];
//            [label setDrawsBackground:NO];
//            [label setEditable:NO];
//            [label setSelectable:NO];
//            [[window contentView] addSubview:label];
//
//            // Create the button
//            NSButton *button = [[NSButton alloc] initWithFrame:NSMakeRect(110, 20, 80, 24)];
//            [button setTitle:@"OK"];
//            [button setTarget:window]; // Close window when clicked
//            [button setAction:@selector(close)];
//            [[window contentView] addSubview:button];
//
//            // Add an icon
//            NSImageView *iconView = [[NSImageView alloc] initWithFrame:NSMakeRect(20, 60, 64, 64)];
//            NSImage *icon = [NSImage imageNamed:NSImageNameCaution]; // Change to your preferred icon
//            [iconView setImage:icon];
//            [[window contentView] addSubview:iconView];
//
//            // Center the window on the screen
//            [window center];
//
//            // Show the window without blocking other UI interactions
//            [window makeKeyAndOrderFront:nil];
//
//            // Ensure the application stays running while the window is open
//            [NSApp activateIgnoringOtherApps:YES];
//
//      m_pqwidget = new QDialog();
      
      UIView * puiview;
      
      if(m_bIcon)
      {
         
         UIImageView *iconView = [[UIImageView alloc] initWithFrame:CGRect{{20, 60}, {64, 64}}];
         
         puiview = (UIView *) iconView;

      }
      else
      {
         
         UILabel *label = [[UILabel alloc] initWithFrame:CGRect{{100, 80},{ 200, 24}}];

         //[label setBezeled:NO];
         //[label setDrawsBackground:NO];
         //[label setEditable:NO];
         //[label setSelectable:NO];
         
         puiview = (UIView *) label;

      }
      
      m_pUIView = (__bridge_retained void *) puiview;

      ::pointer < ::innate_ui_uikit::impact > puikitwindowParent = m_pwindowParent;
      
      UIView * pviewParent = (__bridge UIView *) puikitwindowParent->m_pUIView;
      
      [ pviewParent addSubview : puiview];
     
//
//      if (m_pNSWindow)
//      {
//
//         system()->innate_ui()->add_top_level_window(this);
//
//      }

      //m_pgtkwidgetFixed = gtk_fixed_new();

      //gtk_window_set_child(GTK_WINDOW(m_pgtkwidget), m_pgtkwidgetFixed);
      //gtk_widget_set_parent(m_pgtkwidget, nullptr);
      ///GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(m_pgtkwidget));
      //m_fixed = gtk_fixed_new();
      //gtk_box_append(content_area, m_fixed);

   }

   
   void still::__set_text(const char * pszText)
   {
      
      NSString * pstr = [[NSString alloc] initWithUTF8String:pszText];
   
      UILabel * label = (UILabel *) (__bridge UIView *) m_pUIView;
      
//      NSTextField *label = [[NSTextField alloc] initWithFrame:NSMakeRect(100, 80, 200, 24)];
      [label setText:pstr];

   }


void still::__set_icon(::innate_ui_uikit::icon * picon)
{
   
   UIImageView * puiimageview = (UIImageView *)(__bridge UIView *) m_pUIView;
   
   [puiimageview setImage:(__bridge UIImage *) picon->m_pUIImage];
   
}


} // namespace innate_ui_uikit
