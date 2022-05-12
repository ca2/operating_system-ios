//
//  NSPasteboard++.m
//  axis
//
//  Created by Camilo Sasuke Tsumanuma on 10/08/17.
//
//
#include "framework.h"


UIImage * uiimage_from_image_data(const void * pdata, int cx, int cy, int scan);


char * ns_string(NSString * str);

static UIPasteboard * g_ppasteboard = nullptr;

bool ios_clipboard_has_changed(long & lTicket)
{
   
   auto lClipboardChangeCount = [g_ppasteboard changeCount];
   
   if(lTicket != lClipboardChangeCount)
   {
      
      lTicket = lClipboardChangeCount;
      
      return true;
      
   }
   
   return false;

}


long ios_clipboard_init()
{
   
   if(g_ppasteboard == nullptr)
   {
      
      g_ppasteboard = [UIPasteboard generalPasteboard];
      
   }
   
   long lTicket = [g_ppasteboard changeCount];
   
   return lTicket;
   
}


long ios_clipboard_get_file_count()
{
   
   return [[[UIPasteboard generalPasteboard] itemProviders ] count ];
   
//   NSArray * classes = [NSArray arrayWithObject:[NSURL class]];
//
//   NSDictionary *options = [NSDictionary dictionaryWithObject:
//                            [NSNumber numberWithBool:YES] forKey:UIPasteboardURLReadingFileURLsOnlyKey];
//
//   NSArray * filea = [pasteboard readObjectsForClasses:classes options:options];
//
//   long iCount =  [filea count];
//
//   return iCount;

}


char ** ios_clipboard_get_filea(long * pc)
{
   
   return nullptr;
   
//   UIPasteboard * pasteboard = [UIPasteboard generalPasteboard];
//
//   NSArray * classes = [NSArray arrayWithObject:[NSURL class]];
//
//   NSDictionary *options = [NSDictionary dictionaryWithObject:
//                            [NSNumber numberWithBool:YES] forKey:NSPasteboardURLReadingFileURLsOnlyKey];
//
//   NSArray * filea = [pasteboard readObjectsForClasses:classes options:options];
//
//   long c = [filea count];
//
//   *pc = c;
//
//   char ** psza = NULL;
//
//   if(c > 0)
//   {
//
//      psza = (char **) malloc(c * sizeof(char *));
//
//      for(int i = 0; i < c; i++)
//      {
//
//         NSURL * url = [filea objectAtIndex: i];
//
//         NSString * str = [url path];
//
//         psza[i] = strdup([str UTF8String]);
//
//      }
//
//   }
//
//   return psza;
   
}


void ios_clipboard_set_filea(const char ** psza, long c)
{
   
//   NSMutableArray * filea = [NSMutableArray new];
//
//   for(int i = 0; i < c; i++)
//   {
//
//      const char * psz = psza[i];
//
//      NSString * str = [NSString stringWithUTF8String: psz];
//
//      str = [str stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
//
//      if(psz[0] == '/')
//      {
//
//         str = [NSString stringWithFormat:@"file://%@", str];
//
//      }
//
//
//
//      NSURL * url = [NSURL URLWithString:str];
//
//      [filea addObject : url];
//
//   }
//
//   NSPasteboard * pasteboard = [NSPasteboard generalPasteboard];
//
//   [pasteboard declareTypes:[NSArray arrayWithObject:NSFilenamesPboardType] owner:nil];
//
//   [pasteboard writeObjects: filea];
//
////
////   [pasteboard setPropertyList:filea forType:NSFilenamesPboardType];
   
}




// https://stackoverflow.com/questions/6167557/get-string-from-nspasteboard
char * ios_clipboard_get_plain_text()
{
   
   UIPasteboard * pasteboard = [UIPasteboard generalPasteboard];
   
   NSString * strPasteboard = [pasteboard string];
   
   return ns_string(strPasteboard);
   
}


bool ios_clipboard_has_plain_text()
{
   
   UIPasteboard * pasteboard = [UIPasteboard generalPasteboard];
   
   NSString * strPasteboard = [pasteboard string];
   
   return strPasteboard != nil;
   
}


//https://stackoverflow.com/questions/3655038/how-to-copy-textfield-to-osx-clipboard
//On OSX

void ios_clipboard_set_plain_text(const char * psz)
{
   
   UIPasteboard * pasteboard = [UIPasteboard generalPasteboard];
   
   NSString * strPasteboard = [NSString stringWithUTF8String: psz];

   //[pasteboard clearContents];
   
   [pasteboard setString:strPasteboard];

}


void * ns_image_get_image_data(int & width, int & height, int & iScan, UIImage * pimage);

bool ios_clipboard_has_image()
{
   
   UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
   
   auto image = [pasteboard image];
   
   return image != FALSE;
   
}


// http://findnerd.com/list/view/How-to-copy-image-in-NSPasteBoard/756/
void * ios_clipboard_get_image(int & cx, int & cy, int & iScan)
{

   UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];

   auto image = [pasteboard image];

   if (!image)
   {
   
      return NULL;
   
   }
   
   void * pdata = ns_image_get_image_data(cx, cy, iScan, image);
   
   if(pdata == NULL)
   {
      
      return NULL;
      
   }

   return pdata;
   
}


bool ios_clipboard_set_image(const void * pdata, int cx, int cy, int scan)
{
   
   UIImage * image = uiimage_from_image_data( pdata, cx, cy, scan);
   
   if(!image)
   {
      
      return false;
      
   }

   UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
   
   [pasteboard setImage: image];

   return true;
   
}

