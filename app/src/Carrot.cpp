#include "Carrot.hpp"
#include "app.hpp"

Carrot::Carrot(cage::Texture &texture, float x, float y) :
  m_sprite(),
  cage::Entity(x, y, &m_sprite)
{
  m_sprite.setTexture(texture);
  m_transformable.setOrigin(m_width / 2, m_height / 2);
}

void Carrot::update(float dt)
{
  cage::Entity::update(dt);
}

void Carrot::setPosition(float x, float y)
{
  m_transformable.setPosition(x, y);
}
