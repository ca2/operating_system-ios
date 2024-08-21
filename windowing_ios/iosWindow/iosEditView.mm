/*
     File: iosEditView.m
 Abstract:
A view that illustrates how to implement and use the UITextInput protocol.

Heavily leverages an existing CoreText-based editor and merely serves as the "glue" between the system keyboard and this editor.
 
  Version: 2.0
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
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

#import "_mm.h"
#import "iosEditView.h"
#include "acme/constant/user_key.h"
#import <CoreText/CoreText.h>

#import "iosTextPosition.h"
#import "iosTextRange.h"
//#import "iosTextView.h"


// We use a tap gesture recognizer to allow the user to tap to invoke text edit mode.
@interface iosEditView () <UIGestureRecognizerDelegate>

@property (nonatomic) NSMutableString *text;

/*
 An input tokenizer is an object that provides information about the granularity of text units by implementing the UITextInputTokenizer protocol.  Standard units of granularity include characters, words, lines, and paragraphs. In most cases, you may lazily create and assign an instance of a subclass of UITextInputStringTokenizer for this purpose, as this sample does. If you require different behavior than this system-provided tokenizer, you can create a custom tokenizer that adopts the UITextInputTokenizer protocol.
 */
@property (nonatomic) UITextInputStringTokenizer *tokenizer;


- (void)tap:(UITapGestureRecognizer *)tap;

@end



@implementation iosEditView


@synthesize markedTextStyle = _markedTextStyle;
@synthesize inputDelegate = _inputDelegate;




- (id)initWithFrame:(CGRect)frame
{
   
   self = [super initWithFrame:frame];
   
   
    // Add tap gesture recognizer to let the user enter editing mode.
    UITapGestureRecognizer *tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tap:)];
    [self addGestureRecognizer:tapGestureRecognizer];
    tapGestureRecognizer.delegate = self;

    // Create our tokenizer and text storage.
    self.tokenizer = [[UITextInputStringTokenizer alloc] initWithTextInput:self];
    self.text = [[NSMutableString alloc] init];

    self.userInteractionEnabled = YES;
    self.autoresizesSubviews = YES;
   
   //m_bEditing = true;
   
   m_strContentText = @"";
   // _caretView = [[iosCaretView alloc] initWithFrame:CGRectZero];
   self.layer.geometryFlipped = YES;  // For ease of interaction with the CoreText coordinate system.
   m_font = [UIFont systemFontOfSize:18];
   self.backgroundColor = [UIColor clearColor];
   self.contentMode = UIViewContentModeRedraw;
   m_rangeMarked = NSMakeRange(NSNotFound, NSNotFound);
   m_rangeSelected = NSMakeRange(NSNotFound, NSNotFound);
      
//}
  
//    // Create and set up the iosTextView that will do the drawing.
//    iosTextView *textView = [[iosTextView alloc] initWithFrame:CGRectInset(self.bounds, 5, 5)];
//    textView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
//    [self addSubview:textView];
//    contentText = @"";
//    textView.userInteractionEnabled = NO;
//    self.textView = textView;
   
   return self;
   
}


#pragma mark - Custom user interaction

/**
 UIResponder protocol override.
 Our view can become first responder to receive user text input.
 */
- (BOOL)canBecomeFirstResponder
{
   
   return YES;
   
}


/**
 UIResponder protocol override.
 Called when our view is being asked to resign first responder state (in this sample by using the "Done" button).
 */
- (BOOL)resignFirstResponder
{
   // Flag that underlying iosTextView is no longer in edit mode
    //self.editing = NO;
   return [super resignFirstResponder];
}


/**
 UIGestureRecognizerDelegate method.
 Called to determine if we want to handle a given gesture.
 */
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldReceiveTouch:(UITouch *)touch
{
   // If gesture touch occurs in our view, we want to handle it
    return (touch.view == self);
}


/**
 Our tap gesture recognizer selector that enters editing mode, or if already in editing mode, updates the text insertion point.
 */
- (void)tap:(UITapGestureRecognizer *)tap
{
    
   if ([self isFirstResponder])
   {
      
      auto point = [tap locationInView: m_ioswindow->m_controller->m_ioseditview];
      
      int x = point.x;
      
      int y = point.y;
      
      //m_ioswindow->m_pwindow->m_pointLastTouchBegan = point;
      
      m_ioswindow->m_pwindow->ios_window_mouse_down(0, x, y);

      
//
//      // Already in editing mode, set insertion point (via selectedTextRange).
//        [self.inputDelegate selectionWillChange:self];
//
//        // Find and update insertion point in underlying iosTextView.
//        NSInteger index = [self closestIndexToPoint:[tap locationInView:self]];
//
//        if(index < 0)
//        {
//
//            index = 0;
//
//        }
//       NSUInteger location = index;
//       m_rangeMarked = NSRange{NSNotFound, 0};
//       m_rangeSelected = NSRange{location, 0};
//
//        // Let inputDelegate know selection has changed.
//        [self.inputDelegate selectionDidChange:self];
    }
    else {
      // Inform controller that we're about to enter editing mode.
      [self.editableCoreTextViewDelegate editableCoreTextViewWillEdit:self];
      // Flag that underlying iosTextView is now in edit mode.
        //self.editing = YES;
      // Become first responder state (which shows software keyboard, if applicable).
      if( [self becomeFirstResponder])
      {
         
         [self.editableCoreTextViewDelegate editableCoreTextViewDidBeginEditing:self];

      
      }
    }
}


#if 0
// Helper method to use whenever selection state changes
- (void)selectionChanged
{
   /*
     Not implemented in this sample -- a user selection mechanism is beyond the scope of this simple sample, but if a mechanism and UI existed to support user selection of text, this method would update selection information, and inform the underlying iosTextView.
     */
}

// Helper method to use whenever text storage changes.
- (void)textChanged
{
    //self.textView.text = self.text;
}
#endif


#pragma mark - UITextInput methods

#pragma mark UITextInput - Replacing and Returning Text

/**
 UITextInput protocol required method.
 Called by text system to get the string for a given range in the text storage.
 */
- (NSString *)textInRange:(UITextRange *)range
{
    iosTextRange *r = (iosTextRange *)range;
    return ([self.text substringWithRange:r.range]);
}


/**
 UITextInput protocol required method.
 Called by text system to replace the given text storage range with new text.
 */
- (void)replaceRange:(UITextRange *)range withText:(NSString *)text
{
    iosTextRange *indexedRange = (iosTextRange *)range;
   // Determine if replaced range intersects current selection range
   // and update selection range if so.
    NSRange selectedNSRange = m_rangeSelected;
    if ((indexedRange.range.location + indexedRange.range.length) <= selectedNSRange.location) {
        // This is the easy case.
        selectedNSRange.location -= (indexedRange.range.length - text.length);
    } else {
        // Need to also deal with overlapping ranges.  Not addressed
      // in this simplified sample.
    }

    // Now replace characters in text storage
    [self.text replaceCharactersInRange:indexedRange.range withString:text];

   // Update underlying iosTextView
   m_strContentText = self.text;
   m_rangeSelected = selectedNSRange;
   
}


#pragma mark UITextInput - Working with Marked and Selected Text

/**
 UITextInput selectedTextRange property accessor overrides (access/update underlaying iosTextView)
 */
- (UITextRange *)selectedTextRange
{
    return [iosTextRange indexedRangeWithRange: m_rangeSelected];
}


- (void)setSelectedTextRange:(UITextRange *)range
{
    
   iosTextRange *indexedRange = (iosTextRange *)range;
    
   if(indexedRange.range.location != m_rangeSelected.location
      || indexedRange.range.length != m_rangeSelected.length)
   {
    
      m_rangeSelected = indexedRange.range;
   
      //[ super setSelectedTextRange : range ];
      [ self selectionChanged];
      
   }
   
}


/**
 UITextInput markedTextRange property accessor overrides (access/update underlaying iosTextView).
 */
- (UITextRange *)markedTextRange
{
    /*
     Return nil if there is no marked text.
     */
    NSRange markedTextRange = m_rangeMarked;
    if (markedTextRange.length == 0)
    {
    
       return nil;
       
    }
    
    return [iosTextRange indexedRangeWithRange:markedTextRange];
   
}


/**
 UITextInput protocol required method.
 Insert the provided text and marks it to indicate that it is part of an active input session.
 */
- (void)setMarkedText:(NSString *)markedText selectedRange:(NSRange)selectedRange
{
   
   NSRange selectedNSRange = m_rangeSelected;
   
    NSRange markedTextRange = m_rangeMarked;

    if (markedTextRange.location != NSNotFound)
    {
        if (!markedText)
            markedText = @"";
      // Replace characters in text storage and update markedText range length.
        [self.text replaceCharactersInRange:markedTextRange withString:markedText];
        markedTextRange.length = markedText.length;
    }
    else if (selectedNSRange.length > 0) {
      // There currently isn't a marked text range, but there is a selected range,
      // so replace text storage at selected range and update markedTextRange.
        [self.text replaceCharactersInRange:selectedNSRange withString:markedText];
        markedTextRange.location = selectedNSRange.location;
        markedTextRange.length = markedText.length;
    }
    else {
      // There currently isn't marked or selected text ranges, so just insert
      // given text into storage and update markedTextRange.
        [self.text insertString:markedText atIndex:selectedNSRange.location];
        markedTextRange.location = selectedNSRange.location;
        markedTextRange.length = markedText.length;
    }

   // Updated selected text range and underlying iosTextView.

    selectedNSRange = NSMakeRange(selectedRange.location + markedTextRange.location, selectedRange.length);

    m_strContentText = self.text;
    m_rangeMarked = markedTextRange;
    m_rangeSelected = selectedNSRange;
}


/**
 UITextInput protocol required method.
 Unmark the currently marked text.
 */
- (void)unmarkText
{
   
    NSRange markedTextRange = m_rangeMarked;

    if (markedTextRange.location == NSNotFound) {
        return;
    }
   // Unmark the underlying iosTextView.markedTextRange.
    markedTextRange.location = NSNotFound;
    m_rangeMarked = markedTextRange;
}


#pragma mark UITextInput - Computing Text Ranges and Text Positions

// UITextInput beginningOfDocument property accessor override.
- (UITextPosition *)beginningOfDocument
{
   // For this sample, the document always starts at index 0 and is the full length of the text storage.
    return [iosTextPosition positionWithIndex:0];
}


// UITextInput endOfDocument property accessor override.
- (UITextPosition *)endOfDocument
{
   // For this sample, the document always starts at index 0 and is the full length of the text storage.
    return [iosTextPosition positionWithIndex:self.text.length];
}


/*
 UITextInput protocol required method.
 Return the range between two text positions using our implementation of UITextRange.
 */
- (UITextRange *)textRangeFromPosition:(UITextPosition *)fromPosition toPosition:(UITextPosition *)toPosition
{
   // Generate IndexedPosition instances that wrap the to and from ranges.
    iosTextPosition *fromIndexedPosition = (iosTextPosition *)fromPosition;
    iosTextPosition *toIndexedPosition = (iosTextPosition *)toPosition;
    NSRange range = NSMakeRange(MIN(fromIndexedPosition.index, toIndexedPosition.index), ABS(toIndexedPosition.index - fromIndexedPosition.index));

    return [iosTextRange indexedRangeWithRange:range];
}


/**
 UITextInput protocol required method.
 Returns the text position at a given offset from another text position using our implementation of UITextPosition.
 */
- (UITextPosition *)positionFromPosition:(UITextPosition *)position offset:(NSInteger)offset
{
   // Generate IndexedPosition instance, and increment index by offset.
    iosTextPosition *indexedPosition = (iosTextPosition *)position;
    NSInteger end = indexedPosition.index + offset;
   // Verify position is valid in document.
    if (end > self.text.length || end < 0) {
        return nil;
    }

    return [iosTextPosition positionWithIndex:end];
}


/**
 UITextInput protocol required method.
 Returns the text position at a given offset in a specified direction from another text position using our implementation of UITextPosition.
 */
- (UITextPosition *)positionFromPosition:(UITextPosition *)position inDirection:(UITextLayoutDirection)direction offset:(NSInteger)offset
{
    // Note that this sample assumes left-to-right text direction.
    iosTextPosition *indexedPosition = (iosTextPosition *)position;
    NSInteger newPosition = indexedPosition.index;

    switch ((NSInteger)direction) {
        case UITextLayoutDirectionRight:
            newPosition += offset;
            break;
        case UITextLayoutDirectionLeft:
            newPosition -= offset;
            break;
        UITextLayoutDirectionUp:
        UITextLayoutDirectionDown:
         // This sample does not support vertical text directions.
            break;
    }

    // Verify new position valid in document.

    if (newPosition < 0)
        newPosition = 0;

    if (newPosition > self.text.length)
        newPosition = self.text.length;

    return [iosTextPosition positionWithIndex:newPosition];
}


#pragma mark UITextInput - Evaluating Text Positions

/**
 UITextInput protocol required method.
 Return how one text position compares to another text position.
 */
- (NSComparisonResult)comparePosition:(UITextPosition *)position toPosition:(UITextPosition *)other
{
    iosTextPosition *indexedPosition = (iosTextPosition *)position;
    iosTextPosition *otherIndexedPosition = (iosTextPosition *)other;

   // For this sample, simply compare position index values.
    if (indexedPosition.index < otherIndexedPosition.index) {
        return NSOrderedAscending;
    }
    if (indexedPosition.index > otherIndexedPosition.index) {
        return NSOrderedDescending;
    }
    return NSOrderedSame;
}


/**
 UITextInput protocol required method.
 Return the number of visible characters between one text position and another text position.
 */
- (NSInteger)offsetFromPosition:(UITextPosition *)from toPosition:(UITextPosition *)toPosition
{
    iosTextPosition *fromIndexedPosition = (iosTextPosition *)from;
    iosTextPosition *toIndexedPosition = (iosTextPosition *)toPosition;
    return (toIndexedPosition.index - fromIndexedPosition.index);
}


#pragma mark UITextInput - Text Layout, writing direction and position related methods

/**
 UITextInput protocol method.
 Return the text position that is at the farthest extent in a given layout direction within a range of text.
 */
- (UITextPosition *)positionWithinRange:(UITextRange *)range farthestInDirection:(UITextLayoutDirection)direction
{
    // Note that this sample assumes left-to-right text direction.
    iosTextRange *indexedRange = (iosTextRange *)range;
    NSInteger position;

   /*
     For this sample, we just return the extent of the given range if the given direction is "forward" in a left-to-right context (UITextLayoutDirectionRight or UITextLayoutDirectionDown), otherwise we return just the range position.
     */
    switch (direction) {
        case UITextLayoutDirectionUp:
        case UITextLayoutDirectionLeft:
            position = indexedRange.range.location;
            break;
        case UITextLayoutDirectionRight:
        case UITextLayoutDirectionDown:
            position = indexedRange.range.location + indexedRange.range.length;
            break;
    }

   // Return text position using our UITextPosition implementation.
   // Note that position is not currently checked against document range.
    return [iosTextPosition positionWithIndex:position];
}


/**
 UITextInput protocol required method.
 Return a text range from a given text position to its farthest extent in a certain direction of layout.
 */
- (UITextRange *)characterRangeByExtendingPosition:(UITextPosition *)position inDirection:(UITextLayoutDirection)direction
{
    // Note that this sample assumes left-to-right text direction.
    iosTextPosition *pos = (iosTextPosition *)position;
    NSRange result;

    switch (direction) {
        case UITextLayoutDirectionUp:
        case UITextLayoutDirectionLeft:
            result = NSMakeRange(pos.index - 1, 1);
            break;
        case UITextLayoutDirectionRight:
        case UITextLayoutDirectionDown:
            result = NSMakeRange(pos.index, 1);
            break;
    }

    // Return range using our UITextRange implementation.
   // Note that range is not currently checked against document range.
    return [iosTextRange indexedRangeWithRange:result];
}


/**
 UITextInput protocol required method.
 Return the base writing direction for a position in the text going in a specified text direction.
 */
- (NSWritingDirection)baseWritingDirectionForPosition:(UITextPosition *)position inDirection:(UITextStorageDirection)direction
{
    // This sample assumes left-to-right text direction and does not support bi-directional or right-to-left text.
    return NSWritingDirectionLeftToRight;
}


/**
 UITextInput protocol required method.
 Set the base writing direction for a given range of text in a document.
 */
- (void)setBaseWritingDirection:(NSWritingDirection)writingDirection forRange:(UITextRange *)range
{
    // This sample assumes left-to-right text direction and does not support bi-directional or right-to-left text.
}


#pragma mark UITextInput - Geometry methods

/**
 UITextInput protocol required method.
 Return the first rectangle that encloses a range of text in a document.
 */
- (CGRect)firstRectForRange:(NSRange)range
{
    //iosTextRange *r = (iosTextRange *)range;
   // Use underlying iosTextView to get rect for range.
    //CGRect rect  [self firstRectForRange:r.range];
   
   ///{
      
      //long beg = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range start ] ];
      
      
      //long end = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range end ] ];
      
   long beg = range.location;
   
   long end = range.location + range.length;
      CGRect rBeg;
      
      if(!m_ioswindow->m_pwindow->ios_window_edit_caret_rect(&rBeg, beg))
      {
         
         return CGRectNull;
         
      }

      CGRect rEnd;
      
      if(!m_ioswindow->m_pwindow->ios_window_edit_caret_rect(&rEnd, end))
      {
         
         return CGRectNull;
         
      }

      CGRect rect;
      
      rect.origin.x = fmin(rBeg.origin.x, rEnd.origin.x);
      rect.origin.y = fmin(rBeg.origin.y, rEnd.origin.y);
      float r = fmax(rBeg.origin.x + rBeg.size.width, rEnd.origin.x + rEnd.size.width);
      float b = fmax(rBeg.origin.y + rBeg.size.height, rEnd.origin.y + rEnd.size.height);
      rect.size.width = r - rect.origin.x;
      rect.size.height = b - rect.origin.y;

      return rect;
      
   //}

   // Convert rect to our view coordinates.
    //return [self convertRect:rect fromView:self];
}


/*
 UITextInput protocol required method.
 Return a rectangle used to draw the caret at a given insertion point.
 */
- (CGRect)caretRectForPosition:(UITextPosition *)position
{
    iosTextPosition *pos = (iosTextPosition *)position;

   // Get caret rect from underlying iosTextView.
    CGRect rect =  [self caretRectForIndex:
                    (int)pos.index];
   // Convert rect to our view coordinates.
    return [self convertRect:rect fromView:self];
}


#pragma mark UITextInput - Hit testing

/*
 For this sample, hit testing methods are not implemented because there is no implemented mechanism for letting user select text via touches. There is a wide variety of approaches for this (gestures, drag rects, etc) and any approach chosen will depend greatly on the design of the application.
 */

/*
 UITextInput protocol required method.
 Return the position in a document that is closest to a specified point.
 */
- (UITextPosition *)closestPositionToPoint:(CGPoint)point
{
   // Not implemented in this sample. Could utilize underlying iosTextView:closestIndexToPoint:point.
    return nil;
}

/*
 UITextInput protocol required method.
 Return the position in a document that is closest to a specified point in a given range.
 */
- (UITextPosition *)closestPositionToPoint:(CGPoint)point withinRange:(UITextRange *)range
{
   // Not implemented in this sample. Could utilize underlying iosTextView:closestIndexToPoint:point.
    return nil;
}

/*
 UITextInput protocol required method.
 Return the character or range of characters that is at a given point in a document.
 */
- (UITextRange *)characterRangeAtPoint:(CGPoint)point
{
   // Not implemented in this sample. Could utilize underlying iosTextView:closestIndexToPoint:point.
    return nil;
}


/*
 UITextInput protocol required method.
 Return an array of UITextSelectionRects.
 */
- (NSArray *)selectionRectsForRange:(UITextRange *)range
{
    // Not implemented in this sample.
    return nil;
}


#pragma mark UITextInput - Returning Text Styling Information

/*
 UITextInput protocol required method.
 Return a dictionary with properties that specify how text is to be style at a certain location in a document.
 */
- (NSDictionary *)textStylingAtPosition:(UITextPosition *)position inDirection:(UITextStorageDirection)direction
{
    // This sample assumes all text is single-styled, so this is easy.
    return @{ NSFontAttributeName : m_font };
}


#pragma mark UIKeyInput methods

/**
 UIKeyInput protocol required method.
 A Boolean value that indicates whether the text-entry objects have any text.
 */
- (BOOL)hasText
{
    return (self.text.length != 0);
}


/**
 UIKeyInput protocol required method.
 Insert a character into the displayed text. Called by the text system when the user has entered simple text.
 */
- (void)insertText:(NSString *)text
{
   
   NSRange selectedNSRange = m_rangeSelected;
   
   NSRange markedTextRange = m_rangeMarked;
   
   if([ text isEqual:@"\n" ])
   {
      
      m_ioswindow->m_pwindow->ios_window_key_down(::user::e_key_return);
      m_ioswindow->m_pwindow->ios_window_key_up(::user::e_key_return);
      
      return;
      
   }

   /*
     While this sample does not provide a way for the user to create marked or selected text, the following code still checks for these ranges and acts accordingly.
     */
   if (markedTextRange.location != NSNotFound)
   {
      // There is marked text -- replace marked text with user-entered text.
        [self.text replaceCharactersInRange:markedTextRange withString:text];
        selectedNSRange.location = markedTextRange.location + text.length;
        selectedNSRange.length = 0;
        markedTextRange = NSMakeRange(NSNotFound, 0);
    } else if (selectedNSRange.length > 0) {
      // Replace selected text with user-entered text.
        [self.text replaceCharactersInRange:selectedNSRange withString:text];
        selectedNSRange.length = 0;
        selectedNSRange.location += text.length;
    }
    else
    {
       
       // Insert user-entered text at current insertion point.
       
       [ self.text insertString:text atIndex: selectedNSRange.location ];
       
       selectedNSRange.location += text.length;
       
    }

   // Update underlying iosTextView.
   m_strContentText = self.text;
   m_rangeMarked = markedTextRange;
   m_rangeSelected = selectedNSRange;
   
   [ self on_text_composed ];
   
}


/**
 UIKeyInput protocol required method.
 Delete a character from the displayed text. Called by the text system when the user is invoking a delete (e.g. pressing the delete software keyboard key).
 */
- (void)deleteBackward
{
    
   NSRange selectedNSRange = m_rangeSelected;
   
   NSRange markedTextRange = m_rangeMarked;

   /*
     Note: While this sample does not provide a way for the user to create marked or selected text, the following code still checks for these ranges and acts accordingly.
     */
   if (markedTextRange.location != NSNotFound)
   {
   
      // There is marked text, so delete it.
      [self.text deleteCharactersInRange:markedTextRange];
      
      selectedNSRange.location = markedTextRange.location;
      
      selectedNSRange.length = 0;
      
      markedTextRange = NSMakeRange(NSNotFound, 0);
      
    }
    else if (selectedNSRange.length > 0)
    {
    
       // Delete the selected text.
       [self.text deleteCharactersInRange:selectedNSRange];
       
       selectedNSRange.length = 0;
       
    }
    else if (selectedNSRange.location > 0)
    {
    
       // Delete one char of text at the current insertion point.
       
       selectedNSRange.location--;
       
       selectedNSRange.length = 1;
       
       [self.text deleteCharactersInRange:selectedNSRange];
       
       selectedNSRange.length = 0;

   }

   // Update underlying iosTextView.
   m_strContentText = self.text;
   m_rangeMarked = markedTextRange;
   m_rangeSelected = selectedNSRange;
   
   [ self on_text_composed ];
   
}

//
//- (id)initWithFrame:(CGRect)frame
//{
//
//   self = [super initWithFrame:frame];
//
//   if (self)
//    {
//
//       _contentText = @"";
////       _caretView = [[iosCaretView alloc] initWithFrame:CGRectZero];
//       self.layer.geometryFlipped = YES;  // For ease of interaction with the CoreText coordinate system.
//       self.font = [UIFont systemFontOfSize:18];
//       self.backgroundColor = [UIColor clearColor];
//       self.contentMode = UIViewContentModeRedraw;
//       self.markedTextRange = NSMakeRange(NSNotFound, NSNotFound);
//       self.selectedTextRange = NSMakeRange(NSNotFound, NSNotFound);
//
//    }
//
//    return self;
//
//}


- (void) on_text_composed;
{
   
   NSString * str = m_strContentText;
   
   const char * psz=[str UTF8String];
   
   UITextRange * range = self.selectedTextRange;

   long beg = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range start ] ];
   
   long end = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range end ] ];

   m_ioswindow->m_pwindow->ios_window_on_text(psz,
                                              beg, end);
   
}


// Helper method to update our text storage when the text content has changed.
- (void)textChanged
{
   
   [self clearPreviousLayoutInformation];

   
   ns_main_async(^{

   [self setNeedsDisplay];
      
   });

   // Build the attributed string from our text data and string attribute data,
    //NSAttributedString *attributedString = [[NSAttributedString alloc] initWithString:self.contentText attributes:self.attributes];

//   // Create the Core Text framesetter using the attributed string.
//    if (_framesetter != NULL) {
//        CFRelease(_framesetter);
//    }
//    _framesetter = CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef)attributedString);

}



-(void)setFrame:(CGRect)frame
{
   
   [super setFrame:frame];
   
}


-(void)setBounds:(CGRect)bounds
{

   [super setBounds:bounds];

}

//
//// Helper method for drawing the current selection range (as a simple filled rect).
//- (void)drawRangeAsSelection:(NSRange)selectionRange
//{
//   // If not in editing mode, do not draw selection rectangles.
//    if (!self.editing) {
//        return;
//    }
//
//    // If the selection range is empty, do not draw.
//    if (selectionRange.length == 0 || selectionRange.location == NSNotFound) {
//        return;
//    }
//
//   // Set the fill color to the selection color.
//    [[iosTextView selectionColor] setFill];
//
//   /*
//     Iterate over the lines in our CTFrame, looking for lines that intersect with the given selection range, and draw a selection rect for each intersection.
//     */
//    CFArrayRef lines = CTFrameGetLines(_ctFrame);
//    CFIndex linesCount = CFArrayGetCount(lines);
//
//    for (CFIndex linesIndex = 0; linesIndex < linesCount; linesIndex++) {
//
//        CTLineRef line = (CTLineRef) CFArrayGetValueAtIndex(lines, linesIndex);
//        CFRange lineRange = CTLineGetStringRange(line);
//        NSRange range = NSMakeRange(lineRange.location, lineRange.length);
//        NSRange intersection = RangeIntersection(range, selectionRange);
//        if (intersection.location != NSNotFound && intersection.length > 0) {
//         // The text range for this line intersects our selection range.
//            CGFloat xStart = CTLineGetOffsetForStringIndex(line, intersection.location, NULL);
//            CGFloat xEnd = CTLineGetOffsetForStringIndex(line, intersection.location + intersection.length, NULL);
//            CGPoint origin;
//         // Get coordinate and bounds information for the intersection text range.
//            CTFrameGetLineOrigins(_ctFrame, CFRangeMake(linesIndex, 0), &origin);
//            CGFloat ascent, descent;
//            CTLineGetTypographicBounds(line, &ascent, &descent, NULL);
//         // Create a rect for the intersection and draw it with selection color.
//            CGRect selectionRect = CGRectMake(xStart, origin.y - descent, xEnd - xStart, ascent + descent);
//            UIRectFill(selectionRect);
//        }
//    }
//}

// Standard UIView drawRect override that uses Core Text to draw our text contents.
- (void)drawRect:(CGRect)rect
{
/*    // First draw selection / marked text, then draw text.
    [self drawRangeAsSelection:_selectedTextRange];
    [self drawRangeAsSelection:_markedTextRange];

    CTFrameDraw(_ctFrame, UIGraphicsGetCurrentContext());*/
}


//// Public method to find the text range index for a given CGPoint.
//- (NSInteger)closestIndexToPoint:(CGPoint)point
//{
//
//   return m_ioswindow->m_pwindow->ios_window_edit_hit_test(point.x, point.y);
//
//}


/*
 Public method to determine the CGRect for the insertion point or selection, used when creating or updating the simple caret view instance.
 */
- (CGRect)caretRectForIndex:(int)index
{
   
   CGRect r;
   
   if(m_ioswindow->m_pwindow->ios_window_edit_caret_rect(&r,index))
   {
      
      return r;
      
   }
   
   return CGRectNull;
   
}

///*
// Public method to create a rect for a given range in the text contents.
// Called by our EditableTextRange to implement the required UITextInput:firstRectForRange method.
// */
//- (CGRect)firstRectForRange:(NSRange)range;
//{
//
//   long beg = range.location;
//
//   long end = range.location + range.length;
//
//   CGRect rBeg;
//
//   if(!m_ioswindow->m_pwindow->ios_window_edit_caret_rect(&rBeg, beg))
//   {
//
//      return CGRectNull;
//
//   }
//
//   CGRect rEnd;
//
//   if(!m_ioswindow->m_pwindow->ios_window_edit_caret_rect(&rEnd, end))
//   {
//
//      return CGRectNull;
//
//   }
//
//
//   return CGRectNull;
//
//}


// Helper method to update caretView when insertion point/selection changes.
- (void)selectionChanged
{
   
   ns_main_async(^{
      [ self setNeedsDisplay ];
      
   //   // If not in editing mode, we don't show the caret.
   //    if (!self.editing) {
   ////        [self.caretView removeFromSuperview];
   //        return;
   //    }
   ////   long beg = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range start ] ];
   ////
   ////
   ////   long end = [self offsetFromPosition:[self beginningOfDocument] toPosition:[range end ] ];
   ////   long length = end - beg;
   //   /*
   //
   //     If there is no selection range (always true for this sample), find the insert point rect and create a caretView to draw the caret at this position.
   //     */
   //    if (self.rangeSelected.length == 0) {
   ////        self.caretView.frame = [self caretRectForIndex:(int)self.selectedTextRange.location];
   ////        if (self.caretView.superview == nil) {
   ////            [self addSubview:self.caretView];
   ////            [self setNeedsDisplay];
   ////        }
   ////        // Set up a timer to "blink" the caret.
   ////        [self.caretView delayBlink];
   //    }
   //    else {
   //      // If there is an actual selection, don't draw the insertion caret.
   ////        [self.caretView removeFromSuperview];
   ////        [self setNeedsDisplay];
   //    }
   //
   //    if (self.rangeMarked.location != NSNotFound) {
   ////        [self setNeedsDisplay];
   //    }
   });
   

}


// Helper method to release our cached Core Text framesetter and frame.
- (void)clearPreviousLayoutInformation
{
//    if (_framesetter != NULL) {
//        CFRelease(_framesetter);
//        _framesetter = NULL;
//    }
//
//    if (_ctFrame != NULL) {
//        CFRelease(_ctFrame);
//        _ctFrame = NULL;
//    }
}


#pragma mark - Property accessor overrides

/*
 When setting the font, we need to additionally create and set the Core Text font object that corresponds to the UIFont being set.
 */
- (void)setFont:(UIFont *)newFont
{
    if (newFont != m_font) {
        m_font = newFont;

//        // Find matching CTFont via name and size.
//        CTFontRef ctFont = CTFontCreateWithName((__bridge CFStringRef) _font.fontName, _font.pointSize, NULL);
//
//        // Set CTFont instance in our attributes dictionary, to be set on our attributed string.
//        self.attributes = @{ (NSString *)kCTFontAttributeName : (__bridge id)ctFont };
//
//        CFRelease(ctFont);

        [self textChanged];
       
    }
}


/*
 We need to call textChanged after setting the new property text to update layout.
 */
- (void) setContentText: (NSString *) text
{
   
   m_strContentText = [ text copy ];
   
   [ self.text setString: m_strContentText ];
   
   [ self textChanged ];
   
}


- (NSString * ) getContentText
{

   return m_strContentText;
   
}


/*
 Set accessors should call selectionChanged to update view if necessary.
 */

- (void)setMarkedTextRange:(NSRange)range
{
   
   m_rangeMarked = range;
   
   [self selectionChanged];
   
}


//- (void)setSelectedTextRange:(NSRange)range
//{
//    m_rangeSelected = range;
//    [self selectionChanged];
//}


//- (void)setEditing:(BOOL)editing
//{
//
//   m_bEditing = editing;
//
//   [self selectionChanged];
//
//}


#pragma mark - Selection and caret colors

// Class method that returns current selection color (in this sample the color cannot be changed).
+ (UIColor *)selectionColor
{
    static UIColor *selectionColor = nil;
    if (selectionColor == nil) {
        selectionColor = [[UIColor alloc] initWithRed:0.25 green:0.50 blue:1.0 alpha:0.50];
    }
    return selectionColor;
}


// Class method that returns current caret color (in this sample the color cannot be changed).
+ (UIColor *)caretColor
{
    static UIColor *caretColor = nil;
    if (caretColor == nil) {
        caretColor = [[UIColor alloc] initWithRed:0.25 green:0.50 blue:1.0 alpha:1.0];
    }
    return caretColor;
}


- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesBegan:touches withEvent:event];
   
//   ios_window * p = m_ioswindow->m_pwindow;
   
   //BOOL allTouchesEnded = ([touches count] == [[event touchesForView:self] count]);
   
//   if ([touches count] == 1)
//   {
//      
//      UITouch *touch = [touches anyObject];
//      
//      if ([touch tapCount] == 1)
//      {
//         
//         CGPoint point = [touch locationInView:m_ioswindow->m_controller->m_iosframeview];
//         
//         int x = point.x;
//         
//         int y = point.y;
//         
//         m_ioswindow->m_controller->m_iosframeview->m_pointLastTouchBegan = point;
//         
//         p->ios_window_mouse_down(0, x, y);
//         
//         //         if(allTouchesEnded)
//         //         {
//         //
//         //            p->ios_window_mouse_up(x, y);
//         //
//         //         }
//         
//      }
//      
//   }
   
}


//- (void) detectPan:(UIPanGestureRecognizer *) uiPanGestureRecognizer
//{
//
//   CGPoint translation = [uiPanGestureRecognizer translationInView:self.superview];
//
//   ios_window * p = m_ioswindow->m_pwindow;
//
//   int x = m_pointLastTouchBegan.x + translation.x;
//
//   int y = m_pointLastTouchBegan.y + translation.y;
//
//   p->ios_window_mouse_dragged(x, y);
//
//}


- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesMoved:touches withEvent:event];
   
//   ios_window * p = m_ioswindow->m_pwindow;
//   
//   if ([touches count] == 1)
//   {
//      
//      UITouch *touch = [touches anyObject];
//      
//      if ([touch tapCount] == 1)
//      {
//         
//         CGPoint point = [touch locationInView:m_ioswindow->m_controller->m_iosframeview];
//         
//         int x = point.x;
//         
//         int y = point.y;
//         
//         m_ioswindow->m_controller->m_iosframeview->m_pointLastTouchBegan = point;
//         
//         p->ios_window_mouse_moved(0, x, y);
//         
//      }
//      else
//      {
//         
//         //            twoFingerTapIsPossible = NO;
//         
//      }
//      
//   }
//   else if([touches count] <= 0)
//   {
//      
//      p->ios_window_mouse_up(0, m_ioswindow->m_controller->m_iosframeview->m_pointLastTouchBegan.x, m_ioswindow->m_controller->m_iosframeview->m_pointLastTouchBegan.y);
//      
//   }
   
}


- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
   
   [super touchesEnded:touches withEvent:event];
   
//   BOOL allTouchesEnded = ([touches count] == [[event touchesForView:self] count]);
//   
//   ios_window * p = m_ioswindow->m_pwindow;
//   
//   if ([touches count] == 1 && allTouchesEnded)
//   {
//      
//      UITouch *touch = [touches anyObject];
//      
//      // --------------------------------------------------------
//      //
//      //   tap/ClickCount == 0 :
//      //   not properly a tap/click,
//      //   (but-a/"->"){eco/green-lang): drag.
//      //   So, still send mouse up message, at the final location.
//      //
//      if ([touch tapCount] == 0)
//      {
//         
//         CGPoint point = [touch locationInView:m_ioswindow->m_controller->m_iosframeview];
//         
//         int x = point.x;
//         
//         int y = point.y;
//         
//         p->ios_window_mouse_up(0, x, y);
//         
//      }
//      else if ([touch tapCount] == 1)
//      {
//         
//         // if touch is a single tap, store its location so we can average it with the second touch location
//         
//         CGPoint point = [touch locationInView:m_ioswindow->m_controller->m_iosframeview];
//         
//         //CGRect e = [[UIScreen mainScreen] applicationFrame];
//         
//         //int H = (int) e.size.height;
//         
//         int x = point.x;
//         
//         //int y = H - point.y;
//         
//         int y = point.y;
//         
//         p->ios_window_mouse_up(0, x, y);
//         
//      }
//      else
//      {
//         
//         //            twoFingerTapIsPossible = NO;
//         
//      }
//      
//   }
//   
//   //   CGPoint point = [[self window] convertBaseToScreen:[event locationInWindow]];
   
}

@end


#pragma mark - Range intersection function
/*
 Helper function to obtain the intersection of two ranges (for handling selection range across multiple line ranges in drawRangeAsSelection).
 */
NSRange RangeIntersection(NSRange first, NSRange second)
{
    NSRange result = NSMakeRange(NSNotFound, 0);

   // Ensure first range does not start after second range.
    if (first.location > second.location) {
        NSRange tmp = first;
        first = second;
        second = tmp;
    }

   // Find the overlap intersection range between first and second.
    if (second.location < first.location + first.length) {
        result.location = second.location;
        NSUInteger end = MIN(first.location + first.length, second.location + second.length);
        result.length = end - result.location;
    }

    return result;
}



