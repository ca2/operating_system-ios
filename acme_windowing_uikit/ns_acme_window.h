//
//  nswindow.h
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Soerensen on 02/02/22.
//  Copyright (c) 2022 Camilo Sasuke Thomas Borregaard Soerensen. All rights reserved.
//
#pragma once


#include <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <CoreGraphics/CoreGraphics.h>

class acme_window_bridge;
@class ns_acme_impact;
@class impact_controller;

@interface ns_acme_window : UIWindow < UIDocumentPickerDelegate >
{
@public
   
   impact_controller *        m_pimpactcontroller;
   acme_window_bridge *       m_pacmewindowbridge;
   ns_acme_impact *           m_pnsacmeimpact;
   //NSWindowController *       m_pwindowcontroller;
//    ios_window            * m_pwindow;
    //iosImpactController    * m_controller;
//    NSMutableArray < document_picker_delegate *  > * __strong m_documentpickerdelegates;

}



@property(strong) ns_acme_window *m_thiswindow;
//@property UIViewController *m_initialcontroller;


//-(instancetype) init: (CGRect) rectangle with_acme_window_bridge:(acme_window_bridge * )pacmewindowbridge;
//

- (instancetype)initWithFrame:(CGRect)contentRect;
-(void) setBridge:(acme_window_bridge *) pbridge;
//-(void)create_impact;
-(void)controlling_impact;
@end
 
