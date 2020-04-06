#ifndef CAGE__RUNTIME_HPP
#define CAGE__RUNTIME_HPP

#include "CAGE/World.hpp"
#include "CAGE/Window.hpp"
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
      Window *m_window;
      World *m_activeWorld;
  };
}

#endif
