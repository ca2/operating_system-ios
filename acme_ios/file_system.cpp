//
//  file_system.cpp
//  acme_macos
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 18/08/21.
//
#include "framework.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/path_system.h"
#include "acme/platform/application.h"
#include "file_system.h"

//
//string apple_app_module_path();
//

::e_status ns_cloud_set_data_with_container_id(const char * psz, const char * psz_iCloudContainerIdentifier, const void * p, long l);

::e_status ns_cloud_get_data_with_container_id(void ** ppdata, long & l, const char * psz, const char * psz_iCloudContainerIdentifier);

::enum_status ns_cloud_set_documents_data(const char * psz, const void * p, long l);

::enum_status ns_cloud_get_documents_data(void ** ppdata, long & l, const char * psz);


namespace acme_ios
{

   
   icloud_container::icloud_container()
   {
      
      m_bInitialized = false;
      
   }


   icloud_container::~icloud_container()
   {
   
      
   }

   
   file_system::file_system()
   {

      m_pplatformfile = this;

   }


   file_system::~file_system()
   {


   }


void file_system::initialize(::particle * pparticle)
{

   //auto estatus =
   
   ::file_system::initialize(pparticle);
   
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;

}

   void file_system::touch(const ::file::path & path)
   {

      if(directory_system()->is_icloud_container(path))
      {
         
         touch_app_cloud(path);
         
      }
      else
      {
         ::acme_apple::file_system::touch(path);
         
         
      }

   }


   void file_system::touch_app_cloud(const ::file::path & path, const char * pszAppId)
   {


   }


   void file_system::put_app_cloud_data(const ::file::path & path, const char * psz_iCloudContainerIdentifier, const ::block & block)
   {
      
      ::string strName;
      
      ::string str_iCloudContainerIdentifier(psz_iCloudContainerIdentifier);
      
      path_system()->defer_get_icloud_container_path_name(strName, str_iCloudContainerIdentifier, path);
      
      ns_cloud_set_data_with_container_id(strName.c_str(), str_iCloudContainerIdentifier, block.data(), block.size());

   }


   void file_system::defer_initialize_icloud_container(const char * pszContainerId)
   {
      
      auto & picloudcontainer = m_map_iCloudContainer[pszContainerId];
      
      if(picloudcontainer && picloudcontainer->m_bInitialized)
      {
       
         return;
         
      }
      
      ødefer_construct_new(picloudcontainer);
      
   }


   ::memory file_system::get_app_cloud_data(const ::file::path & path, const char * psz_iCloudContainerIdentifier)
   {
      
      defer_initialize_icloud_container(psz_iCloudContainerIdentifier);
      
      ::string strName;
      
      ::string str_iCloudContainerIdentifier;
      
      path_system()->defer_get_icloud_container_path_name(strName, str_iCloudContainerIdentifier, path);
      
      ::memory m;
      
      void * p = nullptr;
   
      long l = 0;
      
      ::e_status estatus = ns_cloud_get_data_with_container_id(&p, l, strName.c_str(), str_iCloudContainerIdentifier.c_str());
      
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


void file_system::put_documents_cloud_data(const ::file::path & path, const ::block & block)
{

   ns_cloud_set_documents_data(path.c_str(), block.data(), block.size());

}


::memory file_system::get_documents_cloud_data(const ::file::path & path)
{
   
   ::memory m;
   
   void * p = nullptr;

   long l = 0;
   
   ::e_status estatus = ns_cloud_get_documents_data(&p, l, path);
   
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


//   ::file::path file_system::module()
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



