#ifndef CAGE__ENTITY_HPP
#define CAGE__ENTITY_HPP

namespace cage
{
  class Entity
  {
    public:
      Entity();
      virtual ~Entity();

      virtual void update(float dt);
      virtual void render();
  };
}

#endif
