#ifndef CAGE__RUNTIME_HPP
#define CAGE__RUNTIME_HPP

#include "CAGE/World.hpp"
#include "CAGE/SFML/sf.hpp"
#include <string>

namespace cage
{
  class Runtime
  {
    public:
      Runtime();
      virtual ~Runtime();
      void run();
      void gotoWorld(World *world);
    private:
      void update(float dt);
      void render();
      RenderWindow *m_renderWindow;
      World *m_activeWorld;
  };
}

#endif
