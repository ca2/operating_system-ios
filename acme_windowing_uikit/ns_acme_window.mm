//
//  nswindow.m
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/02/22.
//  23:25
//  Copyright © 2022 Camilo Sasuke Tsumanuma. All rights reserved.
//
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>
//#include <Carbon/Carbon.h>
#include "ns_acme_window.h"
#include "acme_window_bridge.h"
#include "ns_acme_impact.h"
#import "ios_app.h"


void ns_main_post(dispatch_block_t block);

bool ns_app_is_running();
void ns_main_post(dispatch_block_t block);

void ns_main_send(dispatch_block_t block);

 
@implementation ns_acme_window


- (id)initWithFrame:(CGRect)contentRect and_with_acme_window_bridge:(acme_window_bridge *) pacmewindowbridge

{
   
    self = [super initWithFrame:contentRect ];

    if(self == NULL)
   {
      
      return NULL;
      
   }
    m_pacmewindowbridge = pacmewindowbridge;
   self.m_thiswindow = self;
   
//   m_documentpickerdelegates = [[NSMutableArray < document_picker_delegate * > alloc] init];
   
   [self setWindowLevel:UIWindowLevelNormal];

    [self setOpaque:NO];

   //[self setBackgroundColor: [ UIColor whiteColor ] ];
   
   [self setClearsContextBeforeDrawing:FALSE];
   
//   iosWindowApp * papp = (iosWindowApp *) [[UIApplication sharedApplication] delegate];
//   
//   papp.m_iosviewcontroller = [[iosViewController alloc] init];
//   
//   iosViewController * pcontroller = papp.m_iosviewcontroller;
//        
//   self.m_initialcontroller = pcontroller;
//   
//   m_controller = pcontroller;
//   
//   m_controller->m_ioswindow = self;
//
//   [self create_view];
//   
//   [self setRootViewController:m_controller];
   
   CGRect rect;
   
   rect.origin.x = 0;
   rect.origin.y = 0;
   rect.size = contentRect.size;
   
   [NSNotificationCenter.defaultCenter addObserver:self
                                            selector:@selector(windowDidBecomeVisible:)
                                                name:UIWindowDidBecomeVisibleNotification
                                              object:self];
   [NSNotificationCenter.defaultCenter addObserver:self
                                            selector:@selector(windowDidBecomeHidden:)
                                                name:UIWindowDidBecomeHiddenNotification
                                              object:self];

    m_pacmewindowbridge->on_layout(0,0,rect.size.width, rect.size.height);
   
    return self;
   
}

//
//- (void)create_view
//{
//
//   CGRect bounds = [self frame];
//    
//   bounds.origin.x = 0;
//   bounds.origin.y = 0;
//
//    iosFrameView * frameView = [[iosFrameView alloc] initWithFrame : bounds] ;
//   
//      m_controller->m_iosframeview = frameView;
//   
//   frameView->m_ioswindow =  self;
//   
//   frameView->m_bShift = false;
//   frameView->m_bControl = false;
//   frameView->m_bAlt = false;
//   
//   [frameView setTintColor:[UIColor clearColor]];
//
//    [frameView setFrame : bounds];
//   
//    [frameView setAutoresizingMask: 0];
//   
//   [m_controller.view addSubview: frameView];
//   
//   iosWindowApp * papp = (iosWindowApp *) [[UIApplication sharedApplication] delegate];
//   
//   papp.m_iosframeview = frameView;
//   
//}
//
//-(void) pickBrowse :(char ** ) ppszUTType callback : (const ::function < void(const ::file::path & ) > &) callback
//{
//   
//   auto picker = [ [ document_picker_delegate alloc ] initForOpeningFile : ppszUTType callback : callback];
//   
//   [m_documentpickerdelegates addObject:picker];
//
//   //void ns_pick_viewer_document()
//   ns_main_post(^{
//      {
////
////      //   auto picker = [[UIDocumentPickerViewController alloc]
////        //  initForOpeningContentTypes:@[ UTTypeFolder, UTTypeZIP //]];
//////         auto picker = [[UIDocumentPickerViewController alloc]
//////          initForOpeningContentTypes:@[ UTTypeFolder ]];
////         //@[ UTTypeImage ]]
////         auto uttypea = uttypea_from_strdupa(ppszUTType);
//////         auto uttypea = [[NSMutableArray alloc] init];
//////         [uttypea addObject:[UTType  typeWithIdentifier:[[NSString alloc] initWithUTF8String:psz];
//////         self->m_bForOpeningFile = true;
//////         self->m_pUserControllerForSaving = nullptr;
//////         self->m_bForOpeningMedia = false;
//
//         
//         [ picker start : self->m_controller ];
//         
//      }
//
//   });
//
//}
//
//
//-(void)pickBrowseForSavingUserController:(void *)pUserController
//{
//   
////   self->m_bForOpeningFile = false;
////   self->m_pUserControllerForSaving = pUserController;
////   self->m_bForOpeningMedia = false;
//   
//   //void ns_pick_viewer_document()
//   ns_main_post(^{
//      {
//         
//      //   auto picker = [[UIDocumentPickerViewController alloc]
//        //  initForOpeningContentTypes:@[ UTTypeFolder, UTTypeZIP //]];
//         //self->m_bForOpeningFile = true;
////         auto UTTypePhotoComposite = [UTType typeWithIdentifier:@"com.app-core.photo-composite"];
//////         auto picker = [[UIDocumentPickerViewController alloc]
//////          initForOpeningContentTypes:@[ UTTypeFolder ]];
////         auto picker = [[UIDocumentPickerViewController alloc]
////          initForOpeningContentTypes:@[ UTTypeImage, UTTypePhotoComposite ]];
////         picker.delegate = self;
////         [self->m_controller presentViewController:picker animated:YES completion:nil];
//      }
//
//   });
////
////   get_app()->::app_core_photo::application::m_ppaneimpact->filemanager_document("file_manager_save")->FileManagerSaveAs(this);
//
////}
//}


/**
 *  This delegate method is called when user will either upload or download the file.
 *
 *  @param controller UIDocumentPickerViewController object
 *  @param urls        urls of the files
 */
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls
{

   NSLog(@"documentPicker:didPickDocumentsAtURLs:");
   
}

/**
 *  Delegate called when user cancel the document picker
 *
 *  @param controller - document picker object
 */
- (void)documentPickerWasCancelled:(UIDocumentPickerViewController *)controller {
   
   
   NSLog(@"documentPickerWasCancelled:");
   
}


- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURL:(NSURL *)url
{

   NSLog(@"documentPicker:didPickDocumentsAtURL:");
   
}


- (void)windowDidBecomeVisible:(NSNotification*)pnotification
{
   
   m_pacmewindowbridge->ios_window_on_show();
   
}

- (void)windowDidBecomeHidden:(NSNotification*)pnotification
{
   
    m_pacmewindowbridge->ios_window_on_hide();
   
}


// rectangle.origin.x = left of rectangle
// rectangle.origin.y = bottom of rectangle
// origin of screen is at the bottom of screen
// top of rectangle is bigger numerically than the bottom
// and grows bigger from bottom as farther from bottom of screen.


//-(instancetype) init: (CGRect) rectangle with_acme_window_bridge:(acme_window_bridge * )pacmewindowbridge
//{
//   
//   m_pacmewindowbridge = pacmewindowbridge;
//   
//   self = [ super
//      initWithContentRect : rectangle
//      styleMask : 0
//      backing : NSBackingStoreBuffered
//      defer : YES ];
//   
//   if(!self)
//   {
//      
//      return nil;
//      
//   }
//   
//   [ self setOpaque : NO ];
//   
//   [ self setBackgroundColor: [ NSColor clearColor ] ];
//      
//   [ self setAcceptsMouseMovedEvents : YES ];
//   
//   [ self setLevel : NSNormalWindowLevel ];
//   
//   [ self setReleasedWhenClosed : NO ];
//   
//   [ self setIgnoresMouseEvents : NO ];
//   
////   macos_app * papp = (macos_app *) [ [ NSApplication sharedApplication ] delegate ];
////   
////   m_pwindowcontroller = [ papp addWindow: self ];
//
//   [ [ NSNotificationCenter defaultCenter ] addObserver: self selector: @selector(windowDidMove:) name: NSWindowDidMoveNotification object: self];
//
//   [ [ NSNotificationCenter defaultCenter ] addObserver: self selector: @selector(windowDidResize:) name: NSWindowDidResizeNotification object: self];
//   
//   [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(windowDidBecomeMain:) name: NSWindowDidBecomeMainNotification object: self];
//   
//   [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(windowDidResignMain:) name: NSWindowDidResignMainNotification object: self];
//
//   [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(windowDidBecomeKey:) name: NSWindowDidBecomeKeyNotification object: self];
//   
//   [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(windowDidResignKey:) name: NSWindowDidResignKeyNotification object: self];
//
//   [ self create_impact ];
//   
//   return self;
//   
//}

-(void)dealloc
{
   
   m_pnsacmeimpact = nil;
   
   [ [ NSNotificationCenter defaultCenter ] removeObserver: self];

}
//
//- (BOOL)windowShouldClose:(NSWindow *)sender
//{
//   
//   return TRUE;
//   
//}

- (void)windowDidMove:(NSNotification *)notification
{
   
   CGRect rectFrame = [ self frame ];
   
   int x = rectFrame.origin.x;
   
   int y = (int) [[UIScreen mainScreen] bounds].size.height - rectFrame.origin.y - rectFrame.size.height;
   
   int w = rectFrame.size.width;
   
   int h = rectFrame.size.height;
   
   m_pacmewindowbridge->on_layout(x, y, w, h);
   
}


- (void)windowDidResize:(NSNotification *)notification
{
   
   CGRect rectFrame = [ self frame ];
   
   int x = rectFrame.origin.x;
   
   int y = (int) [[UIScreen mainScreen] bounds].size.height - rectFrame.origin.y - rectFrame.size.height;
   
   int w = rectFrame.size.width;
   
   int h = rectFrame.size.height;
   
   m_pacmewindowbridge->on_layout(x, y, w, h);
   
}


- (void)windowDidBecomeMain:(NSNotification *)aNotification
{
   
   printf("windowDidBecomeMain\n");
   
   m_pacmewindowbridge->ios_window_become_main();
   
}


- (void)windowDidResignMain:(NSNotification *)aNotification
{
   
   printf("windowDidResignMain\n");
   
   if(m_pacmewindowbridge)
   {
      
      m_pacmewindowbridge->ios_window_resign_main();
      
   }
   
}


- (void)windowDidBecomeKey:(NSNotification *)aNotification
{
   
   printf("windowDidBecomeKey\n");
   
   m_pacmewindowbridge->ios_window_become_key();
   
}


- (void)windowDidResignKey:(NSNotification *)aNotification
{
   
   printf("windowDidResignKey\n");
   
   if(m_pacmewindowbridge)
   {
      
      m_pacmewindowbridge->ios_window_resign_key();
      
   }
   
}


- (BOOL) canBecomeKeyWindow
{
   
   return YES;
   
}


- (BOOL) canBecomeMainWindow
{
   
   return YES;
   
}


- (BOOL) acceptsFirstResponder
{
   
   return YES;
   
}


- (BOOL) canBecomeFirstResponder
{
   
   return YES;
   
}


- (BOOL) resignFirstResponder
{
   
   return YES;
   
}


- (void)create_impact
{

   CGRect bounds = [ self frame ];
   
   bounds.origin.x = 0;
    
    bounds.origin.y = 0;

   m_pnsacmeimpact = [ [ ns_acme_impact alloc ] initWithFrame: bounds and_acme_window_bridge: m_pacmewindowbridge ];
   
   //m_pimpactChild = pimpact;
   
    [ super addSubview: m_pnsacmeimpact ];
   
   [ m_pnsacmeimpact setFrame: bounds ];
   
   [ m_pnsacmeimpact setAutoresizingMask: 0 ];
   
   //[ m_pnsacmeimpact display ];
   
}


@end



