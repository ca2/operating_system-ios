//
//  macos_file.m
//  acme
//
//  Created by Camilo Sasuke Tsumanuma on 03/05/18.
//
#import "_mm.h"
#import "acme_apple/NSMetadataQueryHandler.h"


::enum_status ns_defer_initialize_icloud_access();


//char * str_ns_cloud_container_id_from_app_id(const char * pszAppId);


char * ios_app_document_folder()
{
   
   //https://www.infragistics.com/community/blogs/b/stevez/posts/ios-objective-c-working-with-files
   NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
   //From this array, we're going to grab the first //value. As thats the root path to the directory //we're looking for.

   NSString* rootPath = paths[0];
   
   return strdup([rootPath UTF8String]);
}

char * ios_app_library_folder()
{
   
   //https://www.infragistics.com/community/blogs/b/stevez/posts/ios-objective-c-working-with-files
   NSArray *paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
   //From this array, we're going to grab the first //value. As thats the root path to the directory //we're looking for.

   NSString* rootPath = paths[0];
   
   return strdup([rootPath UTF8String]);
}

enum_status ns_create_alias(const char * pszTarget, const char * pszSource)
{
   
   NSString * strTarget = [[NSString alloc]initWithUTF8String:pszTarget];
   
   NSString * strSource = [[NSString alloc]initWithUTF8String:pszSource];
   
   NSError * error = nullptr;
   if([[NSFileManager defaultManager ] createSymbolicLinkAtPath: strTarget withDestinationPath: strSource error:&error] == NO)
   {
      
      if([error code] == NSFileWriteFileExistsError)
      {
         
         return error_already_exists;
         
      }
      
      return error_failed;
      
   }
   
   return ::success;
   
}


enum_status ns_symbolic_link_destination(char ** ppszDestination, const char * pszLink)
{
   
  
   NSString * strLink = [[NSString alloc]initWithUTF8String:pszLink];
   
   NSError * error = nullptr;
   
   NSString * strDestination = [[NSFileManager defaultManager ] destinationOfSymbolicLinkAtPath:strLink error:&error];
   
   if(strDestination == nullptr)
   {
      
      return error_failed;
      
   }
   
   if(ppszDestination)
   {
   
      *ppszDestination = __strdup(strDestination);
      
   }
   
   return success;
   
}


char * ns_user_local_folder(NSSearchPathDirectory e)
{
   
   NSArray < NSURL * > * pa = [[NSFileManager defaultManager ] URLsForDirectory:e inDomains:NSLocalDomainMask| NSUserDomainMask];
   
   if(pa == NULL || [pa count] <= 0)
   {
      
      return NULL;
      
   }
   
   return __strdup([[pa objectAtIndex:0] path]);
   
}


char * ns_user_local_desktop_folder()
{
   
   return ns_user_local_folder(NSDesktopDirectory);
   
}


char * ns_user_local_documents_folder()
{
   
   return ns_user_local_folder(NSDocumentDirectory);
   
}


char * ns_user_local_downloads_folder()
{
   
   return ns_user_local_folder(NSDownloadsDirectory);
   
}


char * ns_user_local_music_folder()
{
   
   return ns_user_local_folder(NSMusicDirectory);
   
}


char * ns_user_local_image_folder()
{
   
   return ns_user_local_folder(NSPicturesDirectory);
   
}


char * ns_user_local_video_folder()
{
   
   return ns_user_local_folder(NSMoviesDirectory);
   
}


//char * ns_resolve_alias(const char * psz, bool bNoUI = false, bool bNoMount = false)
//{
//   
//   NSString * str = [[NSString alloc] initWithUTF8String: psz];
//   
//   NSURL * url = [NSURL fileURLWithPath: str];
//   
//   NSNumber * aliasFlag = nil;
//   
//   [url getResourceValue:&aliasFlag forKey: NSURLIsAliasFileKey error: nil];
//   
//   if(!aliasFlag.boolValue)
//   {
//   
//      return NULL;
//   
//   }
//   
//   NSURLBookmarkResolutionOptions options = 0;
//   
//   options |= bNoUI ? NSURLBookmarkResolutionWithoutUI : 0;
//   
//   options |= bNoMount ? NSURLBookmarkResolutionWithoutMounting : 0;
//   
//   //NSError * perror = NULL;
//   
//   //NSURL * urlTarget = [NSURL URLByResolvingAliasFileAtURL: url options: options error: &perror];
//   NSString * strTarget = nullptr;
//   if (@available(macOS 10.10, *)) {
//      NSURL * urlTarget = [NSURL URLByResolvingAliasFileAtURL: url options: options error: nil];
//      
//       strTarget = [urlTarget absoluteString];
//   } else {
//      // Fallback on earlier versions
//      strTarget = str;
//   }
//   
//   return __strdup(strTarget);
//
//}
//
//
//bool os_is_alias(const char * psz)
//{
//   
//   NSString * str = [[NSString alloc] initWithUTF8String: psz];
//   
//   NSURL * url = [NSURL fileURLWithPath: str];
//   
//   NSNumber * aliasFlag = nil;
//   
//   [url getResourceValue:&aliasFlag forKey:NSURLIsAliasFileKey error: nil];
//   
//   return aliasFlag.boolValue;
//   
//}
//
//
//


//https://stackoverflow.com/questions/45783013/icloud-drive-read-write-nsdata


enum_status ns_cloud_set_data_with_container_id(const char * psz, const char * pszAppCloudContainerIdentifier, const void * p, long l)
{
   
   auto estatus = ns_defer_initialize_icloud_access();
   
   if(estatus < 0)
   {
      
      return estatus;
      
   }
   
    //Doc dir
//    NSString *documentsDirectory = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
//    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"SampleData.zip"];
//    NSURL *u = [[NSURL alloc] initFileURLWithPath:filePath];
   
   NSString * strContainerIdentifier = [[NSString alloc] initWithUTF8String:pszAppCloudContainerIdentifier];
   
   auto pszDataInspect = (const char *) p;
    NSData *data = [[NSData alloc] initWithBytes:pszDataInspect length:l];
   NSString * str=[[NSString alloc] initWithUTF8String:psz];
    //Get iCloud container URL
    NSURL *ubiq = [[NSFileManager defaultManager]URLForUbiquityContainerIdentifier:strContainerIdentifier];// in place of nil you can add your container name
    //Create Document dir in iCloud container and upload/sync SampleData.zip
    NSURL *ubiquitousPackage = [ubiq URLByAppendingPathComponent:str];
    //Mydoc = [[MyDo alloc] initWithFileURL:ubiquitousPackage];
    //Mydoc.zipDataContent = data;
   NSError * perror = nil;
   [data writeToURL :ubiquitousPackage options:  0 error: &perror];
   
   NSString * strUbiquitousPackage = [[ubiquitousPackage absoluteURL] absoluteString ];
   
   NSLog(@"Called [ NSData writeToURL ] ubiquitousPackage : %@", strUbiquitousPackage);
   NSLog(@"Called [ NSData writeToURL ] ubiquitousPackage : %@", strUbiquitousPackage);

   
//    [Mydoc saveToURL:[Mydoc fileURL] forSaveOperation:UIDocumentSaveForCreating completionHandler:^(BOOL success)
//     {
//         if (success)
//         {
//             NSLog(@"SampleData.zip: Synced with icloud");
//         }
//         else
//             NSLog(@"SampleData.zip: Syncing FAILED with icloud");
//
//     }];
   
   return ::success;
   
}



  // 3 Download data from the iCloud Container

//NSString * ns_cloud_container_id_from_app_id(const char * pszAppId)
//{
//
//   char * p = str_ns_cloud_container_id_from_app_id(pszAppId);
//   
//   NSString * str = [[NSString alloc] initWithUTF8String:p];
//   
//   ::free(p);
//   
//   return st;
//   
//}

enum_status ns_cloud_get_data_with_container_id(void ** pp, long & l, const char * psz, const char * pszAppCloudContainerIdentifier)
{
   
   ns_defer_initialize_icloud_access();

    //--------------------------Get data back from iCloud -----------------------------//
    id token = [[NSFileManager defaultManager] ubiquityIdentityToken];
    if (token == nil)
    {
        NSLog(@"ICloud Is not LogIn");
    }
    else
    {
       
       NSString * strContainerIdentifier = [[NSString alloc] initWithUTF8String:pszAppCloudContainerIdentifier];

        NSLog(@"ICloud Is LogIn");
       NSString * str = [[NSString alloc] initWithUTF8String:psz];
        NSError *error = nil;
        NSURL *ubiq = [[NSFileManager defaultManager]URLForUbiquityContainerIdentifier:strContainerIdentifier];// in place of nil you can add your container name
        NSURL *ubiquitousPackage = [ubiq URLByAppendingPathComponent:str];
        BOOL isFileDounloaded = [[NSFileManager defaultManager]startDownloadingUbiquitousItemAtURL:ubiquitousPackage error:&error];
        if (isFileDounloaded) {
            NSLog(@"%d",isFileDounloaded);
//            NSString *documentsDirectory = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
//            //changing the file name as SampleData.zip is already present in doc directory which we have used for upload
//            NSString* fileName = [NSString stringWithFormat:@"RecSampleData.zip"];
//            NSString* fileAtPath = [documentsDirectory stringByAppendingPathComponent:fileName];
            NSData *dataFile = [NSData dataWithContentsOfURL:ubiquitousPackage];
//            BOOL fileStatus = [dataFile writeToFile:fileAtPath atomically:NO];
//            if (fileStatus) {
//                NSLog(@"success");
//            }
           auto p = ::malloc([dataFile length]);
           NSRange r;
           r.location = 0;
           r.length = [dataFile length];
           [dataFile getBytes:p range: r];
           *pp = p;
           l = [ dataFile length];
           return ::success;
        }
        else{
            NSLog(@"%d",isFileDounloaded);
           
   
        }
   }
   
   return error_failed;
   
}



