//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/listing.h"
//#include "acme/nano/user/window_implementation.h"
#include "acme/platform/system.h"
#include "acme/windowing/windowing.h"
#include <CoreFoundation/CoreFoundation.h>
void ns_main_post(dispatch_block_t block);

void ns_main_send(dispatch_block_t block);

string macos_get_type_identifier(const char * str);

bool ns_is_system_dark_mode();

void ns_app_terminate();
//void os_post_quit(::particle * pparticleQuit);
void ui_open_url(const char * pszUrl);

void ns_launch_app(const char * psz, const char ** argv, int iFlags);


void ansios_sigchld_handler(int sig);


void apex_application_run(const ::string & pszAppName, const ::string & pszProgName);
void ns_acme_application_main(int argc, char * argv[], const char * pszCommandLine);


namespace acme_ios
{


   node::node()
   {

      //m_pAcmePosix = this;

//      factory()->add_factory_item < ::nano::user::window_implementation >();

   }


   node::~node()
   {

   }


   ::string node::get_file_type_identifier(const ::file::path & path)
   {
   
      string strTypeIdentifier = macos_get_type_identifier(path);
   
      return strTypeIdentifier;
   
   }


 void node::call_async(
const ::string & pszPath,
const ::string & pszParam,
const ::string & pszDir,
::e_display edisplay,
bool bPrivileged,
unsigned int * puiPid)
{

   string strCmdLine;

   strCmdLine = pszPath;

   if(ansi_length(pszParam) > 0)
   {

      strCmdLine +=  " ";

      strCmdLine += pszParam;

   }

//   unsigned int processId;

   chdir(pszDir);

   //if(!
   auto processidentifier = create_process(strCmdLine);
//   {
//
//      throw ::exception(error_failed);
//
//   }

   if(puiPid != nullptr)
   {

      *puiPid = (unsigned int) processidentifier;

   }

   //return 0;

}


 void node::call_sync(const ::string & pszPath, const ::string & pszParam, const ::string & pszDir, ::e_display edisplay, const class time & timeTimeout, ::property_set & set, int * piExitCode)
{

   string strCmdLine;

   strCmdLine = pszPath;

   if(ansi_length(pszParam) > 0)
   {

      strCmdLine +=  " ";
      
      strCmdLine += pszParam;
      
   }

   //process processId;

   //if(!
   auto processidentifier = create_process(strCmdLine);
//   {
//
//      return -1;
//
//   }

   set["pid"] = processidentifier;

   while(true)
   {

      if(kill((pid_t) processidentifier, 0) == -1 && errno == ESRCH) // No process can be found corresponding to processId
         break;

      sleep(1_ms);

   }

   //return 0;

}












//bool node::shell_execute_sync(const ::string & pszFile, const ::string & pszParams, ::duration durationTimeout )
//{
//
//   property_set set;
//
//   call_sync(pszFile, pszParams, ::file::path(pszFile).folder(), e_display_none, durationTimeout, set);
//
//   return true;
//
//}
//

   int node::node_init_check(int * pi, char *** ppz)
   {

      //auto iResult = gtk_init_check(pi, ppz);

      //return iResult;

      return 0;

   }


//      ::e_status node::start()
//      {
//
//
//         //      if (psystem->m_bGtkApp)
//         //      {
//         //
//         //         apex_application_run(psystem->m_XstrAppId, psystem->m_strProgName);
//         //
//         //      }
//         //      else
//         //      {
//         //
//         ////      g_set_application_name(psystem->m_XstrAppId);
//         ////
//         ////      g_set_prgname(psystem->m_strProgName);
//         ////
//         ////      //auto idle_source = g_idle_source_new();
//         ////
//         ////      //g_source_set_callback(idle_source, &linux_start_system, (::apex::system *) m_psystem, nullptr);
//         ////
//         ////      //g_source_attach(idle_source, g_main_context_default());
//         ////
//         ////      //int c = 2;
//         ////
//         ////      //const char * argv[]={"app", "--g-fatal-warnings"};
//         ////
//         ////#if !defined(__SANITIZE_ADDRESS__)
//         ////
//         ////      gtk_init_check(&psystem->m_argc, &psystem->m_argv);
//         ////
//         ////#endif
//
//         //         node_fork([this]()
//         //                   {
//         //
//         //                      //x11_add_idle_source();
//         //
//         //                      //x11_add_filter();
//         //
//         //                      auto pgtksettingsDefault = gtk_settings_get_default();
//         //
//         //                      if(pgtksettingsDefault)
//         //                      {
//         //
//         //
//         //                         m_pGtkSettingsDefault = G_OBJECT(pgtksettingsDefault);
//         //
//         //                         g_object_ref (m_pGtkSettingsDefault);
//         //
//         //                         gchar *theme_name = nullptr;
//         //
//         //                         g_object_get(m_pGtkSettingsDefault, "gtk-theme-name", &theme_name, NULL);
//         //
//         //                         m_strTheme = theme_name;
//         //
//         //                         g_free(theme_name);
//         //
//         //                         auto preturn = g_signal_connect_data(
//         //                            m_pGtkSettingsDefault,
//         //                            "notify::gtk-theme-name",
//         //                            G_CALLBACK(gtk_settings_gtk_theme_name_callback),
//         //                            this,
//         //                            NULL,
//         //                            G_CONNECT_AFTER);
//         //
//         //                         //g_object_ref(preturn);
//         //
//         //                         //printf("return %" PRIiPTR, preturn);
//         //
//         //                         //printf("return %" PRIiPTR, preturn);
//         //
//         //                      }
//         //
//         //
//         //                   });
//         //
//         //
//         //         //x11_add_filter();
//         //
//         //psystem->fork([]()
//         //     {
//         //
//         //      x11_main();
//         //
//         //     });
//         //
//         //         gtk_main();
//
//         //x11_main();
//
//         //}
//         //
//         //::parallelization::post_quit_and_wait(get_context_system(), one_minute());
//
//         return ::success;
//
//      }


   void node::initialize(::particle * pparticle)
   {

      //auto estatus =
      
      ::platform::node::initialize(pparticle);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;

   }


   bool node::_os_calc_system_dark_mode()
   {
   
      return ns_is_system_dark_mode();
   
   }

   //
   //
   //   string node::os_get_user_theme()
   //   {
   //
   //      return m_strTheme;
   //
   //   }
   //
   //
   //   bool node::os_set_user_theme(const ::string &strUserTheme)
   //   {
   //
   //      // https://ubuntuforums.org/showthread.php?t=2140488
   //      // gsettings set org.gnome.desktop.interface gtk-theme your_theme
   //
   //      // indirect wall-changer sourceforge.net contribution
   //
   //      auto edesktop = psystem->get_eoperating_ambient();
   //
   //      switch (edesktop)
   //      {
   //
   //      case ::user::e_desktop_gnome:
   //      case ::user::e_desktop_ubuntu_gnome:
   //      case ::user::e_desktop_unity_gnome:
   //      {
   //
   //      bool bOk1 = ::node_gnome::gsettings_set("org.gnome.desktop.interface", "gtk-theme", strUserTheme);
   //
   //      bool bOk2 = true;
   //
   //      //if(m_psystem->directory_system()->system_short_name().contains_ci("manjaro"))
   //      {
   //
   //         bOk2 = ::node_gnome::gsettings_set("org.gnome.desktop.wm.preferences", "theme", strUserTheme);
   //
   //      }
   //
   //      sleep(300_ms);
   //
   //      ::node_gnome::gsettings_sync();
   //
   //      sleep(300_ms);
   //
   //      return
   //      bOk1 &&bOk2;
   //
   //      }
   //
   //      case ::user::e_desktop_mate:
   //
   //      //return ::user::gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
   //
   //      case ::user::e_desktop_lxde:
   //
   //      //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
   //
   //      break;
   //
   //      case ::user::e_desktop_xfce:
   //      {
   //      //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
   //      //          if(entry.contains("image-path") || entry.contains("last-image")){
   //      //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
   //      //      }
   //      //}
   //
   //      }
   //
   //      //break;
   //
   //      default:
   //
   //      output_debug_string("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
   //      return false;
   //
   //      }
   //
   //      return true;
   //
   //   }
   //
   //
   //   void node::os_process_user_theme(string strTheme)
   //   {
   //
   //      _os_process_user_theme(strTheme);
   //
   //   }
   //
   //
   //   bool node::set_wallpaper(index iScreen, string strLocalImagePath)
   //   {
   //
   //      // wall-changer sourceforge.net contribution
   //
   //      auto pnode = Node;
   //
   //      auto edesktop = psystem->get_eoperating_ambient();
   //
   //      switch (edesktop)
   //      {
   //
   //         case ::user::e_desktop_gnome:
   //         case ::user::e_desktop_ubuntu_gnome:
   //         case ::user::e_desktop_unity_gnome:
   //
   //            return ::node_gnome::gsettings_set("org.gnome.desktop.background", "picture-uri", "file://" + strLocalImagePath);
   //
   //         case ::user::e_desktop_mate:
   //
   //            return ::node_gnome::gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
   //
   //         case ::user::e_desktop_lxde:
   //
   //            call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
   //
   //            break;
   //
   //         case ::user::e_desktop_xfce:
   //         {
   //            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
   //            //          if(entry.contains("image-path") || entry.contains("last-image")){
   //            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
   //            //      }
   //            //}
   //
   //         }
   //
   //            //break;
   //
   //         default:
   //
   //            output_debug_string("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
   //            return false;
   //
   //      }
   //
   //      return true;
   //
   //   }
   //
   //
   //   void node::enable_wallpaper_change_notification()
   //   {
   //
   //      auto edesktop = psystem->get_eoperating_ambient();
   //
   //      switch (edesktop)
   //      {
   //
   //         case ::user::e_desktop_gnome:
   //         case ::user::e_desktop_ubuntu_gnome:
   //         case ::user::e_desktop_unity_gnome:
   //
   //            ::node_gnome::g_enable_wallpaper_change_notification("org.gnome.desktop.background", "picture-uri");
   //
   //            break;
   //
   //         case ::user::e_desktop_mate:
   //
   //            ::node_gnome::g_enable_wallpaper_change_notification("org.mate.background", "picture-filename");
   //
   //            break;
   //
   //         case ::user::e_desktop_lxde:
   //
   //            //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
   //
   //            break;
   //
   //         case ::user::e_desktop_xfce:
   //         {
   //            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
   //            //          if(entry.contains("image-path") || entry.contains("last-image")){
   //            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
   //            //      }
   //            //}
   //
   //         }
   //
   //         break;
   //         default:
   //
   //            output_debug_string("Failed to get wallpaper setting. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
   //            //return "";
   //
   //      }
   //
   //   }
   //
   //
   //   string node::get_file_icon_path(const ::string & pszPath, int iSize)
   //   {
   //
   //      return ::linux_g_direct_get_file_icon_path(pszPath, iSize);
   //
   //   }
   //
   //
   //   string node::get_file_content_type(const ::string & pszPath)
   //   {
   //
   //      return ::linux_g_direct_get_file_content_type(pszPath);
   //
   //   }
   //
   //
   //   string node::get_wallpaper(index iScreen)
   //   {
   //
   //      return "";
   //
   //   }


   //   void node::node_fork(const ::procedure & procedure)
   //   {
   //
   //      //gdk_branch(routine);
   //
   //   }


   //   void node::node_post_quit()
   //   {
   //
   //      os_post_quit();
   //
   //   }


   //   ::linux::appindicator * node::appindicator_allocate()
   //   {
   //
   //      return new ::node_gnome::appindicator();
   //
   //   }
   //
   //
   //   void node::appindicator_destroy(::linux::appindicator * pappindicator)
   //   {
   //
   //      //::linux::appindicator_destroy(pappindicator);
   //
   //      delete pappindicator;
   //
   //   }
   //
   //
   //   void node::enum_display_monitors(::aura::session * psession)
   //   {
   //
   //      node_fork(__routine([psession]
   //                           {
   //
   //                              synchronous_lock sl(x11_mutex());
   //
   //                              xdisplay d(x11_get_display());
   //
   //                              GdkDisplay *pdisplay = gdk_display_get_default();
   //
   //                              if (pdisplay == nullptr)
   //                              {
   //
   //                                 return;
   //
   //                              }
   //
   //                              synchronous_lock slSession(psession->mutex());
   //
   //                              ::collection::count iMonitorCount = gdk_display_get_n_monitors(pdisplay);
   //
   //                              psession->m_rectaWorkspace.set_size(iMonitorCount);
   //
   //                              psession->m_rectaMonitor.set_size(iMonitorCount);
   //
   //                              for (index iMonitor = 0; iMonitor < iMonitorCount; iMonitor++)
   //                              {
   //
   //                                 GdkMonitor *pmonitor = gdk_display_get_monitor(pdisplay, iMonitor);
   //
   //                                 auto &rectWorkspace = psession->m_rectaWorkspace[iMonitor];
   //
   //                                 auto &rectMonitor = psession->m_rectaMonitor[iMonitor];
   //
   //                                 if (pmonitor == nullptr)
   //                                 {
   //
   //                                    rectWorkspace.Null();
   //
   //                                    rectMonitor.Null();
   //
   //                                    continue;
   //
   //                                 }
   //
   //                                 GdkRectangle rect;
   //
   //                                 __zero(rect);
   //
   //                                 gdk_monitor_get_workarea(pmonitor, &rect);
   //
   //                                 copy(rectWorkspace, rect);
   //
   //                                 __zero(rect);
   //
   //                                 gdk_monitor_get_geometry(pmonitor, &rect);
   //
   //                                 copy(rectMonitor, rect);
   //
   //                              }
   //
   //                           }));
   //
   //   }
//
//void node::element_quit::run()
//{
//   
//   m_pnode->m_phappeningReadyToTerminateApp->set_event();
//   
//   auto htaskSystem = (pthread_t) m_pnode->m_htaskSystem;
//
//   pthread_join(htaskSystem, nullptr);
//
//   ns_app_terminate();
//   
//   delete this;
//   
//   //return ::success;
//   
//}
//


    void node::user_post_quit()
      {
       
       ns_main_post(^
                     {
          
          ns_app_terminate();
          
       });
       
//       m_phappeningReadyToTerminateApp = __new(manual_reset_happening);
//       
//       m_phappeningReadyToTerminateApp->reset_happening();
//       
//       element_quit * pelementquit = new element_quit(this);
//   
//       ::os_post_quit(pelementquit);
//       
//       m_phappeningReadyToTerminateApp->_wait();
       
      }


   //   void * node::node_wrap_window(void * pvoidDisplay, long long window)
   //   {
   //
   //      Display * pdisplay = (Display *) pvoidDisplay;
   //
   //      GdkDisplay * pd = gdk_x11_lookup_xdisplay (pdisplay);
   //
   //      auto pwindow = gdk_x11_window_foreign_new_for_display(GDK_DISPLAY(pd), (Window) window);
   //
   //      return pwindow;
   //
   //   }

   
   //   bool node::launch_on_node(::subject::subject * psubject)
   //   {
   //
   //      ::matter * pmatter = psubject;
   //
   //      node_fork([pmatter]()
   //                {
   //
   //                   auto ret = g_timeout_add(300, (GSourceFunc) &node_gnome_source_func, pmatter);
   //
   //                   printf("ret %d", ret);
   //
   //                   printf("ret %d", ret);
   //
   ////      g_idle_add(&node_gnome_source_func, pmatter);
   //
   //                });
   //
   //   }
   //
   //
   //} // namespace node_gnome
   //
   //
   //gboolean node_gnome_source_func(gpointer pUserdata)
   //{
   //
   //   ::matter * pmatter = (::matter *) pUserdata;
   //
   //   if(!pmatter->step())
   //   {
   //
   //      return false;
   //
   //   }
   //
   //   return true;
   //
   //}

//


   void node::install_sigchld_handler()
   {

      struct sigaction sa;

      ::zero(sa);

      sa.sa_handler = &ansios_sigchld_handler;

      sigemptyset(&sa.sa_mask);

      sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;

      sigaction(SIGCHLD, &sa, nullptr);

      //return ::success;

   }


   void node::_will_finish_launching()
   {
      
      auto pwindowing = system()->acme_windowing();
      
      pwindowing->_will_finish_launching();
      
   }


   void node::shell_launch(const ::string & strAppId)
   {

      information() << "::acme_ios::node::shell_launch: " << strAppId;
      
      //throw interface_only();

   }

   
//   void node::_launch_macos_app(const ::string & pszAppFolder)
//   {
//
//      if (!pszAppFolder)
//      {
//
//         return false;
//
//      }
//
//      string strCommand;
//
//      strCommand.format("open \"%s\"", pszAppFolder.c_str());
//
//      return _launch_command(strCommand);
//
//   }
//
//
//   ::e_status node::_launch_macos_app_args(const ::string & pszAppFolder, const ::string & pszArgs)
//   {
//
//      if (!pszAppFolder)
//      {
//
//         return false;
//
//      }
//
//      string strCommand;
//
//      strCommand.format("open \"%s\" --args %s", pszAppFolder.c_str(), pszArgs.c_str());
//
//      return _launch_command(strCommand);
//
//   }
//
//
//   ::e_status node::launch_app(const ::string & psz, const char ** argv, int iFlags)
//   {
//
//      ::ns_launch_app(psz, argv, iFlags);
//
//      return ::success;
//
//   }

   
   int node::_create_process2(const char * _cmd_line, unsigned int * pprocessId)
   {
      char *   exec_path_name;
      char *   cmd_line;

      cmd_line = (char *) ::malloc(strlen(_cmd_line ) + 1 );

      if(cmd_line == nullptr)
         return 0;

      ansi_copy(cmd_line, _cmd_line);

      if((*pprocessId = ::fork()) == 0)
      {
         // child
         const char      *pArg, *pPtr;
         const char      *argv[1024 + 1];
         int       argc;
         exec_path_name = cmd_line;
         if( ( pArg = ansi_find_char_reverse( exec_path_name, '/' ) ) != nullptr )
            pArg++;
         else
            pArg = exec_path_name;
         argv[0] = pArg;
         argc = 1;

         if( cmd_line != nullptr && *cmd_line != '\0' )
         {
            pArg = strtok_r(cmd_line, " ", (char **) &pPtr);
            while( pArg != nullptr )
            {
               argv[argc] = pArg;
               argc++;
               if( argc >= 1024 )
                  break;
               pArg = strtok_r(nullptr, " ", (char **) &pPtr);
            }
         }
         argv[argc] = nullptr;

         execv(exec_path_name, (char * const *) argv);
         free(cmd_line);
         exit( -1 );
      }
      else if(*pprocessId == -1)
      {
         // in parent, but error
         *pprocessId = 0;
         free(cmd_line);
         return 0;
      }
      // in parent, success
      return 1;
   }


//   bool node::process_modules(string_array& stra, unsigned int processID)
//   {
//
//      throw interface_only();
//
//      return false;
//
//   }
//
//
//   bool node::load_modules_diff(string_array& straOld, string_array& straNew, const ::string & pszExceptDir)
//   {
//
//      throw interface_only();
//
//      return false;
//
//   }
//
//
////   id_array node::get_pids()
////   {
////
////      return ::get_pids();
////
////   }
//
//
////   id_array node::module_path_get_pid(const char* pszModulePath, bool bModuleNameIsPropertyFormatted)
////   {
////
////      return ::module_path_get_pid(pszModulePath, bModuleNameisPropertyFormatted);
////
////   }
//
////
////   string node::module_path_from_pid(unsigned int pid)
////   {
////
////      return "";
////
////   }
//
//
//   bool node::is_shared_library_busy(unsigned int processid, const string_array& stra)
//   {
//
//      throw interface_only();
//
//      return false;
//
//   }
//
//
//   bool node::is_shared_library_busy(const string_array& stra)
//   {
//
//      throw interface_only();
//
//      return false;
//
//   }
//
//
//   bool node::process_contains_module(string& strImage, unsigned int processID, const ::string & pszLibrary)
//   {
//
//      throw interface_only();
//
//      return false;
//
//   }
//
//
//   void node::shared_library_process(dword_array& dwa, string_array& straProcesses, const ::string & pszLibrary)
//   {
//
//      throw interface_only();
//
//   }
//
//
////   int_bool node::is_process_running(unsigned int pid)
////   {
////
////      throw interface_only();
////
////      return false;
////
////   }
//
//
//   string node::get_environment_variable(const ::string & strEnvironmentVariable)
//   {
//
//      return "";
//
//   }
//
//
//   string node::expand_environment_variables(const ::string & str)
//   {
//
//      return "";
//
//   }
//   
//      
//   //} // namespace macos
//


   void node::open_url_link_at_system_browser(const ::string & strUrl, const string & strProfile)
   {
      
      ::ui_open_url(strUrl);
   
   }


//   void node::ns_app_run()
//   {
//    
//      auto argc = platform()->m_argc;
//
//      auto args = platform()->m_args;
//
//      ns_acme_application_main(argc, args, nullptr);
//      
//   }


} // namespace acme


void * get_system_mmos(::platform::system * psystem)
{

   return psystem->m_pmmos;

}


void set_system_mmos(::platform::system * psystem, void * pmmos)
{

   psystem->m_pmmos = pmmos;

}


char * mm2_get_type_identifier(const char * psz);


string macos_get_type_identifier(const char * psz)
{
   
   return ::string_from_strdup(mm2_get_type_identifier(psz));
   
}



