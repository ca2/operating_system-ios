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
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

void ns_workspace_cgrect(int i, CGRect * p);


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
   
   [self setWindowLevel:UIWindowLevelNormal];

	[self setOpaque:NO];

   //[self setBackgroundColor: [ UIColor whiteColor ] ];
   
   [self setClearsContextBeforeDrawing:FALSE];
		
   m_controller = [[iosViewController alloc] init];
   
   m_controller->m_ioswindow = self;

   [self create_view];
   
   [self setRootViewController:m_controller];
   
   CGRect rect;
   
   rect.origin.x = 0;
   rect.origin.y = 0;
   rect.size = contentRect.size;
   
   m_pwindow->m_dStatusBarFrameHeight = get_status_bar_frame_height();
   
   m_pwindow->ios_window_resized(rect.size.width, rect.size.height);
   
	return self;
   
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
   
   papp.iosframeview = frameView;
   
}

-(void) pickBrowse
{
   
   //void ns_pick_viewer_document()
   ns_main_async(^{
      {
         
      //   auto picker = [[UIDocumentPickerViewController alloc]
        //  initForOpeningContentTypes:@[ UTTypeFolder, UTTypeZIP //]];
         self->m_bForOpeningFile = true;
         auto picker = [[UIDocumentPickerViewController alloc]
          initForOpeningContentTypes:@[ UTTypeFolder ]];
         picker.delegate = self;
         [self->m_controller presentViewController:picker animated:YES completion:nil];
      }

   });

}


/**
 *  This delegate method is called when user will either upload or download the file.
 *
 *  @param controller UIDocumentPickerViewController object
 *  @param url        url of the file
 */

- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentAtURL:(NSURL *)url
{
    if (m_bForOpeningFile)
    {
       
       m_pwindow->ios_window_did_pick_document_at_url([[url path]UTF8String]);
     
//        // Condition called when user download the file
//        NSData *fileData = [NSData dataWithContentsOfURL:url];
//        // NSData of the content that was downloaded - Use this to upload on the server or save locally in directory
//       
//        //Showing alert for success
//        dispatch_async(dispatch_get_main_queue(), ^{
//           
//            NSString *alertMessage = [NSString stringWithFormat:@"Successfully downloaded file %@", [url lastPathComponent]];
//            UIAlertController *alertController = [UIAlertController
//                                                  alertControllerWithTitle:@"UIDocumentView"
//                                                  message:alertMessage
//                                                  preferredStyle:UIAlertControllerStyleAlert];
//            [alertController addAction:[UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil]];
//            [self->m_controller presentViewController:alertController animated:YES completion:nil];
//           
//        });
    }
//    else  if (controller.documentPickerMode == UIDocumentPickerModeExportToService)
//    {
//        // Called when user uploaded the file - Display success alert
//        dispatch_async(dispatch_get_main_queue(), ^{
//           
//            NSString *alertMessage = [NSString stringWithFormat:@"Successfully uploaded file %@", [url lastPathComponent]];
//            UIAlertController *alertController = [UIAlertController
//                                                  alertControllerWithTitle:@"UIDocumentView"
//                                                  message:alertMessage
//                                                  preferredStyle:UIAlertControllerStyleAlert];
//            [alertController addAction:[UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil]];
//            [self presentViewController:alertController animated:YES completion:nil];
//           
//        });
//    }
   
}

/**
 *  Delegate called when user cancel the document picker
 *
 *  @param controller - document picker object
 */
- (void)documentPickerWasCancelled:(UIDocumentPickerViewController *)controller {
   
}



@end
