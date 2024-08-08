//
//  acme_file.hpp
//  acme_macos
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 18/08/21.
//

#pragma once


#include "acme_apple/acme_file.h"


namespace acme_ios
{


   class icloud_container :
      virtual public ::particle
   {
   public:
   
      ::string    m_strContainerId;
      bool        m_bInitialized;
   
      icloud_container();
      ~icloud_container();
   
   };


   class CLASS_DECL_ACME_MACOS acme_file :
      virtual public ::acme_apple::acme_file
   {
   public:
      
      
      string_map < ::pointer < icloud_container > > m_map_iCloudContainer;
      
      
      acme_file();
      ~acme_file() override;

      bool _is_icloud_app_document(const ::file::path & path);
      
      void touch(const ::file::path & path) override;
      void touch_app_cloud(const ::file::path & path, const char * pszContainerId = nullptr) override;
      //::file::path module() override;
      
      
      void put_app_cloud_data(const ::file::path & path, const char * pszContainerId, const ::block & block) override;
      
      virtual void defer_initialize_icloud_container(const char * pszContainerId);
      
      ::memory get_app_cloud_data(const ::file::path & path, const char * pszContainerId) override;
      
      void put_documents_cloud_data(const ::file::path & path, const ::block & block) override;

      ::memory get_documents_cloud_data(const ::file::path & path) override;
      

   };


} // namespace acme_ios



