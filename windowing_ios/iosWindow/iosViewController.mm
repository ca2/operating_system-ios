//
//  iosViewController.m
//  base
//
//  Created by Camilo Sasuke Tsumanuma on 14/05/14.
//
//

#import "_mm.h"
#import "iosEditView.h"
#import "iosTextView.h"
#import "iosTextPosition.h"

@interface iosViewController ()

@end

@implementation iosViewController


- (BOOL)shouldAutorotate
{
   return YES;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
   
   [super viewDidLoad];
   
   self->m_ioseditview = nullptr;
   
   // Do any additional setup after loading the view.

   m_iosframeview.frame = self.view.frame;
   
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
   
   [m_iosframeview on_text : text ];
   
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
      
      m_iosframeview.frame = rect;
      
      m_ioswindow->m_pwindow->ios_window_resized(rect.size.width, rect.size.height);
      
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
   
   ios_window * p = m_ioswindow->m_pwindow;
   
   if(p->ios_window_has_keyboard_focus())
   {
      
      return [super becomeFirstResponder];
      
   }
   
   return FALSE;
   
}


- (BOOL)textViewShouldBeginEditing:(UITextView * ) pimpact
{
   
   ios_window * p = m_ioswindow->m_pwindow;
   
   if(p->m_bCanBecomeFirstResponder)
   {
      
       return YES;
      
   }
   
   return NO;
   
}


- (BOOL)textViewShouldEndEditing:(UITextView * ) pimpact
{
   
   ios_window * p = m_ioswindow->m_pwindow;
   
   if(!p->ios_window_has_keyboard_focus())
   {
      
       return YES;
      
   }
   
   return NO;
   
}


-(void)deferEdit : (CGRect) frame
{
   
   if(!self->m_ioseditview)
   {

      self->m_ioseditview = [ [ iosEditView alloc ] initWithFrame : frame];
   
      [ self->m_iosframeview addSubview: self->m_ioseditview];

      [ self->m_ioseditview setEditableCoreTextViewDelegate:m_ioswindow->m_controller];
      
      self->m_ioseditview->m_ioswindow = m_ioswindow;

   }
   else
   {
      
      [ self->m_ioseditview setFrame : frame ];
      
      [ self->m_ioseditview setHidden : FALSE ];
      
   }
   
}


- (void)editingChanged:(id)object {
    // Do your code here
}

-(void)onEditSetFocus : (CGRect) rect withText: (NSString *) strText withSelBeg:(long)iSelBeg withSelEnd:(long)iSelEnd
{
   
   ns_main_async(^()
   {
   
      [ self deferEdit : rect ];
      
      [ self->m_ioseditview setContentText:strText];
      
//      self->m_ioseditview.rangeSelected = NSMakeRange(iSelBeg, iSelEnd);
//
//      [ self->m_ioseditview selectionChanged ];
      
//      UITextPosition * beg = self->m_ioseditview.beginningOfDocument;
//
//      UITextPosition * end = self->m_ioseditview.endOfDocument;
//
//      UITextRange * prange = [ self->m_ioseditview textRangeFromPosition: beg toPosition: end ];
//
//      [ self->m_ioseditview replaceRange : prange withText : strText ];

      UITextPosition * beg = [ iosTextPosition positionWithIndex : iSelBeg ];
      
      UITextPosition * end = [ iosTextPosition positionWithIndex : iSelEnd ];

      UITextRange * prange = [ self->m_ioseditview textRangeFromPosition: beg toPosition: end ];

      [ self->m_ioseditview setSelectedTextRange: prange ];
      
      [self->m_ioseditview.editableCoreTextViewDelegate editableCoreTextViewWillEdit:self->m_ioseditview];
      
      self->m_ioseditview.editing = TRUE;
      if( [self->m_ioseditview becomeFirstResponder])
      {
         
         [self->m_ioseditview.editableCoreTextViewDelegate editableCoreTextViewDidBeginEditing:self->m_ioseditview];

      
      }
   }
   );
   
}


-(void)onEditKillFocus
{
   
   ns_main_async(^{
      if(self->m_ioseditview && [ self->m_ioseditview isFirstResponder ])
      {
      
       //  [ self->m_ioseditview resignFirstResponder];
         [ self->m_ioseditview setHidden: TRUE ];

         [ self->m_iosframeview endEditing:YES];
         
         
      }
   });
   

    

   
}

- (void)editableCoreTextViewWillEdit:(iosEditView *)ioseditview
{
   
   
   
}


- (void)editableCoreTextViewDidBeginEditing:(iosEditView *)ioseditview
{
   
   m_ioswindow->m_pwindow->ios_window_text_view_did_begin_editing();
   
}


@end



