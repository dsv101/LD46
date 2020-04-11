#ifndef CAGE__ENTITY_HPP
#define CAGE__ENTITY_HPP

#include "CAGE/SFML/sf.hpp"

namespace cage
{
  class Entity
  {
    public:
      Entity();
      virtual ~Entity();

      virtual void update(float dt);
      virtual void render(RenderTarget &renderTarget);
  };
}

#endif
