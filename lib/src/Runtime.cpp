#include "CAGE/Runtime.hpp"
#include "CAGE/InputManager.hpp"

cage::Runtime::Runtime() :
  m_renderWindow(new cage::SfRenderWindow(cage::SfVideoMode(1280, 720), "My Game")),
  m_activeWorld(nullptr)
{

}

cage::Runtime::~Runtime()
{
  delete m_renderWindow;
}

void cage::Runtime::run()
{
  SfClock clock;
  while (m_renderWindow->isOpen())
  {
    InputManager::flush();
    SfEvent event;
    while (m_renderWindow->pollEvent(event))
    {
      if (event.type == SfEventType::Closed)
      {
        m_renderWindow->close();
      }
      else if (m_renderWindow->hasFocus())
      {
        InputManager::handleEvent(event);
      }
    }
    update(clock.getElapsedTime().asSeconds());
    m_renderWindow->clear();
    render();
    m_renderWindow->display();
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
    m_activeWorld->render(*m_renderWindow);
}
