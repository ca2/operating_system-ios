//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_apple/node.h"


namespace acme_ios
{


   class CLASS_DECL_ACME node :
      virtual public ::acme_apple::node
   {
   public:

      
//      class element_quit :
//      virtual public ::particle
//      {
//      public:
//         
//         node * m_pnode;
//         
//         element_quit(node * pnode)
//         {
//            
//            m_pnode = pnode;
//            
//         }
//         
//         void run() override;
//         
//         
//      };

      //gpointer m_pGtkSettingsDefault;
      string m_strTheme;

      ::pointer < manual_reset_happening > m_phappeningReadyToTerminateApp;

      node();
      ~node() override;

      
      ::string get_file_type_identifier(const ::file::path & path) override;
      
      
      void call_async(const ::string & pszPath, const ::string & pszParam, const ::string & pszDir, ::e_display edisplay, bool bPrivileged, unsigned int * puiPid = nullptr) override;
      void call_sync(const ::string & pszPath, const ::string & pszParam, const ::string & pszDir, ::e_display edisplay, const class time & timeTimeout, ::property_set & set, int * piExitCode) override;

      //virtual ::color::color get_system_color(enum_system_color esystemcolor) override;
      
      virtual bool _os_calc_system_dark_mode();
     

      int node_init_check(int * pi, char *** ppz) override;

      //virtual ::e_status start_node();

      //override;

      void initialize(::particle * pparticle) override;
      
      //void node_quit() override;

      void user_post_quit() override;

      void install_sigchld_handler() override;
      
      void _will_finish_launching() override;
      
      void shell_launch(const ::string & strAppId) override;

//         ::e_status _launch_macos_app(const ::string & pszAppFolder) override;
//
//         ::e_status _launch_macos_app_args(const ::string & pszAppFolder, const ::string & pszArgs) override;
//
//         ::e_status launch_app(const ::string & psz, const char ** argv, int iFlags) override;
      
      
      virtual int _create_process2(const char * _cmd_line, unsigned int * pprocessId);
      
//         ::e_status create_process(const ::string & pszCommandLine, unsigned int * pprocessId) override;
      
//         bool process_modules(string_array& stra, unsigned int processID) override;
//
//         bool load_modules_diff(string_array& straOld, string_array& straNew, const ::string & pszExceptDir) override;
//
//         id_array get_pids() override;
//
//         id_array module_path_get_pid(const ::string & pszModulePath, bool bModuleNameIsPropertyFormatted = false) override;
//
//         string module_path_from_pid(unsigned int pid) override;
//
//         string command_line_from_pid(unsigned int pid) override;
//
//         bool is_shared_library_busy(unsigned int processid, const string_array& stra) override;
//
//         bool is_shared_library_busy(const string_array& stra) override;
//
//         bool process_contains_module(string& strImage, unsigned int processID, const ::string & pszLibrary) override;
//
//         void shared_library_process(dword_array& dwa, string_array& straProcesses, const ::string & pszLibrary) override;
//
////         int_bool is_process_running(unsigned int pid) override;
//
//         string get_environment_variable(const ::string & pszEnvironmentVariable) override;
//
//         string expand_environment_variables(const ::string & str) override;
//
//         array <::serial::port_info> list_serial_ports() override;
      
//         virtual bool _launch_command(const char * const pszCommand);
//
//         virtual bool shell_execute_sync(const ::string & pszFile, const ::string & pszParams, ::duration durationTimeout );
      
      
      //void open_url(const ::string & strUrl) override;
      
      void open_url_link_at_system_browser(const string & strUrl, const string & strProfile = {}) override;

      //virtual void ns_app_run();
      

   };


} // namespace acme_ios



