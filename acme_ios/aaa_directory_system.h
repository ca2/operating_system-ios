#pragma once


#include "acme/filesystem/filesystem/directory_system.h"


namespace acme_ios
{
   
   
   class CLASS_DECL_ACME directory_system :
   virtual public ::directory_system
   {
   public:
      
      
      
      ::file::path            m_strTimeFolder;
      ::file::path            m_strNetSeedFolder;
      ::file::path            m_strCommonAppData;
//      ::file::path            m_strAppData;
      ::file::path            m_strPrograms;
      ::file::path            m_strCommonPrograms;
      ::file::path            m_strCa2AppData;
      //::file::path            m_pathHome;
      
      directory_system();
      ~directory_system() override;
      
      void initialize(::particle * pparticle) override;
      
      //virtual void update_module_path();

      ::file::path compute_default_app_data_path() override;

      
      void init_system() override;
      
      
   };
   
   
} // namespace acme_ios



