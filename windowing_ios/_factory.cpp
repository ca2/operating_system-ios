//
//  _factory.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-20 01:19 <3ThomasBS_!!
//
#include "framework.h"
#include "buffer.h"
#include "windowing.h"
#include "window.h"
#include "host_interaction.h"
#include "display.h"
#include "monitor.h"
#include "imm_client.h"
#include "keyboard.h"
#include "icon.h"
//#include "cursor.h"
#include "copydesk.h"
#include "aura/windowing/desktop_environment.h"


extern "C"
void aura_ios_factory(::factory::factory * pfactory);


extern "C"
void windowing_ios_factory(::factory::factory * pfactory)
{
   

   aura_ios_factory(pfactory);

   
   pfactory->add_factory_item < windowing_ios::windowing, ::acme::windowing::windowing > ();


   pfactory->add_factory_item < windowing_ios::window,
   ::acme::windowing::window > ();

   pfactory->add_factory_item < windowing_ios::host_interaction, ::acme::sandbox_windowing::host_interaction > ();

//   pfactory->add_factory_item < windowing_ios::node, ::platform::node > ();
   pfactory->add_factory_item < windowing_ios::display, ::acme::windowing::display > ();
   pfactory->add_factory_item < windowing_ios::monitor, ::windowing::monitor > ();
   pfactory->add_factory_item < windowing_ios::buffer, ::graphics::graphics > ();
//   pfactory->add_factory_item < windowing_ios::cursor, ::windowing::cursor > ();
//   pfactory->add_factory_item < windowing_ios::notify_icon, ::user::notify_icon > ();
   pfactory->add_factory_item < windowing_ios::icon, ::windowing::icon > ();

   pfactory->add_factory_item < ::imm_client, ::user::text_composition_client > ();

   pfactory->add_factory_item < windowing_ios::keyboard, ::windowing::keyboard > ();

   pfactory->add_factory_item < windowing_ios::copydesk, ::user::copydesk > ();
   
   //pfactory->add_factory_item < windowing_ios::host_interaction, ::acme::sandbox_windowing::host_interaction > ();
   
   pfactory->add_factory_item < ::windowing::desktop_environment > ();

}



