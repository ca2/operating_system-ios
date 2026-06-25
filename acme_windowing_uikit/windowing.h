//
// Created by camilo on 2024-05-26 21:59 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "acme/windowing/sandbox/windowing.h"


class command_handler;


namespace uikit
{

namespace acme
{

namespace windowing
{


class CLASS_DECL_ACME_WINDOWING_UIKIT windowing :
virtual public ::acme::sandbox_windowing::windowing
{
public:
    
   ::map < ::operating_system::window, ::pointer < ::acme::windowing::window > > m_mapWindow;
    
    windowing();
    ~windowing() override;
    
    //::e_status defer_initialize_windowing() override;
    void initialize_windowing() override;
   
   ::acme::windowing::window * acme_windowing_window(const ::operating_system::window & operatingsystemwindow) override;

   
    ::acme::windowing::display * acme_display() override;
    void main_send(const ::procedure & procedure) override;
    void main_post(const ::procedure & procedure) override;
    void display_error_trap_push(int i) override;
    void display_error_trap_pop_ignored(int i) override;
   void set_clipboard_text(const char * psz) override;
    //   ::e_status x11_initialize() override;
    //   void * x11_get_display() override;
    //   void x11_sync(const ::procedure & procedure) override;
    //   void x11_async(const ::procedure & procedure) override;
    //   void x11_display_error_trap_push(int i) override;
    //   void x11_display_error_trap_pop_ignored(int i) override;
   
   
   //void windowing_application_main_loop() override;
   void run() override;
   void windowing_post_quit() override;
   
   void application_handle(::i64 l, void* p) override;

   bool handle_messages() override;
   
   virtual void defer_create_windowing_application_delegate(::platform::application * papplication, ::application_menu * papplicationmenu, ::command_handler * pcommandhandler);
   
   
   void each_window(const ::function < void(::acme::windowing::window*) > & function) override;

//    virtual void defer_create_windowing_application_delegate(::platform::application * papplication, ::application_menu * papplicationmenu, ::application_menu_callback * papplicationmenucallback);

    //void windowing_application_main_loop()
    
    virtual ::string _ns_application_delegate_class();

};


        } // namespace windowing


    } // namespace acme


} // namespace uikit



