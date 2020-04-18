#ifndef JOEKEEPER_HPP
#define JOEKEEPER_HPP

#include "CAGE/lib.hpp"

class JoeKeeper : public cage::Entity
{
  public:
    JoeKeeper(float x=0.0f, float y=0.0f);
    void update(float dt) override;
  private:
    const float HSPD = 150.0f;
    cage::Texture m_texture;
    cage::Sprite m_sprite;
};

#endif
