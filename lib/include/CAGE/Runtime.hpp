#ifndef CAGE__RUNTIME_HPP
#define CAGE__RUNTIME_HPP

#include <string>

namespace cage
{
  class Runtime
  {
    public:
      virtual int run(unsigned int width, unsigned int height, const std::string &title) = 0;
      virtual unsigned int getWidth() = 0;
      virtual unsigned int getHeight() = 0;
  };
}

#endif
