//
//  node.cpp
//  aura_macos
//
//  Created by Camilo Sasuke on 2021-05-20 14:21 BRT <3ThomasBS_!!
//  Copyright © 2021 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#include "framework.h"
#include "node.h"
#include "acme/filesystem/filesystem/file_system_options.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/application.h"
#include "aura/graphics/image/image.h"
#include "aura/platform/context.h"


//void ns_pick_viewer_document();


bool apple_get_file_image(::image * pimage, const char * pszFilePath);
bool apple_get_file_image_by_type_identifier(::image * pimage, const char * pszTypeIdentifier);


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


   ::image_pointer node::get_file_image_by_type_identifier(int iSize, const ::scoped_string & scopedstrTypeIdentifier)
   {

      auto pimage = m_pcontext->m_pauracontext->create_image( { iSize, iSize } );

      if(!apple_get_file_image_by_type_identifier(pimage, scopedstrTypeIdentifier))
      {

         return nullptr;

      }

      return pimage;

   }


   ::image_pointer node::get_file_image(int iSize, const ::file::path & path)
   {

      auto pimage = m_pcontext->m_pauracontext->create_image( { iSize, iSize } );

      if(!apple_get_file_image(pimage, path))
      {

         return nullptr;

      }

      return pimage;

   }


   void node::root_ones(::file::listing &listing)
   {
      
      if(application()->m_pfilesystemoptions->m_straUTType.contains("public.audio"))
      {
         
         auto iPickAudioMedia = listing.size();
         
         auto & path = listing.insert_at(iPickAudioMedia, "pick-audio-media://");
         
         path.m_iDir = 1;
         
         listing.m_straTitle.insert_at(iPickAudioMedia, "Pick Audio Media...");
         
      }
else
{
   
   auto iPickBrowse = listing.size();
   
   auto & path = listing.insert_at(iPickBrowse, "pick-browse://");
   
   path.m_iDir = 1;
   
   listing.m_straTitle.insert_at(iPickBrowse, "Pick Browse...");


}
   //   auto & options = application()->m_filesystemoptions;
   //
   //   if(options.m_bOperatingSystemRootOnes)
   //   {
   //
   //      dir()->root_ones(listing);
   //
   //   }
   //
   //   if(options.m_bDropbox)
   //   {
   //
   //      ::file::path pathDropbox = m_pcontext->m_papexcontext->defer_process_path("dropbox://");
   //
   //      if(pathDropbox.has_char() && dir()->is(pathDropbox))
   //      {
   //
   //         ::file::path & path = listing.insert_at(0, "dropbox://");
   //
   //         path.m_iDir = 1;
   //
   //         listing.m_straTitle.insert_at(0, unitext("Dropbox"));
   //
   //      }
   //
   //      ::file::path pathDropboxApp = m_pcontext->m_papexcontext->defer_process_path("dropbox-app://");
   //
   //      if(pathDropboxApp.m_epath == ::e_path_file && dir()->is(pathDropboxApp))
   //      {
   //
   //         ::file::path & path = listing.insert_at(0, "dropbox-app://");
   //
   //         path.m_iDir = 1;
   //
   //         listing.m_straTitle.insert_at(0, unitext("Dropbox-App"));
   //
   //      }
   //
   //   }
   //
   //   if(options.m_bOneDrive)
   //   {
   //
   //      ::file::path pathOneDrive = m_pcontext->m_papexcontext->defer_process_path("onedrive://");
   //
   //      if(pathOneDrive.m_epath == ::e_path_file && dir()->is(pathOneDrive))
   //      {
   //
   //         ::file::path & path = listing.insert_at(0, "onedrive://");
   //
   //         path.m_iDir = 1;
   //
   //         listing.m_straTitle.insert_at(0, unitext("OneDrive"));
   //
   //      }
   //
   //   }
   //
   //   if(options.m_b_iCloud)
   //   {
   //
   //      if(acmedirectory()->has_app_cloud_document())
   //      {
   //
   //         ::file::path & path = listing.insert_at(0, "icloud://");
   //
   //         path.m_iDir = 1;
   //
   //         listing.m_straTitle.insert_at(0, unitext("iCloud"));
   //
   //      }
   //
   //   }
   //
   //   if(options.m_bVideo)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "video://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Video"));
   //
   //   }
   //
   //
   //   if(options.m_bImage)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "image://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Image"));
   //
   //   }
   //
   //
   //   if(options.m_bMusic)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "music://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Music"));
   //
   //   }
   //
   //   if(options.m_bDownload)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "download://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Download"));
   //
   //   }
   //
   //   if(options.m_bDocument)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "document://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Document"));
   //
   //   }
   //
   //   if(options.m_bDesktop)
   //   {
   //
   //      ::file::path & path = listing.insert_at(0, "desktop://");
   //
   //      path.m_iDir = 1;
   //
   //      listing.m_straTitle.insert_at(0, unitext("Desktop"));
   //
   //   }
   //
   ////#ifdef WINDOWS_DESKTOP
   ////
   ////      ::file::path strDesktopFolder;
   ////
   ////      ::windows::shell_get_special_folder_path(
   ////         nullptr,
   ////         strDesktopFolder,
   ////         CSIDL_DESKTOP,
   ////         false);
   ////
   ////      ::file::path & path = listing.insert_at(0,strDesktopFolder);
   ////      path.m_iDir = 1;
   ////      listing.m_straTitle.insert_at(0,unitext("Desktop"));
   ////
   ////#endif

      
   }

   
   bool node::defer_enumerate_protocol(::file::listing& listing)
   {
      
      ::file::path pathFinal = listing.m_pathFinal;
      
      if(pathFinal.is_empty())
      {
         
         pathFinal = m_pcontext->defer_process_path(listing.m_pathUser);
         
      }
      
      if(pathFinal.begins_eat("pick-browse://"))
      {

         application()->pick_browse();
         
      }
      else if(pathFinal.begins_eat("pick-audio-media://"))
      {

         application()->pick_media("audio");
         
      }

      return ::acme_ios::node::defer_enumerate_protocol(listing);
      
   }


} // namespace aura_ios



