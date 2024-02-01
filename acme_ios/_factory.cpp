#include "framework.h"
#include "file.h"
#include "acme_file.h"
#include "acme_directory.h"
#include "acme_path.h"
#include "dir_system.h"
#include "dir_context.h"
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
   
   pfactory->add_factory_item < ::acme_ios::acme_directory, ::acme_directory > ();
   pfactory->add_factory_item < ::acme_ios::acme_file, ::acme_file > ();
   pfactory->add_factory_item < ::acme_ios::acme_path, ::acme_path > ();

   
   pfactory->add_factory_item < ::acme_ios::file_context, ::file_context > ();
   pfactory->add_factory_item < ::acme_ios::dir_context, ::dir_context > ();
//   pfactory->add_factory_item < ::acme_ios::file_system, ::file_system > ();
   pfactory->add_factory_item < ::acme_ios::dir_system, ::dir_system > ();

   //create_factory < ::macos::os_context         , ::os_context       > ();
   //create_factory < ::apple::process            , ::process::process > ();
   
//  pfactory->add_factory_item < ::acme_posix::pipe               , ::operating_system::pipe    > ();
//   
   //create_factory < ::macos::dir_system         , ::dir_system       > ();
   //create_factory < ::macos::file_system        , ::file_system      > ();
   //create_factory < ::macos::dir_context        , ::dir_context      > ();
   //create_factory < ::macos::file_context       , ::file_context     > ();
   //create_factory < ::macos::interaction_impl   , ::user::interaction_impl > ();
   
   //create_factory < ::macos::copydesk           , ::user::copydesk > ();

   //create_factory < ::file::os_watcher          , ::file::watcher    > ();
   //create_factory < ::file::os_watch            , ::file::watch      > ();
   
   
   //create_factory < ::macos::shell   , ::user::shell > ();

}



