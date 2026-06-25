//
//  _mm.h
//  uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 12/05/26.
//
#pragma once


#include "operating_system-apple/core_graphics/_mm.h"
#include "_struct.h"

using namespace uikit;

void ui_window_release(ui_window_t & uiwindow);

void ui_image_release(ui_image_t & uiimage);


cg_image_t ui_image_get_cg_image(ui_image_t uiimage);


