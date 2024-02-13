#pragma once


#include "acme_apple/file_context.h"


namespace acme_ios
{


   class CLASS_DECL_ACME file_context :
      virtual public ::acme_apple::file_context
   {
   public:

      
      ::pointer < dir_system >      m_pdirsystem;
      ::pointer < file_system >     m_pfilesystem;


      file_context();
      ~file_context() override;

      virtual void initialize(::particle * pparticle) override;
      
      //virtual void update_module_path() override;

      virtual ::payload length(const ::file::path & path, ::payload * pvarQuery) override;
      
      //virtual ::file_pointer get_file(const ::payload & payloadFile, ::file::e_open eopen) override;
      
      ::file_pointer get_file(const ::payload & payloadFile, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception = nullptr) override;
      
      
      ::file_pointer defer_get_protocol_file(const ::scoped_string & scopedstrProtocol, const ::file::path & path, ::file::e_open eopen, ::pointer < ::file::exception > * pfileexception = nullptr) override;

      
      void calculate_main_resource_memory() override;

   };


} // namespace acme_ios



