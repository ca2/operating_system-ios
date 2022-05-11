//
//  node.hpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-19 04:19 BRT <3ThomasBS_!!
//
#pragma once


namespace windowing_macos
{


   class CLASS_DECL_WINDOWING_MACOS node :
      virtual public ::aura_ios::node
   {
   public:
      
      
      node();
      ~node() override;

      
      void os_menu_item_enable(void * pitem, bool bEnable) override;
      void os_menu_item_check(void * pitem, bool bCheck) override;

      void defer_create_main_menu(const string_array & straParent, const string_array & straMenu, const string_array & straId) override;
      
      //void implement() override;
      
      
      void _will_finish_launching() override;
      
      
      //bool is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt) override;

//
//      void install_keyboard_hook(::matter * pmatterListener) override;
//      void uninstall_keyboard_hook(::matter * pmatterListener) override;
//
//      void install_mouse_hook(::matter * pmatterListener) override;
//      void uninstall_mouse_hook(::matter * pmatterListener) override;
//

      
   };



} // namespace windowing_macos






