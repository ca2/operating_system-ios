//
//  iosViewController.h
//  aura
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 14/05/14.
//
//

#include "iosEditView.h"

@class iosFrameView;
@class iosEditView;
@protocol iosEditTextDelegate;

@interface iosViewController : UIViewController < UITextViewDelegate, iosEditTextDelegate >
{
@public
   
   
   iosFrameView *       m_iosframeview;
   iosWindow *          m_ioswindow;
   iosEditView *        m_ioseditview;

}


-(void) deferEdit : (CGRect) frame;
- (void)editingChanged:(id)object;
-(void)onEditSetFocus : (CGRect) int_rectangle withText : (NSString *) strText withSelBeg : (long) iSelBeg withSelEnd : (long) iSelEnd;
-(void)onEditKillFocus;

@end
