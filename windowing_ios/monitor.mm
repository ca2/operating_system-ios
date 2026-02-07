//
//  monitor.m
//  windowing_macos
//
//  Created by Camilo Sasuke on 27/05/21 20:48 BRT <3ThomasBS_!!
//
#include "framework.h"
#import <UIKit/UIKit.h>


double get_status_bar_frame_height();


int ns_monitor_count()
{
   
   int __block iCount = 0;
   
   ns_main_send(^{
      
      if (@available(iOS 16.0, *))
      {
         // Count screens by looking at connected scenes' screens
         NSCountedSet *screens = [[NSCountedSet alloc] init];
         for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
            if (![scene isKindOfClass:[UIWindowScene class]]) { continue; }
            UIScreen *screen = ((UIWindowScene *)scene).screen;
            if (screen) { [screens addObject:screen]; }
         }
         iCount = (int)screens.count;
      } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

         NSArray *screenArray = [UIScreen screens];
         iCount= (int)screenArray.count;
#pragma clang diagnostic pop
      }
   });
   
   return iCount;
   
}


void ns_screen_translate(CGRect * prect)
{
   
   CGRect rectMainMonitor;

   ns_main_monitor_cgrect(&rectMainMonitor);
   
   auto nsBottom = prect->origin.y + prect->size.height;
   
   auto top = rectMainMonitor.origin.y + rectMainMonitor.size.height;

   prect->origin.y = top - nsBottom;

}


void ns_monitor_cgrect(int i, CGRect * prect)
{
   
   CGRect __block bounds{};
   ns_main_send(^{
      
   UIScreen *pscreen = nil;
   
   if (@available(iOS 16.0, *)) {
      // Collect unique screens from connected scenes
      NSMutableOrderedSet<UIScreen *> *uniqueScreens = [NSMutableOrderedSet orderedSet];
      for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
         if (![scene isKindOfClass:[UIWindowScene class]]) { continue; }
         UIScreen *screen = ((UIWindowScene *)scene).screen;
         if (screen) { [uniqueScreens addObject:screen]; }
      }
      if (i >= 0 && i < (int)uniqueScreens.count) {
         pscreen = uniqueScreens[i];
      } else {
         pscreen = [UIScreen mainScreen];
      }
   } else {
      
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

      NSArray *screenArray = [UIScreen screens];
      if (i >= 0 && i < (int)screenArray.count) {
         pscreen = [screenArray objectAtIndex:i];
      } else {
         pscreen = [UIScreen mainScreen];
      }
#pragma clang diagnostic pop

   }

   bounds = [pscreen nativeBounds];
   
   });
   
   *prect = bounds;

   ns_screen_translate(prect);
}


void ns_workspace_cgrect(int i, CGRect * prect)
{
   
   CGRect __block bounds{};
   
   ns_main_send(^()
                {
                UIScreen *pscreen = nil;
                if (@available(iOS 16.0, *)) {
                   NSMutableOrderedSet<UIScreen *> *uniqueScreens = [NSMutableOrderedSet orderedSet];
                   for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
                      if (![scene isKindOfClass:[UIWindowScene class]]) { continue; }
                      UIScreen *screen = ((UIWindowScene *)scene).screen;
                      if (screen) { [uniqueScreens addObject:screen]; }
                   }
                   if (i >= 0 && i < (int)uniqueScreens.count) {
                      pscreen = uniqueScreens[i];
                   } else {
                      pscreen = [UIScreen mainScreen];
                   }
                } else {
                   
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

                   NSArray *screenArray = [UIScreen screens];
                   if (i >= 0 && i < (int)screenArray.count) {
                      pscreen = [screenArray objectAtIndex:i];
                   } else {
                      pscreen = [UIScreen mainScreen];
                   }
#pragma clang diagnostic pop

                }
                bounds =[pscreen nativeBounds];
});

   *prect = bounds;
   
   prect->size.height -= get_status_bar_frame_height();
   
   ns_screen_translate(prect);
}


void ns_main_monitor_cgrect(CGRect * prect)
{

   auto pscreen = [UIScreen mainScreen];

   *prect = [pscreen nativeBounds];
   
}


