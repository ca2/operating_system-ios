//
//  acme_file.cpp
//  acme_macos
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 18/08/21.
//
#include "framework.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme_file.h"

//
//string apple_app_module_path();
//

::enum_status ns_cloud_set_data_with_container_id(const char * psz, const char * pszAppCloudContainerIdentifier, const void * p, long l);

::enum_status ns_cloud_get_data_with_container_id(void ** ppdata, long & l, const char * psz, const char * pszAppCloudContainerIdentifier);


namespace acme_ios
{

   
   acme_file::acme_file()
   {

      m_pplatformfile = this;

   }


   acme_file::~acme_file()
   {


   }


   void acme_file::touch(const ::file::path & path)
   {

      if(acmedirectory()->is_app_cloud_document(path))
      {
         
         touch_app_cloud(path);
         
      }
      else
      {
         ::acme_apple::acme_file::touch(path);
         
         
      }

   }


   void acme_file::touch_app_cloud(const ::file::path & path, const char * pszAppId)
   {


   }


   void acme_file::put_app_cloud_data(const ::file::path & path, const char * pszAppCloudContainerIdentifier, const ::block & block)
   {
      
      ::string strName;
      
      ::string strAppCloudContainerIdentifier(pszAppCloudContainerIdentifier);
      
      acmepath()->defer_get_app_cloud_path_name(strName, strAppCloudContainerIdentifier, path);
      
      ns_cloud_set_data_with_container_id(strName.c_str(), strAppCloudContainerIdentifier, block.data(), block.size());

   }


   ::memory acme_file::get_app_cloud_data(const ::file::path & path, const char * pszAppCloudContainerIdentifier)
   {
      
      ::string strName;
      
      ::string strAppCloudContainerIdentifier;
      
      acmepath()->defer_get_app_cloud_path_name(strName, strAppCloudContainerIdentifier, path);
      
      ::memory m;
      
      void * p = nullptr;
   
      long l = 0;
      
      ::e_status estatus = ns_cloud_get_data_with_container_id(&p, l, strName.c_str(), strAppCloudContainerIdentifier.c_str());
      
      if(estatus.failed())
      {
         
         throw ::exception(estatus);
         
      }
      
      if(::is_set(p))
      {
         
         m.assign(p, l);
         
         ::free(p);
         
      }
         
      return m;
      
   }


//   ::file::path acme_file::module()
//   {
//
//      ::file::path path = apple_app_module_path();
//
//      return path;
//
//   }


} // namespace acme_ios


//char * ns_get_executable_path();
//
//
//string apple_app_module_path()
//{
//
//   return ::string_from_strdup(ns_get_executable_path());
//
//}



