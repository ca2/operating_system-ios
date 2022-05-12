#include "framework.h"
#include "apex/platform/launcher.h"
#include "launcher.h"
#include "grand_central_dispatch/watcher.h"


extern "C"
void apex_apple_factory(::factory::factory * pfactory);


extern "C"
void acme_ios_factory(::factory::factory * pfactory);


extern "C"
void apex_ios_factory(::factory::factory * pfactory)
{
   

   apex_apple_factory(pfactory);
   
   acme_ios_factory(pfactory);

   pfactory->add_factory_item < ::apex_ios::node, ::acme::node > ();

   pfactory->add_factory_item < ::grand_central_dispatch::watcher, ::file::watcher > ();

   pfactory->add_factory_item < ::grand_central_dispatch::watch, ::file::watch > ();

   pfactory->add_factory_item < ::apex_ios::file_context, ::file_context > ();
   pfactory->add_factory_item < ::apex_ios::dir_context, ::dir_context > ();
   pfactory->add_factory_item < ::apex_ios::file_system, ::file_system > ();
   pfactory->add_factory_item < ::apex_ios::dir_system, ::dir_system > ();

   pfactory->add_factory_item < ::apex_ios::os_context, ::os_context > ();
   
   pfactory->add_factory_item < ::apex_ios::interprocess_communication_base, ::interprocess_communication::base >();
   pfactory->add_factory_item < ::apex_ios::interprocess_communication_rx, ::interprocess_communication::rx >();
   pfactory->add_factory_item < ::apex_ios::interprocess_communication_tx, ::interprocess_communication::tx >();
//   pfactory->add_factory_item < ::macos::launcher, ::launcher > ();
//   pfactory->add_factory_item < ::macos::shell_launcher, ::shell_launcher > ();


}



