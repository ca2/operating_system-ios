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

