// Created by camilo on 2024-09-12 22:34 <3ThomasBorregaardSorensen!!
#pragma once


#include "__impact.h"
//#include "acme/_operating_system.h"
//#include "acme/operating_system/windows/window.h"
//#include <gtk/gtk.h>
//#include <QMainWindow>

namespace innate_ui_uikit
{

   class innate_ui;

   class CLASS_DECL_INNATE_UI_APPKIT impact :
      virtual public ::innate_ui_uikit::__impact
   {
   public:

      //void * m_pUIView;
      //QWidget * m_pqwidget;
      //GtkWidget * m_pgtkwidget;
      //HWND m_hwnd;
      //HMENU m_hmenuSystem;
      //int m_iChildIdSeed;
      //int m_iCreateStyle;

      impact();
      ~impact() override;

      void set_text(const ::scoped_string & scopedstr) override;

      //LONG_PTR _get_style();

//      void _post(const ::procedure & procedure);
      //virtual const char * __get_class_name();
      //virtual wstring _get_class_name();
      //virtual ATOM _register_class();
      //virtual void _get_class(WNDCLASSEXW & wcex);
      void _create() override;
      void _create_child(window * pwindow) override;

      void create() override;
      void create_child(::innate_ui::window * pwindow) override;
      void destroy_window() override;
      void center() override;

      void show() override;
      void hide() override;

      //void set_position(const ::int_point & point) override;
      //void set_size(const ::int_size & size) override;
      void adjust_for_client_size(int cx, int cy) override;

      ::innate_ui_uikit::innate_ui * innate_ui();

      //virtual ::pointer < window > _get_child_with_id(int iId);
      //virtual LRESULT _window_procedure(UINT message, WPARAM wparam, LPARAM lparam);

      //virtual bool _on_command();

      //virtual int _get_id();

      void defer_show_system_menu(::user::mouse * pmouse) override;

      virtual void __center();
      void __show() override;
      virtual void __hide();
      virtual void __destroy_window();
      
      void __window_release();
      virtual void __set_size(int cx, int cy);

   };


} // namespace innate_ui_uikit




