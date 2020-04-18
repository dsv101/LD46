#ifndef CAGE__ENTITY_HPP
#define CAGE__ENTITY_HPP

#include "CAGE/SFML/sf.hpp"

namespace cage
{
  class Entity
  {
    public:
      Entity(float x=0.0f, float y=0.0f, Drawable *drawable=nullptr);
      virtual ~Entity();

      virtual void update(float dt);
      virtual void render(RenderTarget &renderTarget);
    private:
      Transformable m_transformable;
      Drawable *m_drawable;
  };
}

#endif
