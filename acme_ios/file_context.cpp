#include "framework.h"
#include "file_context.h"


#include <sys/stat.h>


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
      
      ::file_context::initialize(pparticle);
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