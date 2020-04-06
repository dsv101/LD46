#ifndef CAGE__SFML__SFWINDOW_HPP
#define CAGE__SFML__SFWINDOW_HPP

#include "CAGE/Window.hpp"
#include <SFML/Graphics.hpp>

namespace cage
{
  namespace sfml
  {
    class SfWindow : public Window
    {
      public:
        SfWindow(const Props &props);
        virtual ~SfWindow();
        virtual void render(Renderable &renderable) override;
        virtual bool isOpen() override;
        virtual void clear() override;
        virtual void display() override;
        virtual void update() override;
      private:
        sf::RenderWindow m_window;
    };
  }
}

#endif
