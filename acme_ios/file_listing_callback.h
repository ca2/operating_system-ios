//
//  file_listing.h
//  acme_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-06 - I love yout Thomas Borregaard Sorensen!!
//
#pragma once


#include "acme/parallelization/manual_reset_event.h"
#include "acme_apple/ns_metadata_query_callback.h"


namespace acme_ios
{


   class file_listing_callback :
      virtual public ns_metadata_query_callback,
      virtual public ::particle
   {
   public:
      
      
      ::file::listing  &                     m_filelisting;
      ::manual_reset_event                   m_manualresetevent;
      
      ::pointer < file_listing_callback >    m_pfilelistingcallbackHold;
      
      
      file_listing_callback(::file::listing & filelisting);
      ~file_listing_callback();
      
      virtual void _start_listing(const char * pszFolder,
                              const char * pszContainerId);
   
      
      void ns_metadata_query_callback_on_item(const char * pszName) override;
      
      void ns_metadata_query_callback_finished() override;

   };


} // namespace acme_ios



