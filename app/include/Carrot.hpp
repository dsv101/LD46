#ifndef CARROT_HPP
#define CARROT_HPP

#include "CAGE/lib.hpp"

class Carrot : public cage::Entity
{
  private:
    float m_width = 32;
    float m_height = 32;
    cage::Sprite m_sprite;

  public:
    Carrot(cage::Texture &texture, float x=0.0f, float y=0.0f);
    void update(float dt) override;
    void setPosition(float x, float y);
};

#endif
