//
//  nsview.h
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Soerensen on 02/02/22.
//  09:10
//  Copyright (c) 2022 Camilo Sasuke Thomas Borregaard Soerensen. All rights reserved.
//

//
//  RoundWindowFrameImpact.h
//  RoundWindow
//
//  Created by Matt Gallagher on 12/12/08.
//  Copyright 2008 Matt Gallagher. All rights reserved.
//
//  Permission is given to use this source code file without charge in any
//  project, commercial or otherwise, entirely at your risk, with the condition
//  that any redistribution (in part or whole) of source code must retain
//  this copyright and permission notice. Attribution in compiled projects is
//  appreciated but not required.
//


#define NS_ROUND_WINDOW_FRAME_PADDING 0

//#include "keyboard.h"

struct mf_context
{

//   enum APPLE_KEYBOARD_TYPE appleKeyboardType;
   
};


@class ns_acme_window;


@interface ns_acme_impact : UIView
{
   @public
//   mf_context* mfc;
   //APPLE_KEYBOARD_TYPE appleKeyboardType;
   //ns_nano_window * m_pnanowindow;
   ns_acme_window * m_pnsacmewindow;
   //acme_window_bridge * m_pacmewindowbridge;
   //UITrackingArea * trackingArea;
   bool m_bLShift;
   bool m_bRShift;
   bool m_bLControl;
   bool m_bRControl;
   bool m_bLAlt;
   bool m_bRAlt;
   bool m_bLCommand; // In Windows, the Windows Key
   bool m_bRCommand; // In Windows, the Windows Key
   unsigned int kbdModFlags;
    CGPoint m_pointLastTouchBegan;
   
}

- (id)initWithFrame:(CGRect)frame andWindow:(ns_acme_window *) pnsacmewindow;

@end
