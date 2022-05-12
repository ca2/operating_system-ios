//
//  keyboard.m
//  windowing_macos
//
//  Created by Camilo Sasuke on 31/05/21 16:29 BRT <3ThomasBS_!!
//
#include "framework.h"
#include <UIKit/UIKit.h>
//#include <Carbon/Carbon.h>

//
//const char * mm_keyboard_input_source()
//{
//
//   TISInputSourceRef source = TISCopyCurrentKeyboardInputSource();
//   NSString *s = (__bridge NSString *)(TISGetInputSourceProperty(source, kTISPropertyInputSourceID));
//
//   if(s == nil)
//      return strdup("");
//
//   return strdup([s UTF8String]);
//
//}
//

//
//bool apple_is_action_key(int i)
//{
//
//   if(i==kVK_Return) return true;
//   if(i==kVK_Tab          ) return true;
//   //if(i==kVK_Space        ) return true;
//   if(i==kVK_Delete       ) return true;
//   if(i==kVK_Escape       ) return true;
//   if(i==kVK_Command      ) return true;
//   if(i==kVK_Shift        ) return true;
//   if(i==kVK_CapsLock     ) return true;
//   if(i==kVK_Option       ) return true;
//   if(i==kVK_Control      ) return true;
//   if(i==kVK_RightShift   ) return true;
//   if(i==kVK_RightOption  ) return true;
//   if(i==kVK_RightControl ) return true;
//   if(i==kVK_Function     ) return true;
//   if(i==kVK_F17          ) return true;
//   if(i==kVK_VolumeUp     ) return true;
//   if(i==kVK_VolumeDown   ) return true;
//   if(i==kVK_Mute         ) return true;
//   if(i==kVK_F18          ) return true;
//   if(i==kVK_F19          ) return true;
//   if(i==kVK_F20          ) return true;
//   if(i==kVK_F5           ) return true;
//   if(i==kVK_F6           ) return true;
//   if(i==kVK_F7           ) return true;
//   if(i==kVK_F3           ) return true;
//   if(i==kVK_F8           ) return true;
//   if(i==kVK_F9           ) return true;
//   if(i==kVK_F11          ) return true;
//   if(i==kVK_F13          ) return true;
//   if(i==kVK_F16          ) return true;
//   if(i==kVK_F14          ) return true;
//   if(i==kVK_F10          ) return true;
//   if(i==kVK_F12          ) return true;
//   if(i==kVK_F15          ) return true;
//   if(i==kVK_Help         ) return true;
//   if(i==kVK_Home         ) return true;
//   if(i==kVK_PageUp       ) return true;
//   if(i==kVK_ForwardDelete) return true;
//   if(i==kVK_F4           ) return true;
//   if(i==kVK_End          ) return true;
//   if(i==kVK_F2           ) return true;
//   if(i==kVK_PageDown     ) return true;
//   if(i==kVK_F1           ) return true;
//   if(i==kVK_LeftArrow    ) return true;
//   if(i==kVK_RightArrow   ) return true;
//   if(i==kVK_DownArrow    ) return true;
//   if(i==kVK_UpArrow      ) return true;
//
//   return false;
//
//}
//
//
//::user::enum_key apple_scancode_to_userkey(int iScanCode)
//{
//
//   iptr vkcode = (iptr)wparam;
//
//    switch(vkcode)
//    {
//          case kVK_ANSI_0:
//             return ::user::e_key_0;
//          case kVK_ANSI_1:
//             return ::user::e_key_1;
//          case kVK_ANSI_2:
//             return ::user::e_key_2;
//          case kVK_ANSI_3:
//             return ::user::e_key_3;
//          case kVK_ANSI_4:
//             return ::user::e_key_4;
//          case kVK_ANSI_5:
//             return ::user::e_key_5;
//          case kVK_ANSI_6:
//             return ::user::e_key_6;
//          case kVK_ANSI_7:
//             return ::user::e_key_7;
//          case kVK_ANSI_8:
//             return ::user::e_key_8;
//          case kVK_ANSI_9:
//             return ::user::e_key_9;
//          case kVK_ANSI_A:
//             return ::user::e_key_a;
//          case kVK_ANSI_B:
//             return ::user::e_key_b;
//          case kVK_ANSI_C:
//             return ::user::e_key_c;
//          case kVK_ANSI_D:
//             return ::user::e_key_d;
//          case kVK_ANSI_E:
//             return ::user::e_key_e;
//          case kVK_ANSI_F:
//             return ::user::e_key_f;
//          case kVK_ANSI_G:
//             return ::user::e_key_g;
//          case kVK_ANSI_H:
//             return ::user::e_key_h;
//          case kVK_ANSI_I:
//             return ::user::e_key_i;
//          case kVK_ANSI_J:
//             return ::user::e_key_j;
//          case kVK_ANSI_K:
//             return ::user::e_key_k;
//          case kVK_ANSI_L:
//             return ::user::e_key_l;
//          case kVK_ANSI_M:
//             return ::user::e_key_m;
//          case kVK_ANSI_N:
//             return ::user::e_key_n;
//          case kVK_ANSI_O:
//             return ::user::e_key_o;
//          case kVK_ANSI_P:
//             return ::user::e_key_p;
//          case kVK_ANSI_Q:
//             return ::user::e_key_q;
//          case kVK_ANSI_R:
//             return ::user::e_key_r;
//          case kVK_ANSI_S:
//             return ::user::e_key_s;
//          case kVK_ANSI_T:
//             return ::user::e_key_t;
//          case kVK_ANSI_U:
//             return ::user::e_key_u;
//          case kVK_ANSI_V:
//             return ::user::e_key_v;
//          case kVK_ANSI_W:
//             return ::user::e_key_w;
//          case kVK_ANSI_X:
//             return ::user::e_key_x;
//          case kVK_ANSI_Y:
//             return ::user::e_key_y;
//          case kVK_ANSI_Z:
//             return ::user::e_key_z;
//
//    case kVK_Delete:
//       return ::user::e_key_back;
//    case kVK_Shift:
//       return ::user::e_key_left_shift;
//    case kVK_RightShift:
//       return ::user::e_key_right_shift;
//    case kVK_Control:
//       return ::user::e_key_left_control;
//    case kVK_RightControl:
//       return ::user::e_key_right_control;
//    case kVK_Option:
//       return ::user::e_key_left_alt;
//    case kVK_RightOption:
//       return ::user::e_key_right_alt;
//    case kVK_ForwardDelete:
//       return ::user::e_key_delete;
//    case kVK_Return:
//       return ::user::e_key_return;
//    case kVK_Tab:
//       return ::user::e_key_tab;
//    case kVK_LeftArrow:
//       return ::user::e_key_left;
//    case kVK_RightArrow:
//       return ::user::e_key_right;
//    case kVK_UpArrow:
//       return ::user::e_key_up;
//    case kVK_DownArrow:
//       return ::user::e_key_down;
//    case kVK_PageUp:
//       return ::user::e_key_prior;
//    case kVK_PageDown:
//       return ::user::e_key_next;
//    case kVK_Home:
//       return ::user::e_key_home;
//    case kVK_End:
//       return ::user::e_key_end;
//    case kVK_Command:
//       return ::user::e_key_left_command;
//    case kVK_RightCommand:
//       return ::user::e_key_right_command;
//
//
//    }
//
//    return ::user::e_key_none;
//
//}
