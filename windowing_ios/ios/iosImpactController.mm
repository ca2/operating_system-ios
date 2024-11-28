//
//  iosImpactController.m
//  base
//
//  Created by Camilo Sasuke Tsumanuma on 14/05/14.
//
//

#import "_mm.h"
#import "iosEditImpact.h"
//#import "iosTextView.h"
#import "iosTextPosition.h"


double get_status_bar_frame_height();

@interface iosImpactController ()

@end

@implementation iosImpactController


- (BOOL)shouldAutorotate
{
   return YES;
}


-(void)dealloc
{
   
   
   
}


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}


-(void)create_ns_acme_impact
{
   
   CGRect bounds = [ self.view frame ];

   m_pnsacmeimpact = [ [ iosImpact alloc ] initWithFrame: bounds andWindow: m_pnsacmewindow ];

}


- (void)viewDidLoad
{
   
   [super viewDidLoad];
   
   self->m_pioseditimpact = nullptr;
   
   // Do any additional setup after loading the view.

   //m_piosimpact.frame = self.view.frame;
   
   //childContentView.delegate = self;
   
   //childContentView.text = @"Lorem Ipsum";
   

}




//- (void)didRotate:(NSNotification *)notification {
//   UIDeviceOrientation orientation = [[notification object] orientation];
//
//   CGAffineTransform t;
//   if (orientation == UIDeviceOrientationLandscapeLeft) {
//      t = CGAffineTransformMakeRotation(M_PI / 2.0);
//   } else if (orientation == UIDeviceOrientationLandscapeRight) {
//      t = CGAffineTransformMakeRotation(M_PI / -2.0);
//   } else if (orientation == UIDeviceOrientationPortraitUpsideDown) {
//      t = CGAffineTransformMakeRotation(M_PI);
//   } else if (orientation == UIDeviceOrientationPortrait) {
//      t = CGAffineTransformMakeRotation(0.0);
//   }
//
//   CGPoint screenCenter = CGPointMake([UIScreen mainScreen].bounds.size.width/2,[UIScreen mainScreen].bounds.size.height/2);
//   self.view.center = CGPointApplyAffineTransform(screenCenter, t);
//   self.view.bounds = CGRectApplyAffineTransform([UIScreen mainScreen].bounds, t);
//   [self.view setTransform:t];
//
//}

-(BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
   
   return YES;
   
}

- (void)textViewDidChange:(UITextView *)textView
{
   
   NSString * text = [textView text];
   
   iosImpact * piosimpact = (iosImpact *) m_pnsacmeimpact;
   
   [piosimpact on_text : text ];
   
}


- (void)textViewDidChangeSelection:(UITextView *)textView
{
   
   //UITextRange * sel = [textView selectedTextRange];
   
   //[childContentView on_sel : sel ];
   
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/


-(void) viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id )coordinator
{
   
   [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
   
   try
   {
      
      CGRect rect;
      
      rect.origin.x = 0;
      rect.origin.y = 0;
      rect.size = size;
      
      [ m_pnsacmeimpact setFrame: rect ];
      
      auto dStatusBarFrameHeight = get_status_bar_frame_height();
      
      auto pioswindow = (iosWindow *) m_pnsacmewindow;
      
      pioswindow->m_pwindow->m_dStatusBarFrameHeight = dStatusBarFrameHeight;
      
      pioswindow->m_pwindow->ios_window_resized(rect.size.width, rect.size.height);
      
   }
   catch (...)
   {
      
      
      
   }
   
   //      NSRect rect = [self frame];
   //
   //      rect.origin.y        = [[NSScreen mainScreen] frame ].size.height - (rect.origin.y + rect.size.height);
   //
   //      m_pwindow->ios_window_resized(rect);
   
}

- (BOOL)canBecomeFirstResponder
{
   
//   ios_window * p = m_ioswindow->m_pwindow;
//   
//   return p->m_bCanBecomeFirstResponder;
   
   return YES;
}


- (BOOL)becomeFirstResponder
{
   
   auto pioswindow = (iosWindow *) m_pnsacmewindow;
   
   ios_window * p = pioswindow->m_pwindow;
   
   if(p->ios_window_has_keyboard_focus())
   {
      
      return [super becomeFirstResponder];
      
   }
   
   return FALSE;
   
}


- (BOOL)textViewShouldBeginEditing:(UITextView * ) pimpact
{
   
   auto pioswindow = (iosWindow *) m_pnsacmewindow;
   
   ios_window * p = pioswindow->m_pwindow;
   
   if(p->m_bCanBecomeFirstResponder)
   {
      
       return YES;
      
   }
   
   return NO;
   
}


- (BOOL)textViewShouldEndEditing:(UITextView * ) pimpact
{
   
   auto pioswindow = (iosWindow *) m_pnsacmewindow;
   
   ios_window * p = pioswindow->m_pwindow;
   
   if(!p->ios_window_has_keyboard_focus())
   {
      
       return YES;
      
   }
   
   return NO;
   
}


-(void)deferEdit : (CGRect) frame
{
   
   if(!self->m_pioseditimpact)
   {

      self->m_pioseditimpact = [ [ iosEditImpact alloc ] initWithFrame : frame];
   
      [ self->m_pnsacmeimpact addSubview: self->m_pioseditimpact];

      [ self->m_pioseditimpact setEditableCoreTextViewDelegate: self];
      
      self->m_pioseditimpact->m_ioswindow = (iosWindow *) m_pnsacmewindow;

   }
   else
   {
      
      [ self->m_pioseditimpact setFrame : frame ];
      
      [ self->m_pioseditimpact setHidden : FALSE ];
      
   }
   
}


- (void)editingChanged:(id)object {
    // Do your code here
}

-(void)onEditSetFocus : (CGRect) rect withText: (NSString *) strText withSelBeg:(long)iSelBeg withSelEnd:(long)iSelEnd
{
   
   ns_main_post(^()
   {
   
      [ self deferEdit : rect ];
      
      [ self->m_pioseditimpact setContentText : strText ];
      
//      self->m_pioseditimpact.rangeSelected = NSMakeRange(iSelBeg, iSelEnd);
//
//      [ self->m_pioseditimpact selectionChanged ];
      
//      UITextPosition * beg = self->m_pioseditimpact.beginningOfDocument;
//
//      UITextPosition * end = self->m_pioseditimpact.endOfDocument;
//
//      UITextRange * prange = [ self->m_pioseditimpact textRangeFromPosition: beg toPosition: end ];
//
//      [ self->m_pioseditimpact replaceRange : prange withText : strText ];

      UITextPosition * beg = [ iosTextPosition positionWithIndex : iSelBeg ];
      
      UITextPosition * end = [ iosTextPosition positionWithIndex : iSelEnd ];

      UITextRange * prange = [ self->m_pioseditimpact textRangeFromPosition: beg toPosition: end ];

      [ self->m_pioseditimpact setSelectedTextRange: prange ];
      
      [self->m_pioseditimpact.editableCoreTextViewDelegate editableCoreTextViewWillEdit:self->m_pioseditimpact];
      
      //self->m_pioseditimpact.editing = TRUE;
      if( [self->m_pioseditimpact becomeFirstResponder])
      {
         
         [self->m_pioseditimpact.editableCoreTextViewDelegate editableCoreTextViewDidBeginEditing:self->m_pioseditimpact];

      
      }
   }
   );
   
}


-(void)onEditKillFocus
{
   
   ns_main_post(^{
      if(self->m_pioseditimpact && [ self->m_pioseditimpact isFirstResponder ])
      {
      
       //  [ self->m_pioseditimpact resignFirstResponder];
         [ self->m_pioseditimpact setHidden: TRUE ];
         
         iosImpact * piosimpact = (iosImpact *) self-> m_pnsacmeimpact;

         [ piosimpact endEditing:YES];
         
         
      }
   });
   

    

   
}

- (void)editableCoreTextViewWillEdit:(iosEditImpact *)ioseditview
{
   
   
   
}


- (void)editableCoreTextViewDidBeginEditing:(iosEditImpact *)ioseditview
{
   
   auto pioswindow = (iosWindow *) m_pnsacmewindow;
   
   pioswindow->m_pwindow->ios_window_text_view_did_begin_editing();
   
}


@end



