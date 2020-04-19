#include "JoeKeeper.hpp"
#include "app.hpp"

JoeKeeper::JoeKeeper(float x, float y) :
  m_texture(),
  m_sprite(),
  cage::Entity(x, y, &m_sprite)
{
  m_texture.loadFromFile(DUDE_PNG);
  m_sprite.setTexture(m_texture);
  m_transformable.setOrigin(12, 16);
}

void JoeKeeper::update(float dt)
{
  if (cage::InputManager::isKeysetDown("move-left"))
  {
    m_faceDir = -1;
  }
  if (cage::InputManager::isKeysetDown("move-right"))
  {
    m_faceDir = 1;
  }
  if (cage::InputManager::isKeysetPressed("jump") && vsp == 0.0f)
  {
    vsp = -JMP;
  }

  cage::Vector2f pos = m_transformable.getPosition();

  vsp += GRAV_HI;
  if (vsp != 0.0f)
  {
    pos.y += vsp * dt;
  }

  if (pos.y > DUDE_START_Y)
  {
    pos.y = DUDE_START_Y;
    vsp = 0.0f;
  }

  m_transformable.setPosition(pos);
  cage::Entity::update(dt);
}

cage::Vector2f JoeKeeper::getHandPosition() const
{
  cage::Vector2f pos = m_transformable.getPosition();
  pos.x += m_faceDir * 12;

  return pos;
}

bool JoeKeeper::isOnGround()
{
  return m_transformable.getPosition().y == DUDE_START_Y;
}
