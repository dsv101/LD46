#include "CarrotWorld.hpp"
#include "app.hpp"

CarrotWorld::CarrotWorld() :
  cage::World(),
  m_joe(DUDE_START_X, DUDE_START_Y),
  m_bunch()
{
  addEntity(&m_joe);
  addEntity(&m_bunch);
}

void CarrotWorld::update(float dt)
{
  if (!m_bunch.isPlanted())
  {
    cage::Vector2f joeHandPos = m_joe.getHandPosition();
    m_bunch.setPosition(joeHandPos.x, joeHandPos.y);

    if (cage::InputManager::isKeysetPressed("action"))
    {
      m_bunch.plant(joeHandPos.x, joeHandPos.y + 16);
    }
  }

  cage::World::update(dt);
}
