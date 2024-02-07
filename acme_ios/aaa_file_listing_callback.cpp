//
//  file_listing.h
//  acme_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-06 - I love yout Thomas Borregaard Sorensen!!
//
#include "framework.h"
#include "file_listing_callback.h"
#include "acme/filesystem/filesystem/listing.h"


void ns_app_cloud_start_listing(ns_metadata_query_callback * pcallback, const char * pszFolder, const char * pszAppCloudContainerIdentifier);


namespace acme_ios
{


   file_listing_callback::file_listing_callback(::file::listing & filelisting):
      m_filelisting(filelisting)
   {
      
      m_pfilelistingcallbackHold = this;
      
      m_manualresetevent.ResetEvent();
      
   }


   file_listing_callback::~file_listing_callback()
   {
 
      ns_metadata_query_callback_uninstall();
   
   }

   
   void file_listing_callback::_start_listing(const char * pszFolder, const char * pszAppCloudContainerIdentifier)
   {
      
      try
      {
         
         ns_app_cloud_start_listing(this, pszFolder, pszAppCloudContainerIdentifier);
         
      }
      catch (const char * psz)
      {
         
         ::string str(psz);
         
         if(str == "failed container identifier")
         {
            
            throw ::exception(error_failed);
            
         }
         
      }
      
   }

void file_listing_callback::ns_metadata_query_callback_on_item(const char * pszName)
{
   ::file::path path;
   
   ::file::path pathName;
   
   path = pathName.name();
   
   m_filelisting.m_eflag +=::file::e_flag_file;
   
   path.m_iDir = 0;
   
   m_filelisting.defer_add(path);
   
}

void file_listing_callback::ns_metadata_query_callback_finished()
{
 
   m_manualresetevent.SetEvent();
   
}


} // namespace acme_ios



