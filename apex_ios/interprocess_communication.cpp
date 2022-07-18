#include "framework.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include "acme/operating_system/ansi/_pthread.h"





namespace apex_ios
{


   interprocess_communication_base::interprocess_communication_base()
   {
      
      //m_port = nullptr;
      
   }


   interprocess_communication_base::~interprocess_communication_base()
   {
      
      
   }


   interprocess_communication_tx::interprocess_communication_tx()
   {

      
   }


   interprocess_communication_tx::~interprocess_communication_tx()
   {

      
   }


   void interprocess_communication_tx::open(const ::string & strChannel,launcher * plauncher)
   {

      m_strBaseChannel = strChannel;
      //CFDataRef data;

      //SInt32 messageID = 0x1111; // Arbitrary

      //CFTimeInterval timeout = 10.0;

//      CFStringRef name = CFStringCreateWithCString(nullptr,  (string("com.ca2.app.port.server.") + strChannel), kCFStringEncodingUTF8);

//      m_port =        CFMessagePortCreateRemote(nil,name);
//
//      CFRelease(name);

      //return true;

   }


   void interprocess_communication_tx::close()
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


   void interprocess_communication_tx::send(const ::string & strMessage, const ::duration & durationTimeout)
   {
      
      string strUrl;
      
      //string strCommand = m_psystem->url()->url_encode(strMessage);
      
      strUrl = strMessage;
      
      m_psystem->node()->open_url(strUrl);

   }


   void interprocess_communication_tx::send(int message,void * pdata,int len, const duration & durationTimeout)
   {

      if(message == 0x80000000)
      {
         
         throw ::exception(error_bad_argument);
         
         
      }


      if(!is_tx_ok())
      {
         
         throw ::exception(error_wrong_state);
         
      }

      memory m(pdata, len);

      string strCommand = m.to_hex();

      string strUrl;
      
      strUrl = m_strBaseChannel + "://localhost/?command_block=" + strCommand;
      
      m_psystem->node()->open_url(strUrl);

   }


   bool interprocess_communication_tx::is_tx_ok()
   {

      return m_strBaseChannel.has_char();

   }


   interprocess_communication_rx::interprocess_communication_rx()
   {

      m_preceiver    = nullptr;

   }


   interprocess_communication_rx::~interprocess_communication_rx()
   {

      
   }


   void interprocess_communication_rx::create(const ::string & strChannel)
   {

      start_receiving();

   }


   void interprocess_communication_rx::destroy()
   {

     
   }


   bool interprocess_communication_rx::start_receiving()
   {

      m_bRunning = true;

      m_bRun = true;

      m_pthread = fork([&]()
      {

         receive();
         
      });

      return true;

   }



   bool interprocess_communication_rx::on_idle()
   {

      return false;

   }


   bool interprocess_communication_rx::is_rx_ok()
   {

      return m_strBaseChannel.has_char();
      
   }


   void * interprocess_communication_rx::receive()
   {

      do
      {

         preempt(100_ms);
         
      }
      while(::task_get_run());

      return nullptr;

   }


} // namespace apex_ios



