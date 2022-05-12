//
//  iosViewController.h
//  aura
//
//  Created by Camilo Sasuke Tsumanuma on 14/05/14.
//
//

@class iosWindowFrameView;
@class iosEditView;

@interface iosViewController : UIViewController < UITextViewDelegate >
{
@public
   
   
   iosWindowFrameView   *   childContentView;
   iosWindow *              m_pwindow;
   iosEditView *            m_pedit;

}


-(void) deferEdit : (CGRect) frame;
- (void)editingChanged:(id)object;
-(void)onEditSetFocus : (CGRect) rectangle_i32 withText : (NSString *) strText withSelBeg : (long) iSelBeg withSelEnd : (long) iSelEnd;
-(void)onEditKillFocus;

@end
