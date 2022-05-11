//
//  Created by Camilo Sasuke Tsumanuma on 6/18/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#pragma once


#define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
//#define _POSIX_C_SOURCE 200809L
#define index __ancient_bsd_source_index
#define wait __ancient_bsd_source_wait


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <sys/time.h>
#include <wchar.h>
#include <xlocale.h>
#include <string.h>
#include <unistd.h>

#define platform_char char


#ifdef __cplusplus


#include <new>

#include <concepts>


#endif


#ifdef __OBJC__

#include <Foundation/Foundation.h>

#include <UIKit/UIKit.h>

#else

#include <CoreFoundation/CoreFoundation.h>

#include <CoreGraphics/CoreGraphics.h>

#endif



////#include <Carbon/Carbon.h>
//
//
//#if DEBUG
//#undef DEBUG
//#define DEBUG
//#else
//#undef DEBUG
//#endif



#ifndef EXPORT
#define EXPORT
#endif



//inline void debug_break() { __asm("int $3"); }

//void debug_break();

#define TRUE 1
#define FALSE 0



#define MOVE_SEMANTICS


#define DECL_C

#define __cdecl
#define _stdcall
#define __stdcall

#define _NORMAL_BLOCK  1

#define _PRE_WIDEN(x) L ## x
#define _WIDEN(x) unitext(x)

#define NOTHROW throw()
#define THROWS

#define _WCHAR_T_DEFINED

#ifdef _DEBUG

#define RELEASENOTHROW

#else

#define RELEASENOTHROW throw()

#endif


#define DWORD     uint32_t
#define BYTE      uint8_t


#define _strcmpi strcasecmp



typedef void * PVOID;


#define _strcmpi strcasecmp


//#include <pthread.h>



typedef unsigned short     unichar;
typedef wchar_t            unichar32;



#undef index


#define WINBOOL int



#define strnicmp strncasecmp
#define stricmp strcasecmp
#define _strdup strdup



#ifdef __cplusplus


#include <typeinfo>
#include <initializer_list>

typedef ::std::type_info std_type_info;


#endif


#include <stddef.h>
#include <limits.h>
#include <malloc/malloc.h>

#include <sys/types.h>
//#include <time.h>

#define __time_t time_t


#include <netinet/in.h>


#define timespec_get mach_timespec_get


int mach_timespec_get(timespec * ptimespec, int);


#define INFINITE_TIMEOUT UINT_MAX


#undef index
#undef wait



