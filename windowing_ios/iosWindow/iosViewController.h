//
//  iosViewController.h
//  aura
//
//  Created by Camilo Sasuke Tsumanuma on 14/05/14.
//
//

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
-(void)onEditSetFocus : (CGRect) rectangle_i32 withText : (NSString *) strText withSelBeg : (long) iSelBeg withSelEnd : (long) iSelEnd;
-(void)onEditKillFocus;

@end
