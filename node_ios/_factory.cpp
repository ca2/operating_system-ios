#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_ios_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_ios_factory(::factory::factory * pfactory)
{
   

   aura_ios_factory(pfactory);
   
   pfactory->add_factory_item<::node_ios::node, ::platform::node>();
   
}



