#include "framework.h"
#include "file_system.h"


#include <sys/stat.h>
#include <ctype.h>


struct PROCESS_INFO_t
{
   
   string csProcess;
   u32 dwImageListIndex;
   
};


namespace acme_ios
{


   file_system::file_system()
   {

   }


   file_system::~file_system()
   {

   }


   void file_system::initialize(::object * pobject)
   {
   
      //auto estatus =
      
      ::file_system::initialize(pobject);
      
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
   
   }

//
//   void file_system::update_module_path()
//   {
//
//      m_pathModule = apple_app_module_path();
//
//      m_pathCa2Module = m_pathModule;
//
//      return true;
//
//   }


} // namespace acme_ios



