#include "framework.h"
#include "watcher.h"
#include "acme/parallelization/manual_reset_happening.h"


namespace grand_central_dispatch
{


   watch::watch()
   {
      
   }

   
   watch::~watch()
   {
      
      //eraseAll();

   }


   bool watch::open(const ::file::path & pathFolderParam, bool bRecursive)
   {
      
      auto pevent = __create_new < manual_reset_happening >();
      
      auto pathFolder = pathFolderParam;
      
      fork([this, pevent, pathFolder]()
      {
         
         // Add a file descriptor for our test file
         m_iFileDescriptor = ::open(pathFolder, O_EVTONLY | O_CLOEXEC);
             
         // Get a reference to the default queue so our file notifications can go out on it
         dispatch_queue_t defaultQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
             
             // Create a dispatch source
         m_dispatchsource = dispatch_source_create(DISPATCH_SOURCE_TYPE_VNODE,
                                              m_iFileDescriptor,
                                              DISPATCH_VNODE_ATTRIB | DISPATCH_VNODE_DELETE | DISPATCH_VNODE_EXTEND | DISPATCH_VNODE_LINK | DISPATCH_VNODE_RENAME | DISPATCH_VNODE_REVOKE | DISPATCH_VNODE_WRITE,
                                              defaultQueue);
             
             // Log one or more messages to the screen when there's a file change event
         dispatch_source_set_event_handler(m_dispatchsource, ^
         {
   
            unsigned long eventTypes = dispatch_source_get_data(m_dispatchsource);
            
            on_event(eventTypes);
            
         });
             
         dispatch_source_set_cancel_handler(m_dispatchsource, ^
         {
         
            close(m_iFileDescriptor);
            
            m_iFileDescriptor = 0;
            
            m_dispatchsource = nil;
                 
   //              // If this dispatch source was canceled because of a rename or delete notification, recreate it
   //              if (_keepMonitoringFile)
   //              {
   //                 m_bKeepMonitoringFile = NO;
   //                  [self __beginMonitoringFile];
   //              }
         });
         
         pevent->set_happening();
         
         // Start monitoring the test file
         dispatch_resume(m_dispatchsource);

      });
      
      pevent->wait();
      
      if(!::file::watch::open(pathFolder, bRecursive))
      {
         
         return false;
         
      }

      return true;

   }
   
   
   bool watch::file_watch_step()
   {
      
      return true;
      
   }


   void watch::on_event(unsigned long ulEventTypes)
   {
      
      
   }

//   void watch::myCallbackFunction(
//   ConstFSEventStreamRef streamRef,
//   void *clientCallBackInfo,
//   size_t numEvents,
//   void *eventPaths,
//   const FSEventStreamEventFlags eventFlags[],
//   const FSEventStreamEventId eventIds[])
//   {
//
//      int i;
//
//      char **paths = (char **) eventPaths;
//
//      auto pwatch = (watch *) clientCallBackInfo;
//
//      ::file::action action;
//
//      action.m_pwatch = pwatch;
//
//      action.m_id = pwatch->m_id;
//
//      action.m_pathFolder = pwatch->m_pathFolder;
//
//      for (i = 0; i < numEvents; i++)
//      {
//
//         ::file::path path = paths[i];
//
//         if(!pwatch->m_bRecursive)
//         {
//
//            if(path.folder().get_length() > action.m_pathFolder.get_length())
//            {
//
//               continue;
//
//            }
//
//         }
//
//         ::str::begins_eat(path, action.m_pathFolder);
//
//         action.m_pathFile = path;
//
//         if(eventFlags[i] & kFSEventStreamEventFlagItemRemoved)
//         {
//
//            action.m_eaction = ::file::e_action_delete;
//
//         }
//
//         if(eventFlags[i] & kFSEventStreamEventFlagItemRenamed)
//         {
//
//            action.m_eaction = ::file::e_action_modify;
//         }
//
//         if(eventFlags[i] & kFSEventStreamEventFlagItemModified)
//         {
//
//            action.m_eaction = ::file::e_action_modify;
//
//         }
//
//         if(eventFlags[i] & kFSEventStreamEventFlagItemCreated)
//         {
//
//            action.m_eaction = ::file::e_action_add;
//
//         }
//
//         pwatch->handle_action(&action);
//
//      }
//
//   }

//
//   void watch::eraseAll()
//   {
//
////      FSEventStreamStop(m_stream);
////
////      FSEventStreamInvalidate(m_stream);
////
////      FSEventStreamRelease(m_stream);
//
//      m_stream = nullptr;
//
//   }
//

   bool watcher::file_watcher_step()
   {
      
      //bool done = false;
      
      // Start the run loop but return after each source is handled.
      //SInt32 result = CFRunLoopRunInMode(kCFRunLoopDefaultMode, 2, true);
      
      // If a source explicitly stopped the run loop, or if there are no
      // sources or timers, go ahead and exit.
      //if ((result == kCFRunLoopRunStopped) || (result == kCFRunLoopRunFinished))
      //if (result == kCFRunLoopRunFinished)
      //{
         
      //   done = true;
         
      //}
      
      // Check for any other exit conditions here and set the
      // done variable as needed.
      
      //if(done)
      //{
         
      //   return false;
         
      //}
      
      auto estatus = ::file::watcher::file_watcher_step();
      
      if(!estatus)
      {
       
         return estatus;
         
      }
      
      return estatus;

   }
   

   watcher::watcher()
   {

      //m_pThis = this;
      
   }


   watcher::~watcher()
   {

   }


} // namespace grand_central_dispatch



