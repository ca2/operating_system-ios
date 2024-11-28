//
//  document_picker_delegate.h
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-08-06 12:23
//
#pragma once


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface document_picker_delegate : NSObject < UIDocumentPickerDelegate >
{
  
   ::function < void(const ::file::path &) > m_callback;
   bool m_bForOpeningFile;
   void * m_pUserControllerForSaving;
   bool m_bForOpeningMedia;
   
   NSArray<UTType *> * __strong m_uttypea;
   UIDocumentPickerViewController * __strong m_controller;

}

- (instancetype _Nullable )init NS_UNAVAILABLE;

- (instancetype _Nullable) initForOpeningFile : (char * _Nonnull* _Nonnull) ppszUTType callback : (const ::function < void(const ::file::path & ) > &) callback;

- (instancetype _Nullable) initForSavingUserController : (void * _Nonnull) pUserController;

- (void )start : (UIViewController * _Nonnull) pcontroller;



@end
