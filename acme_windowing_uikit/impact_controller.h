//
//  impact_controller.h
//  acme_windowing_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-11-26.
//

#import <UIKit/UIKit.h>
@class ns_acme_window;
@class ns_acme_impact;

class acme_window_bridge;

@interface impact_controller : UIViewController
{
@public
   
   
   ns_acme_window *           m_pnsacmewindow;
  
   
   ns_acme_impact *           m_pnsacmeimpact;
   
   
}

@end
