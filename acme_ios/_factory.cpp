#include "framework.h"
#include "file.h"
#include "file_system.h"
#include "directory_system.h"
#include "path_system.h"
#include "directory_system.h"
#include "directory_context.h"
#include "file_system.h"
#include "file_context.h"

//#include "copydesk.h"
//#include "file_os_watcher.h"
//#include "acme/node/posix/pipe.h"
//#include "acme/node/apple/process.h"
//#include "acme/node/macos/shell_macos.h"
//#include "acme/node/unix/process.h"


//namespace macos
//{
//
//   factory_exchange::factory_exchange()
//   {
//
//
//
//   }
//
//
//   factory_exchange::~factory_exchange()
//   {
//
//   }
//
//
//} // namespace macos


__FACTORY_EXPORT void acme_apple_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_ios_factory(::factory::factory * pfactory)
{
   
   acme_apple_factory(pfactory);

   //pfactory->add_factory_item < ::acme_ios::stdio_file, ::file::text_file > ();
   pfactory->add_factory_item < ::acme_ios::file, ::file::file > ();
   
   pfactory->add_factory_item < ::acme_ios::directory_system, ::directory_system > ();
   pfactory->add_factory_item < ::acme_ios::file_system, ::file_system > ();
   pfactory->add_factory_item < ::acme_ios::path_system, ::path_system > ();

   
   pfactory->add_factory_item < ::acme_ios::file_context, ::file_context > ();
   pfactory->add_factory_item < ::acme_ios::directory_context, ::directory_context > ();
   pfactory->add_factory_item < ::acme_ios::file_system, ::file_system > ();
   pfactory->add_factory_item < ::acme_ios::directory_system, ::directory_system > ();

   //create_factory < ::macos::os_context         , ::os_context       > ();
   //create_factory < ::apple::process            , ::process::process > ();
   
//  pfactory->add_factory_item < ::acme_posix::pipe               , ::operating_system::pipe    > ();
//   
   //create_factory < ::macos::directory_system         , ::directory_system       > ();
   //create_factory < ::macos::file_system        , ::file_system      > ();
   //create_factory < ::macos::directory_context        , ::directory_context      > ();
   //create_factory < ::macos::file_context       , ::file_context     > ();
   //create_factory < ::macos::interaction_impl   , ::user::interaction_impl > ();
   
   //create_factory < ::macos::copydesk           , ::user::copydesk > ();

   //create_factory < ::file::os_watcher          , ::file::watcher    > ();
   //create_factory < ::file::os_watch            , ::file::watch      > ();
   
   
   //create_factory < ::macos::shell   , ::user::shell > ();

}



