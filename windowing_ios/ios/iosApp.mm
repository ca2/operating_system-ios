//
//  AppDelegate.mm
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 05/05/14.
//  Copyright (c) 2014 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//

#include "_mm.h"
#import "iosApp.h"
#include "acme/constant/id.h"
//#include <AVFoundation/AVFoundation.h>
//void os_on_will_finish_launching();

//void application_send_status(::enum_status estatus, ::particle * pparticle = nullptr, long long ll = 0);
void system_id_update(::platform::system * psystem, ::huge_integer iUpdate, ::huge_integer iPayload);
::platform::system * application_system(::platform::application * papplication);

int defer_run_system();

int defer_run_system(const char * pszFileName);

int defer_run_system(char * * psza, int c);

void system_call_update_app_activated();

@implementation iosApp


- (BOOL)application:(UIApplication *)application
willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
{
   
   //m_pplanesystem = get_plane_system();
   
   //os_on_will_finish_launching();
   
   m_b_iCloudInitialized = false;
   
   m_estatus_iCloud = error_not_initialized;
   
   [super application:application willFinishLaunchingWithOptions:launchOptions];
   
   return YES;
   
}

-(void) create_ns_acme_window
{

   auto bounds = [[UIScreen mainScreen] bounds];
   
   m_pnsacmewindow = [[iosWindow alloc] initWithFrame: bounds];

   
}


- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
{
   
   return [super application:application didFinishLaunchingWithOptions:launchOptions];
   //system_id_update(application_system(m_papplication), id_app_activated, 0);

   //return YES;
   
}


- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options
{
   
   NSString * strUrl = [ url absoluteString ];
   
//   ::function < void(bool) > function = [completion](bool bSuccess)
//   {
//
//      completion(bSuccess ? TRUE : FALSE);
//
//   };
   
   //m_pplanesystem->_main_application_handle_url([ strUrl UTF8String ], nullptr);
   
   system_id_update(application_system(m_papplication), id_did_pick_document_at_url, (::iptr) (void *) (const char*)[ strUrl UTF8String ]);
   
   return true;
   
}


- (UIInterfaceOrientationMask)application:(UIApplication *)application
  supportedInterfaceOrientationsForWindow:(UIWindow *)window
{

   return UIInterfaceOrientationMaskAll;
   
}


- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the backgios state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackgios:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports backgios execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForegios:(UIApplication *)application
{
    // Called as part of the transition from the backgios to the inactive state; here you can undo many of the changes made on entering the backgios.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the backgios, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackgios:.
}

@end

//
//void ui_application_main(int argc, char * argv[], const char * pszCommandLine, NSString * strDelegateClass);

char * ns_aura_application_delegate_class()
{
   
    return strdup([NSStringFromClass([iosApp class])UTF8String]);
    
}


//void ns_windowing_application_main(int argc, char * argv[], const char * pszCommandLine)
//{
//                              
//   ui_application_main(argc, argv, pszCommandLine, NSStringFromClass([iosApp class]));
//   
//}
//
//
//::enum_status ios_defer_initialize_icloud_container_access()
//{
//   
//   __block enum_status estatus;
//   
//   ns_main_send(^{
//      
//      iosApp * papp = (iosApp *) [[UIApplication sharedApplication] delegate];
//
//      estatus = [ papp deferInitializeiCloudContainerAccess ];
//
//   });
//   
//   return estatus;
//   
//}
//
//
//
