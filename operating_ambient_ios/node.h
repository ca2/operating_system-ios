//
//  node.hpp
//  aura_macos
//
//  Created by Camilo Sasuke on 2021-05-20 14:20 BRT <3ThomasBS_!!
//  Copyright © 2021 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#pragma once


#include "node_ios/node.h"


namespace operating_ambient_ios
{


   class CLASS_DECL_OPERATING_AMBIENT_IOS node :
      virtual public ::node_ios::node
   {
   public:
      
      
      node();
      ~node() override;
      
      
   };


} // namespace operating_ambient_ios



