#ifndef CAGE__WINDOW_HPP
#define CAGE__WINDOW_HPP

#include "CAGE/Renderable.hpp"
#include <string>

namespace cage
{
  class Window : public Renderable
  {
    public:
      struct Props
      {
        unsigned int width;
        unsigned int height;
        std::string title;
      };
      Window(const Props &props);
      virtual ~Window();
      Props &getProps();
      virtual bool isOpen() = 0;
      virtual void clear() = 0;
      virtual void display() = 0;
      virtual void update() = 0;
    protected:
      Props m_props;
  };
}

#endif
