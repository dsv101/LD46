#include "CarrotWorld.hpp"
#include "app.hpp"

CarrotWorld::CarrotWorld() :
  cage::World(),
  m_mountains(),
  m_joe(DUDE_START_X, DUDE_START_Y),
  m_bunch(),
  m_pick(PICK_START_X, PICK_START_Y),
  m_ground(),
  m_music(),
  m_isMuted(false)
{
  m_music.openFromFile(SONG_1_OGG);
  m_music.setLoop(true);
  addEntity(&m_mountains);
  addEntity(&m_bunch);
  addEntity(&m_pick);
  addEntity(&m_joe);
  addEntity(&m_ground);
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

  if (cage::InputManager::isKeysetPressed("mute"))
  {
    m_isMuted = !m_isMuted;
    if (m_isMuted)
    {
      m_music.pause();
    }
    else
    {
      m_music.play();
    }
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

    if (cage::InputManager::isKeysetPressed("action"))
    {
      m_pick.swing();
    }
  }

  m_ground.moveX(offsetX);

  cage::World::update(dt);
}

void CarrotWorld::onEnter(cage::Runtime &runtime)
{
  m_music.play();
}

void CarrotWorld::onLeave(cage::Runtime &runtime)
{
  m_music.stop();
}
