#pragma once


#include "apex/filesystem/filesystem/file_watcher.h"


//#include <CoreServices/CoreServices.h>


namespace grand_central_dispatch
{


   class CLASS_DECL_APEX watch :
      virtual public ::file::watch
   {
   public:


      int m_iFileDescriptor;
      
      dispatch_source_t m_dispatchsource;
      bool m_bKeepMonitoringFile;


      watch();
      ~watch() override;


      virtual bool open(const ::file::path & pathFolder, bool bRecursive) override;

      //void handle_action(::file::action * paction) override;


//      static void myCallbackFunction(
//      ConstFSEventStreamRef streamRef,
//      void *clientCallBackInfo,
//      size_t numEvents,
//      void *eventPaths,
//      const FSEventStreamEventFlags eventFlags[],
//      const FSEventStreamEventId eventIds[]);

//      void addAll();
//      void eraseAll();

      bool step() override;

      virtual void on_event(unsigned long ulEventTypes);
      

   };


   class CLASS_DECL_APEX watcher :
      virtual public ::file::watcher
   {
   public:


      watcher();
      ~watcher() override;


      bool step() override;


   };


} // namespace grand_central_dispatch



