//
//  AppDelegate.h
//  teste_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 05/05/14.
//  Copyright (c) 2014 ca2 Desenvolvimento de Software Ltda. All rights reserved.
//

//#import <UIKit/UIKit.h>
#include "acme/operating_system/ios/nano/user/app.h"

@class iosWindow;
@class iosFrameView;
@class iosViewController;

@interface iosWindowApp : ios_app
{
   
@public
   
   struct plane_system * m_pplanesystem;
   bool m_b_iCloudInitialized;
   enum_status m_estatus_iCloud;
   
}

@property (strong, nonatomic) iosWindow * m_ioswindow;
@property (strong, nonatomic) iosFrameView * m_iosframeview;
@property (strong, nonatomic) iosViewController *m_iosviewcontroller;

//-(enum_status)deferInitializeiCloudContainerAccess;

@end
