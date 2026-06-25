//
//  uikit.h
//  uikit
//
//  UIKit platform wrapper.
//  <3ThomasBorregaardSørensen!!
//
#pragma once



namespace uikit
{


   class CLASS_DECL_UIKIT uikit :
      virtual public ::particle
   {
   public:
   
      
      uikit();
      
      ~uikit();
   
      ::pointer < ui_image > load_icon(enum_cursor ecursor);
      

   
   };


} // namespace uikit


CLASS_DECL_UIKIT ::uikit::uikit & UIKit();
