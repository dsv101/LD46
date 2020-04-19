#ifndef PICK_HPP
#define PICK_HPP

#include "CAGE/lib.hpp"

class Pick : public cage::Entity
{
  public:
    Pick(float x=0.0f, float y=0.0f, float swingLength=0.1f);
    void swing();
    bool isSwinging();
    void update(float dt) override;
    bool isHeld();
    void hold(float x, float y);
    void moveX(float x);
    cage::Vector2f getPosition();
  private:
    cage::Texture m_texture;
    cage::Sprite m_sprite;
    float m_swingLength;
    float m_timer;
    bool m_isHeld;
};

#endif
