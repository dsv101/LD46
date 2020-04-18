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
      Runtime(unsigned int width=800, unsigned int height=600, const std::string &title="My CAGE Game", unsigned int framerateLimit=60);
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
