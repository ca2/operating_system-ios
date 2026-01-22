#include "framework.h"
#include "interprocess.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include "acme/operating_system/ansi/_pthread.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"


namespace apex_ios
{


   interprocess_base::interprocess_base()
   {
      
      //m_port = nullptr;
      
   }


   interprocess_base::~interprocess_base()
   {
      
      
   }


   interprocess_caller::interprocess_caller()
   {

      
   }


   interprocess_caller::~interprocess_caller()
   {

      
   }


   void interprocess_caller::open(const ::scoped_string & scopedstrChannel,launcher * plauncher)
   {

      m_strBaseChannel = scopedstrChannel;
      //CFDataRef data;

      //SInt32 messageID = 0x1111; // Arbitrary

      //CFTimeInterval timeout = 10.0;

//      CFStringRef name = CFStringCreateWithCString(nullptr,  (string("com.ca2.app.port.server.") + strChannel), kCFStringEncodingUTF8);

//      m_port =        CFMessagePortCreateRemote(nil,name);
//
//      CFRelease(name);

      //return true;

   }


   void interprocess_caller::close()
   {

//      if(m_port == nullptr)
//      {
//
//         return;
//
//      }

//      CFRelease(m_port);
//
//      m_port = nullptr;

      //return true;

   }

//
//   void interprocess_caller::send(const ::string & strMessage, const ::duration & durationTimeout)
//   {
//      
//      string strUrl;
//      
//      //string strCommand = m_psystem->url()->url_encode(strMessage);
//      
//      strUrl = strMessage;
//      
//      m_psystem->node()->open_url(strUrl);
//
//   }


//   void interprocess_caller::send(int message,void * pdata,int len, const duration & durationTimeout)
void interprocess_caller::call(const ::scoped_string & scopedstrUri, const class time & timeTimeout)
   {

//      if(message == 0x80000000)
//      {
//         
//         throw ::exception(error_bad_argument);
//         
//         
//      }
//

      if(!is_caller_ok())
      {
         
         throw ::exception(error_wrong_state);
         
      }

//      memory m(pdata, len);
//
//      string strCommand = m.to_hex();
//
//      string strUrl;
//      
//      strUrl = m_strBaseChannel + "://localhost/?command_block=" + strCommand;
      
      system()->node()->open_internet_link(scopedstrUri);

   }


   bool interprocess_caller::is_caller_ok()
   {

      return m_strBaseChannel.has_character();

   }


   interprocess_target::interprocess_target()
   {

      //m_preceiver    = nullptr;

   }


   interprocess_target::~interprocess_target()
   {

      
   }


   void interprocess_target::create(const ::scoped_string & strChannel)
   {

      start_receiving();

   }


   void interprocess_target::destroy()
   {

     
   }


   bool interprocess_target::start_receiving()
   {

      m_bRunning = true;

      m_bRun = true;

      m_pthread = fork([&]()
      {

         receive();
         
      });

      return true;

   }



   bool interprocess_target::on_idle()
   {

      return false;

   }


   bool interprocess_target::is_target_ok()
   {

      return m_strBaseChannel.has_character();
      
   }


   void * interprocess_target::receive()
   {

      do
      {

         preempt(100_ms);
         
      }
      while(::task_get_run());

      return nullptr;

   }


} // namespace apex_ios



