#ifndef JOEKEEPER_HPP
#define JOEKEEPER_HPP

#include "CAGE/lib.hpp"

class JoeKeeper : public cage::Entity
{
  public:
    JoeKeeper(float x=0.0f, float y=0.0f);
    void update(float dt) override;
    cage::Vector2f getHandPosition() const;
    bool isOnGround();
  private:
    const float HSPD = 150.0f;
    const float GRAV_HI = 40.0f;
    const float JMP = 500.0f;
    float vsp = 0.0f;
    cage::Texture m_texture;
    cage::Sprite m_sprite;
    int m_faceDir = -1;
};

#endif
