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
#include "acme_windowing_uikit/ns_acme_window.h"
#include "acme/constant/user.h"
//#import <MediaPlayer/MediaPlayer.h>

::user::enum_key event_key(UIEvent * event);


class ios_window;

@class iosImpactController;
@class document_picker_delegate;


@interface iosWindow : ns_acme_window
{
@public
   
   
    ios_window            * m_pwindow;
    //iosImpactController    * m_controller;
   
   NSMutableArray < document_picker_delegate *  > * __strong m_documentpickerdelegates;

}


//@property(strong) iosWindow *m_thiswindow;
@property UIViewController *m_initialcontroller;

- (id)initWithFrame:(CGRect)contentRect andAcmeWindowBridgeAsParticle: (::acme::windowing::window *) pacmewindowingwindow;


-(void) pickBrowse:(char **) ppszUTType callback: (const ::function < void(const ::file::path & path) > &) callback;
-(void) pickBrowseForSavingUserController:(void *) pUserController;

@end



