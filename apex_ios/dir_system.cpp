#include "framework.h"
//#include "_ios.h"


namespace apex_ios
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



} // namespace apex_ios



