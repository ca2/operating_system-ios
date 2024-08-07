/*
     File: iosTextRange.m
 Abstract: A UITextRange object represents a range of characters in a text container; in other words, it identifies a starting index and an ending index in string backing a text-entry object.

 Classes that adopt the UITextInput protocol must create custom UITextRange objects for representing ranges within the text managed by the class. The starting and ending indexes of the range are represented by UITextPosition objects. The text system uses both UITextRange and UITextPosition objects for communicating text-layout information.

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
#import "iosTextRange.h"
#import "iosTextPosition.h"

@implementation iosTextRange

// Class method to create an instance with a given range
+ (instancetype)indexedRangeWithRange:(NSRange)range
{
    if (range.location == NSNotFound) {
        return nil;
    }

    iosTextRange *indexedRange = [[self alloc] init];
    indexedRange.range = range;
    return indexedRange;
}


// UITextRange read-only property - returns start index of range.
- (UITextPosition *)start
{
    return [iosTextPosition positionWithIndex:self.range.location];
}


// UITextRange read-only property - returns end index of range.
- (UITextPosition *)end
{
   return [iosTextPosition positionWithIndex:(self.range.location + self.range.length)];
}


// UITextRange read-only property - returns YES if range is zero length.
-(BOOL)isEmpty
{
    return (self.range.length == 0);
}

@end
