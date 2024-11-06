#pragma once



//
//string get_error_message(::u32 dwError);
//
//
////::platform::application *     macos_instantiate_application(::platform::application * pappSystem, const char * pszId);
//
//CLASS_DECL_ACME void vfxThrowFileException(::object * pobject, int cause, int lOsError, const char * lpszFileName = nullptr);
//
//CLASS_DECL_ACME ::file::exception * get_FileException(::object * pobject, const ::e_status & estatus, int lOsError, const char * lpszFileName = nullptr);
//
//#define NULL_REF(class) (*((class *) nullptr))
//
//#define MAC_THREAD(pthread) (dynamic_cast < ::mac::thread * > (dynamic_cast < ::thread * >(pthread)))
//
//
////CLASS_DECL_ACME void __trace_message(const char * lpszPrefix, ::message::message * pmessage);
////CLASS_DECL_ACME void __trace_message(const char * lpszPrefix, MESSAGE * lpmsg);
//int_bool mq_peek_message(MESSAGE * lpMsg,oswindow hWnd,::u32 wMsgFilterMin,::u32 wMsgFilterMax,::u32 wRemoveMsg);
//int_bool mq_get_message(MESSAGE * lpMsg,oswindow hWnd,::u32 wMsgFilterMin,::u32 wMsgFilterMax);
//int CLASS_DECL_ACME __mac_main(int argc, char * argv[]);
//CLASS_DECL_ACME void vfxThrowFileException(::matter * pobject, const ::e_status & estatus, int lOsError, const char * lpszFileName = nullptr);
//
//
//
//#include "factory_exchange.h"
//#include "thread.h"
////#include "os_context.h"
//
//
////#include "shell.h"
//
//#include "application.h"
//
//
//
//
//
//
//#include "file.h"
////#include "shell_macos.h"
//#include "stdio_file.h"
//
////#include "directory_system.h"
////#include "file_system.h"
////
////#include "directory_context.h"
////#include "file_context.h"
//
//
//
//
//
////void ns_app_terminate();
//void ns_create_alias(const char * pszTarget, const char * pszSource);
//
//

#pragma once


#include "acme_apple/_.h"


#if defined(_ACME_MACOS_LIBRARY)
   #define CLASS_DECL_ACME_MACOS  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_ACME_MACOS  CLASS_DECL_IMPORT
#endif


namespace acme
{


   namespace macos
   {


      class node;


   } // namespace macos


} // namespace acme


