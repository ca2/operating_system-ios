#include "framework.h"
#include "directory_context.h"
#include "directory_system.h"
#include "file_system.h"
#include "acme_ios/directory_system.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/system.h"
#include "acme/prototype/prototype/url.h"


bool _ui_library_dir(char * psz, unsigned int * puiSize);


namespace acme_ios
{


   directory_context::directory_context()
   {


   }


   directory_context::~directory_context()
   {
   
   
   }


bool directory_context::fast_has_subdir(const ::file::path & path)
{
   
   ::string strProtocol = ::url::get_protocol(path);
   
   if(strProtocol == "icloud")
   {
      
      return true;
      
   }
   
   return ::directory_context::fast_has_subdir(path);
   
}


   ::file::listing_base & directory_context::root_ones(::file::listing_base & listing)
   {
      
      ::file::path path;
      
      path = "/";
      
      path.m_etype = ::file::e_type_existent_folder;
      
      listing.defer_add(path);

      listing.m_straTitle.add("File System");

      return listing;

   }


//   bool directory_context::enumerate(::file::listing & listing)
//   {
//
//      return ::directory_context::enumerate(listing);
//
////      if(listing.m_bRecursive)
////      {
////
////         index iStart = listing.get_size();
////
////         {
////
////            ___scoped_restore(listing.m_pathUser);
////
////            ___scoped_restore(listing.m_pathFinal);
////
////            ___scoped_restore(listing.m_eextract);
////
////            if(::directory_context::ls(listing))
////            {
////
////               listing = ::error_failed;
////
////               return listing;
////
////            }
////
////            ::file::listing dira(get_app());
////
////            dira.ls_dir(listing.m_pathFinal);
////
////            for(int i = 0; i < dira.get_count(); i++)
////            {
////
////               ::file::path directory_context = dira[i];
////
////               if(directory_context == listing.m_pathFinal)
////                  continue;
////
////               listing.m_pathUser.Empty();
////               listing.m_pathFinal = directory_context;
////
////               if(listing.m_eextract != extract_all)
////               {
////
////                  listing.m_eextract = extract_none;
////
////               }
////
////               listing.ls();
////
////            }
////
////         }
////
////         ::file::path_array  straPath;
////
////         ::dir::ls(straPath, listing.m_pathFinal);
////
//////            file_find file_find;
////
////         //          bool bWorking = file_find.FindFile(listing.m_path / listing.os_pattern()) != false;
////
////         for(auto & strPath : straPath)
////         {
////
////            bool bDir = is(strPath);
////
////            if((listing.m_bDir && bDir) || (listing.m_bFile && !bDir))
////            {
////
////               if(!bDir && !matches_wildcard_criteria(listing.m_straPattern, strPath.name()))
////                  continue;
////
////               listing.add(strPath);
////
////               listing.last().m_iDir = bDir ? 1 : 0;
////
////            }
////
////         }
////
////         for(index i = iStart; i < listing.get_size(); i++)
////         {
////
////            listing[i].m_iRelative = listing.m_pathFinal.get_length() + 1;
////
////         }
////
////      }
////      else
////      {
////
////         if(::directory_context::ls(listing).succeeded())
////         {
////
////            return listing;
////
////         }
////
////         ::file::path_array  straPath;
////
////         ::dir::ls(straPath, listing.m_pathFinal);
////
////         // file_find file_find;
////
////         // bool bWorking = file_find.FindFile(listing.m_path / listing.os_pattern()) != false;
////
////         for(auto & strPath : straPath)
////         {
////
////            bool bDir = is(strPath);
////
////            if((listing.m_bDir && bDir) || (listing.m_bFile && !bDir))
////            {
////
////               if(!bDir && !matches_wildcard_criteria(listing.m_straPattern, strPath.name()))
////                  continue;
////
////               listing.add(strPath);
////
////               listing.last().m_iDir = bDir ? 1 : 0;
////
////            }
////
////         }
////
////      }
////
////      return listing;
//
//   }
//

//   bool directory_context::is(const ::file::path & path)
//   {
//
//      return ::directory_context::is(path);
//
////      auto psystem = m_psystem;
////
////      auto pdirectorysystem = psystem->directory_system();
////
////      if(pdirectorysystem->is(path))
////      {
////
////         return true;
////
////      }
////
////      string strPath(path);
////
////#ifdef WINDOWS
////
////      if(strPath.get_length() >= MAX_PATH)
////      {
////
////         if(::str::begins(strPath, "\\\\"))
////         {
////
////            strPath = "\\\\?\\UNC" + strPath.Mid(1);
////
////         }
////         else
////         {
////
////            strPath = "\\\\?\\" + strPath;
////
////         }
////
////      }
////
////#endif
////
////      bool bIsDir = ::dir::_is(strPath);
////
////      return bIsDir;
//
//   }
//
//
////   bool directory_context::mk(const ::file::path & pcsz)
////   {
////
////      if(is(pcsz))
////      {
////
////         return true;
////
////      }
////
////      ::file::path_array stra;
////
////      pcsz.ascendants_path(stra);
////
////      index i = stra.get_upper_bound();
////
////      for(; i >= 0; i--)
////      {
////
////         if(is(stra[i]))
////         {
////
////            i++;
////
////            break;
////
////         }
////
////      }
////
////      if(i < 0)
////      {
////
////         return true;
////
////      }
////
////      for(; i < stra.get_size(); i++)
////      {
////
////         if(!is(stra[i]))
////         {
////
////            if(::dir::mkdir(stra[i]))
////            {
////
////            }
////
////            if(!         auto psystem = m_psystem;
////
////         auto pdirectorysystem = psystem->directory_system();
////
////pdirectorysystem->is(stra[i]))
////            {
////
////               return false;
////
////            }
////
////         }
////
////      }
////
////      return true;
////
////   }
////

   //   bool dir::rm(::application *   papp, const ::file::path & psz, bool bRecursive)
   //   {
   //      if(bRecursive)
   //      {
   //         string_array straPath;
   //         string_array straTitle;
   //         ls(papp, psz, &straPath, &straTitle);
   //         for(int i = 0; i < straPath.get_count(); i++)
   //         {
   //            if(is(straPath[i], papp))
   //            {
   //               rm(papp, path(psz, straTitle[i]), true);
   //            }
   //            else
   //            {
   //               ::unlink(straPath[i]);
   //            }
   //         }
   //      }
   //      return ::rmdir(psz) != false;
   //   }
   //
   //
   //   string ::file_path_folder(const char * path1)
   //   {
   //      const char * psz = path1 + strlen(path1) - 1;
   //      while(psz >= path1)
   //      {
   //         if(*psz != '\\' && *psz != '/' && *psz != ':')
   //            break;
   //         psz--;
   //      }
   //      while(psz >= path1)
   //      {
   //         if(*psz == '\\' || *psz == '/' || *psz == ':')
   //            break;
   //         psz--;
   //      }
   //      if(psz >= path1) // strChar == "\\" || strChar == "/"
   //      {
   //         const char * pszEnd = psz;
   //         /*while(psz >= path1)
   //          {
   //          if(*psz != '\\' && *psz != '/' && *psz != ':')
   //          break;
   //          psz--;
   //          }*/
   //         return string(path1, pszEnd - path1 + 1);
   //      }
   //      else
   //      {
   //         return "";
   //      }
   //   }
   //
   //   string ::file_path_folder(const ::scoped_string & scopedstr)
   //   {
   //
   //      character_count iLast = str.get_length() - 1;
   //
   //      while(iLast >= 0)
   //      {
   //         if(str.m_pszData[iLast] != '\\' && str.m_pszData[iLast] != '/' && str.m_pszData[iLast] != ':')
   //            break;
   //         iLast--;
   //      }
   //      while(iLast >= 0)
   //      {
   //         if(str.m_pszData[iLast] == '\\' || str.m_pszData[iLast] == '/' || str.m_pszData[iLast] == ':')
   //            break;
   //         iLast--;
   //      }
   //      if(iLast >= 0)
   //      {
   //         while(iLast >= 0)
   //         {
   //            if(str.m_pszData[iLast] != '\\' && str.m_pszData[iLast] != '/' && str.m_pszData[iLast] != ':')
   //               break;
   //            iLast--;
   //         }
   //         return str.Left(iLast + 1);
   //      }
   //      else
   //      {
   //         return "";
   //      }
   //   }
   //
   //
   //   class ::file::path & dir::path()
   //   {
   //      return m_path;
   //   }



//   ::file::path directory_context::trash_that_is_not_trash(const ::file::path & psz)
//   {
//      if(psz == nullptr)
//         return "";
//
//      if(psz[1] == ':')
//      {
//         string strDir = name(psz);
//         string str;
//         str = strDir.Left(2);
//         str += "\\trash_that_is_not_trash\\";
//         string strFormat;
//         ::earth::time time;
//         time = ::earth::time::now();
//         strFormat.format("%04d-%02d-%02d %02d-%02d-%02d\\", time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
//         str += strFormat;
//         if(strDir.m_pszData[2] == '\\')
//         {
//            str += strDir.Mid(3);
//         }
//         else
//         {
//            str += strDir.Mid(2);
//         }
//         return str;
//      }
//
//      return "";
//   }


//   bool directory_context::has_subdir(const ::file::path & pszDir)
//   {
//      ::file::listing stra(get_context());
//      stra.ls_dir(pszDir);
//      return stra.get_size() > 0;
//
//   }



   ::file::path directory_context::time()
   {
      
      return this->module();
      
   }


   ::file::path directory_context::stage()
   {
      
      return install() / "stage";
      
   }

   ::file::path directory_context::stageapp()
   {
      return stage() / "basis";
   }

//   ::file::path directory_context::netseed()
//   {
//      return m_strNetSeedFolder;
//   }

   // stage in ca2os spalib
//   ::file::path dir::install()
//   {
//
//      single_lock synchronouslock(&m_mutex, true);
//
//      return m_strCa2;
//
//   }


   ::file::path directory_context::module()
   {

      return directory_system()->module();

   }


//   ::file::path directory_context::ca2module()
//   {
//
//      return ::apex::get_system()->directory_system()->m_pathCa2Module;
//
//   }


   ::file::path directory_context::time_square(const ::scoped_string & scopedstrPrefix,const ::scoped_string & scopedstrSuffix)
   {

      __UNREFERENCED_PARAMETER(scopedstrPrefix);
      __UNREFERENCED_PARAMETER(scopedstrSuffix);
      return time() / "time";

   }


   ::file::path directory_context::time_log()
   {

      return appdata() / "log";

   }


::file::path directory_context::document()
{
   
   return directory_system()->icloud_container_documents();
   
}

   
//   bool directory_context::rm(const ::file::path & psz, bool bRecursive)
//   {
//      if(bRecursive)
//      {
//         ::file::listing patha(get_context());
//         patha.ls(psz);
//         for(auto & path : patha)
//         {
//            if(is(path))
//            {
//               rm(psz / path.name(), true);
//            }
//            else
//            {
//               ::unlink(path);
//            }
//         }
//      }
//      return ::rmdir(psz) == 0;
//   }
//
//
   
//   ::file::path directory_context::name(const ::file::path & str)
//   {
//
//      character_count iLast = str.get_length() - 1;
//
//      while(iLast >= 0)
//      {
//         if(str.m_pszData[iLast] != '\\' && str.m_pszData[iLast] != '/' && str.m_pszData[iLast] != ':')
//            break;
//         iLast--;
//      }
//      while(iLast >= 0)
//      {
//         if(str.m_pszData[iLast] == '\\' || str.m_pszData[iLast] == '/' || str.m_pszData[iLast] == ':')
//            break;
//         iLast--;
//      }
//      if(iLast >= 0)
//      {
//         while(iLast >= 0)
//         {
//            if(str.m_pszData[iLast] != '\\' && str.m_pszData[iLast] != '/' && str.m_pszData[iLast] != ':')
//               break;
//            iLast--;
//         }
//         return str.Left(iLast + 1);
//      }
//      else
//      {
//         return "";
//      }
//   }


   void directory_context::initialize(::particle * pparticle)
   {

      //auto estatus =
      
      ::directory_context::initialize(pparticle);
      

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
      m_pdirsystem = system()->directory_system();
      
      m_pfilesystem = system()->m_pfilesystem;

      m_pdirsystem->m_pathHome = directory_system()->home();

//      if(!update_module_path())
//      {
//
//         return false;
//
//      }

      
//      m_strCa2 = ::file::path(getenv("HOME")) / "Library/papp Support";
//      {
//
//         string str;
//
//         unsigned int uiSize = 4096;
//
//         char * psz = str.get_buffer(uiSize);
//
//         _ui_library_dir(psz, &uiSize);
//
//         str.release_buffer(uiSize);
//
//         m_pdirsystem->m_strCa2 = str;
//
//      }

//
//      ::file::path pathHome;
//
//      pathHome = m_pdirsystem->m_strCa2/"Documents";
//
//      ::apex::get_system()->m_strIosHome = pathHome;
//
//      m_pdirsystem->m_pathHome = m_pdirsystem->m_strCa2/"Documents";

      //nodeos_set_home(::apex::get_system()->m_strIosHome);

//      ::file::path str = m_pdirsystem->m_strCa2 / ".ca2/appdata";
//
////      m_pathUser = m_strCa2 / ".ca2/user";

      string strRelative;

      strRelative = install();

//      m_pdirsystem->m_strCa2AppData = str / "ca2" / strRelative;
//
//      str = m_pdirsystem->m_pathModule.folder();
//
//      m_pdirsystem->m_strCommonAppData = str / "commonappdata";

//      m_pdirsystem->m_pathAppData = m_psystem->directory_system()->m_pplatformdir->m_pathLibrary / "AppData";

//      m_pdirsystem->m_strCommonAppData = m_psystem->directory_system()->m_pplatformdir->m_pathLibrary / "CommonAppData";

      string str;

      str = "/usr/bin";

      m_pdirsystem->m_strPrograms = str;

      str = "/usr/share/";

      m_pdirsystem->m_strCommonPrograms = str;

//      return true;

   }


   void directory_context::init_context()
   {

//      xml::document doc;
//
//      string strPath = appdata() / "configuration/directory.xml";
//
//
//      string strDocument = papplication->file().as_string(strPath);
//
//      if(doc.load(strDocument))
//      {
//
//         if(doc.root()->get_name() == "directory_configuration")
//         {
//
//            m_pdirsystem->m_strTimeFolder = doc.root()->get_child_value("time");
//
//            m_pdirsystem->m_strNetSeedFolder = doc.root()->get_child_value("netseed");
//
//         }
//
//      }
//
//      if(m_pdirsystem->m_strTimeFolder.is_empty())
//      {
//
//         m_pdirsystem->m_strTimeFolder = m_pdirsystem->m_strCa2 / "Library/Cache/time";
//
//      }
//
//      if(m_pdirsystem->m_strNetSeedFolder.is_empty())
//      {
//
//         m_pdirsystem->m_strNetSeedFolder = install() / "net";
//
//      }
//
//      mk(m_pdirsystem->m_strTimeFolder);
//
//      if(!is(m_pdirsystem->m_strTimeFolder))
//      {
//
//         return false;
//
//      }
//
//      string strTime = m_pdirsystem->m_strTimeFolder / "time";
//
//      mk(strTime);
//
//      if(!is(strTime))
//      {
//
//         return false;
//
//      }
//
//      ::apex::get_system()->m_strIosTemp = strTime;
//
//      //nodeos_set_temp(::apex::get_system()->m_strIosTemp);
//
//      string str;
//
//      str = "/usr/bin";
//
//      m_pdirsystem->m_strPrograms = str;
//
//      str = "/usr/share/";
//
//      m_pdirsystem->m_strCommonPrograms = str;
//
//      return true;

   }
//
//
//   ::file::path directory_context::appdata()
//   {
//
//      return m_pdirsystem->m_strCa2AppData;
//
//   }


   ::file::path directory_context::commonappdata_root()
   {

      return m_pdirsystem->m_strCommonAppData;

   }


   ::file::path directory_context::userquicklaunch()
   {

      return m_pdirsystem->m_pathAppData / "Microsoft/Internet Explorer/Quick Launch";

   }


   ::file::path directory_context::userprograms()
   {

      return m_pdirsystem->m_strPrograms;

   }


   ::file::path directory_context::commonprograms()
   {

      return m_pdirsystem->m_strCommonPrograms;

   }


//   bool directory_context::is_inside_time(const ::file::path & pszPath)
//   {
//
//      return is_inside(time(), pszPath);
//
//   }
//
//
//   bool directory_context::is_inside(const ::file::path & pszDir, const ::file::path & pszPath)
//   {
//
//      return ::str::case_insensitive_begins(pszDir, pszPath);
//
//   }


} // namespace acme_ios



