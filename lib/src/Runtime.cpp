#include "CAGE/Runtime.hpp"
#include "CAGE/InputManager.hpp"

cage::Runtime::Runtime(unsigned int width, unsigned int height, const std::string &title) :
  m_renderWindow(new cage::RenderWindow(cage::VideoMode(width, height), title, cage::Style::Titlebar | cage::Style::Close)),
  m_activeWorld(nullptr)
{
  cage::VideoMode vm = cage::VideoMode::getDesktopMode();
  cage::Vector2i pos(vm.width/2 - m_renderWindow->getSize().x/2, vm.height/2 - m_renderWindow->getSize().y/2);
  m_renderWindow->setPosition(pos);
}

cage::Runtime::~Runtime()
{
  delete m_renderWindow;
}

void cage::Runtime::run()
{
  Clock clock;
  while (m_renderWindow->isOpen())
  {
    InputManager::flush();
    Event event;
    while (m_renderWindow->pollEvent(event))
    {
      if (event.type == EventType::Closed)
      {
        m_renderWindow->close();
      }
      else if (m_renderWindow->hasFocus())
      {
        InputManager::handleEvent(event);
      }
    }
    float dt = clock.getElapsedTime().asSeconds();
    clock.restart();
    update(dt);
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
