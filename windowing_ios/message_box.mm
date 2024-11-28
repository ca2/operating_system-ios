//
//  message_box.mm
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 2024-11-16 02:31 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "message_box.h"
#include "ios/iosApp.h"

namespace windowing_ios
{

void message_box::on_realize(::message_box * pmessagebox)
{
   ::string strTextTitle(pmessagebox->m_strTitle);
   NSString * strTitle = [[NSString alloc] initWithUTF8String:
                          strTextTitle.c_str()];

   ::string strTextMessage(pmessagebox->m_strMessage);
   NSString * strMessage = [[NSString alloc] initWithUTF8String:
                          strTextMessage.c_str()];

   UIAlertController* alert = [UIAlertController
                               alertControllerWithTitle:strTitle
                               message: strMessage
                               preferredStyle:UIAlertControllerStyleAlert];
   
   m_pUIAlertController = (__bridge_retained void *) alert;
   
   ::acme::user::message_box::on_realize(pmessagebox);
}


void message_box::add_button(const ::scoped_string & scopedstrText, enum_dialog_result edialogresult, char chLetter)
{
   ::string strText(scopedstrText);
   NSString * strTitle = [[NSString alloc] initWithUTF8String:
                          strText.c_str()];
   UIAlertAction* defaultAction = [UIAlertAction
                                   actionWithTitle:strTitle style:UIAlertActionStyleDefault
                                   handler:^(UIAlertAction * action) {
      
      set_dialog_result(edialogresult);
      
   }];
   UIAlertController * alert = (__bridge UIAlertController *) m_pUIAlertController;
   [alert addAction:defaultAction];
   
}


void message_box::run()
{
   __block UIAlertController * alert = (__bridge_transfer UIAlertController *) m_pUIAlertController;

   
   ns_main_post(^{
     
      iosApp * papp = (iosApp *) [[UIApplication sharedApplication] delegate];
      
      [[papp m_iosviewcontroller ] presentViewController:alert animated:YES completion:nil];


   });
   


}


} // namespace windowing_ios
