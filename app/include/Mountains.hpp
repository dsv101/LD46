#ifndef MOUNTAINS_HPP
#define MOUNTAINS_HPP

#include "CAGE/lib.hpp"

class Mountains : public cage::Entity
{
  private:
    cage::Texture m_texturePurple;
    cage::Texture m_textureRed;
    cage::Texture m_textureOrange;
    cage::Texture m_textureSky;
    cage::Sprite m_spritePurple;
    cage::Sprite m_spriteRed;
    cage::Sprite m_spriteOrange;
    cage::Sprite m_spriteSky;
    float m_offset = 0.0f;
  public:
    Mountains();
    void update(float dt) override;
    void render(cage::RenderTarget &renderTarget) override;
};

#endif
