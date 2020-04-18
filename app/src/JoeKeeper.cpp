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
  int hdir = 0;
  if (cage::InputManager::isKeysetDown("move-left"))
  {
    --hdir;
  }
  if (cage::InputManager::isKeysetDown("move-right"))
  {
    ++hdir;
  }

  int vdir = 0;
  if (cage::InputManager::isKeysetPressed("jump"))
  {
    --vdir;
  }

  m_transformable.move(hdir * HSPD * dt, 0);

  cage::Entity::update(dt);
}
