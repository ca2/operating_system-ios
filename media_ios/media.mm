//
//  media.m
//  media_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 11/02/24.
//
#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>


void ns_main_post(dispatch_block_t block);


void ios_play_media_item(void * pMPMediaItem)
{
   
   
ns_main_post(^()
              {
   
   
   //NSError * perror = nil;
   //   [[AVAudioSession sharedInstance ] setCategory:AVAudioSessionCategoryPlayback
   //
   //
   //   error:&perror];
   MPMediaItem * itemRequest=(__bridge MPMediaItem*)pMPMediaItem;
   MPMusicPlayerController *controller = [MPMusicPlayerController systemMusicPlayer];
   NSArray * arrayOfMediaItems=[[NSArray alloc] initWithObjects: itemRequest, nil];
   MPMediaItemCollection *collection = [[MPMediaItemCollection alloc] initWithItems:arrayOfMediaItems];
   MPMediaItem *item = [collection representativeItem];
   
   [controller setQueueWithItemCollection:collection];
   [controller setNowPlayingItem:item];
   //[controller setVolume:1.0f];
   [controller prepareToPlay];
   [controller play];
   
});
}


void ios_av_session_initialize()
{
 
   NSError *setCategoryErr = nil;
   //NSError *activationErr  = nil;
   [[AVAudioSession sharedInstance] setCategory: AVAudioSessionCategoryPlayback error:&setCategoryErr];
   //[[AVAudioSession sharedInstance] setActive:YES error:&activationErr];
   
}



