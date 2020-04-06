#include "CAGE/Window.hpp"

cage::Window::Window(const cage::Window::Props &props) :
  m_props(props)
{

}

cage::Window::~Window()
{

}

cage::Window::Props &cage::Window::getProps()
{
  return m_props;
}
