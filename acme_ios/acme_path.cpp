// Create on 2021-03-22 09:12 <3ThomasBS_ // at Linux(Question)
// Recreated on 2021-05-16 15:07 <3ThomasBS_ // for macOS
#include "framework.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme_path.h"

//enum
//{
//   e_anonymouse_enum,
//   
//};
//typedef UInt16 UniChar;
//inline int operator -(UniChar ush, decltype(e_anonymouse_enum) e) { return ush - (int) e; }
//#include <Carbon/Carbon.h>


string apple_app_module_path();
enum_status ns_create_alias(const char * pszLink, const char * pszSource);
enum_status ns_symbolic_link_destination(char ** ppszDestination, const char * pszLink);

namespace acme_ios
{

   
   acme_path::acme_path()
   {

      //m_pplatformpath = this;

   }


   acme_path::~acme_path()
   {


   }


//   ::file::path acme_path::app_module()
//   {
//
//      ::file::path path = apple_app_module_path();
//
//      return path;
//
//   }
//


   void acme_path::create_symbolic_link(const ::scoped_string & scopedstrLink, const ::scoped_string & scopedstrSource)
   {
      
      if(!ns_create_alias(scopedstrLink, scopedstrSource))
      {
         
         throw ::exception(error_failed);
         
      }
      
      //return success;
      
   }


   bool acme_path::is_symbolic_link(const ::scoped_string & scopedstrLink)
   {
      
      auto estatus = ns_symbolic_link_destination(nullptr, scopedstrLink);
      
      if(!estatus)
      {
         
         return estatus;
         
      }
      
      return estatus;
      
   }


   ::file::path acme_path::symbolic_link_destination(const ::scoped_string & scopedstrLink)
   {
      
      string strDestination;
      
      char * pszDestination = nullptr;
      
      auto estatus = ns_symbolic_link_destination(&pszDestination, scopedstrLink);
      
      strDestination = ::string_from_strdup(pszDestination);
      
      if(!estatus)
      {
         
         return "";
         
      }
      
      return strDestination;
      
   }


   bool acme_path::has_custom_icon(const ::file::path & path)
   {

//      FSRef ref;
//      
//      FSCatalogInfo info = {};
//      
//      //path = (const UInt8 *)[path fileSystemRepresentation]
//      
//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
//      if (FSPathMakeRef((const UInt8 *) path, &ref, NULL) == noErr)
//#pragma clang diagnostic pop
//      {
//    
//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
//         if (FSGetCatalogInfo(&ref, kFSCatInfoFinderInfo, &info, NULL, NULL, NULL) == noErr)
//#pragma clang diagnostic pop
//         {
//        
//            FileInfo *fileInfo = (FileInfo *)(&info.finderInfo);
//      
//            if(fileInfo->finderFlags & kHasCustomIcon)
//            {
//               
//               return true;
//               
//            }
//    
//         }
//
//      }

      return false;
      
   }


} // namespace acme_ios



