#pragma once
#pragma once


#include "apex_apple/_.h"
#include "acme_ios/_.h"


#if defined(_APEX_MACOS_LIBRARY)
   #define CLASS_DECL_APEX_MACOS  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_APEX_MACOS  CLASS_DECL_IMPORT
#endif


namespace apex_ios
{


   class dir_system;
   class dir_context;

   class file_system;
   class file_context;

   class node;


} // namespace apex_ios



