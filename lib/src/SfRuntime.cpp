#include "CAGE/SFML/SfRuntime.hpp"

int cage::sfml::SfRuntime::run(unsigned int width, unsigned int height, const std::string &title)
{
  m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

  while (m_window->isOpen())
  {
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window->close();
    }

    m_window->clear();

    // TODO: DRAW CALLS

    m_window->display();
  }

  return EXIT_SUCCESS;
}

unsigned int cage::sfml::SfRuntime::getWidth()
{
  if (m_window == nullptr)
    return 0;

  return m_window->getSize().x;
}


unsigned int cage::sfml::SfRuntime::getHeight()
{
  if (m_window == nullptr)
    return 0;

  return m_window->getSize().y;
}
