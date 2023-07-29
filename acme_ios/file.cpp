#include "framework.h"
#include "file.h"
#include "acme/filesystem/file/exception.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include <fcntl.h>


#ifdef LINUX
#include <dlfcn.h>
#include <link.h>
#include <ctype.h>
#elif defined(__APPLE__)
#include <dlfcn.h>
#include <sys/stat.h>
#endif

//__STATIC inline bool IsDirSep(WCHAR ch)
//{
//
//   return (ch == '\\' || ch == '/');
//
//}


namespace acme_ios
{


   file::file()
   {

      m_iFile = (::u32) hFileNull;

   }

//   file::file(::object * pobject, i32 hFile) :
//      ::object(pobject)
//   {
//
//      m_iFile = hFile;
//
////      m_bCloseOnDelete = true;
//
//   }
//
//   file::file(::object * pobject, const char * lpszFileName, ::u32 nOpenFlags) :
//      ::object(pobject)
//   {
//
//      ASSERT(__is_valid_string(lpszFileName));
//
//      if(!open(lpszFileName, nOpenFlags))
//         throw ::exception(::file::exception(::file::exception::none, -1, lpszFileName));
//
//   }

   file::~file()
   {

//      if (m_iFile != (::u32)hFileNull && m_bCloseOnDelete)
      //       close();
      if (m_iFile != (::u32)hFileNull)
      {
       
         close();
      
      }

   }

//   ::pointer < ::file::file > file::Duplicate() const
//   {
//      ASSERT_VALID(this);
//      ASSERT(m_iFile != (::u32)hFileNull);
//
//      i32 iNew = dup(m_iFile);
//
//      if(iNew == -1)
//         return nullptr;
//
//      file* pFile = new file(get_app(), iNew);
//      pFile->m_iFile = (::u32)iNew;
//      ASSERT(pFile->m_iFile != (::u32)hFileNull);
////      pFile->m_bCloseOnDelete = m_bCloseOnDelete;
//      return pFile;
//   }

   void file::open(const ::file::path& path, const ::file::e_open & eopenParam)
   {

      if (m_iFile != (::u32)hFileNull)
      {
         
         close();
         
      }
      
      auto eopen = eopenParam;

      ASSERT_VALID(this);
      ASSERT(!(eopen & ::file::e_open_text) );   // text mode not supported

      // file objects are always binary and CreateFile does not need flag
      eopen -= ::file::e_open_binary;


      if ((eopen & ::file::e_open_defer_create_directory) && (eopen & ::file::e_open_write))
      {

         m_psystem->m_pacmedirectory->create(path.folder());

      }

      m_iFile = (::u32)hFileNull;
      
      m_path = path;
      
      ASSERT(::file::e_open_share_compat == 0);

      ASSERT((::file::e_open_read|::file::e_open_write|::file::e_open_read_write) == 3);
      
      ::u32 dwFlags =  0;
      
      switch (eopen & 3)
      {
      case ::file::e_open_read:
         dwFlags |=  O_RDONLY;
         break;
      case ::file::e_open_write:
         dwFlags |=  O_WRONLY ;
         break;
      case ::file::e_open_read_write:
         dwFlags |=  O_RDWR;
         break;
      default:
         dwFlags |=  O_RDONLY;
         break;
      }

      switch (eopen & 0x70)
      {
      default:
         ASSERT(false);  // invalid share mode?
      case ::file::e_open_share_compat:
      case ::file::e_open_share_exclusive:
         //dwShareMode = 0;
         break;
      case ::file::e_open_share_deny_write:
         //dwFlags |= O_SHLOCK;
         break;
      case ::file::e_open_share_deny_read:
         //         dwFlags |= O_EXLOCK;
         break;
      case ::file::e_open_share_deny_none:
         //dwFlags = FILE_SHARE_WRITE|FILE_SHARE_READ;
         break;
      }

      if (eopen & ::file::e_open_create)
      {
         
         dwFlags |= O_CREAT;
         
         if(!(eopen & ::file::e_open_no_truncate))
         {
            
            dwFlags |= O_TRUNC;
            
         }
         
      }

      ::u32 dwPermission = 0;

      dwPermission |= S_IRUSR | S_IWUSR | S_IXUSR;

      dwPermission |= S_IRGRP | S_IWGRP | S_IXGRP;

      i32 hFile = ::open(m_path, dwFlags | O_CLOEXEC, dwPermission);
      
      if(hFile == hFileNull)
      {

         auto cerrornumber = c_error_number();

         if(iErrNo != ENOENT && iErrNo != ENFILE)
         {
            /*         if (pException != nullptr)
             {
             pException->create(this);
             ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
             if(pfe != nullptr)
             {
             pfe->m_lOsError = dwLastError;
             pfe->m_cause = ::win::file_exception::os_error_to_exception(pfe->m_lOsError);
             pfe->m_strFileName = lpszFileName;
             }
             return false;
             }
             else
             {*/


            //            vfxThrowFileexception(::macos::file_exception::os_error_to_exception(dwLastError), dwLastError, m_strFileName);
            
            auto estatus = errno_to_status(iErrNo);
            
            throw ::file::exception(estatus, __errno(iErrNo), m_path, "open == -1", eopen);

            //}

         }

         /*try
          {
          get_app()->m_psystem->m_spfilesystem.m_p->FullPath(m_wstrFileName, m_wstrFileName);
          }
          catch(...)
          {
          return false;
          }

          m_strFileName = ::str::international::unicode_to_utf8(m_wstrFileName);

          hFile = ::open(m_strFileName, nOpenFlags);*/

         if (hFile == -1)
         {
            /*if (pException != nullptr)
             {
             pException->create(this);
             ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
             if(pfe != nullptr)
             {
             pfe->m_lOsError = ::get_last_error();
             pfe->m_cause = ::win::file_exception::os_error_to_exception(pfe->m_lOsError);
             pfe->m_strFileName = lpszFileName;
             }
             return false;
             }
             else
             {*/


            //            vfxThrowFileexception(::macos::file_exception::os_error_to_exception(dwLastError), dwLastError, m_strFileName);
            
            m_estatus = ::errno_to_status(iErrNo);
            
            if(eopen & ::file::e_open_no_exception_on_open)
            {
             
               if(!failed(m_estatus))
               {
                
                  m_estatus = error_failed;
                  
               }
               
               return;
               
            }

            throw ::file::exception(m_estatus, __errno(iErrNo), m_path, "open == -1", eopen);

            //}

         }

      }

      m_iFile = (i32)hFile;
      
      m_estatus = ::success;
      
      set_ok();
      
      //      m_bCloseOnDelete = true;

      //return ::success;

   }

   memsize file::read(void * lpBuf, memsize nCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != (::u32)hFileNull);

      if (nCount == 0)
         return 0;   // avoid Win32 "null-read"

      ASSERT(lpBuf != nullptr);
      ASSERT(::is_memory_segment_ok(lpBuf, nCount));

      memsize pos = 0;
      memsize sizeRead = 0;
      memsize readNow;
      while(nCount > 0)
      {
         
         readNow = (size_t) minimum(0x7fffffff, nCount);
         
         size_t iRead = ::read(m_iFile, &((::u8 *)lpBuf)[pos], readNow);
         
         if(iRead == -1)
         {
            
            i32 iErrNo = errno;
            
            if(iErrNo == EAGAIN)
            {

            }
            
            auto estatus = errno_to_status(iErrNo);
            
            throw ::file::exception(estatus, __errno(iErrNo), m_path, "read == -1", m_eopen);
            
         }
         else if(iRead == 0)
         {
            
            break;
            
         }

         nCount -= iRead;
         
         pos += iRead;
         
         sizeRead += iRead;
         
      }

      return sizeRead;
      
   }


   void file::write(const void * lpBuf, memsize nCount)
   {
      
      ASSERT_VALID(this);
      
      ASSERT(m_iFile != (::u32)hFileNull);

      if (nCount == 0)
      {
         
         return;     // avoid Win32 "null-write" option
         
      }

      ASSERT(lpBuf != nullptr);
      
      ASSERT(::is_memory_segment_ok(lpBuf, nCount, false));

      memsize pos = 0;
      
      while(nCount > 0)
      {
         
         size_t iWrite = ::write(m_iFile, &((const ::u8 *)lpBuf)[pos], (size_t) minimum(0x7fffffff, nCount));
         
         if(iWrite == -1)
         {
            
            auto cerrornumber = c_error_number();
            
            auto estatus = errno_to_status(iErrNo);
            
            throw ::file::exception(estatus, __errno(iErrNo), m_path, "write == -1", m_eopen);
            
         }
         
         nCount -= iWrite;
         
         pos += iWrite;
         
      }

   }


   filesize file::translate(filesize lOff, ::enum_seek eseek)
   {

      if(m_iFile == (::u32)hFileNull)
      {
       //  ::file::throw_os_error( (::i32)0);
         
         int iErrNo = -1;
         
         ::e_status estatus = ::error_failed;
         
         throw ::file::exception(estatus, __errno(iErrNo), m_path, "m_iFile == -1", m_eopen);
         
      }

      ASSERT_VALID(this);
      ASSERT(m_iFile != (::u32)hFileNull);
      ASSERT(eseek == ::e_seek_set || eseek == ::e_seek_from_end || eseek == ::e_seek_current);
      ASSERT(::e_seek_set == SEEK_SET && ::e_seek_from_end == SEEK_END && ::e_seek_current == SEEK_CUR);

      ::i32 lLoOffset = lOff & 0xffffffff;
      //::i32 lHiOffset = (lOff >> 32) & 0xffffffff;

      filesize posNew = ::lseek(m_iFile, lLoOffset, (::u32)eseek);
      //      posNew |= ((filesize) lHiOffset) << 32;
      if(posNew  == (filesize)-1)
      {
         
         auto cerrornumber = c_error_number();
         
         auto estatus = errno_to_status(iErrNo);
         
         throw ::file::exception(estatus, __errno(iErrNo), m_path, "lsize == -1", m_eopen);
         
      }

      return posNew;
   }

   filesize file::get_position() const
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != (::u32)hFileNull);

      ::i32 lLoOffset = 0;
      //      ::i32 lHiOffset = 0;

      filesize pos = ::lseek(m_iFile, lLoOffset, SEEK_CUR);
      //    pos |= ((filesize)lHiOffset) << 32;
      if(pos  == (filesize)-1)
      {
         
         auto iErrNo = errno;
         
         auto estatus = errno_to_status(iErrNo);

         throw ::file::exception(estatus, __errno(iErrNo), m_path, "lseek == -1", m_eopen);
         
      }

      return pos;
   }

//   void file::Flush()
//   {
//
//      /*      ::open
//       ::read
//       ::write
//
//       access the system directly no buffering : direct I/O - efficient for large writes - innefficient for lots of single ::u8 writes
//
//       */
//
//      /*ASSERT_VALID(this);
//
//       if (m_iFile == (::u32)hFileNull)
//       return;
//
//       if (!::FlushFileBuffers((HANDLE)m_iFile))
//       ::macos::file_exception::throw_os_error( (::i32)::get_last_error());*/
//   }

//   filesize file::get_position() const
//   {
//      ASSERT_VALID(this);
//      ASSERT(m_iFile != (::u32)hFileNull);
//
//      ::i32 lLoOffset = 0;
//      //      ::i32 lHiOffset = 0;
//
//      filesize pos = ::lseek(m_iFile, lLoOffset, SEEK_CUR);
//      //    pos |= ((filesize)lHiOffset) << 32;
//      if(pos  == (filesize)-1)
//         ::file::throw_os_error( (::i32)::get_last_error());
//
//      return pos;
//   }
//
   void file::flush()
   {
//
//      /*      ::open
//       ::read
//       ::write
//
//       access the system directly no buffering : direct I/O - efficient for large writes - innefficient for lots of single ::u8 writes
//
//       */
//
//      /*ASSERT_VALID(this);
//
         if (m_iFile == (::u32)hFileNull)
       return;
      
      //::flush(m_iFile);
      
//
//       if (!::FlushFileBuffers((HANDLE)m_iFile))
//       ::file::throw_os_error( (::i32)::get_last_error());*/
   }

   void file::close()
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != (::u32)hFileNull);

      bool bError = false;
      if (m_iFile != (::u32)hFileNull)
         bError = ::close(m_iFile) != 0;

      m_iFile = (::u32) hFileNull;
      //      m_bCloseOnDelete = false;
      m_path.Empty();

      if (bError)
      {
         
         auto iErrNo = errno;
         
         auto estatus = errno_to_status(iErrNo);
      
         throw ::file::exception(estatus, __errno(iErrNo), m_path, "close != 0", m_eopen);
         
      }
      
   }

//   void file::Abort()
//   {
//      ASSERT_VALID(this);
//      if (m_iFile != (::u32)hFileNull)
//      {
//         // close but ignore errors
//         ::close(m_iFile);
//         m_iFile = (::u32)hFileNull;
//      }
//      m_strFileName.Empty();
//   }
//
   

   void file::lock(filesize dwPos, filesize dwCount)
   {
      
      ASSERT_VALID(this);
      
      ASSERT(m_iFile != (::u32)hFileNull);

      /*if (!::LockFile((HANDLE)m_iFile, LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
       ::macos::file_exception::throw_os_error( (::i32)::get_last_error());*/
      
   }


   void file::unlock(filesize dwPos, filesize dwCount)
   {
      
      ASSERT_VALID(this);
      
      ASSERT(m_iFile != (::u32)hFileNull);

      /*      if (!::UnlockFile((HANDLE)m_iFile,  LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
       ::macos::file_exception::throw_os_error( (::i32)::get_last_error());*/
      
   }


   void file::set_size(filesize dwNewLen)
   {
      
      ASSERT_VALID(this);
      
      ASSERT(m_iFile != (::u32)hFileNull);

      translate((::i32)dwNewLen, (::enum_seek)::e_seek_set);

      if (::ftruncate(m_iFile, dwNewLen) == -1)
      {
         
         auto iErrNo = errno;
         
         auto estatus = errno_to_status(iErrNo);
         
         throw ::file::exception(estatus, __errno(iErrNo), m_path, "ftruncate == -1", m_eopen);
         
      }
      
   }


   filesize file::get_size() const
   {
      
      ASSERT_VALID(this);

      filesize dwLen, dwCur;

      // seek is a non const operation
      file * pfile = (file*)this;
      
      dwCur = pfile->set_position(0);
      
      dwLen = pfile->seek_to_end();
      
      VERIFY(dwCur == pfile->set_position(dwCur));

      return (filesize) dwLen;
      
   }


   void file::assert_ok() const
   {
      
      ::file::file::assert_ok();
      
   }


   void file::dump(dump_context & dumpcontext) const
   {
      
      ::file::file::dump(dumpcontext);

      dumpcontext << "with handle " << (::u32)m_iFile;
      dumpcontext << " and name \"" << m_path << "\"";
      dumpcontext << "\n";
      
   }


//   string file::get_file_name() const
//   {
//
//      ASSERT_VALID(this);
//
//      ::file::file_status status;
//
//      get_status(status);
//
//      return status.m_strFullName.name();
//
//   }


//   string file::get_file_title() const
//   {
//
//      ASSERT_VALID(this);
//
//      ::file::file_status status;
//
//      get_status(status);
//
//      return status.m_strFullName.title();
//
//   }


   ::file::path file::get_file_path() const
   {
      
      return m_path;
      
   }


   bool file::get_status(::file::file_status & status) const
   {
      
      ASSERT_VALID(this);

      if (m_iFile != hFileNull)
      {
         
         struct ::stat st;
         
         if(fstat(m_iFile, &st) == -1)
         {
            
            return false;
            
         }

         status.m_filesize = st.st_size;

         status.m_attribute = 0;

         status.m_ctime = ::earth::time(st.st_mtime);
         status.m_atime = ::earth::time(st.st_atime);
         status.m_mtime = ::earth::time(st.st_ctime);

         if (status.m_ctime.get_time() == 0)
            status.m_ctime = status.m_mtime;

         if (status.m_atime.get_time() == 0)
            status.m_atime = status.m_mtime;
         
         status.m_strFullName = m_path;

      }
      
      return true;
      
   }


//   bool PASCAL file::GetStatus(const char * lpszFileName, ::file::file_status& rStatus)
//   {
//      // attempt to fully qualify path first
//      wstring wstrFullName;
//      wstring wstrFileName;
//      wstrFileName = ::str::international::utf8_to_unicode(lpszFileName);
//      //      if (!windows_full_path(wstrFullName, wstrFileName))
//      //    {
//      //     rStatus.m_strFullName.Empty();
//      //   return false;
//      //}
//
//      wstrFullName = wstrFileName;
//
//      ::str::international::unicode_to_utf8(rStatus.m_strFullName, wstrFullName);
//
//      struct ::stat st;
//      if(stat(lpszFileName, &st) == -1)
//         return false;
//      //if (hFind == INVALID_HANDLE_VALUE)
//      // return false;
//      //VERIFY(FindClose(hFind));
//
//      // strip attribute of NORMAL bit, our API doesn't have a "normal" bit.
//      //rStatus.m_attribute = (::u8) (findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);
//
//      rStatus.m_attribute = 0;
//
//      // get just the low ::u32 of the file size_i32
//      //ASSERT(findFileData.nFileSizeHigh == 0);
//      //rStatus.m_size = (::i32)findFileData.nFileSizeLow;
//
//      rStatus.m_size = st.st_size;
//
//      // convert times as appropriate
//      /*rStatus.m_ctime = ::earth::time(findFileData.ftCreationTime);
//       rStatus.m_atime = ::earth::time(findFileData.ftLastAccessTime);
//       rStatus.m_mtime = ::earth::time(findFileData.ftLastWriteTime);*/
//      rStatus.m_ctime = ::earth::time(st.st_mtime);
//      rStatus.m_atime = ::earth::time(st.st_atime);
//      rStatus.m_mtime = ::earth::time(st.st_ctime);
//
//      if (rStatus.m_ctime.get_time() == 0)
//         rStatus.m_ctime = rStatus.m_mtime;
//
//      if (rStatus.m_atime.get_time() == 0)
//         rStatus.m_atime = rStatus.m_mtime;
//
//      return true;
//   }


   bool file::is_opened() const
   {
      
      return m_iFile != hFileNull;
      
   }


   void file::set_file_path(const ::file::path & path)
   {

      m_path = path;
      
   }


} // namespace acme_ios


#define _wcsdec(_cpc1, _cpc2) ((_cpc1)>=(_cpc2) ? nullptr : (_cpc2)-1)


#define _wcsinc(_pc)    ((_pc)+1)


//// turn a file, relative path or other into an absolute path
//bool CLASS_DECL_APEX windows_full_path(wstring & wstrFullPath, const wstring & wstrPath)
//// lpszPathOut = buffer of _MAX_PATH
//// lpszFileIn = file, relative path or absolute path
//// (both in ANSI character set)
//{
//
//
//   wstrFullPath = wstrPath;
//
//
//   return true;
//
//}

//
//CLASS_DECL_APEX void vfxGetModuleShortFileName(HINSTANCE hInst, string& strShortName)
//{
//
//   throw ::exception(todo);
//
//}


//void CLASS_DECL_APEX vfxThrowFileException(::object * pobject, void cause, ::i32 lOsError, const char * lpszFileName /* == nullptr */)
//{
//
//   throw ::exception(::file::exception(cause, lOsError, lpszFileName));
//
//}
//
//
//::file::exception * CLASS_DECL_APEX get_FileException(::object * pobject, void cause, ::i32 lOsError, const char * lpszFileName /* == nullptr */)
//{
//
//   return __new(::file::exception(cause, lOsError, lpszFileName));
//
//}


//namespace ios
//{
//
//
//   namespace file_exception
//   {
//
//      void ErrnoToException(i32 nErrno)
//      {
//         switch(nErrno)
//         {
//         case EPERM:
//         case EACCES:
//            return ::file::exception::accessDenied;
//         case EBADF:
//            return ::file::exception::invalidFile;
//         case EMFILE:
//            return ::file::exception::tooManyOpenFiles;
//         case ENOENT:
//         case ENFILE:
//            return ::file::exception::fileNotFound;
//         case ENOSPC:
//            return ::file::exception::diskFull;
//         case EINVAL:
//         case EIO:
//            return ::file::exception::hardIO;
//         default:
//            return ::file::exception::type_generic;
//         }
//
//      }
//
//
//   } // namespace file_exception
//
//
//} // namespace ios




CLASS_DECL_ACME bool _os_may_have_alias(const char * psz)
{

   return true;

}



