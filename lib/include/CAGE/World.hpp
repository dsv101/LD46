#ifndef CAGE__WORLD_HPP
#define CAGE__WORLD_HPP

#include "CAGE/SFML/sf.hpp"
#include "CAGE/Entity.hpp"
#include <vector>

namespace cage
{
  class Runtime;
  class World
  {
    public:
      World();
      World(std::vector<Entity*> &entities);
      virtual ~World();

      const std::vector<Entity*> getEntities();
      void addEntity(Entity *entity);
      void removeEntity(Entity *entity);

      virtual void update(float dt);
      virtual void render(RenderTarget &renderTarget);

      virtual void onEnter(cage::Runtime &runtime) { };
      virtual void onLeave(cage::Runtime &runtime) { };

    private:
      std::vector<Entity*> m_entities;
  };
}

#endif
