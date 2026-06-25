//
//  _struct.h
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 12/05/26.
//

#pragma once

#include "acme/operating_system/ios/window.h"

namespace uikit
{

   struct uikit_type
   {
      
      void * m_p = nullptr;
      
      bool is_set() const
      {
         
         return m_p != nullptr;
         
      }
      
      
      bool is_null() const
      {
         
         return !this->is_set();
         
      }
      
      
      void clear()
      {
         
         m_p = nullptr;
         
      }
      operator ::hash32() const
      {
         return ::as_hash32((::uptr)this->m_p);
      }

      bool operator == (const uikit_type & t) const
      {
         
         return t.m_p == m_p;
         
      }
            
   };


   struct ui_window_t : public uikit_type {
      
      
      ui_window_t() = default;
      ui_window_t(const ui_window_t &) = default;
      ui_window_t(void * p)
      {
         m_p = p;
         
      }
      ui_window_t(const ::operating_system::window & operatingsystemwindow)
      {
         if(operatingsystemwindow.m_eoperatingambient == ::windowing::e_operating_ambient_ios)
         {
            m_p = (void*) operatingsystemwindow.m_opaque.m_ulla[0];
         }
         else
         {
            m_p = nullptr;
         }
         
      }
      
      ::operating_system::ios_window as_ios_window() const
      {
         
         return {m_p, ::windowing::e_operating_ambient_ios};
         
      }
            
      
   };
   struct ui_image_t : public uikit_type {};


   struct ui_impact_t
   {
      void * m_pUIImpact = nullptr;
      void * m_pUIWindow = nullptr;
      ::u64 m_uTag = 0;
      
      ui_impact_t()
      {
         
      }
      
      ui_impact_t(const ::operating_system::window & operatingsystemwindow)
      {
         
         if(operatingsystemwindow.m_eoperatingambient != ::windowing::e_operating_ambient_ios_impact2
            && operatingsystemwindow.m_eoperatingambient != ::windowing::e_operating_ambient_ios_impact_by_tag)
         {
            
            //throw ::exception(error_wrong_type);
            m_pUIWindow = nullptr;
            m_pUIImpact = nullptr;
            m_uTag = 0;
            
         }
         else if(operatingsystemwindow.m_eoperatingambient == ::windowing::e_operating_ambient_ios_impact_by_tag)
         {

            m_pUIWindow = (void *) operatingsystemwindow.m_opaque.m_ulla[0];
            m_uTag = operatingsystemwindow.m_opaque.m_ulla[1];

         }
         else
         {
            
            m_pUIImpact = (void *) operatingsystemwindow.m_opaque.m_ulla[0];
            m_uTag = 0;
            
         }
         
      }
      
      bool is_set() const
      {
         
         return m_pUIWindow != nullptr || m_pUIImpact != nullptr;
         
      }
      
      
      bool is_null() const
      {
         
         return !this->is_set();
         
      }
      
      
      void clear()
      {
         
         m_pUIWindow = nullptr;
         m_pUIImpact = nullptr;
         m_uTag = 0;
         
      }
      
      operator ::hash32() const
      {
         
         return ::as_hash32((::uptr)this->m_pUIWindow) + ::as_hash32((::uptr)this->m_uTag) + ::as_hash32((::uptr)this->m_pUIImpact);
         
      }
      

      bool operator == (const ui_impact_t & t) const
      {

         return t.m_pUIWindow == this->m_pUIWindow && t.m_pUIImpact == this->m_pUIImpact && t.m_uTag == this->m_uTag;

      }
      
      
      ui_window_t ui_window() const
      {
       
         return {m_pUIWindow};
         
      }
      
      
      ::operating_system::ios_window as_ios_window() const
      {
         
         return { m_pUIWindow,::windowing:: e_operating_ambient_ios_impact2};
         
      }
      
            
   };



} // namespace uikit
