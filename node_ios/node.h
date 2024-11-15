//
//  node.hpp
//  node_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/Oct/22 09:24
//
#pragma once


#include "aura_ios/node.h"


namespace node_ios
{


   class CLASS_DECL_NODE_IOS node :
      virtual public ::aura_ios::node
   {
   public:
   
      
      //void implement(::pointer < ::platform::node > & pnode, ::pointer < ::platform::system > & psystem) override;
      
      
      node();
      ~node() override;

      //void on_system_main() override;
      
      void _will_finish_launching() override;
      
      //void on_start_system() override;
      //bool is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt) override;

//
//      void install_keyboard_hook(::matter * pmatterListener) override;
//      void uninstall_keyboard_hook(::matter * pmatterListener) override;
//
      
      
//      void implement(::pointer < ::platform::node > & pnode, ::pointer < ::platform::system > & psystem) override;
//
//      
//      void _will_finish_launching() override;
//      
      void on_app_activated() override;
      void on_start_system() override;
      //bool is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt) override;

//
//      void install_keyboard_hook(::matter * pmatterListener) override;
//      void uninstall_keyboard_hook(::matter * pmatterListener) override;
//
//      void install_mouse_hook(::matter * pmatterListener) override;
//      void uninstall_mouse_hook(::matter * pmatterListener) override;
//
//       ::pointer < ::conversation > create_new_message_box_conversation() override;

//      void install_mouse_hook(::matter * pmatterListener) override;
//      void uninstall_mouse_hook(::matter * pmatterListener) override;
//
//       ::pointer < ::conversation > create_new_message_box_conversation() override;

      
      void defer_create_windowing_application_delegate(::platform::application * papplication, ::application_menu * papplicationmenu, ::application_menu_callback * papplicationmenucallback) override;


      void ns_app_run() override;
      
      void _node_file_dialog(::file::file_dialog * pdialog) override;


   };


} // namespace node_ios



