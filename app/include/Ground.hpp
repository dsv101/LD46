#ifndef GROUND_HPP
#define GROUND_HPP

#include "CAGE/lib.hpp"

class Ground : public cage::Entity
{
  public:
    Ground();
    void moveX(float x);
  private:
    cage::Texture m_texture;
    cage::Sprite m_sprite;
    float m_offset = 0.0f;
};

#endif
