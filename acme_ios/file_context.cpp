#include "framework.h"
#include "file_context.h"
//#include "icloud_file.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/file_system_options.h"
#include "acme/platform/application.h"
#include "acme/prototype/prototype/url.h"


#include <sys/stat.h>

::enum_status ns_defer_initialize_icloud_container_access();

string matter_zip_path();

namespace acme_ios
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::particle * pparticle)
   {
      
      //auto estatus =
      
      ::acme_apple::file_context::initialize(pparticle);
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
      
//      m_pdirsystem = ::apex::get_system()->m_pdirsystem;
//
//      m_pfilesystem = ::apex::get_system()->m_pfilesystem;
//
//      string str = getenv("HOME");
//
//      ::file::path strRelative = ::dir::install();
//
//      string strUserFolderShift;
//
//      if(::apex::get_system()->has_property("user_folder_relative_path"))
//      {
//
//         strUserFolderShift = strRelative / get_app()->payload("user_folder_relative_path").as_string();
//
//      }
//      else
//      {
//
//         strUserFolderShift = strRelative;
//
//      }
//
//      m_pfilesystem->m_strUserFolder = str / "ca2" / strUserFolderShift;
//
//      return true;

   }


//   void file_context::update_module_path()
//   {
//
////      m_pfilesystem->m_pathModule = apple_app_module_path();
////
////      m_pfilesystem->m_pathCa2Module = m_pdirsystem->m_pathModule;
//
//      //return ::success;
//
//   }


   ::file_pointer file_context::get_file(const ::payload & payloadFile, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception)
   {

      ::file_pointer pfileresult;

      pfileresult = ::file_context::get_file(payloadFile, eopen, ppfileexception);

      if(!pfileresult)
      {

         return pfileresult;

      }

      return pfileresult;

   }

// C++ string at STL

// STL - Standard Template Library

// ::std::string


// Qt is a C++ framework

// Qt string is called QString


// MFC is Microsoft Foundation Classes (for C++)

// MFC string is called CString

// MFC wide string is called CStringW


// ATL is Microsoft Active Template Library (for C++)

// ATL string is called ATLString


// ca2 is a C++ Framework

// ca2 string is called string


   ::file_pointer file_context::defer_get_protocol_file(const ::scoped_string & scopedstrProtocol, const ::file::path & path, ::file::e_open eopen, ::pointer < ::file::exception > * pfileexception)
   {
      
//      if(scopedstrProtocol == "icloud")
//      {
//         
//         auto pfilesystemoptions = application()->m_pfilesystemoptions;
//         
//         if(pfilesystemoptions->m_b_iCloudContainer)
//         {
//            
//            auto estatus = ns_defer_initialize_icloud_container_access();
//            
//            if(estatus == error_icloud_not_available)
//            {
//               
//               application()->application_on_status(estatus);
//               
//               throw ::exception(estatus);
//               
//               return nullptr;
//               
//            }
//            
//            auto pfile = __create_new < ::acme_ios::icloud_file >();
//            
//            ::string strName;
//            
//            ::string str_iCloudContainerIdentifier;
//            
//            acmepath()->defer_get_icloud_container_path_name(strName, str_iCloudContainerIdentifier, path);
//            
//            //pfile->m_pathName = "Documents";
//            
//            pfile->m_pathName /= strName;
//            
//            pfile->m_str_iCloudContainerIdentifier = str_iCloudContainerIdentifier;
//            
//            pfile->m_eopen = eopen;
//            
//            if(eopen & ::file::e_open_read)
//            {
//               
//               auto memory = acmefile()->get_app_cloud_data(pfile->m_pathName, nullptr);
//               
//               pfile->get_memory()->assign(memory);
//               
//            }
//            
//            return pfile;
//            
//         }
//      
//      }
    
      return ::acme_apple::file_context::defer_get_protocol_file(scopedstrProtocol, path, eopen, pfileexception);
      
   }


   ::payload file_context::length(const ::file::path & path, ::payload * pvarQuery)
   {

      ::payload varRet;

      struct stat stat;

      if(::stat(path, &stat)  == -1)
      {
         
         varRet.set_type(::e_type_null);
         
      }
      else
      {
         
         varRet = stat.st_size;
         
      }

      return varRet;

   }


void file_context::calculate_main_resource_memory()
{
   
   ::file::path pathMatter = matter_zip_path();
   
   m_memoryMainResource = as_memory(pathMatter);

}


} // namespace acme_ios





char * ios_matter_zip_path();


string matter_zip_path()
{
   
   return ::string_from_strdup(ios_matter_zip_path());
   
}
