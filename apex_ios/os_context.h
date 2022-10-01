#pragma once


#include "apex_posix/os_context.h"


namespace apex_ios
{


   class CLASS_DECL_APEX os_context :
      virtual public ::apex_posix::os_context
   {
   public:


      os_context();
      ~os_context() override;


      virtual string get_command_line() override;


      void reboot() override;
      void shutdown(bool bPowerOff) override;

//      virtual void terminate_processes_by_title(const char * pszName) override;
//      virtual string get_module_path(HMODULE hmodule);
//      virtual bool get_pid_by_path(const char * pszName, ::u32 & dwPid) override;
//      virtual bool get_pid_by_title(const char * pszName, ::u32 & dwPid) override;
      //virtual int get_pid() override
//      virtual void get_all_processes(u32_array & dwa) override;
//      virtual ::file::path get_process_path(::u32 dwPid) override;

      virtual ::payload connection_settings_get_auto_detect() override;
      virtual ::payload connection_settings_get_auto_config_url() override;


//      virtual bool local_machine_set_run(const char * pszKey, const char * pszCommand);
//      virtual bool local_machine_set_run_once(const char * pszKey, const char * pszCommand);
//      virtual bool current_user_set_run(const char * pszKey, const char * pszCommand);
//      virtual bool current_user_set_run_once(const char * pszKey, const char * pszCommand);
//      virtual bool defer_register_ca2_plugin_for_mozilla() override;
//
//      virtual bool file_extension_get_open_with_list_keys(string_array & straKey, const char * pszExtension) override;
//      virtual bool file_extension_get_open_with_list_commands(string_array & straCommand, const char * pszExtension) override;
//
//      virtual bool file_association_set_default_icon(const char * pszExtension, const char * pszExtensionNamingClass, const char * pszIconPath) override;
//      virtual bool file_association_set_shell_open_command(const char * pszExtension, const char * pszExtensionNamingClass,  const char * pszCommand, const char * pszParam) override;
//      virtual bool file_association_get_shell_open_command(const char * pszExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;
//
//
//      virtual bool open_in_ie(const char * pcsz);
//
//      virtual void create_service() override;
//      virtual void erase_service() override;
//
//      virtual void start_service() override;
//      virtual void stop_service() override;

      void raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags);

      virtual bool is_remote_session() override;

//      virtual void post_to_all_threads(const ::atom & atom, WPARAM wParam, LPARAM lParam);


      void file_open(const ::file::path & path, const string & strParams = "", const ::file::path & pathFolder = "") override;


      void initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

   };


} // namespace apex_ios



