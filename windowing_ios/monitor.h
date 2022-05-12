//
//  monitor.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke on 27/05/21 19:47 BRT <3ThomasBS_!!
//  From windowing_macos on 2022-05-11 02:13 <3ThomasBorregaardSorensen!!
//

#pragma once


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_MACOS monitor :
      virtual public ::windowing::monitor
   {
   public:
      

      monitor();
      ~monitor() override;
      
      
      void get_monitor_rectangle(::RECTANGLE_I32 * prectangle) override;
      void get_workspace_rectangle(::RECTANGLE_I32 * prectangle) override;

      
   };



} // namespace windowing_ios



