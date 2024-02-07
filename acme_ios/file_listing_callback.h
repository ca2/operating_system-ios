//
//  file_listing.h
//  acme_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-02-06 - I love yout Thomas Borregaard Sorensen!!
//
#pragma once


#include "acme/filesystem/filesystem/listing.h"
#include "acme_apple/ns_metadata_query_callback.h"


namespace acme_ios
{


   class file_listing :
      virtual public ::file::listing,
      virtual public ns_metadata_query_callback
   {
   public:
      
      
      virtual void _start_listing(const char * pszFolder,
                              const char * pszContainerId);
   
   };


} // namespace acme_ios



