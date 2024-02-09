//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"


void os_post_quit();


void ns_launch_app(const char * psz, const char ** argv, int iFlags);


void ansios_sigchld_handler(int sig);


void apex_application_run(const char * pszAppName, const char * pszProgName);



namespace apex_ios
{


   node::node()
   {

      m_pAcmePlatform = this;

   }


   node::~node()
   {

   }


   int node::node_init_check(int * pi, char *** ppz)
   {
      
      return 0;
      
   }


   string node::app_id_to_executable_name(const string & strAppId)
   {
      
      string strName = app_id_to_app_name(strAppId);

      return "_" + strName;

   }




} // namespace apex_ios

//
//void * get_system_mmos(void * pSystem)
//{
//   
//   auto psystem = (class ::system *) pSystem;
//   
//   return psystem->m_pmmos;
//   
//}
//
//
//void set_system_mmos(void * pSystem, void * pmmos)
//{
//   
//   auto psystem = (class ::system *) pSystem;
//   
//   psystem->m_pmmos = pmmos;
//   
//}
//
//
//

