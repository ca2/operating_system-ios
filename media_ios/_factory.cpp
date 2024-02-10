#include "framework.h"


//namespace coreimage_imaging
//{
//
//
//#define new ACME_NEW
//
//
//   factory_exchange::factory_exchange()
//   {
//
//      create_factory < imaging, ::imaging >();
//
//   }
//
//
//   factory_exchange::~factory_exchange()
//   {
//
//   }
//
//
//} // namespace coreimage_imaging

void media_apple_facotry(::factory::factory * pfactory);

__FACTORY_EXPORT void media_ios_factory(::factory::factory * pfactory)
{

   media_apple_factory(pfactory);
   

//   pfactory->add_factory_item<::media_ios::media_ios>("media_ios::media_ios");

   
   pfactory->add_factory_item<::media_ios::media_picker, ::aqua::media_picker>();

}



