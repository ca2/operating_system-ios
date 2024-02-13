//
//  macos_window_impl.h
//  aura
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2013-09-18.
//  From windowing_macos on 2022-05-11 02:15 <3ThomasBorregaardSorensen!!
//
//

#pragma once
struct platform_media_item_t;
//
//
//#ifdef cplusplus
//
//
//typedef comparable_array < oswindow_data * > oswindow_dataptra;
//
//
//#endif

#include "aura/windowing/sandbox/window.h"
#include "iosWindow/ios_window.h"
namespace aqua
{
class media_item_picker;

}//namespace aqua
namespace windowing_ios
{


    class CLASS_DECL_WINDOWING_MACOS window :
      virtual public ::sandbox_windowing::window,
      virtual public ::ios_window
   {
   public:
      
      
      void *                     m_pNSCursorLast;
      class windowing *          m_pioswindowing;
      ::windowing::window *      m_pwindowCapture;
      ::point_i32                m_pointMouseCursor;
      ::pointer < ::aqua::media_item_picker > m_pmediaitempicker;
      
      window();
      ~window() override;
      
      
      void create_window() override;
      

      //void ios_window_add_ref() override;
//      void ios_window_dec_ref() override;
      
      class windowing * windowing();
      
      double get_top_margin() override;
      
      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      
      void install_message_routing(channel * pchannel) override;
      
      //void set_keyboard_focus() override;
      
      void set_active_window() override;
      
      void set_foreground_window() override;
      
      void set_tool_window(bool bSet) override;
      
      bool is_active_window() const override;
      
      bool has_keyboard_focus() const override;
      
      bool ios_window_has_keyboard_focus() const override;
       
       
       bool _configure_window_unlocked(const class ::zorder& zorder, const ::e_activation& eactivation, bool bNoZorder, ::e_display edisplay) override;
       bool _strict_set_window_position_unlocked(i32 x, i32 y, i32 cx, i32 cy, bool bNoMove, bool bNoSize) override;


//      void window_show() override;
//      
//      void show_window(const ::e_display &edisplay, const ::e_activation &eactivation) override;
      
      void set_mouse_cursor(::windowing::cursor * pcursor) override;
//      
//      ::point_i32 get_mouse_cursor_position() override;
//      
//      bool set_window_position(const class ::zorder & zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags) override;

      //void set_mouse_capture() override;

      
      void window_update_screen() override;
      

      void ios_window_draw(CGContextRef cgc, CGSize sizeWindow) override;
      void ios_window_mouse_down(int iGesture, double x, double y) override;
      void ios_window_mouse_up(int iGesture, double x, double y) override;
      void ios_window_mouse_moved(int iGesture, double x, double y) override;
      void ios_window_mouse_dragged(int iGesture, double x, double y) override;
      //void ios_window_mouse_wheel(double deltaY, double x, double y) override;
      //void ios_window_double_click(int iButton, double x, double y) override;
      //bool ios_window_key_down(unsigned int vk, unsigned int scan, const char * pszUtf8) override;
      //bool ios_window_key_up(unsigned int vk, unsigned int scan) override;
      bool ios_window_key_down(::user::enum_key ekey) override;
      bool ios_window_key_up(::user::enum_key ekey) override;
//      virtual bool macos_window_key_down(unsigned int uiKeyCode) override;
//      virtual bool macos_window_key_up(unsigned int uiKeyCode) override;
      bool ios_window_on_text(const char * pszText, long iSel, long iEnd) override;
      bool ios_window_on_sel_text(long iBeg, long iEnd) override;

      
      //long ios_window_edit_hit_test(int x, int y) override;
      bool ios_window_edit_caret_rect(CGRect * prectangle, long iSel) override;

      
      void ios_window_did_become_key() override;
      void ios_window_on_activate() override;
      void ios_window_on_deactivate() override;

      bool ios_window_become_first_responder() override;
      
      void ios_window_text_view_did_begin_editing() override;
      //void * ios_window_get_mouse_cursor() override;


      //void profiling_on_start_draw_rectangle() override;
      //void profiling_on_end_draw_rectangle() override;

      
      void ios_window_resized(int cx, int cy) override;
      void ios_window_moved(CGPoint point_i32) override;
      //void ios_window_iconified() override;
      //void ios_window_deiconified() override;

//
//      void get_cursor_position(POINT_I32 * ppoint) override;



      void ios_window_on_show() override;
      void ios_window_on_hide() override;
      //void ios_window_on_miniaturize() override;

      void frame_toggle_restore() override;
      
      
      void non_top_most_upper_window_rects(::rectangle_i32_array & recta) override;


      bool post_message(::message::message * pmessage);
      bool send_message(::message::message * pmessage);

      
      void destroy_window() override;
      
      
      void bring_to_front() override;
      
      
      void pick_browse() override;
      void pick_media(const char * pszMediaType) override;
      void ios_window_did_pick_document_at_url(const char * pszUrl) override;
      void on_prompt_write_file(::user::controller *pusercontroller) override;

   };


} // windowing_ios



