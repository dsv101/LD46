#ifndef CAGE__WORLD_HPP
#define CAGE__WORLD_HPP

#include "CAGE/SFML/sf.hpp"
#include "CAGE/Entity.hpp"
#include <vector>

namespace cage
{
  class World
  {
    public:
      World();
      World(std::vector<Entity*> &entities);
      virtual ~World();

      std::vector<Entity*> &entities();
      void addEntity(Entity *entity);
      void removeEntity(Entity *entity);

      virtual void update(float dt);
      virtual void render(SfRenderTarget &renderTarget);

    private:
      std::vector<Entity*> m_entities;
  };
}

#endif
