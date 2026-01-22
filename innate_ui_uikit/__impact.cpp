//
//  __impact.cpp
//  innate_ui_uikit
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-09-20 16:54
//
#include "framework.h"
#include "__impact.h"
#include "innate_ui.h"
#include "acme/exception/interface_only.h"
#include "acme/nano/nano.h"
#include "acme/platform/platform.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/parallelization/manual_reset_happening.h"
#include "acme/prototype/geometry2d/size.h"
//#include "acme/operating_system/windows/nano/user/user.h"
#include "acme/platform/node.h"


namespace innate_ui_uikit
{

   

   //const WCHAR * g_pszWindowClass = L"innate_ui_win32_window";

   __impact::__impact()
   {
      
      //m_pqwidget = nullptr;
      //m_hmenuSystem = nullptr;
      //m_iChildIdSeed = 1000;
      
      m_bImpactPoint = false;
      m_bImpactSize = false;
      
   }


   __impact::~__impact()
   {
      __impact_release();
//      if(!m_pqwidget)
//      {
//
//         delete m_pqwidget;
//
//      }

   }



   void __impact::set_text(const ::scoped_string & scopedstr)
   {

      ::string str(scopedstr);
      
      main_send([this, str]
      ()
         {

         __set_text(str);
         //::string str;
            //gtk_window_set_title(GTK_WINDOW(m_pgtkwidget), str);

      });

   }
   //
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//

   // LONG_PTR __impact::_get_style()
   // {
   //
   //    return ::GetWindowLongPtr(m_hwnd, GWL_STYLE);
   //
   // }

   // const char * __impact::__get_class_name()
   // {
   //
   //    return typeid(*this).name();
   //
   // }

   //
   // wstring __impact::_get_class_name()
   // {
   //
   //    return __get_class_name();
   //
   // }

   //
   // ATOM __impact::_register_class()
   // {
   //
   //    auto pszClassName = __get_class_name();
   //
   //    auto & atom = innate_ui()->m_classmap[pszClassName];
   //
   //    if (atom)
   //    {
   //
   //       return atom;
   //
   //    }
   //
   //    WNDCLASSEXW wcex;
   //
   //    wcex.cbSize = sizeof(WNDCLASSEX);
   //    wstring wstrClassName(pszClassName);
   //    wcex.lpszClassName = wstrClassName;
   //
   //
   //    _get_class(wcex);
   //
   //    atom = RegisterClassExW(&wcex);
   //
   //    return atom;
   //
   // }

   //
   // void __impact::_get_class(WNDCLASSEXW & wcex)
   // {
   //
   //    wcex.style = CS_HREDRAW | CS_VREDRAW;
   //    wcex.lpfnWndProc = WndProc;
   //    wcex.cbClsExtra = 0;
   //    wcex.cbWndExtra = 0;
   //    wcex.hInstance = (HINSTANCE) ::platform::get()->m_hinstanceThis;
   //    //wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
   //    wcex.hIcon = nullptr;
   //    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
   //    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
   //    //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
   //    wcex.lpszMenuName = nullptr;
   //    //wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
   //    wcex.hIconSm = nullptr;
   //
   // }
   //


   void __impact::_create()
   {

//      auto pmainwindow = new QMainWindow();
//
//      m_pqwidget = pmainwindow;
//
//      if (m_pqwidget)
//      {
//
//         pmainwindow->setWindowFlags(Qt::FramelessWindowHint); // No window decorations
//         pmainwindow->setAttribute(Qt::WA_TranslucentBackground); // Translucent background
//         pmainwindow->setAttribute(Qt::WA_NoSystemBackground, true);
//         pmainwindow->setAttribute(Qt::WA_OpaquePaintEvent, false);
//
//         system()->innate_ui()->add_top_level_window(this);
//
//      }
//
   }


   void __impact::_create_child(window * pwindow)
   {


   }


   void __impact::create()
   {

      main_send([this]()
         {

            //_register_class();
            
            _create();

         innate_ui()->m_windowmap[m_pUIView] = this;


      });

      if (!m_pUIView)
      {

         throw ::exception(error_failed);

      }

   }


   // int __impact::_get_id()
   // {
   //
   //    return GetWindowLong(m_hwnd, GWL_ID);
   //
   // }

   // ::pointer < window > __impact::_get_child_with_id(int iId)
   // {
   //
   //    for (auto & pchild : m_childa)
   //    {
   //
   //       ::pointer < window > pwindow = pchild;
   //
   //       if (pwindow)
   //       {
   //
   //          if (pwindow->_get_id() == iId)
   //          {
   //
   //             return pwindow;
   //          }
   //
   //       }
   //
   //    }
   //
   //    return {};
   //
   // }

   // LRESULT __impact::_window_procedure(UINT message, WPARAM wparam, LPARAM lparam)
   // {
   //
   //
   //
   //    switch (message)
   //
   //    {
   //    case WM_APP + 124:
   //       PostQuitMessage(0);
   //       break;
   //    case WM_COMMAND:
   //    {
   //       int wmId = LOWORD(wparam);
   //       auto pchild = _get_child_with_id(wmId);
   //
   //       if (pchild)
   //       {
   //
   //          if (pchild->_on_command())
   //          {
   //
   //             return 0;
   //
   //          }
   //
   //       }
   //       //// Parse the menu selections:
   //       //switch (wmId)
   //       //{
   //       //   //case IDM_ABOUT:
   //       //     // DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
   //       //      //break;
   //       //case 123:
   //       //   DestroyWindow(hWnd);
   //       //   break;
   //       //default:
   //       return DefWindowProc(m_hwnd, message, wparam, lparam);
   //       //}
   //    }
   //    break;
   //    case WM_PAINT:
   //    {
   //       //PAINTSTRUCT ps;
   //       //HDC hdc = BeginPaint(hWnd, &ps);
   //       //// TODO: Add any drawing code that uses hdc here...
   //       //EndPaint(hWnd, &ps);
   //       return DefWindowProc(m_hwnd, message, wparam, lparam);
   //    }
   //    break;
   //    case WM_CLOSE:
   //       destroy_window();
   //       break;
   //    case WM_DESTROY:
   //       //PostQuitMessage(0);
   //    default:
   //       return DefWindowProc(m_hwnd, message, wparam, lparam);
   //    }
   //    return 0;
   //
   //
   // }

   //
   // bool __impact::_on_command()
   // {
   //
   //    return false;
   //
   // }


   void __impact::create_child(::innate_ui::window * pwindow)
   {
      
      //throw interface_only();

      ::pointer< window > pwindowImpl = pwindow;

      main_send([this, pwindowImpl]()
      {

         _create_child(pwindowImpl);

         innate_ui()->m_windowmap[m_pUIView] = this;
         pwindowImpl->m_childa.add(this);
         //pwindowImpl->m_iChildIdSeed++;
         //::SetWindowLong(m_hwnd, GWL_ID, pwindowImpl->m_iChildIdSeed);

      });

      if (!m_pUIView)
      {

         throw ::exception(error_failed);

      }

   }


   void __impact::destroy_window()
   {

      for (auto pchild : m_childa)
      {

         pchild->destroy_window();

      }

      m_childa.clear();

      //if (!::GetParent(m_hwnd))
      {

         innate_ui()->m_windowa.erase(this);

      }

      //::DestroyWindow(m_hwnd);

      //gtk_window_destroy(GTK_WINDOW(m_pgtkwidget));

      innate_ui()->m_windowmap[m_pUIView].release();

      //m_pgtkwidget = nullptr;

   }


   void __impact::show()
   {

      post([this]()
      {

         //m_pqwidget->show();
         //if(GTK_IS_WINDOW(m_pgtkwidget))
         //{

           // gtk_window_present(GTK_WINDOW(m_pgtkwidget));

         //}
         //else
         {

           // gtk_widget_set_visible(m_pgtkwidget, true);

         }
         
         __show();

      });

   }


   void __impact::hide()
   {

      //m_pqwidget->hide();

 
   }


void __impact::__defer_size_position()
{
 
   __set_size_position(
                       m_pointImpact.x,
                       m_pointImpact.y,
                       m_sizeImpact.cx,
                       m_sizeImpact.cy);
   
}


void __impact::_defer_size_position()
{
   
   if(m_bImpactPoint && m_bImpactSize)
   {
      
      if(m_pwindowParent == this)
      {
         
         m_procedureaLayoutParent.add(
                                      [this]()
                                      {
                                         
                                         
                                         __defer_size_position();
                                         
                                      });
         
      }
      else
      {
         
         m_pwindowParent->m_procedureaLayoutChildPosition.add(
                                                              [this]()
                                                              {
                                                                 
                                                                 __defer_size_position();
                                                                 
                                                              });
         
      }
      
   }

}


   void __impact::set_position(const ::int_point & point)
   {

      m_pointImpact = point;

      m_bImpactPoint = true;
      
      _defer_size_position();

   }


   void __impact::set_size(const ::int_size & size)
   {

      m_sizeImpact = size;
      
      m_bImpactSize = true;
      
      _defer_size_position();

//      m_pwindowParent->m_procedureaLayoutChildSize.add(
//      [this, size]()
//      {
//
//         //gtk_widget_set_size_request(m_pqwidget, size.cx, size.cy);
//         //m_pqwidget->resize(size.cx, size.cy);
//         __set_size(size.cx, size.cy);
//      });

   }


   void __impact::adjust_for_client_size(const ::int_size & sizeParam)
   {

      auto size = sizeParam;
      
#if !defined(APPLE_IOS)
      
      size.cx += 8;
      
      size.cy += 40;
      
#endif

      set_size(size);

      // sync([this, size]()
      //    {
      //
      //       RECT r{};
      //
      //       r.right = r.left + size.cx;
      //       r.bottom = r.top + size.cy;
      //
      //
      //       AdjustWindowRect(&r, _get_style(), FALSE);
      //
      //       ::SetWindowPos(m_hwnd, nullptr, 0, 0, width(r), height(r), SWP_NOMOVE);
      //
      //       RECT rThis2;
      //       ::GetWindowRect(m_hwnd, &rThis2);
      //
      //
      //    });

   }


   void __impact::center()
   {

      main_send([this]()
      {

            //gtk_window_set_position(GTK_WINDOW(m_pgtkwidget), GTK_WIN_POS_CENTER);
         // auto hwnd = ::GetParent(m_hwnd);
         //
         // if (hwnd == nullptr)
         // {
         //
         //    hwnd = ::GetDesktopWindow();
         //
         // }
         //
         // RECT r;
         //
         // ::GetWindowRect(hwnd, &r);
         // RECT rThis;
         // ::GetWindowRect(m_hwnd, &rThis);
         //
         // int wThis = rThis.right - rThis.left;
         // int hThis = rThis.bottom - rThis.top;
         //
         // int x = ((r.right - r.left) - (wThis)) / 2;
         // int y = ((r.bottom - r.top) - (hThis)) / 2;
         //
         // ::SetWindowPos(m_hwnd, nullptr, x, y, 0, 0, SWP_NOSIZE);
         //
         // RECT rThis2;
         // ::GetWindowRect(m_hwnd, &rThis2);
      });


   }


   ::innate_ui_uikit::innate_ui * __impact::innate_ui()
   {

      return dynamic_cast <::innate_ui_uikit::innate_ui *> (::innate_ui::window::innate_ui());

   }

   
   void __impact::defer_show_system_menu(::user::mouse * pmouse)
   {

      node()->defer_show_system_menu(pmouse);

   }


} // namespace innate_ui_uikit




