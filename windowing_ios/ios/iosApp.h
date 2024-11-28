//
//  AppDelegate.h
//  teste_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 05/05/14.
//  Copyright (c) 2014 ca2 Desenvolvimento de Software Ltda. All rights reserved.
//

//#import <UIKit/UIKit.h>
#include "acme_windowing_uikit/ios_app.h"

@class iosWindow;
@class iosImpact;
@class iosImpactController;

@interface iosApp : ios_app
{
   
@public
   
   struct plane_system * m_pplanesystem;
   bool m_b_iCloudInitialized;
   enum_status m_estatus_iCloud;
   
}

@property (strong, nonatomic) iosWindow * m_ioswindow;
@property (strong, nonatomic) iosImpact * m_piosimpact;
@property (strong, nonatomic) iosImpactController *m_iosviewcontroller;

//-(enum_status)deferInitializeiCloudContainerAccess;

@end
