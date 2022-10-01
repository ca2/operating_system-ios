#include "framework.h"
#include "shell.h"
#include "interaction_impl.h"
#include "apex/platform/launcher.h"
//#include "launcher.h"
//#include "FileSystemEvents/watcher.h"


__FACTORY_EXPORT void aura_apple_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_ios_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_ios_factory(::factory::factory * pfactory)
{
   

   aura_apple_factory(pfactory);
   
   apex_ios_factory(pfactory);

   pfactory->add_factory_item < ::aura_ios::interaction_impl, ::user::interaction_impl > ();

   pfactory->add_factory_item < ::aura_ios::shell, ::user::shell > ();

}



