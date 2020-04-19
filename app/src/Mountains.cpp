#include "Mountains.hpp"
#include "app.hpp"

Mountains::Mountains() :
  cage::Entity()
{
  m_texturePurple.loadFromFile(MOUNTAINS_PURPLE_PNG);
  m_texturePurple.setRepeated(true);
  m_spritePurple.setTexture(m_texturePurple);
  m_spritePurple.setTextureRect(cage::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

  m_textureRed.loadFromFile(MOUNTAINS_RED_PNG);
  m_textureRed.setRepeated(true);
  m_spriteRed.setTexture(m_textureRed);
  m_spriteRed.setTextureRect(cage::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

  m_textureOrange.loadFromFile(MOUNTAINS_ORANGE_PNG);
  m_textureOrange.setRepeated(true);
  m_spriteOrange.setTexture(m_textureOrange);
  m_spriteOrange.setTextureRect(cage::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

  m_textureSky.loadFromFile(SKY_PNG);
  m_textureSky.setRepeated(true);
  m_spriteSky.setTexture(m_textureSky);
  m_spriteSky.setTextureRect(cage::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Mountains::update(float dt)
{
    cage::Entity::update(dt);

    if (cage::InputManager::isKeysetDown("move-left"))
    {
      m_offset -= 120 * dt;
    }

    if (cage::InputManager::isKeysetDown("move-right"))
    {
      m_offset += 120 * dt;
    }

    m_spritePurple.setTextureRect(cage::IntRect(m_offset, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    m_spriteRed.setTextureRect(cage::IntRect(m_offset * 0.6, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    m_spriteOrange.setTextureRect(cage::IntRect(m_offset * 0.4, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    m_spriteOrange.setTextureRect(cage::IntRect(m_offset * 0.15, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Mountains::render(cage::RenderTarget &renderTarget)
{
  renderTarget.draw(m_spriteSky, m_transformable.getTransform());
  renderTarget.draw(m_spriteOrange, m_transformable.getTransform());
  renderTarget.draw(m_spriteRed, m_transformable.getTransform());
  renderTarget.draw(m_spritePurple, m_transformable.getTransform());
}
