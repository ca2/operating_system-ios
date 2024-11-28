// Created by camilo on 2024-09-12 22:34 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/innate_ui/dialog.h"
#include "impact.h"


namespace innate_ui_uikit
{


   class CLASS_DECL_INNATE_UI_APPKIT dialog :
      virtual public ::innate_ui_uikit::impact,
      virtual public ::innate_ui::dialog
   {
   public:


      //GtkWidget *       m_pgtkwidgetFixed;
      int m_iDialogW;
      int m_iDialogH;

      dialog();
      ~dialog() override;


      void create() override;
      virtual void __create_dialog();
      void _create() override;
      //void _get_class(WNDCLASSEXW & wcex);
      //void set_text(const ::scoped_string & scopedstr) override;
      
      void show() override;
      
      void set_size(const ::int_size & size) override;
      
      void __defer_size_position() override;
      
      
   };


} // namespace innate_ui_uikit




