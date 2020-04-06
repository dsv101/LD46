#ifndef CAGE__RENDERABLE_HPP
#define CAGE__RENDERABLE_HPP

namespace cage
{
  class Renderable
  {
    public:
      virtual void render(Renderable &renderable) = 0;
  };
}

#endif
