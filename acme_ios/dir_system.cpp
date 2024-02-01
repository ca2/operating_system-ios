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


   void dir_system::initialize(::particle * pparticle)
   {

      //auto estatus =
      
      ::dir_system::initialize(pparticle);
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

      return acmedirectory()->m_pplatformdir->m_pathLibrary / "application";

   }


   void dir_system::init_system()
   {

      ::dir_system::init_system();
      
      m_pathHome = acmedirectory()->home();
      
      m_pathCa2Config = m_pathHome / "Library/Application Support/ca2";
      
   }


} // namespace acme_ios



