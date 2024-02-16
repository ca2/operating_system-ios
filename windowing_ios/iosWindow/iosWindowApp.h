//
//  AppDelegate.h
//  teste_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 05/05/14.
//  Copyright (c) 2014 ca2 Desenvolvimento de Software Ltda. All rights reserved.
//

//#import <UIKit/UIKit.h>
#include "acme/operating_system/ios/nano/app.h"

@class iosWindow;
@class iosFrameView;

@interface iosWindowApp : ios_app
{
   
@public
   
   struct plane_system * m_pplanesystem;
   bool m_b_iCloudInitialized;
   enum_status m_estatus_iCloud;
   
}

@property (strong, nonatomic) iosWindow * ioswindow;
@property (strong, nonatomic) iosFrameView * iosframeview;

//-(enum_status)deferInitializeiCloudContainerAccess;

@end
