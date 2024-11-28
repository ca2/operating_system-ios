//
//  impact_controller.mm
//  acme_windowing_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-11-26.
//
#import "impact_controller.h"
#include "ns_acme_impact.h"
#include "ns_acme_window.h"
#include "acme_window_bridge.h"


@implementation impact_controller


-(void)create_ns_acme_impact
{
   
   CGRect bounds = [ self.view frame ];

   m_pnsacmeimpact = [ [ ns_acme_impact alloc ] initWithFrame: bounds andWindow: m_pnsacmewindow ];
   
}


- (void)viewDidLoad
{
   
    [super viewDidLoad];

    // Set the background color of the view
    //self.view.backgroundColor = [UIColor whiteColor];

    // Add a UILabel to the view
//    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(50, 100, 300, 50)];
//    label.text = @"Welcome to My App!";
//    label.textColor = [UIColor blackColor];
//    label.font = [UIFont boldSystemFontOfSize:24];
//    label.textAlignment = NSTextAlignmentCenter;
   
   
   
   [self create_ns_acme_impact];
   
   auto pnsacmewindow = m_pnsacmewindow;
   
   pnsacmewindow->m_pnsacmeimpact = m_pnsacmeimpact;
   
   //m_pimpactChild = pimpact;
   //[ m_pnsacmeimpact setFrame: bounds ];
   
   [ m_pnsacmeimpact setAutoresizingMask: 0 ];
   
   [ m_pnsacmeimpact setHidden:false];
   
   [m_pnsacmeimpact setAlpha: 1.0f];

   [ self.view addSubview: m_pnsacmeimpact ];
   
   

//    [self.view addSubview:label];
//
//    // Add a UIButton to the view
//    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
//    button.frame = CGRectMake(100, 200, 200, 50);
//    [button setTitle:@"Tap Me" forState:UIControlStateNormal];
//    button.titleLabel.font = [UIFont systemFontOfSize:20];
//    [button addTarget:self action:@selector(buttonTapped) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:button];
}
//
//- (void)buttonTapped {
//    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Hello!"
//                                                                   message:@"You tapped the button."
//                                                            preferredStyle:UIAlertControllerStyleAlert];
//    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK"
//                                                       style:UIAlertActionStyleDefault
//                                                     handler:nil];
//    [alert addAction:okAction];
//    [self presentViewController:alert animated:YES completion:nil];
//}

@end
