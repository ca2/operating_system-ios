//
//  AppDelegate.h
//  teste_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 05/05/14.
//  Copyright (c) 2014 ca2 Desenvolvimento de Software Ltda. All rights reserved.
//

//#import <UIKit/UIKit.h>
#include "acme/operating_system/ios/nano/app.h"

@class iosWindowFrameView;

@interface iosWindowApp : ios_app
{
   
@public
   
   struct plane_system * m_pplanesystem;
   
}

@property (strong, nonatomic) UIWindow * window;
@property (strong, nonatomic) iosFrameView * iosframeview;

@end
