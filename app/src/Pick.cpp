#include "Pick.hpp"
#include "app.hpp"

Pick::Pick(float x, float y, float swingLength) :
  m_texture(),
  m_sprite(),
  m_swingLength(swingLength),
  m_timer(0.0f),
  m_isHeld(false),
  cage::Entity(x, y, &m_sprite)
{
  m_texture.loadFromFile(PICK_PNG);
  m_sprite.setTexture(m_texture);
  m_sprite.setOrigin(8, 24);
}

void Pick::update(float dt)
{
  static float scaleX = 1.0f;

  if (isSwinging())
  {
    m_timer -= dt;
    if (m_timer < 0.0f)
    {
      m_timer = 0.0f;
    }
  }

  if (isHeld())
  {
    if (cage::InputManager::isKeysetDown("move-left"))
    {
      scaleX = -1.0f;
    }
    else if (cage::InputManager::isKeysetDown("move-right"))
    {
      scaleX = 1.0f;
    }
    m_sprite.setScale(scaleX, 1.0f);
  }

  m_transformable.setRotation(m_timer * 400 * scaleX);
  cage::Entity::update(dt);
}

bool Pick::isSwinging()
{
  return m_timer > 0.0f;
}

void Pick::swing()
{
  m_timer = m_swingLength;
}

bool Pick::isHeld()
{
  return m_isHeld;
}

void Pick::hold(float x, float y) {
  m_isHeld = true;
  m_transformable.setPosition(x, y);
}

void Pick::moveX(float x) {
  m_transformable.move(x, 0.0f);
}

cage::Vector2f Pick::getPosition()
{
  return m_transformable.getPosition();
}
