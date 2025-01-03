/*
     File: iosEditImpact.h
 Abstract:
A impact that illustrates how to implement and use the UITextInput protocol.

Heavily leverages an existing CoreText-based editor and merely serves as the "glue" between the system keyboard and this editor.
 
  Version: 2.0
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 topic to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2013 Apple Inc. All Rights Reserved.
 
*/

//#import <UIKit/UIKit.h>

//#import "iosTextView.h"

@class iosEditImpact;
//@class iosTextView;

//// iosEditTextDelegate - simple delegate protocol to notify when the iosEditImpact
//// becomes first responder
@protocol iosEditTextDelegate
- (void)editableCoreTextViewWillEdit:(iosEditImpact *)ioseditview;
- (void)editableCoreTextViewDidBeginEditing:(iosEditImpact *)ioseditview;
@end


// iosEditImpact - Main custom text impact that handles text input and draws text
// (using contained iosTextView)
@interface iosEditImpact : UIView <UITextInput>
{
@public
   
   
   iosWindow *          m_ioswindow;
   //bool                 m_bEditing;
   NSString *           m_strContentText;
   NSRange              m_rangeMarked; // Marked text range (for input method marked text).
   NSRange              m_rangeSelected; // Selected text range.
   UIFont *             m_font;
   
   
}

//@property (nonatomic, copy) NSString *contentText; // The text content (without attributes).
//@property (nonatomic, strong) UIFont *font; // Font used for text content.
//@property (nonatomic, getter=isEditing) BOOL editing; // Is impact in "editing" mode or not (affects drawn results).

- (CGRect)caretRectForIndex:(int)index;
- (CGRect)firstRectForRange:(NSRange)range;
///- (NSInteger)closestIndexToPoint:(CGPoint)point;

+ (UIColor *)caretColor;

- (void) on_text_composed;
- (void) setContentText: (NSString *) text;
- (NSString *) getContentText;

@property (nonatomic, weak) id <iosEditTextDelegate> editableCoreTextViewDelegate;
//@property (nonatomic) iosTextView *textView;

@end
