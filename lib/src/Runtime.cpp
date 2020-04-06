#include "CAGE/Runtime.hpp"
#include "CAGE/SFML/SfWindow.hpp"

cage::Runtime::Runtime() :
  m_window(new cage::sfml::SfWindow(cage::Window::Props { 1280, 720, "My Game" })),
  m_activeWorld(nullptr)
{

}

cage::Runtime::~Runtime()
{
  delete m_window;
}

void cage::Runtime::run()
{
  while (m_window->isOpen())
  {
    update(1.0f / 60.0f);
    m_window->update();
    m_window->clear();
    render();
    m_window->display();
  }
}

void cage::Runtime::gotoWorld(World *world)
{
  m_activeWorld = world;
}

void cage::Runtime::update(float dt)
{
  if (m_activeWorld != nullptr)
    m_activeWorld->update(dt);
}

void cage::Runtime::render()
{
  if (m_activeWorld != nullptr)
    m_activeWorld->render();
}
