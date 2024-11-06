#pragma once


//class FileException;
//struct FileStatus;
//
//void CLASS_DECL_APEX vfxGetRoot(const unichar * lpszPath, string& wstrRoot);

namespace acme_ios
{

   /////////////////////////////////////////////////////////////////////////////
   // File - raw unbuffered disk file I/O

   class CLASS_DECL_ACME file :
      virtual public ::file::file
   {
   public:

      
      enum Attribute
      {
         
         normal =    0x00,
         readOnly =  0x01,
         hidden =    0x02,
         system =    0x04,
         volume =    0x08,
         directory = 0x10,
         archive =   0x20
         
      };

      enum
      {

         hFileNull = -1

      };

      enum BufferCommand
      {

         bufferRead,
         bufferWrite,
         bufferCommit,
         bufferCheck

      };

      //zip::util *    m_pziputil;
      //string         m_strFileName;
      //wstring        m_wstrFileName;
      int            m_iFile;


      file();
      ~file() override;

//
//      void assert_ok() const override;
//      void dump(dump_context & dumpcontext) const override;

      //virtual bool has_write_mode() override;

      virtual filesize get_position() const override;
      ::file::file_status get_status() const override;
      ::file::path get_file_path() const override;
      void set_file_path(const ::file::path & path) override;
//
//      void open(const ::file::path & path, ::file::e_open eopen) override;

  
      
      void open(const ::file::path & path, ::file::e_open eopen, ::pointer < ::file::exception > * pfileexception = nullptr) override;
      
      //filesize translate(filesize uiCount, ::enum_seek eseek) override;
      
      void translate(filesize offset, ::enum_seek eseek) override;
     void set_size(filesize uiCount) override;
      filesize size() const override;

      memsize read(void * pbuffer, memsize uiCount) override;
      void write(const void * pbuffer, memsize uiCount) override;

      void lock(filesize pos, filesize uiCount) override;
      void unlock(filesize pos, filesize uiCount) override;

      void flush() override;
      void close() override;

      bool is_opened() const override;


   };


//   namespace file_exception
//   {
//
//
//      void os_error_to_exception(int lOsError);
//      void err_no_to_exception(int nErrno);
//      void throw_os_error(::object * pobject, int lOsError, const char * lpszFileName = nullptr);
//      void throw_err_no(::object * pobject, int nErrno, const char * lpszFileName = nullptr);
//
//
//   }  // namespace file_exception
//
//
} // namespace acme_ios


