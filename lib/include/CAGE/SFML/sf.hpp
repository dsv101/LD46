#ifndef CAGE__SF_HPP
#define CAGE__SF_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace cage
{
  typedef sf::RenderWindow RenderWindow;
  typedef sf::Drawable Drawable;
  typedef sf::VideoMode VideoMode;
  typedef sf::Event Event;
  typedef sf::Event::EventType EventType;
  typedef sf::RenderTarget RenderTarget;
  typedef sf::Clock Clock;
  typedef sf::Time Time;
  typedef sf::Keyboard Keyboard;
  typedef sf::Mouse Mouse;
  typedef sf::Vector2i Vector2i;
  namespace Style = sf::Style;
  typedef sf::Transformable Transformable;
  typedef sf::Texture Texture;
  typedef sf::Sprite Sprite;
};

#endif
