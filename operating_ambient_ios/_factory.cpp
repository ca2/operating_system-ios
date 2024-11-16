#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void node_ios_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_ios_factory(::factory::factory * pfactory)
{
   
   node_ios_factory(pfactory);

   pfactory->add_factory_item < ::operating_ambient_ios::node, ::platform::node > ();

}



