#ifndef CARROTWORLD_HPP
#define CARROTWORLD_HPP

#include "CAGE/lib.hpp"
#include "JoeKeeper.hpp"
#include "BunchOfCarrots.hpp"
#include "Mountains.hpp"
#include "Pick.hpp"
#include "Ground.hpp"

class CarrotWorld : public cage::World
{
  public:
    CarrotWorld();
    void update(float dt) override;
  private:
    Mountains m_mountains;
    JoeKeeper m_joe;
    BunchOfCarrots m_bunch;
    Pick m_pick;
    Ground m_ground;
};

#endif
