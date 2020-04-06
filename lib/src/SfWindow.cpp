#include "CAGE/SFML/SfWindow.hpp"

cage::sfml::SfWindow::SfWindow(const cage::Window::Props &props) :
  cage::Window::Window(props),
  m_window(sf::VideoMode(props.width, props.height), props.title)
{

}

cage::sfml::SfWindow::~SfWindow()
{

}

bool cage::sfml::SfWindow::isOpen()
{
  return m_window.isOpen();
}

void cage::sfml::SfWindow::clear()
{
  m_window.clear(sf::Color::Black);
}

void cage::sfml::SfWindow::display()
{
  m_window.display();
}

void cage::sfml::SfWindow::update()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      m_window.close();
  }
}

void cage::sfml::SfWindow::render(Renderable &renderable)
{

}
