//
//  document_picker_delegate.m
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 06/08/24.
//
#include "document_picker_delegate.h"
#import <Foundation/Foundation.h>


@implementation iosWindow

- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls
{

    if (m_bForOpeningFile)
    {
       
       long l = [urls count];
       
       if(l == 1)
       {
          
          m_pwindow->ios_window_did_pick_document_at_url([[[urls objectAtIndex:0] path]UTF8String]);
          
       }
       else
       {
          
          auto psza = (const char **) malloc(sizeof(const char *) * l);
          
          auto p = psza;
          
          for(NSURL * url in urls)
          {
           
             *p++ = strdup([[url path]UTF8String]);
             
          }
          
          m_pwindow->ios_window_did_pick_document_at_urls(psza, l);
          
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
   
}
