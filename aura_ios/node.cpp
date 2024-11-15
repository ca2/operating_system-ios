//
//  node.cpp
//  aura_macos
//
//  Created by Camilo Sasuke on 2021-05-20 14:21 BRT <3ThomasBS_!!
//  Copyright © 2021 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#include "framework.h"
#include "node.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system_options.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/application.h"
#include "acme/handler/request.h"
#include "aura/graphics/image/context.h"
#include "aura/graphics/image/image.h"
#include "aura/platform/context.h"


//void ns_pick_viewer_document();


bool apple_get_file_image(::image::image * pimage, const char * pszFilePath);
bool apple_get_file_image_by_type_identifier(::image::image * pimage, const char * pszTypeIdentifier);


namespace aura_ios
{


   node::node()
   {
   
   }


   node::~node()
   {
      
   }


   void node::initialize(::particle * pparticle)
   {
      
      //auto estatus =
      
      ::aura_apple::node::initialize(pparticle);
      
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
      
      //estatus =
      
      ::apex_ios::node::initialize(pparticle);
      
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
      
   }


   ::image::image_pointer node::get_file_image_by_type_identifier(int iSize, const ::scoped_string & scopedstrTypeIdentifier)
   {

      auto pimage = image()->create_image( { iSize, iSize } );

      if(!apple_get_file_image_by_type_identifier(pimage, scopedstrTypeIdentifier))
      {

         return nullptr;

      }

      return pimage;

   }


   ::image::image_pointer node::get_file_image(int iSize, const ::file::path & path)
   {

      auto pimage = image()->create_image( { iSize, iSize } );

      if(!apple_get_file_image(pimage, path))
      {

         return nullptr;

      }

      return pimage;

   }


   void node::root_ones(::file::listing &listing)
   {
      
      ::apex_ios::node::root_ones(listing);
      
      if(application()->m_pfilesystemoptions->m_straFileSystemExtension.contains("apple.music"))
      {
         
         auto iPickAudioMedia = listing.size();
         
         auto & path = listing.insert_at(iPickAudioMedia, "apple.music://");
         
         path.m_etype = ::file::e_type_existent_folder;
         
         listing.m_straTitle.insert_at(iPickAudioMedia, "Apple Music");
         
      }
      else
      {
         
         auto iPickBrowse = listing.size();
         
         auto & path = listing.insert_at(iPickBrowse, "pick-browse://");
         
         path.m_etype = ::file::e_type_existent_folder;
         
         listing.m_straTitle.insert_at(iPickBrowse, "Pick Browse...");


      }
      
   }

   
   bool node::defer_enumerate_protocol(::file::listing& listing)
   {
      
      ::file::path pathFinal = listing.m_pathFinal;
      
      if(pathFinal.is_empty())
      {
         
         pathFinal = application()->defer_process_path(listing.m_pathUser);
         
      }
      
      if(pathFinal.begins_eat("pick-browse://"))
      {
         
         auto callback = [this](const ::file::path & path)
         {
            
            auto prequest = __create_new <::request>();
            
            prequest->m_payloadFile = path;
            
            prequest->m_ecommand = ::e_command_file_open;

            application()->request(prequest);
            
         };

         application()->pick_browse(callback);
         
      }
      else if(pathFinal.begins_eat("apple.music://"))
      {

         application()->pick_media("audio");
         
      }

      return ::acme_ios::node::defer_enumerate_protocol(listing);
      
   }


   bool node::defer_process_protocol_path(::file::path & path)
   {
      
      if(path.begins("pick-browse://"))
      {

         return true;
         
      }
      else if(path.begins("apple.music://"))
      {

         return true;
         
      }

      if(application()->m_pfilesystemoptions->m_b_iCloudContainer)
      {
         
         auto path_iCloudContainer = directory_system()->icloud_container2();
         
         if(path.begins_eat(path_iCloudContainer))
         {
            
            path = directory_system()->icloud_container2_final() / path;
            
            return true;
            
         }
         
      }
      
      return false;
      
   }


} // namespace aura_ios



