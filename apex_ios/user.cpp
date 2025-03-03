#include "framework.h"
#include "acme/prototype/collection/str_array.h"

//
//int_bool GetCursorPos(INT_POINT * ppointCursor)
//{
//
//   HIPoint point;
//
//   HICoordinateSpace space = kHICoordSpaceScreenPixel;
//
//   HIGetMousePosition(space, nullptr, &point);
//
//   ppointCursor->x = point.x;
//
//   ppointCursor->y = point.y;
//
//   return true;
//
//}


char * mm_browse_folder(::platform::system * psystem, const char * pszStartDir, bool bCanCreateDirectories);


string apple_browse_folder(class ::platform::system * psystem, const char * pszStartDir, bool bCanCreateDirectories)
{

   return ::string_from_strdup(mm_browse_folder(psystem, pszStartDir, bCanCreateDirectories));

}


char** mm_browse_file_open(void * psystem, const char ** pszStartDir, bool bMulti);


string_array apple_browse_file_open(class ::platform::system * psystem, const char ** pszStartDir, bool bMulti)
{
   
   return stringa_from_strdupa(mm_browse_file_open(psystem, pszStartDir, bMulti));

}



