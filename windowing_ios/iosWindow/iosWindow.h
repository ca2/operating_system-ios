//
//  iosWindow.h
//  iosWindow
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
#include "acme/constant/user.h"
//#import <MediaPlayer/MediaPlayer.h>

::user::enum_key event_key(UIEvent * event);


class ios_window;

@class iosViewController;


@interface iosWindow : UIWindow < UIDocumentPickerDelegate >
{
@public
   
   
    ios_window            * m_pwindow;
    iosViewController    * m_controller;
   bool m_bForOpeningFile;
   void * m_pUserControllerForSaving;
   bool m_bForOpeningMedia;
}

-(void) pickBrowse;
-(void) pickBrowseForSavingUserController:(void *) pUserController;

@end



