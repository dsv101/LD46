#include "CarrotWorld.hpp"
#include "app.hpp"

CarrotWorld::CarrotWorld() :
  cage::World(),
  m_mountains(),
  m_joe(DUDE_START_X, DUDE_START_Y),
  m_bunch()
{
  addEntity(&m_mountains);
  addEntity(&m_joe);
  addEntity(&m_bunch);
}

void CarrotWorld::update(float dt)
{
  if (!m_bunch.isPlanted())
  {
    cage::Vector2f joeHandPos = m_joe.getHandPosition();
    m_bunch.setPosition(joeHandPos.x, joeHandPos.y);

    if (cage::InputManager::isKeysetPressed("action") && m_joe.isOnGround())
    {
      m_bunch.plant(joeHandPos.x, joeHandPos.y + 16);
    }
  }

  float offsetX = 0.0f;
  if (cage::InputManager::isKeysetDown("move-left"))
  {
    offsetX += 120 * dt;
  }

  if (cage::InputManager::isKeysetDown("move-right"))
  {
    offsetX -= 120 * dt;
  }

  if (m_bunch.isPlanted())
  {
    m_bunch.moveX(offsetX);
  }

  cage::World::update(dt);
}
