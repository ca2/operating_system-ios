#include "framework.h"
#include "shell_launcher.h"


namespace apex_ios
{


   void shell_launcher::launch()
   {

      if(m_iMode == 0)
      {

         if(m_strOperation.is_empty())
         {

            property_set set;

            //call_sync(m_strFile, m_strParameters, m_strDirectory, m_edisplay, 1_min, set);

         }
         else if(m_strOperation.case_insensitive_order("open") == 0)
         {

            property_set set;

            //call_sync("open", m_strFile, m_strDirectory, m_edisplay, 1_min, set);

         }

      }

   }


//
//
//   bool shell_launcher::succeeded()
//   {
//
//      return m_dwResult >= 0;
//
//   }


} // namespace apex_ios


