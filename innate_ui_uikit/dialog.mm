//
//  dialog.mm
//  innate_ui_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-09-20
//
#include "framework.h"
#import <UIKit/UIKit.h>
#include "dialog.h"
#include "acme_windowing_uikit/impact_controller.h"
#include "acme_windowing_uikit/ios_app.h"
#include "acme_windowing_uikit/ns_acme_window.h"


@interface InnateUIDialog : UIView

-(void)dealloc;
@end

@implementation InnateUIDialog

- (void) dealloc
{
   
   NSLog(@"InnateUIDialog::dealloc");
}
@end


namespace innate_ui_uikit
{
   
   void dialog::create()
   {
      
      ::innate_ui_uikit::__impact::create();
      
   }


   void dialog::__create_dialog()
   {
      
      increment_reference_count();

      // m_hwnd = CreateWindowW(_get_class_name(), L"", WS_DLGFRAME | WS_CAPTION | WS_POPUPWINDOW,
      //         CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, (HINSTANCE) ::platform::get()->m_hinstanceThis,
      //         nullptr);

      // m_pgtkwidget = gtk_dialog_new_with_buttons("Custom Dialog",
      //                                              NULL,
      //                                              GTK_DIALOG_DESTROY_WITH_PARENT,
      //                                              NULL);

      
      CGRect frame =CGRect{{0, 0}, {300, 300}};
      
      UIView * view = [[InnateUIDialog alloc] initWithFrame:frame];
      
      [view setBackgroundColor: [UIColor whiteColor]];
      
      //[ view setTitle:@"Custom Dialog" ];
      
            // Create the label
//            NSTextField *label = [[NSTextField alloc] initWithFrame:NSMakeRect(100, 80, 200, 24)];
//            [label setStringValue:@"This is a custom message"];
//            [label setBezeled:NO];
//            [label setDrawsBackground:NO];
//            [label setEditable:NO];
//            [label setSelectable:NO];
//            [[window contentView] addSubview:label];
            
            // Create the button
//            NSButton *button = [[NSButton alloc] initWithFrame:NSMakeRect(110, 20, 80, 24)];
//            [button setTitle:@"OK"];
//            [button setTarget:window]; // Close window when clicked
//            [button setAction:@selector(close)];
//            [[window contentView] addSubview:button];
            
            // Add an icon
//            NSImageView *iconView = [[NSImageView alloc] initWithFrame:NSMakeRect(20, 60, 64, 64)];
//            NSImage *icon = [NSImage imageNamed:NSImageNameCaution]; // Change to your preferred icon
//            [iconView setImage:icon];
//            [[window contentView] addSubview:iconView];
            
            // Center the window on the screen
            ///[window center];
            
            // Show the window without blocking other UI interactions
            ///[window makeKeyAndOrderFront:nil];
            
            // Ensure the application stays running while the window is open
            //[NSApp activateIgnoringOtherApps:YES];
      
      m_pUIView = (__bridge_retained void *) view;
            
      //m_pqwidget = new QDialog();


      //m_pgtkwidgetFixed = gtk_fixed_new();

      //gtk_window_set_child(GTK_WINDOW(m_pgtkwidget), m_pgtkwidgetFixed);
      //gtk_widget_set_parent(m_pgtkwidget, nullptr);
      ///GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(m_pgtkwidget));
      //m_fixed = gtk_fixed_new();
      //gtk_box_append(content_area, m_fixed);

   }


void dialog::show()
{
   
   __show();

   ios_app * papp = (ios_app * ) [[UIApplication sharedApplication] delegate];
   
   auto pwindow = papp->m_pnsacmewindow;
   
   auto pUIView = (__bridge UIView *) m_pUIView;
   
   [pwindow->m_pimpactcontroller.view addSubview: pUIView];
   
   //[pUIView makeKeyAndVisibile];

}

} // namespace innate_ui_uikit
