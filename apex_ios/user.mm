//
//  user.m
//  apex_macos
//
//  Created by Camilo Sasuke on 2021-05-15 01:11 PM <3ThomasBorregaardSoerensen!!
//
#include "framework.h"


CGFloat ios_top_inset()
{
   
   CGFloat fTopInset = 0.f;
   
   if([ [ UIApplication shared ] keyWindow])
   {
      
      fTopInset = [ [ [ [ UIApplication shared ] keyWindow] safeAreaInsets ] top ];
      
   }
   else
   {

      fTopInset = [ [ [ UIApplication shared  ]statusBarFrame] size].height;
      
   }
      
   return fTopInset;
   
}





