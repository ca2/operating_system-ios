///
//  macos_mm.m
//  apex
//
//  Created by Camilo Sasuke Tsumanuma on 3/8/16.
//
//
#import "framework.h"
#include <UniformTypeIdentifiers/UTType.h>

//
//char * ns_get_default_browser_path()
//{
//   
//    /*
//   CFURLRef appURL = LSCopyDefaultApplicationURLForURL((__bridge CFURLRef)[NSURL URLWithString: @"http:"], kLSRolesAll, NULL);
//   
//   CFStringRef str = CFURLGetString(appURL);
//   r
//   char * psz = strdup([(__bridge NSString *)str UTF8String]);
//   
//   CFRelease(appURL);r
//   
//   //CFRelease(str);
//   
//     */
//    
//    char * psz = strdup("");
//     
//   return psz;
//   
//}
//
//
//bool ns_open_url(const char * psz)
//{
//
//   NSString * str = [NSString stringWithUTF8String:psz];
//
//   if(str == NULL)
//   {
//
//      return false;
//
//   }
//
//   NSURL * url = [[NSURL alloc] initWithString: str];
//
//   if(url == NULL)
//   {
//
//      return false;
//
//   }
//
//   if(![[NSWorkspace sharedWorkspace] openURL: url])
//   {
//
//      return false;
//
//   }
//
//   return true;
//
//}
//
//
//bool ns_open_file(const char * psz)
//{
//
//   NSString * path = [NSString stringWithUTF8String:psz];
//
//   if(path == NULL)
//   {
//
//      return false;
//
//   }
//
//   NSURL * url = [[NSURL alloc] initFileURLWithPath:path];
//
//   if(![[NSWorkspace sharedWorkspace] openURL: url])
//   {
//
//      return false;
//
//   }
//
//   return true;
//
//}
//
void ns_launch_app_at_url(NSURL * url, const char ** argv, int iFlags)
{
    
    
    BOOL canOpenURL = [[UIApplication sharedApplication]
                           canOpenURL:url];
                       
    if ( canOpenURL )
    {
        
        [[UIApplication sharedApplication]
         openURL:url options: @{} completionHandler:  ^(BOOL){}];
    }
    
    
}
    
//   NSWorkspace * workspace = [NSWorkspace sharedWorkspace];
//
//   NSMutableDictionary * dict = [[NSMutableDictionary alloc] init];
//
//   if(argv != NULL)
//   {
//
//      NSMutableArray * array = [[NSMutableArray alloc] init];
//
//      while(*argv != NULL)
//      {
//
//         [array addObject: [[NSString alloc] initWithUTF8String: *argv]];
//
//         argv++;
//
//      }
//
//      [dict setObject:array forKey:NSWorkspaceLaunchConfigurationArguments];
//
//   }
//
//   //NSWorkspaceLaunchWithoutActivation
//   //NSWorkspaceLaunchNewInstance
//   //NSWorkspaceLaunchDefault
//
//   [workspace launchApplicationAtURL:url options: iFlags configuration:dict error:nil];
//
//  /*
//   NSWorkspaceOpenConfiguration * configuration = [[NSWorkspaceOpenConfiguration alloc] init];
//
//   if(argv != NULL)
//   {
//
//      NSMutableArray * array = [[NSMutableArray alloc] init];
//
//      while(*argv != NULL)
//      {
//
//         [array addObject: [[NSString alloc] initWithUTF8String: *argv]];
//
//         argv++;
//
//      }
//
//      [configuration setArguments: array];
//
//   }
//
//   //NSWorkspaceLaunchWithoutActivation
//   //NSWorkspaceLaunchNewInstance
//   //NSWorkspaceLaunchDefault
//
//   [workspace openApplicationAtURL:url configuration:configuration completionHandler:nil ];
//
//*/
//}
//
//void ns_launch_app(const char * psz, const char ** argv, int iFlags)
//{
//
//   NSString * path = [[NSString alloc] initWithUTF8String:psz];
//
//   NSURL * url = [NSURL fileURLWithPath:path isDirectory:YES];
//
//   ns_launch_app_at_url(url, argv, iFlags);
//
//}
//
//void node_launch_app(const char * psz, const char ** argv, int iFlags)
//{
//
//   return ns_launch_app(psz, argv, iFlags);
//
//}
//
//
//
//void ns_launch_bundle(const char * pszBundle, const char ** argv)
//{
//
//   NSString * bundle = [[NSString alloc] initWithUTF8String:pszBundle];
//
//   NSURL * url = [[NSWorkspace sharedWorkspace] URLForApplicationWithBundleIdentifier:bundle];
//
//   ns_launch_app_at_url(url, argv, 0x00010000 | 0x00080000);
//
//}
//
//





bool GetImagePixelData(unsigned int * pcr, int cx, int cy, int iScan, CGImageRef inImage)
;

//
//
//
//bool mm2_get_file_image(unsigned int * pcr, int cx, int cy, int iScan, const char * psz)
//{
//
//   NSString * str = [NSString stringWithUTF8String:psz];
//
//   if(str == NULL)
//   {
//
//      return false;
//
//   }
//
//   NSImage *image = [[NSWorkspace sharedWorkspace] iconForFile:str];
//   if(image == NULL)
//   {
//
//      return false;
//
//   }
//
//   NSRect r;
//
//   r.origin.x = 0;
//   r.origin.y = 0;
//   r.size.width = cx;
//   r.size.height = cy;
//
//   CGImageRef i = [image CGImageForProposedRect: &r context:nil hints:nil];
//
//   bool bOk = GetImagePixelData(pcr, cx, cy, iScan,  i);
//
//   //CFRelease(i);
//
//   return bOk;
//
//
//
//}
//
//
//

//
//bool mm1_get_file_image(unsigned int * pcr, int cx, int cy, int iScan, const char * psz)
//{
//
//   return mm2_get_file_image(pcr, cx, cy, iScan, psz);
//
//}

//
//void os_post_quit(::element * pelementQuit)
//{
//
//   ns_main_post(^()
//   {
//
//      pelementQuit->run();
//
//   });
//
//}

void ns_app_terminate()
{

   //[UIApp terminate:nil];

}



//void ns_Sleep(unsigned int uiMillis)
//{
//
//   [NSThread sleepForTimeInterval: ((double) uiMillis / 1000.0) ];
//
//}
//






//https://stackoverflow.com/questions/14699604/replacements-for-getmacosstatuserrorstring-getmacosstatuscommentstring

//11
//down vote
//accepted
//You can use [NSError errorWithDomain:NSOSStatusErrorDomain code:errorCode userInfo:nil] to get an NSError representing the OSStatus of errorCode. NSError provides the ability to get a localized error message from the error code (-localizedDescription), or a regular unlocalized one for debugging purposes (-description).

// GetMacOSStatusErrorString and GetMacOSStatusCommentString







void library_launch(const char *psz)
{
   //NSString *path =  [NSString stringWithUTF8String:psz];
//
//
//   NSWorkspace *ws=[NSWorkspace sharedWorkspace];
//   NSURL* url = [NSURL fileURLWithPath:path isDirectory:YES];
//   
//   NSMutableDictionary* dict = [[NSMutableDictionary alloc] init];
//   [ws launchApplicationAtURL:url
//                      options:NSWorkspaceLaunchDefault
//                configuration:dict
//                        error:nil];
//
///*
//
//   NSWorkspace *workspace=[NSWorkspace sharedWorkspace];
//   NSURL* url = [NSURL fileURLWithPath:path isDirectory:YES];
//   
//   NSWorkspaceOpenConfiguration * configuration =
//   [[NSWorkspaceOpenConfiguration alloc] init];
//   
//   [workspace openApplicationAtURL:url
//                      configuration:configuration
//                completionHandler:nil];
//  */
//   
}



char * mm2_get_type_identifier(const char * pszFilePath)
{
   
   NSString * strFilePath = [NSString stringWithUTF8String:pszFilePath];
   
   if(strFilePath == NULL)
   {
      
      return nullptr;
      
   }
   
   NSURL * url = [[NSURL alloc] initFileURLWithPath:strFilePath];
   
   if(url == nullptr)
   {
      
      return nullptr;
      
   }
   
   NSString * strType = nullptr;
   
   if(@available(macOS 11.0, iOS 14.0, *))
   {
      
      UTType * type = nullptr;

      if(![url getResourceValue: &type
                       forKey: NSURLContentTypeKey error:nil])
      {
       
         return nullptr;
         
      }
      
      if(type == nullptr)
      {
       
         return nullptr;
      
      }

      strType = [type identifier];
      
   }
   else
   {
      
      if(![url getResourceValue: &strType
                       forKey: NSURLTypeIdentifierKey error:nil])
      {
       
         return nullptr;
         
      }

   }
   
   if(strType == nullptr)
   {
    
      return nullptr;
      
   }
   
   return strdup([strType UTF8String]);
   
}




