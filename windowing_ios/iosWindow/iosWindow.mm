//
//  iosWindow.m
//  iosWindow
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
#import "_mm.h"
#import "iosWindowApp.h"
#import "iosViewController.h"
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#include "document_picker_delegate.h"


// apple_media_t pointer is a opaque pointer to a MPMediaItem
struct apple_media_t;

void ns_workspace_cgrect(int i, CGRect * p);

void * ns_create_media_item(void * pmediaitem);
double get_status_bar_frame_height();


@implementation iosWindow


//
// initWithContentRect:styleMask:backing:defer:screen:
//
// Init method for the object.
//
- (id)initWithFrame:(CGRect)contentRect

{
   
	self = [super initWithFrame:contentRect ];

	if(self == NULL)
   {
      
      return NULL;
      
   }
   
   self.m_thiswindow = self;
   
   m_documentpickerdelegates = [[NSMutableArray < document_picker_delegate * > alloc] init];
   
   [self setWindowLevel:UIWindowLevelNormal];

	[self setOpaque:NO];

   //[self setBackgroundColor: [ UIColor whiteColor ] ];
   
   [self setClearsContextBeforeDrawing:FALSE];
   
   iosWindowApp * papp = (iosWindowApp *) [[UIApplication sharedApplication] delegate];
   
   papp.m_iosviewcontroller = [[iosViewController alloc] init];
   
   iosViewController * pcontroller = papp.m_iosviewcontroller;
		
   self.m_initialcontroller = pcontroller;
   
   m_controller = pcontroller;
   
   m_controller->m_ioswindow = self;

   [self create_view];
   
   [self setRootViewController:m_controller];
   
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

   m_pwindow->ios_window_resized(rect.size.width, rect.size.height);
   
	return self;
   
}

-(void)dealloc
{
   
   
   
}

- (void)create_view
{

   CGRect bounds = [self frame];
	
   bounds.origin.x = 0;
   bounds.origin.y = 0;

	iosFrameView * frameView = [[iosFrameView alloc] initWithFrame : bounds] ;
   
  	m_controller->m_iosframeview = frameView;
   
   frameView->m_ioswindow =  self;
   
   frameView->m_bShift = false;
   frameView->m_bControl = false;
   frameView->m_bAlt = false;
   
   [frameView setTintColor:[UIColor clearColor]];

	[frameView setFrame : bounds];
   
	[frameView setAutoresizingMask: 0];
   
   [m_controller.view addSubview: frameView];
   
   iosWindowApp * papp = (iosWindowApp *) [[UIApplication sharedApplication] delegate];
   
   papp.m_iosframeview = frameView;
   
}

-(void) pickBrowse :(char ** ) ppszUTType callback : (const ::function < void(const ::file::path & ) > &) callback
{
   
   auto picker = [ [ document_picker_delegate alloc ] initForOpeningFile : ppszUTType callback : callback];
   
   [m_documentpickerdelegates addObject:picker];

   //void ns_pick_viewer_document()
   ns_main_post(^{
      {
//         
//      //   auto picker = [[UIDocumentPickerViewController alloc]
//        //  initForOpeningContentTypes:@[ UTTypeFolder, UTTypeZIP //]];
////         auto picker = [[UIDocumentPickerViewController alloc]
////          initForOpeningContentTypes:@[ UTTypeFolder ]];
//         //@[ UTTypeImage ]]
//         auto uttypea = uttypea_from_strdupa(ppszUTType);
////         auto uttypea = [[NSMutableArray alloc] init];
////         [uttypea addObject:[UTType  typeWithIdentifier:[[NSString alloc] initWithUTF8String:psz];
////         self->m_bForOpeningFile = true;
////         self->m_pUserControllerForSaving = nullptr;
////         self->m_bForOpeningMedia = false;

         
         [ picker start : self->m_controller ];
         
      }

   });

}


-(void)pickBrowseForSavingUserController:(void *)pUserController
{
   
//   self->m_bForOpeningFile = false;
//   self->m_pUserControllerForSaving = pUserController;
//   self->m_bForOpeningMedia = false;
   
   //void ns_pick_viewer_document()
   ns_main_post(^{
      {
         
      //   auto picker = [[UIDocumentPickerViewController alloc]
        //  initForOpeningContentTypes:@[ UTTypeFolder, UTTypeZIP //]];
         //self->m_bForOpeningFile = true;
//         auto UTTypePhotoComposite = [UTType typeWithIdentifier:@"com.app-core.photo-composite"];
////         auto picker = [[UIDocumentPickerViewController alloc]
////          initForOpeningContentTypes:@[ UTTypeFolder ]];
//         auto picker = [[UIDocumentPickerViewController alloc]
//          initForOpeningContentTypes:@[ UTTypeImage, UTTypePhotoComposite ]];
//         picker.delegate = self;
//         [self->m_controller presentViewController:picker animated:YES completion:nil];
      }

   });
//
//   get_app()->::app_core_photo::application::m_ppaneimpact->filemanager_document("file_manager_save")->FileManagerSaveAs(this);

//}
}


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
   
   m_pwindow->ios_window_on_show();
   
}

- (void)windowDidBecomeHidden:(NSNotification*)pnotification
{
   
   m_pwindow->ios_window_on_hide();
   
}


@end


NSArray < UTType * > * uttypea_from_strdupa(char ** pp)
{

   NSMutableArray < UTType * > * uttypea = [[NSMutableArray < UTType * > alloc] init];
   
   auto ppiterator = pp;

   while (*ppiterator != nullptr)
   {
      
      NSString * str = [[NSString alloc] initWithUTF8String:*ppiterator];
      
      UTType * type;
      
      if([str hasSuffix:@".txt"])
      {
         
         type = [UTType  typeWithIdentifier: @"public.plain-text"];
         
      }
      else
      {
         
         type = [UTType  typeWithIdentifier: str];
         
      }

      [uttypea addObject: type];
      
      ::free(*ppiterator);
      
      ppiterator++;

   }

   free(pp);

   return uttypea;

}
