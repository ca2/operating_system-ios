#include "framework.h"
#include "dir_system.h"
#include "acme_ios/acme_directory.h"
//#include "_ios.h"


namespace acme_ios
{


   dir_system::dir_system()
   {


   }


   dir_system::~dir_system()
   {


   }


   void dir_system::initialize(::object * pobject)
   {

      //auto estatus =
      
      ::dir_system::initialize(pobject);
//
//      if (!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;

   }


   ::file::path dir_system::compute_default_app_data_path()
   {

      return m_psystem->m_pacmedirectory->m_pplatformdir->m_pathLibrary / "application";

   }


   void dir_system::init_system()
   {

      ::dir_system::init_system();
      
      m_pathHome = m_psystem->m_pacmedirectory->home();
      
      m_pathCa2Config = m_pathHome / "Library/Application Support/ca2";
      
   }


} // namespace acme_ios



