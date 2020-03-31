#ifndef CAGE__SFML__SFRUNTIME_HPP
#define CAGE__SFML__SFRUNTIME_HPP

#include "CAGE/Runtime.hpp"
#include "CAGE/SFML/SfRuntime.hpp"
#include <SFML/Graphics.hpp>

namespace cage
{
  namespace sfml
  {
    class SfRuntime : public cage::Runtime
    {
      public:
        int run(unsigned int width, unsigned int height, const std::string &title) override;
        unsigned int getWidth() override;
        unsigned int getHeight() override;
      private:
        sf::RenderWindow *m_window;
    };
  }
}

#endif
