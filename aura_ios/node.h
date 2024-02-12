//
//  node.hpp
//  aura_macos
//
//  Created by Camilo Sasuke on 2021-05-20 14:20 BRT <3ThomasBS_!!
//  Copyright © 2021 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#pragma once


#include "aura_apple/node.h"
#include "apex_ios/node.h"
#include "aura/windowing/sandbox/node.h"


namespace aura_ios
{


   class CLASS_DECL_AURA_MACOS node :
      virtual public ::aura_apple::node,
      virtual public ::apex_ios::node,
      virtual public ::sandboxed::node
   {
   public:
      
      
      node();
      ~node() override;
      
      
      void initialize(::particle * pparticle) override;
      
      
      ::image_pointer get_file_image_by_type_identifier(int iSize, const ::scoped_string & scopedstrTypeIdentifier) override;

      ::image_pointer get_file_image(int iSize, const ::file::path & path) override;


      void root_ones(::file::listing &listing) override;
      
      
      bool defer_enumerate_protocol(::file::listing& listing) override;

      bool defer_process_protocol_path(::file::path & path) override;

      
   };


} // namespace aura_ios



