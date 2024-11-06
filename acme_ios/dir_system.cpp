#include "framework.h"
#include "directory_system.h"
#include "acme_ios/directory_system.h"
//#include "_ios.h"


namespace acme_ios
{


   directory_system::directory_system()
   {


   }


   directory_system::~directory_system()
   {


   }


   void directory_system::initialize(::particle * pparticle)
   {

      //auto estatus =
      
      ::directory_system::initialize(pparticle);
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


   ::file::path directory_system::compute_default_app_data_path()
   {

      return directory_system()->m_pplatformdir->m_pathLibrary / "application";

   }


   void directory_system::init_system()
   {

      ::directory_system::init_system();
      
      m_pathHome = directory_system()->home();
      
      m_pathCa2Config = m_pathHome / "Library/Application Support/ca2";
      
   }


} // namespace acme_ios



