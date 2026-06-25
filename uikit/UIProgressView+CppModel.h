//
//  UIProgressView+CppModel.h
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 16/05/26.
//

#import <UIKit/UIKit.h>

@interface UIProgressView (CppModel)
// A raw pointer to your C++ class, struct, or data model
@property (nonatomic, assign) void *cppModelPointer;
@end
