#include "framework.h"
#include "os_context.h"
#include "interprocess.h"
#include "node.h"
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


   pfactory->add_factory_item < ::apex_ios::os_context, ::os_context > ();
   
   pfactory->add_factory_item < ::apex_ios::interprocess_base, ::interprocess::base >();
   pfactory->add_factory_item < ::apex_ios::interprocess_caller, ::interprocess::caller >();
   pfactory->add_factory_item < ::apex_ios::interprocess_target, ::interprocess::target >();
//   pfactory->add_factory_item < ::macos::launcher, ::launcher > ();
//   pfactory->add_factory_item < ::macos::shell_launcher, ::shell_launcher > ();


}



