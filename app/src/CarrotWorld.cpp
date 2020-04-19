#include "CarrotWorld.hpp"
#include "app.hpp"

CarrotWorld::CarrotWorld() :
  cage::World(),
  m_mountains(),
  m_joe(DUDE_START_X, DUDE_START_Y),
  m_bunch(),
  m_pick(PICK_START_X, PICK_START_Y)
{
  addEntity(&m_mountains);
  addEntity(&m_bunch);
  addEntity(&m_pick);
  addEntity(&m_joe);
}

void CarrotWorld::update(float dt)
{
  float offsetX = 0.0f;
  if (cage::InputManager::isKeysetDown("move-left"))
  {
    offsetX += 120 * dt;
  }

  if (cage::InputManager::isKeysetDown("move-right"))
  {
    offsetX -= 120 * dt;
  }

  cage::Vector2f joeHandPos = m_joe.getHandPosition();
  if (!m_bunch.isPlanted())
  {
    m_bunch.setPosition(joeHandPos.x, joeHandPos.y);

    if (cage::InputManager::isKeysetPressed("action") && m_joe.isOnGround())
    {
      m_bunch.plant(joeHandPos.x, joeHandPos.y + 16);
    }
  }
  else
  {
    m_bunch.moveX(offsetX);
  }

  cage::Vector2f pickPos = m_pick.getPosition();
  if (!m_pick.isHeld())
  {
    m_pick.moveX(offsetX);
    pickPos = m_pick.getPosition();

    if (cage::InputManager::isKeysetPressed("action")
        && m_joe.isOnGround()
        && cage::Math::dist2d(joeHandPos.x, joeHandPos.y, pickPos.x, pickPos.y) < 12.0f)
    {
      m_pick.hold(joeHandPos.x, joeHandPos.y);
    }
  }
  else
  {
    m_pick.hold(joeHandPos.x, joeHandPos.y);
  }

  cage::World::update(dt);
}
