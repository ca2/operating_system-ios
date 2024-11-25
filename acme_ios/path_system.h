// Create on 2021-03-22 09:12 <3ThomasBS_ // at Linux(Question.)
// Recreated on 2021-05-16 15:07 <3ThomasBS_ // for macOS
#pragma once


#include "acme_apple/path_system.h"


namespace acme_ios
{


   class CLASS_DECL_ACME_MACOS path_system :
      virtual public ::acme_apple::path_system
   {
   public:


      path_system();
      ~path_system() override;


      
      void create_symbolic_link(const ::scoped_string & scopedstrLink, const ::scoped_string & scopedstrSource) override;

      bool is_symbolic_link(const ::scoped_string & scopedstrLink) override;

      ::file::path symbolic_link_destination(const ::scoped_string & scopedstrLink) override;

      bool has_custom_icon(const ::file::path & path) override;
      

   };


} // namespace acme_ios


