//
//  image.m
//  acme_macos
//
//  Created by Camilo Sasuke on 29/05/21.
//
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>


void * cg_image_get_image_data(int & width, int & height, int & iScan, CGImageRef image);



UIImage * uiimage_from_cgimageref(CGImageRef image)
{
   
   return [[UIImage alloc] initWithCGImage:image ];
   
}


UIImage * uiimage_from_image_data(const void * pdata, int cx, int cy, int scan)
{

   CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
   CGContextRef context = CGBitmapContextCreate((void *) pdata, cx, cy, 8, scan, colorSpace, kCGImageAlphaPremultipliedLast);
   CFRelease(colorSpace);

   CGImageRef cgImage = CGBitmapContextCreateImage(context);
   CGContextRelease(context);

   UIImage *image = [UIImage imageWithCGImage:cgImage ];
   CGImageRelease(cgImage);
   
   return image;

}



void * ns_image_get_image_data(int & width, int & height, int & iScan, UIImage * image)
{
   
   CGImageRef inputCGImage = [image CGImage];
   
   return cg_image_get_image_data(width, height, iScan, inputCGImage);
   
}



#import <Foundation/Foundation.h>
#import <UniformTypeIdentifiers/UTType.h>


bool GetImagePixelData(unsigned int * pcr, int cx, int cy, int iScan, CGImageRef inImage);


bool mm2_get_file_image(unsigned int * pcr, int cx, int cy, int iScan, const char * pszFilePath)
{

   NSString * strFilePath = [NSString stringWithUTF8String:pszFilePath];

   if(strFilePath == NULL)
   {

      return false;

   }


   UIImage * image = [[UIImage alloc] initWithContentsOfFile:strFilePath];;

   if(image == NULL)
   {

      return false;

   }

   CGImageRef i = [image CGImage];

   bool bOk = GetImagePixelData(pcr, cx, cy, iScan,  i);

   return bOk;

}


bool mm2_get_file_image_by_type_identifier(unsigned int * pcr, int cx, int cy, int iScan, const char * pszTypeIdentifier)
{

   NSString * strTypeIdentifier = [NSString stringWithUTF8String:pszTypeIdentifier];

   if(strTypeIdentifier == NULL)
   {

      return false;

   }

   //UIImage * image = nullptr;

//
//   NSString *extension = @"pptx"; // or something else
//   NSString *dummyPath = [@"~/foo" stringByAppendingPathExtension:extension]; // doesn't exist
//   NSURL *URL = [NSURL fileURLWithPath:dummyPath];
//   UIDocumentInteractionController *documentInteractionController = [UIDocumentInteractionController interactionControllerWithURL:URL];
//   NSArray *systemIconImages = documentInteractionController.icons;
//
//   return systemIconImages;
//   if(@available(macOS 11.0, *))
//   {
//
//      UTType * ptype = [ UTType typeWithIdentifier: strTypeIdentifier ];
//
//      if(ptype == NULL)
//      {
//
//         return false;
//
//      }
//
//      image = [[ NSWorkspace sharedWorkspace ] iconForContentType: ptype];
//
//      if(image == NULL)
//      {
//
//         return false;
//
//      }
//
//   }
//   else
//   {
//
//      image = [[NSWorkspace sharedWorkspace] iconForFileType: strTypeIdentifier];
//
//   }
//
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

   //return bOk;

   return false;

}
//
//
//bool mm1_get_file_image(unsigned int * pcr, int cx, int cy, int iScan, const char * psz)
//{
//
//   return mm2_get_file_image(pcr, cx, cy, iScan, psz);
//
//}
//
//
bool mm1_get_file_image_by_type_identifier(unsigned int * pcr, int cx, int cy, int iScan, const char * pszTypeIdentifier)
{

   return mm2_get_file_image_by_type_identifier(pcr, cx, cy, iScan, pszTypeIdentifier);

}

//
//


