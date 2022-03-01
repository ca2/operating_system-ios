#pragma once


namespace macos
{


   class CLASS_DECL_APEX os_context :
      virtual public ::os_context
   {
   public:


      os_context();
      virtual ~os_context();


      virtual string get_command_line() override;

      virtual bool reboot() override;

      virtual bool shutdown(bool bPowerOff) override;

      virtual void terminate_processes_by_title(const ::string & pszName) override;
      //virtual string get_module_path(HMODULE hmodule);

      virtual bool get_pid_by_path(const ::string & pszName, ::u32 & dwPid) override;

      virtual bool get_pid_by_title(const ::string & pszName, ::u32 & dwPid) override;

      virtual void get_all_processes(u32_array & dwa) override;
      virtual ::file::path get_process_path(::u32 dwPid) override;

      virtual ::payload connection_settings_get_auto_detect() override;
      virtual ::payload connection_settings_get_auto_config_url() override;


      virtual bool local_machine_set_run(const ::string & pszKey, const ::string & pszCommand);
      virtual bool local_machine_set_run_once(const ::string & pszKey, const ::string & pszCommand);
      virtual bool current_user_set_run(const ::string & pszKey, const ::string & pszCommand);
      virtual bool current_user_set_run_once(const ::string & pszKey, const ::string & pszCommand);
      virtual bool defer_register_ca2_plugin_for_mozilla() override;


      virtual bool file_extension_get_open_with_list_keys(string_array & straKey, const ::string & pszExtension) override;

      virtual bool file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & pszExtension) override;

      virtual bool file_association_set_default_icon(const ::string & pszExtension, const ::string & pszExtensionNamingClass, const ::string & pszIconPath) override;

      virtual bool file_association_set_shell_open_command(const ::string & pszExtension, const ::string & pszExtensionNamingClass,  const ::string & pszCommand, const ::string & pszParam) override;

      virtual bool file_association_get_shell_open_command(const ::string & pszExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;

      virtual bool open_in_ie(const ::string & pcsz);

      ::e_status enable_service() override;

      ::e_status disable_service() override;

      ::e_status start_service() override;

      ::e_status stop_service() override;

      virtual bool resolve_link(::file::path & pathTarget, const string & strSource, string * pstrFolder = nullptr, string * pstrParams = nullptr) override;

      void raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags);

      virtual bool is_remote_session() override;

      //virtual void post_to_all_threads(const ::id & id, WPARAM wParam, LPARAM lParam);

      virtual int get_pid() override;

      virtual bool initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

      virtual bool get_default_browser(string & strId, ::file::path & path, string & strParam) override;

      virtual bool set_default_browser() override;

      ::file::path get_app_path(const string & strApp) override;

      void on_process_command(::create * pcommand) override;

      bool file_open(::file::path path, string strParams = "", string strFolder = "") override;
      
      ::e_status link_open(const ::string & strUrl, const ::string & strProfile) override;

      void set_file_status(const ::string & lpszFileName, const ::file::file_status& status) override;

      bool browse_folder(property_set &set) override;
      bool browse_file_open(property_set &set) override;

   };



} // namespace macos



