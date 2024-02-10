//
//  iosAudioPickerViewController.h
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard
//  Sørensen on 2024-02-09 23:43
//

#import <Foundation/Foundation.h>
//
//// Have to add this framework
//
////CoreMedia.framework
////AudioToolbox.framework
////CoreAudio.framework
////MediaPlayer.framework
////AVFoundation.framework
//
//
////in UploadAudioViewController.h file
//
//#import <UIKit/UIKit.h>
//#import <CoreAudio/CoreAudioTypes.h>
//#import <AudioToolbox/AudioToolbox.h>
#import <MediaPlayer/MediaPlayer.h>
////#import <AVFoundation/AVFoundation.h>
//#import <CoreMedia/CoreMedia.h>
//
//
@interface iosAudioPickerViewController : UIViewController<MPMediaPickerControllerDelegate>
{

   MPMediaItem *song;
   NSURL *exportURL;
}


@property (nonatomic, retain) NSData *audioData;
//@synthesize musicPlayer,audioData;
@synthesize audioData;



@end



