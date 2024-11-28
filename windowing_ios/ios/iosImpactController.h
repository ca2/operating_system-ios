//
//  iosImpactController.h
//  aura
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 14/05/14.
//
//


#include "acme_windowing_uikit/impact_controller.h"
#include "iosEditImpact.h"

@class iosImpact;
@class iosEditImpact;
@protocol iosEditTextDelegate;

@interface iosImpactController : impact_controller < UITextViewDelegate, iosEditTextDelegate >
{
@public
   
   
   //iosImpact *           m_piosimpact;
   //iosWindow *             m_ioswindow;
   iosEditImpact *         m_pioseditimpact;

}


-(void) deferEdit : (CGRect) frame;
- (void)editingChanged:(id)object;
-(void)onEditSetFocus : (CGRect) int_rectangle withText : (NSString *) strText withSelBeg : (long) iSelBeg withSelEnd : (long) iSelEnd;
-(void)onEditKillFocus;

@end
