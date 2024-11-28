//
//  document_picker_delegate.mm
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-08-06 12:23
//
#include "document_picker_delegate.h"
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>


NSArray < UTType * > * uttypea_from_strdupa(char ** pp);


@implementation document_picker_delegate


-(instancetype) initForOpeningFile : (char ** ) ppszUTType callback: (const ::function < void (const ::file::path &) > & ) callback
{
   
   self = [super init];
   
   m_bForOpeningFile = true;
   m_pUserControllerForSaving = nullptr;
   m_bForOpeningMedia = false;
   
   m_callback = callback;
   
   m_uttypea = uttypea_from_strdupa(ppszUTType);
   
  
   return self;

}

-(instancetype) initForSavingUserController : (void * ) pUserController
{
   
   self = [super init];
   
   m_bForOpeningFile = false;
   m_pUserControllerForSaving = pUserController;
   m_bForOpeningMedia = false;
   
   auto UTTypePhotoComposite = [UTType typeWithIdentifier:@"com.app-core.photo-composite"];
   
   m_uttypea = @[ UTTypeImage, UTTypePhotoComposite ];
   return self;
   
}
   
- (void)dealloc {
  m_controller.delegate = nil;
}

   
- (void) start : (UIViewController *) pcontroller
{
   
   auto controller = [ [ UIDocumentPickerViewController alloc ] initForOpeningContentTypes : m_uttypea ];
   
   m_controller = controller;
   
   controller.delegate = self;

   [ pcontroller presentViewController: controller animated : YES completion : nil ];
   
}

/**
 *  This delegate method is called when user will either upload or download the file.
 *
 *  @param controller UIDocumentPickerViewController object
 *  @param urls        urls of the files
 */
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray <NSURL *>*)urls
{

    if (m_bForOpeningFile)
    {
       
       long l = [urls count];
       
       if(l == 1)
       {
          
          auto psz = [[[urls objectAtIndex:0] path]UTF8String];
          
          m_callback(psz);
          
          //m_pwindow->ios_window_did_pick_document_at_url();
          
       }
       else
       {
          
//          auto psza = (const char **) malloc(sizeof(const char *) * l);
//          
//          auto p = psza;
//          
//          for(NSURL * url in urls)
//          {
//           
//             *p++ = strdup([[url path]UTF8String]);
//             
//          }
//          
//          m_pwindow->ios_window_did_pick_document_at_urls(psza, l);
//          
       }
     
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
   
   
   m_callback({});
   
}
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURL:(NSURL *)url
{

          auto psz = [[url path]UTF8String];
          
          m_callback(psz);
          
}



@end
