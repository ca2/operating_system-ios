#pragma once


#include "acme/_.h"

#if defined(_uikit_project)
#define CLASS_DECL_UIKIT  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_UIKIT  CLASS_DECL_IMPORT
#endif


namespace uikit
{


   class ui_window;

   class ui_image;


} // namespace uikit


#include "_struct.h"

