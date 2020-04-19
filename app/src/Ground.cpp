#include "Ground.hpp"
#include "app.hpp"

Ground::Ground() :
  m_texture(),
  m_sprite(),
  cage::Entity(0.0f, 16.0f, &m_sprite)
{
  m_texture.loadFromFile(GROUND_PNG);
  m_texture.setRepeated(true);
  m_sprite.setTexture(m_texture);
  m_sprite.setTextureRect(cage::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Ground::moveX(float x) {
  m_offset -= x;
  m_sprite.setTextureRect(cage::IntRect(m_offset, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}
